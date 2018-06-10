#!/usr/bin/env python

import sys,codecs
def cleanChar(c):
    if ord(c) == 8220 or ord(c) == 8221:
        return u'"'
    if ord(c) == 8217:
        return u"'"
    if ord(c) == 8212:
        return u'-'
    if ord(c) == 160:
        return u' '
    if ord(c) == 239:
        return 'i'
    if ord(c) ==  239:
        return 'i'
    if ord(c) == 8230:
        return '...'
    if ord(c) ==u'\uff1d':
        return '='
    if ord(c) == 65307:
        return ';'
    if ord(c) == 65373:
        return '}'
    if ord(c) == 8211:
        return '-'

cleaned = u''
if __name__ == "__main__":
    with codecs.open(sys.argv[1], "r", "utf-8") as f:
        origFile = f.read()
    for c in origFile:
        #print(repr(c))
        if c == u'\uff1d':
            c = '='
        if c == u'\uff5b':
            c = '{'
        #print c,ord(c)
        #if (c == '-'): quit()
        if ord(c) > 126:
            #print c,ord(c)
            #print cleanChar(c),ord(c)
            c = cleanChar(c)
        cleaned += c
print(cleaned)
