#!/usr/bin/env python

import cgitb
cgitb.enable()

import os,cgi,json,sys

COURSE_DIR="../course/"
STUDENT_REPLACE = "//@@ student code here"
STUDENT_START = "\n// STUDENT CODE STARTS HERE\n"
STUDENT_END = "\n// STUDENT CODE ENDS HERE\n"

form = cgi.FieldStorage() 

# Get data from fields
searchDir = form.getvalue('searchDir')
studentName = form.getvalue('studentName')

print("Content-Type: text/plain\n")

# read in the tester code
with open(COURSE_DIR + searchDir + "/" + "_testCode.cpp") as f:
    template = f.read()

# read in the student's code
with open(COURSE_DIR + searchDir + "/" + studentName) as f:
    studentCode = f.read()

# add some delimeters so we can find the student's code when grading
studentCode = STUDENT_START + studentCode + STUDENT_END

# merge the two by replacing the STUDENT_REPLACE line 
template = template.replace(STUDENT_REPLACE,studentCode)

print(template)
