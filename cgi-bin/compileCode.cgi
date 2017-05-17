#!/usr/bin/env python

import cgitb
cgitb.enable()

import os,cgi,json,sys,tempdir,shutil

COURSE_DIR="../course/"
BUILD_DIR=COURSE_DIR+"build/"

form = cgi.FieldStorage() 

# Get data from fields
codeToRun = form.getvalue('code')

print("Content-Type: text/plain\n")

# save the code to a file where we will compile it
# using the Makefile

# create a temp directory
tempPath = tempfile.mkdtemp()

# put the code there
with open(tempPath+"code.cpp","w") as f:
    f.write(code)

# make the code, and capture all output

# print the output

