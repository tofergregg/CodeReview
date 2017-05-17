#!/usr/bin/env python
import cgitb
cgitb.enable()

import os,cgi,json,re

COURSE_DIR="../course/"

form = cgi.FieldStorage() 

def natural_key(string_):
    """See http://www.codinghorror.com/blog/archives/001018.html"""
    return [int(s) if s.isdigit() else s for s in re.split(r'(\d+)', string_)]

# Get data from fields
searchDir = form.getvalue('searchDir')

print("Content-Type: text/json\n")
dirs = os.listdir(COURSE_DIR+searchDir)

# remove files that start with underscore (these have metadata)
dirs = [x for x in dirs if not x.startswith('_')]

# sort in natural order
dirs = sorted(dirs, key=natural_key)
print(json.dumps(dirs))

