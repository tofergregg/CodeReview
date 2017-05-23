#!/usr/bin/env python

import cgitb
cgitb.enable()

import os,cgi,json,sys
import MySQLdb

form = cgi.FieldStorage() 
SETTINGS_FILE="../settings/settings.txt"

# Get data from fields
course = form.getvalue('course')
offering = form.getvalue('offering')
assignment = form.getvalue('assignment')
problem = form.getvalue('problem')
student = form.getvalue('studentName')

print("Content-Type: text/plain\n")
# read the database settings file
with open(SETTINGS_FILE) as f:
    settings = json.loads(f.read())

# Open database connection
db = MySQLdb.connect(settings['server'],settings['username'],settings['pw'],settings['db'])

# get a cursor for the database manipulation
cursor = db.cursor()

# Get latest change
# select * from revision_table where course='cs106b' and offering='1176' and assignment='midterm' and problem='p2' order by revision desc limit 1;
sql = "select text from `revision_table` where student='%s' and \
                                            course='%s' and \
                                            offering='%s' and \
                                            assignment='%s' and \
                                            problem='%s'" \
                                            % (student,course,offering,assignment,problem)
#print(sql)
#try:
# Execute the SQL command
cursor.execute(sql)

# get all result
result = cursor.fetchall()[0][0].decode('string_escape')

# disconnect from server
db.close()

print(result)
