
<?php

require_once '../Classes/TeacherEx.inc';

$cm = $_POST['command'];
//echo $cm;
$teacherid = $_POST['teacherid'];
$content = $_POST['name'];
$family = $_POST['family'];
$username = $_POST['username'];
$passwd = $_POST['password'];
$codemelli = $_POST['codemelli'];


$student = new Teacher();
$student->TeacherId = $teacherid;
$student->Name = $content;
$student->Family = $family;
$student->CodeMelli = $codemelli;
$student->Username = $username;
$student->Passwd = $passwd;
//echo $teacher->TeacherId ;
//echo $teacher->Name ;
//echo $teacher->Family ;
//echo $teacher->Username ;
//echo $teacher->Passwd ;
//echo $cm;
if ($cm == 'edit') {
    TeacherEx::Update($student);
} else {
    TeacherEx::Insert($student);
}

header("Location: Teachers.php");



