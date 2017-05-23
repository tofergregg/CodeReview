#!/usr/bin/env python
import cgitb,cgi
cgitb.enable()

import argparse,os,re,tempfile,subprocess
import MySQLdb
import json

SETTINGS_FILE="../settings/settings.txt"

def natural_key(string_):
    """See http://www.codinghorror.com/blog/archives/001018.html"""
    return [int(s) if s.isdigit() else s for s in re.split(r'(\d+)', string_)]

def parse_arguments():
        parser = argparse.ArgumentParser(description='Return a set of responses for a query')
        parser.add_argument('column',
                           help='The column you want to return data from. E.g., course, offering, assignment, problem, student')
        parser.add_argument('course',
                           help='The course (default is blank)',
                           nargs='?',const='')
        parser.add_argument('offering',
                           help='The offering (default is blank)',
                           nargs='?',const='')
        parser.add_argument('assignment',
                           help='The assignment (default is blank)',
                           nargs='?',const='')
        parser.add_argument('problem',
                           help='The problem (default is blank)',
                           nargs='?',const='')
        parser.add_argument('student',
                           help='The student (default is blank)',
                           nargs='?',const='')

        args = parser.parse_args()

        return args

def processArgsForMySql(args):
    partialQuery = ''
    if args.course:
        partialQuery += "course='" + args.course + "' and "
    if args.offering:
        partialQuery += "offering='" + args.offering + "' and "
    if args.assignment:
        partialQuery += "assignment='" + args.assignment + "' and "
    if args.problem:
        partialQuery += "problem='" + args.problem + "' and "
    if args.student:
        partialQuery += "student='" + args.student + "'"
    # remove trailing and if necessary
    if partialQuery.endswith(' and '):
        partialQuery = partialQuery[:-len(' and ')]
    # if there is a query, add a where
    if partialQuery != '':
        partialQuery = 'where ' + partialQuery
    return partialQuery

def processQueryForMySql(column, form):
    # course, offering, assignment, problem
    course = ''
    offering = ''
    assignment = ''
    problem = ''
    student = ''

    searchDir = form.getvalue('searchDir')

    searchDirSplit = searchDir.split('/')
    splitLen = len(searchDirSplit)

    if splitLen == 2 and searchDirSplit[0] == '':
        # no sub-data
        partialQuery = ''
        return ''

    if splitLen >= 5:
        student = searchDirSplit[4]
    if splitLen >= 4:
        problem = searchDirSplit[3]
    if splitLen >= 3:
        assignment = searchDirSplit[2]
    if splitLen >= 2:
        offering = searchDirSplit[1]
    if splitLen >= 1:
        course = searchDirSplit[0]

    partialQuery = ''

    if course:
        partialQuery += "course='" + course + "' and "
    if offering:
        partialQuery += "offering='" + offering + "' and "
    if assignment:
        partialQuery += "assignment='" + assignment + "' and "
    if problem:
        partialQuery += "problem='" + problem + "' and "
    if student:
        partialQuery += "student='" + student + "'"
    # remove trailing and if necessary
    if partialQuery.endswith(' and '):
        partialQuery = partialQuery[:-len(' and ')]
    # if there is a query, add a where
    if partialQuery != '':
        partialQuery = 'where ' + partialQuery
    return partialQuery

def requestDistinctValues(column, partialQuery):
    """ Return distinct entries for the column 
    """
    
    # read the database settings file
    with open(SETTINGS_FILE) as f:
        settings = json.loads(f.read())

    # Open database connection
    db = MySQLdb.connect(settings['server'],settings['username'],settings['pw'],settings['db'])

    # get a cursor for the database manipulation
    cursor = db.cursor()

    # Get latest change
    # select * from revision_table where course='cs106b' and offering='1176' and assignment='midterm' and problem='p2' order by revision desc limit 1;
    sql = "select distinct %s from `revision_table` %s" % (column,partialQuery)
    #print(sql)
    #try:
    # Execute the SQL command
    cursor.execute(sql)
    
    # get all result
    result = [str(x[0]) for x in cursor.fetchall()]
    #print(result)

    # disconnect from server
    db.close()
    
    return result
        
if __name__ == "__main__":
    #args = parse_arguments()
    #partialQuery = processArgsForMySql(args)

    form = cgi.FieldStorage() 
    column = form.getvalue('column')
    partialQuery = processQueryForMySql(column, form)

    distinctValues = requestDistinctValues(column,partialQuery)
    queryResult = sorted(distinctValues,key=natural_key)

    print("Content-Type: text/json\n")
    print(json.dumps(queryResult))

