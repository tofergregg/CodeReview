This is a small website that allows Stanford Section Leaders to 
compile and run student code as uploaded from the Bluebook 
computerized exam program.

In addition to these files, you must also put the 
[https://github.com/ajaxorg/ace-builds "src-conflict" files](https://github.com/ajaxorg/ace-builds)
into the `js/src-noconflict` folder in the website.

In order for the files to work on the Stanford web server, the entire repository
should be placed into the `cgi-bin` folder in a user's top-level directory (i.e,
not in the WWW directory). Permissions must be set through corn:

1. Log into Corn (no fsr command on myth...):

2.
$ fsr sa CodeReview ${USER}.cgi rl

$ fsr sa CodeReview system:www-servers rl

3. For internal cgi-bin folders, you must set ${USER}.cgi to just rl:

$ fs sa cgi-bin ${USER}.cgi rl 
