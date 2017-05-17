#!/usr/bin/env python

import cgitb
cgitb.enable()

import os,cgi,json,sys,tempfile,shutil,subprocess

COURSE_DIR="../course/"
BUILD_DIR=COURSE_DIR+"build/"

form = cgi.FieldStorage() 

# Get data from fields
code = form.getvalue('code')
run = form.getvalue('run')

if code==None:
    code = '#include "error.h"\n#include<iostream>\nint main(){\n    int i=0;\nstd::cout<<"hello\\n";\n    return 0;\n}'
if run==None:
    run = False
else:
    run = (run == 'true')

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
compileOutput = {'compileOutput':compileOut, 'compileErrors':compileErr}

# only run if compiled correctly
if run and compileErr == "":
    os.chdir(tempPath)
    p = subprocess.Popen([tempPath+'code'], stdout=subprocess.PIPE,
                                   stderr=subprocess.PIPE)
    runOut, runErr = p.communicate()
    if runOut == "":
        runOut = "[no output]"
    if runErr == "":
        runErr = "[none]"
    compileOutput['runOutput'] = runOut
    compileOutput['runErrors'] = runErr


# print the output
print(json.dumps(compileOutput))
