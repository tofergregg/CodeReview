#!/usr/bin/env python

import cgitb
cgitb.enable()

import os,cgi,json,sys,tempfile,subprocess
import MySQLdb

SETTINGS_FILE="../settings/settings.txt"

def patchCode(code,diff):
    """run the patch command on code and diff
       to get the new code
    """
    # create a temp directory
    tempPath = tempfile.mkdtemp()+'/'
    
    # save original code
    with open(tempPath+"/code.c","w") as f:
        f.write(code+'\n')

    # save new code
    with open(tempPath+"/code.pat","w") as f:
        f.write(diff+'\n')

    # run the patch command
    cat = subprocess.Popen(['cat',tempPath+'/code.pat'],stdout=subprocess.PIPE)
    patch = subprocess.check_output(['patch', tempPath+'code.c'],
            stdin=cat.stdout)
    cat.wait()

    # read in patched file
    with open(tempPath+"/code.c","r") as f:
        newCode = f.read()
    return newCode 
    
if __name__ == "__main__":
    form = cgi.FieldStorage() 

    # Get data from fields
    course = form.getvalue('course')
    offering = form.getvalue('offering')
    assignment = form.getvalue('assignment')
    problem = form.getvalue('problem')
    student = form.getvalue('studentName')
    revision = form.getvalue('revision').split(' ')[0] # could be in the form: 1 (c)
    unique_compile = form.getvalue('unique_compile')

    print("Content-Type: text/plain\n")
    # read the database settings file
    with open(SETTINGS_FILE) as f:
        settings = json.loads(f.read())

    # Open database connection
    db = MySQLdb.connect(settings['server'],settings['username'],settings['pw'],settings['db'])

    # get a cursor for the database manipulation
    cursor = db.cursor()

    # we must patch the diff and return the patched file

    # get original
    if unique_compile:
        sql = "select text from `revision_table` where unique_compile='%s'" % (unique_compile)
    else:
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
    escapedCode = cursor.fetchall()[0][0]
    #origCode = escapedCode.decode('string_escape')
    origCode = escapedCode # hmm...we might need to deal with this

    if revision == '0' or unique_compile:
        print(origCode)
    else:
        # get the revision we want
        sql = "select text from `revision_table` where student='%s' and \
                                                    course='%s' and \
                                                    offering='%s' and \
                                                    assignment='%s' and \
                                                    problem='%s' and \
                                                    revision='%s'" \
                                                    % (student,course,offering,assignment,problem,revision)
        #print(sql)
        #try:
        # Execute the SQL command
        cursor.execute(sql)

        # get all result
        diff = cursor.fetchall()[0][0]
        #diff = diff.decode('string_escape')
        #print(diff)
        # disconnect from server
        db.close()

        result = patchCode(origCode,diff)

        print(result)
