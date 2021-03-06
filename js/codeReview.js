var editor = ace.edit("editor");
editor.setTheme("ace/theme/eclipse");
editor.session.setMode("ace/mode/c_cpp");
editor.$blockScrolling = Infinity

var cpp_console = ace.edit("cpp_console");
cpp_console.setTheme("ace/theme/eclipse");
cpp_console.session.setMode("ace/mode/text");
cpp_console.$blockScrolling = Infinity

var good_code_console = ace.edit("good_code_console");
good_code_console.setTheme("ace/theme/eclipse");
good_code_console.session.setMode("ace/mode/c_cpp");
good_code_console.$blockScrolling = Infinity

function initCodeReview() {
    console.log("Initializing...");
    
    // get a list of courses
    getCourses('/');
}

function getCourses(mainDir) {
    getDirInfo('course',mainDir,function(data) {
        var courses = data
        //console.log(courses)
        populateOptions("course",courses);
        getOffering(courses[0]);
    });
}

function getOffering(courseDir) {
    getDirInfo('offering',courseDir,function(data) {
        var offering = data
        //console.log(offering)
        populateOptions("offering",offering);
        getAssn(courseDir+'/'+offering[0]);
    });
}

function getAssn(offeringDir) {
    getDirInfo('assignment',offeringDir,function(data) {
        var assn = data
        //console.log(assn)
        populateOptions("assn",assn);
        getProblems(offeringDir+'/'+assn[0]);
    });
}

function getProblems(assnDir) {
    getDirInfo('problem',assnDir,function(data) {
        var problems = data
        //console.log(problems)
        populateOptions("problem",problems);
        getStudents(assnDir+"/"+problems[0]);
        getSolutions(assnDir+"/"+problems[0]);
    });
}

function getStudents(problemDir) {
    getDirInfo('student',problemDir,function(data) {
        var students = data
        //console.log(students)
        populateOptions("student",students);
        getRevision(problemDir+"/" + students[0])
    });
}

function getRevision(studentsDir) {
    getDirInfo('revision',studentsDir,function(data) {
        var revisions = data
        //console.log(revisions)
        populateOptions("revision",revisions);
        revisionChanged();
    });
}

function getSolutions(problemDir) {
    getDirInfo('score',problemDir,function(data) {
        var students = data
        //console.log(students)
        populateSolutionsOptions("closeCode",students);
        solutionChanged();
    });
}

function courseChanged() {
    setSpinner(true);
    var courseDir = $("#course")[0].value;
    getOffering(courseDir);
}

function offeringChanged() {
    setSpinner(true);
    var offeringDir = $("#course")[0].value + "/" +
                 $("#offering")[0].value;
    getAssn(offeringDir);
}

function assnChanged() {
    setSpinner(true);
    var assnDir = $("#course")[0].value + "/" +
                 $("#offering")[0].value + "/" +
                 $("#assn")[0].value;
    getProblems(assnDir);
}

function problemChanged() {
    setSpinner(true);
    var problemDir = $("#course")[0].value + "/" +
                 $("#offering")[0].value + "/" +
                 $("#assn")[0].value + "/" +
                 $("#problem")[0].value;
    getStudents(problemDir);
    getSolutions(problemDir);
}

function studentChanged() {
    setSpinner(true);
    var studentDir = $("#course")[0].value + "/" +
                 $("#offering")[0].value + "/" +
                 $("#assn")[0].value + "/" +
                 $("#problem")[0].value + "/" +
                 $("#student")[0].value;
    getRevision(studentDir);
}

function revisionChanged() {
    // start spinner
    setSpinner(true);
    var course = $("#course")[0].value;
    var offering = $("#offering")[0].value;
    var assn = $("#assn")[0].value;
    var problem = $("#problem")[0].value;
    var studentName = $("#student")[0].value;
    var revision = $("#revision")[0].value;
    if (revision.indexOf('original') == 0) {
       revision = '0'; // revert to numbers
    } 

    $.post("cgi-bin/loadStudent.cgi", {"course" : course,
        "offering" : offering,
        "assignment" : assn,
        "problem" : problem,
        "studentName" : studentName,
        "revision" : revision}).done(function(data) {
            editor.setValue(data);
            editor.clearSelection();
            // stop spinner
            setSpinner(false);
        });
}

