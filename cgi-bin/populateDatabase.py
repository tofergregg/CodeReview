#!/usr/bin/env python

import argparse,os,re,tempfile,subprocess
import MySQLdb
import json

STUDENT_START = "\n// STUDENT CODE STARTS HERE\n"
STUDENT_END = "\n// STUDENT CODE ENDS HERE\n"
STUDENT_REPLACE = "//@@ student code here"
SETTINGS_FILE = "../settings/settings.txt"

def natural_key(string_):
    """See http://www.codinghorror.com/blog/archives/001018.html"""
    return [int(s) if s.isdigit() else s for s in re.split(r'(\d+)', string_)]

def parse_arguments():
        parser = argparse.ArgumentParser(description='Populate mysql database with student exam responses')
        parser.add_argument('course',
                           help='the course number, e.g., cs106b')
        parser.add_argument('offering',
                           help='quarter, e.g., 1172')
        parser.add_argument('assignment',
                           help='e.g., midterm')
        parser.add_argument('problem_number',
                           help='e.g., p2')
        parser.add_argument('problem_folder',
                           help='e.g., "/afs/ir/class/cs106b/midterm_responses/p2"')

        args = parser.parse_args()

        return args

def mergeCode(studentCode, testCode):
    # create template that starts with including all Stanford lib headers
    template = '#include "allStanfordHeaders.h"\n'

    template += testCode 

    # add some delimeters so we can find the student's code when grading
    studentCode = STUDENT_START + studentCode + STUDENT_END

    # merge the two by replacing the STUDENT_REPLACE line 
    template = template.replace(STUDENT_REPLACE,studentCode)

    return template

def compileCode(tempPath,code):
    """ All we care about is whether or not
        the code compiled correctly.
    """
    # put the code in the tempPath 
    with open(tempPath+"code.cpp","w") as f:
        f.write(code+'\n')

    # make the code, and capture all output
    # first, change directory to the build directory
    os.chdir('../build')

    # run the build command
    p = subprocess.Popen(['make', 'PROG='+tempPath+'code'], stdout=subprocess.PIPE, 
                                       stderr=subprocess.PIPE)
    compileOut, compileErr = p.communicate()
    return compileErr == ""

def addToDatabase():
    pass
def processAll(args):
    """ For each student code response in the problem folder,
        create a full program, compile, and populate the mysql
        database
    """
    # read the template test code
    with open(args.problem_folder+'/_testCode.cpp') as f:
        testCode = f.read()

    # get a listing of all the student submissions
    students = os.listdir(args.problem_folder)

    # remove underscore meta files
    students = [x for x in students if not x.startswith('_')]
    
    # sort naturally
    students = sorted(students,key=natural_key)

    # create a temp directory for compiling
    tempPath = tempfile.mkdtemp()+'/'

    # read the database settings file
    with open(SETTINGS_FILE) as f:
        settings = json.loads(f.read())

    # Open database connection
    db = MySQLdb.connect(settings['server'],settings['username'],settings['pw'],settings['db'])

    # get a cursor for the database manipulation
    cursor = db.cursor()

    # Get latest change
    # select * from revision_table where course='cs106b' and offering='1176' and assignment='midterm' and problem='p2' order by revision desc limit 1;

    for student in students:
        # pull out student name
        # (may change depending on formatting of names in folders)
        sunet = student.split('.')[0]
        filename = args.problem_folder+'/'+student
        
        # load the code
        with open(filename) as f:
            code = f.read()

        # merge it
        code = mergeCode(code,testCode)

        # compile and get result
        compileResult = compileCode(tempPath,code)
        print(sunet + " : " + str(compileResult))
        
        # Prepare SQL query to INSERT a record into the database.
        # first, escape code
        escCode = db.escape_string(code.decode("utf8").encode('ascii',errors='ignore'))
        sql = "INSERT INTO %s \
               (course, offering, assignment, problem, student, modified_by, \
               compile_result, score, timed_out, timeout, diff, \
               text, keystrokes, revision) \
               VALUES ('%s', '%s', '%s', '%s', '%s', 'cgregg', \
                       '%s', '0', '0', '5', '0', \
                       '%s', '', '%d'  )" % \
               (settings['table'],
                args.course, args.offering, args.assignment, args.problem_number,
                sunet,int(compileResult),escCode, 0)
        #print(sql)
        try:
            # Execute the SQL command
            cursor.execute(sql)
            # Commit your changes in the database
            db.commit()
            print("committed to db")
        except:
           # Rollback in case there is any error
           print("rolling back db")
           db.rollback()

    # disconnect from server
    db.close()

def getTerm(offering):
    if offering.endswith('2'):
        return "Fall"
    if offering.endswith('4'):
        return "Winter"
    if offering.endswith('6'):
        return "Spring"
    if offering.endswith('8'):
        return "Summer"
        
if __name__ == "__main__":
    args = parse_arguments()
    offeringTerm = getTerm(args.offering)
    print("You are about to add names to the database")
    print("with the following information:\n")
    print("Course: %s\nOffering: %s (%s)" %
            (args.course,args.offering,offeringTerm))
    print("Assignment: %s\nProblem: %s\nProblem folder: %s\n" % 
        (args.assignment,args.problem_number, args.problem_folder))
    print("Please type 'yes' to proceed.")
    answer = raw_input()
    if answer == 'yes':
        processAll(args)

