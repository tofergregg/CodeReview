var editor = ace.edit("editor");
editor.setTheme("ace/theme/eclipse");
editor.session.setMode("ace/mode/c_cpp");
editor.$blockScrolling = Infinity

var cpp_console = ace.edit("cpp_console");
cpp_console.setTheme("ace/theme/eclipse");
cpp_console.session.setMode("ace/mode/text");

function init() {
    console.log("Initializing...");
    
    // get a list of courses
    getCourses('/');
}

function getCourses(mainDir) {
    getDirInfo(mainDir,function(data) {
        var courses = data
        console.log(courses)
        populateOptions("course",courses);
        getAssn(mainDir+"/"+courses[0]);
    });
}

function getAssn(courseDir) {
    getDirInfo(courseDir,function(data) {
        var assn = data
        console.log(assn)
        populateOptions("assn",assn);
        getProblems(courseDir+"/"+assn[0]);
    });
}

function getProblems(assnDir) {
    getDirInfo(assnDir,function(data) {
        var problems = data
        console.log(problems)
        populateOptions("problem",problems);
        getStudents(assnDir+"/"+problems[0]);
    });
}

function getStudents(problemDir) {
    getDirInfo(problemDir,function(data) {
        var students = data
        console.log(students)
        populateOptions("student",students);
        studentChanged(); 
    });
}

function courseChanged() {
    var courseDir = $("#course")[0].value;
    getAssn(courseDir);
}

function assnChanged() {
    var assnDir = $("#course")[0].value + "/" +
                 $("#assn")[0].value;
    getProblems(assnDir);
}

function problemChanged() {
    var problemDir = $("#course")[0].value + "/" +
                 $("#assn")[0].value + "/" +
                 $("#problem")[0].value;
    getStudents(problemDir);
}

function studentChanged() {
    var searchDir = $("#course")[0].value + "/" +
                 $("#assn")[0].value + "/" +
                 $("#problem")[0].value;
    var studentName = $("#student")[0].value;
    $.post("cgi-bin/loadStudent.cgi", {"searchDir" : searchDir,
        "studentName" : studentName}).done(function(data) {
            editor.setValue(data);
            editor.clearSelection();
        });
}


function getDirInfo(dir, callBack) {
$.post( "cgi-bin/listdir.cgi", { "searchDir" : dir })
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
        opt.value = options[i];
        opt.innerHTML = options[i];
        sel[0].appendChild(opt);
    }
}



