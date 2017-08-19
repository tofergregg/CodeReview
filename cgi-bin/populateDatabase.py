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
        parser = argparse.ArgumentParser(description='Populate mysql database with student exam responses (problem folder in json form)')
        parser.add_argument('course',
                           help='the course number, e.g., cs106b')
        parser.add_argument('offering',
                           help='quarter, e.g., 1172')
        parser.add_argument('assignment',
                           help='e.g., midterm')
        parser.add_argument('problem_folder',
                           help='e.g., "/afs/ir/class/cs106b/midterm_responses/p2/"')
        parser.add_argument('bracketed_problems',
                           help='e.g., if you want to select problems 1, 4, 5, it should be [1,4,5]')

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
def processAll(args,inputProblems):
    """ For each student code response in the problem folder,
        create a full program, compile, and populate the mysql
        database
    """
    # get a listing of all the student submissions
    students = os.listdir(args.problem_folder)
    
    # remove underscore meta files
    students = [x for x in students if not x.startswith('_')]

    # remove files that end with tilde ~
    students = [x for x in students if not x.endswith('~')]

    # remove non-json files
    studetns = [x for x in students if x.endswith('.json')]
    
    # sort naturally
    students = sorted(students,key=natural_key)

    # read the database settings file
    with open(SETTINGS_FILE) as f:
        settings = json.loads(f.read())

    # Open database connection
    db = MySQLdb.connect(settings['server'],settings['username'],settings['pw'],settings['db'])

    for student in students:
        # read in json for student
        with open(args.problem_folder+'/'+student) as f:
            studentData = json.loads(f.read())
            problems = [x for x in studentData.keys() if x.startswith("Problem")]
        print("student: %s, problems:%s" % (student,str(problems)))
        for problem in problems:
            if not problem in inputProblems: continue
            # read the template test code
            print("Problem: "+problem+" Student: "+student)
            with open(args.problem_folder+'_testCode_'+problem+'.cpp') as f:
                testCode = f.read()
            # create a temp directory for compiling
            tempPath = tempfile.mkdtemp()+'/'

            # get a cursor for the database manipulation
            cursor = db.cursor()

            # Get latest change
            # select * from revision_table where course='cs106b' and offering='1176' and assignment='midterm' and problem='p2' order by revision desc limit 1;

            # pull out student name
            # (may change depending on formatting of names in folders)
            sunet = student.split('.')[0]

            filename = args.problem_folder+'/'+student
            
            # get the code for this problem
            code = studentData[problem]

            # merge it
            code = mergeCode(code,testCode)

            # compile and get result
            compileResult = compileCode(tempPath,code)
            print(sunet + " : " + str(compileResult))
            
            # Prepare SQL query to INSERT a record into the database.
            # first, escape code
            escCode = db.escape_string(code.decode("utf8").encode('ascii',errors='ignore'))
            if sunet == 'cgregg':
                score = 100
            else:
                score = 0
            sql = "INSERT INTO %s \
                   (course, offering, assignment, problem, student, modified_by, \
                   compile_result, score, timed_out, timeout, diff, \
                   text, keystrokes, revision) \
                   VALUES ('%s', '%s', '%s', '%s', '%s', 'cgregg', \
                           '%s', %d, '0', 5, '0', \
                           '%s', '', '%d'  )" % \
                   (settings['table'],
                    args.course, args.offering, args.assignment, problem,
                    sunet,int(compileResult),score,escCode, 0)
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
        return "Fall 20" + str(offering[1:3])
    if offering.endswith('4'):
        return "Winter 20" + str(offering[1:3])
    if offering.endswith('6'):
        return "Spring 20" + str(offering[1:3])
    if offering.endswith('8'):
        return "Summer 20" + str(offering[1:3])

def parseProblems(problemString):
    """ problemString should be in the form
    [1,2,3]"""
    problemString = problemString[1:-1] # strip brackets
    return ["Problem " + x for x in problemString.split(',')]
    
if __name__ == "__main__":
    args = parse_arguments()
    offeringTerm = getTerm(args.offering)
    problems = parseProblems(args.bracketed_problems)
    print("You are about to add names to the database")
    print("with the following information:\n")
    print("Course: %s\nOffering: %s (%s)" %
            (args.course,args.offering,offeringTerm))
    print("Assignment: %s\nProblem folder: %s\n" % 
        (args.assignment, args.problem_folder))
    print("Problems: %s" % str(problems))
    print("Please type 'yes' to proceed.")
    answer = raw_input()
    if answer == 'yes':
        processAll(args,problems)

