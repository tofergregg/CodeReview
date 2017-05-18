#!/usr/bin/env python
print("Content-Type: text/html")
print
import cgi,cgitb
cgitb.enable()
import sys
print(sys.version_info)
#read POST_STRING
#echo $POST_STRING
#echo $POST_STRING | LD_LIBRARY_PATH=/afs/.ir/users/c/g/cgregg/cgi-bin/local_libc/lib/x86_64-linux-gnu/ ./listdir.py

