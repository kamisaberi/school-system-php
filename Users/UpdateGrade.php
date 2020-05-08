
<?php

require_once '../Classes/GradeEx.inc';

$cm = $_POST['command'];
//echo $cm;
$gradeid = $_POST['gradeid'];
$content = $_POST['name'];
$family = $_POST['family'];
$username = $_POST['username'];
$passwd = $_POST['password'];



$grade = new Grade();
$grade->GradeId = $gradeid;
$grade->Name = $content;
$grade->Family = $family;
$grade->Username = $username;
$grade->Passwd = $passwd;
//echo $grade->GradeId ;
//echo $grade->Name ;
//echo $grade->Family ;
//echo $grade->Username ;
//echo $grade->Passwd ;
//echo $cm;
if ($cm == 'edit') {
    GradeEx::Update($grade);
} else {
    GradeEx::Insert($grade);
}

header("Location: Grades.php");



