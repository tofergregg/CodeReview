#!/usr/bin/env python

import cgitb
cgitb.enable()

import os,cgi,json,sys,tempfile,shutil,subprocess
import MySQLdb

COURSE_DIR="../course/"
BUILD_DIR=COURSE_DIR+"build/"
DEFAULT_TIMEOUT = 5
SETTINGS_FILE = "../settings/settings.txt"

def createDiff(origCode, newCode, db,cursor,table,
        course, offering, assignment, problem, student, compileResult):
    """run diff on the two pieces of code and return the result
    """
    # create a temp directory
    tempPath = tempfile.mkdtemp()+'/'
    
    # save original code
    with open(tempPath+"/origCode.cpp","w") as f:
        f.write(origCode+'\n')

    # save new code
    with open(tempPath+"/newCode.cpp","w") as f:
        f.write(newCode+'\n')

    # run the diff command
    p = subprocess.Popen(['diff', tempPath+'origCode.cpp', tempPath+'newCode.cpp'],
            stdout=subprocess.PIPE, stderr=subprocess.PIPE)
    diffOut, diffErr = p.communicate()

    # Get revision to update
    sql = "select revision from `revision_table` where student='%s' and \
                                                course='%s' and \
                                                offering='%s' and \
                                                assignment='%s' and \
                                                problem='%s' order by revision desc limit 1" \
                                                % (student,course,offering,assignment,problem)
    # Execute the SQL command
    cursor.execute(sql)

    # get all result
    result = cursor.fetchone()
    revision = result[0]

    # Prepare SQL query to INSERT a record into the database.
    # first, escape code
    escDiff = db.escape_string(diffOut.decode("utf8").encode('ascii',errors='ignore'))
    sql = "INSERT INTO %s \
           (course, offering, assignment, problem, student, modified_by, \
           compile_result, was_run, timed_out, timeout, diff, \
           text, keystrokes, revision) \
           VALUES ('%s', '%s', '%s', '%s', '%s', 'cgregg', \
                   '%s', '0', '0', '5', '0', \
                   '%s', '', '%d'  )" % \
           (table,
            course, offering, assignment, problem,
            student,int(compileResult),escDiff, revision+1)
    #print(sql)
    try:
        # Execute the SQL command
        cursor.execute(sql)
        # Commit your changes in the database
        db.commit()
        #print("committed to db")
    except:
       # Rollback in case there is any error
       #print("rolling back db")
       db.rollback()

def saveCodeToDatabase(course, offering, assignment, problem, student, code, compileResult):
    # read the database settings file
    with open(SETTINGS_FILE) as f:
        settings = json.loads(f.read())

    # Open database connection
    db = MySQLdb.connect(settings['server'],settings['username'],settings['pw'],settings['db'])

    # get a cursor for the database manipulation
    cursor = db.cursor()

    # Get original code
    sql = "select text from `revision_table` where student='%s' and \
                                                course='%s' and \
                                                offering='%s' and \
                                                assignment='%s' and \
                                                problem='%s' and \
                                                revision='0'" \
                                                % (student,course,offering,assignment,problem)
    #print(sql)
    #try:
    # Execute the SQL command
    cursor.execute(sql)

    # get all result
    result = cursor.fetchone()
    origCode = result[0].decode('string_escape')

    createDiff(origCode,code,db,cursor,settings['table'],
            course,offering,assignment,problem,student,compileResult)

    # disconnect from server
    db.close()
if __name__ == "__main__":
    form = cgi.FieldStorage() 

    # Get data from fields
    code = form.getvalue('code')
    run = form.getvalue('run')
    timeout = form.getvalue('timeout')
    course = form.getvalue('course')
    offering = form.getvalue('offering')
    assignment = form.getvalue('assignment')
    problem = form.getvalue('problem')
    student = form.getvalue('student')

    if code==None:
        code = '#include "error.h"\n#include<iostream>\nint main(){\n    int i=0;\nstd::cout<<"hello\\n";\n    return 0;\n}'
    if run==None:
        run = False
    else:
        run = (run == 'true')

    if timeout==None:
        timeout = DEFAULT_TIMEOUT 
    else:
        timeout = int(timeout) 

    print("Content-Type: text/json\n")


    # save the code to a file where we will compile it
    # using the Makefile

    # create a temp directory
    tempPath = tempfile.mkdtemp()+'/'

    # put the code there
    with open(tempPath+"code.cpp","w") as f:
        f.write(code+'\n')

    # make the code, and capture all output
    # first, change directory to the build directory
    os.chdir('../build')

    # run the build command
    p = subprocess.Popen(['make', 'PROG='+tempPath+'code'], stdout=subprocess.PIPE, 
                                       stderr=subprocess.PIPE)
    compileOut, compileErr = p.communicate()
    compileOutput = {'compileOutput':compileOut, 'compileErrors':compileErr, 'tempPath':tempPath}

    # only run if compiled correctly
    if run and compileErr == "":
        os.chdir(tempPath)
        p = subprocess.Popen(['timeout',str(timeout),tempPath+'code'], stdout=subprocess.PIPE,
                                       stderr=subprocess.PIPE)
        runOut, runErr = p.communicate()
        if runOut == "":
            runOut = "[no output]"
        if runErr == "":
            runErr = "[none]"
        compileOutput['runOutput'] = runOut
        compileOutput['runErrors'] = runErr
        compileOutput['returnCode'] = str(p.returncode)

    # save the diff to the database
    saveCodeToDatabase(course, offering, assignment, problem, 
            student, code, compileErr == True)

    # print the output
    print(json.dumps(compileOutput))