function solutionChanged() {
    // start spinner
    setSpinner(true);
    var unique_compile = $("#closeCode")[0].value;
    if (unique_compile != "") {
        $.post("cgi-bin/loadStudent.cgi", {"unique_compile" : unique_compile, 'revision' : '0'}).done(function(data) {
            good_code_console.setValue(data);
            good_code_console.clearSelection();
            // stop spinner
            setSpinner(false);
        });
    }
}

function setSpinner(value) {
    var spinner = $("#spinner")[0];
    spinner.style.visibility = (value == true ? 'visible' : 'hidden');
}

//function getDirInfo(column, dir, callBack) {
//    $.post( "cgi-bin/listdir.cgi", { "searchDir" : dir })
//      .done(callBack);
//}

function getDirInfo(column, dir, callBack) {
    $.post( "cgi-bin/listParts.cgi", { "column" : column, "searchDir" : dir })
        .done(callBack);
}

function populateOptions(id,options) {
    var sel = $("#"+id);
    // remove all current options
    sel.find('option')
        .remove()
        .end();
    for (var i=0; i < options.length; i++) {
        var opt = document.createElement('option');
        //console.log(id);
        opt.value = options[i];
        opt.innerHTML = options[i];
        sel[0].appendChild(opt);
    }
}

function populateSolutionsOptions(id,options) {
    var sel = $("#"+id);
    // remove all current options
    sel.find('option')
        .remove()
        .end();
    for (var i=0; i < options.length; i++) {
        var opt = document.createElement('option');
        // should be an array with two indices
        opt.value = options[i][1];
        opt.innerHTML = options[i][0];
        sel[0].appendChild(opt);
    }
}

function compileProg(runProg) {
    // if runProg is true, will run the program
    setSpinner(true);
    var code=editor.getValue();
    var timeout = $("#timeout")[0].value;
    var course = $("#course")[0].value;
    var offering = $("#offering")[0].value;
    var assignment = $("#assn")[0].value;
    var problem = $("#problem")[0].value;
    var student = $("#student")[0].value;
    $.post("cgi-bin/compileCode.cgi", {'code' : code, 
        'run' : (runProg ? 'true' : 'false'), 
        'timeout' : timeout,
        'course' : course,
        'offering' : offering,
        'assignment' : assignment,
        'problem' : problem,
        'student' : student })
        .done(function(compileRet) {
            compileOutput = compileRet[0];
            revision = compileRet[1]; 
            //console.log(compileOutput);
            //console.log(revision);
            //var current_cpp_console = cpp_console.getValue()
            var current_cpp_console = ""
            if(compileOutput['compileErrors'] == "") {
                cpp_console.setValue(current_cpp_console+"Program compiled successfully."
                    +"\n\n");
                // print run output if necessary
                if (runProg) {
                    current_cpp_console = cpp_console.getValue()
            cpp_console.setValue(current_cpp_console
                +'Run output:\n'
                +compileOutput['runOutput']
                +'\n\nRun errors:\n'
                +compileOutput['runErrors']
                +'\n\nTimed out? '
                +(compileOutput['returnCode'] == '124' ? 'TIMED OUT' : 'No')
                +'\n\n');

                }
            } else {
                cpp_console.setValue(current_cpp_console+compileOutput['compileErrors']+'\n\n');
            }
        cpp_console.clearSelection();
        // update revision opt and set to latest
        var sel = $("#revision");
        // remove all current options
        var opt = document.createElement('option');
        opt.value = revision;
        opt.innerHTML = revision;
        sel[0].appendChild(opt);
        sel[0].value = revision; 
        setSpinner(false);
        });
}

