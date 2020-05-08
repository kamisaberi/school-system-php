
<?php

require_once '../Classes/StudentEx.inc';

$cm = $_POST['command'];
//echo $cm;
$studentid = $_POST['studentid'];
$content = $_POST['name'];
$family = $_POST['family'];
$codemelli = $_POST['codemelli'];
$passwd = $_POST['password'];



$student = new Student();
$student->StudentId = $studentid;
$student->Name = $content;
$student->Family = $family;
$student->CodeMelli = $codemelli;
$student->Passwd = $passwd;
//echo $teacher->TeacherId ;
//echo $teacher->Name ;
//echo $teacher->Family ;
//echo $teacher->Username ;
//echo $teacher->Passwd ;
//echo $cm;
if ($cm == 'edit') {
    StudentEx::Update($student);
    header("Location: Students.php");
} else {
    if (StudentEx::CheckExists($codemelli) == FALSE) {
        StudentEx::Insert($student);
        header("Location: Students.php");
    } else {
        header("Location: Student.php");
    }
}





