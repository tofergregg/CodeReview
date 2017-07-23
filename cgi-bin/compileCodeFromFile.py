#!/usr/bin/env python

import cgitb
cgitb.enable()

import os,cgi,json,sys,tempfile,shutil,subprocess
import MySQLdb

COURSE_DIR="../course/"
BUILD_DIR=COURSE_DIR+"build/"
DEFAULT_TIMEOUT = 5
SETTINGS_FILE = "../settings/settings.txt"

if __name__ == "__main__":

    form = cgi.FieldStorage() 

    # Get data from fields
    #code = form.getvalue('code')
    with open(sys.argv[1]) as f:
        code = f.read()

    run = form.getvalue('run')
    timeout = form.getvalue('timeout')
    course = form.getvalue('course')
    offering = form.getvalue('offering')
    assignment = form.getvalue('assignment')
    problem = form.getvalue('problem')
    student = form.getvalue('student')

    if code==None:
        code = '#include "error.h"\n#include<iostream>\nint main(){\n    std::cout<<"hello\\n";\n    return 0;\n}'
    if run==None:
        run = True
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
        origDir = os.getcwd()
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
        os.chdir(origDir)


    # print the output
    print(compileOutput)
