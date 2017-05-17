#!/usr/bin/env python
##!../../python_local/bin/python
import cgitb
cgitb.enable()

import os,cgi,json

COURSE_DIR="../course/"

form = cgi.FieldStorage() 

# Get data from fields
searchDir = form.getvalue('searchDir')

print("Content-Type: text/json\n")
dirs = os.listdir(COURSE_DIR+searchDir)

# remove files that start with underscore (these have metadata)
dirs = [x for x in dirs if not x.startswith('_')]
print(json.dumps(dirs))

