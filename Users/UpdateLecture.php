
<?php

require_once '../Classes/LectureEx.inc';

$cm = $_POST['command'];
//echo $cm;
$lectureid= $_POST['lectureid'];
$content = $_POST['name'];
$tedadvahed= $_POST['tedadvahed'];
$tozihat = $_POST['tozihat'];


$lecture= new Lecture();
$lecture->LectureId = $lectureid;
$lecture->Name = $content;
$lecture->TedadVahed = $tedadvahed;
$lecture->Tozihat = $tozihat;
//echo $teacher->TeacherId ;
//echo $teacher->Name ;
//echo $teacher->Family ;
//echo $teacher->Username ;
//echo $teacher->Passwd ;
//echo $cm;
if ($cm == 'edit') {
    LectureEx::Update($lecture);
} else {
    LectureEx::Insert($lecture);
}

header("Location: Lectures.php");



