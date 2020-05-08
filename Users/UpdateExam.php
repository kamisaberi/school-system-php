
<?php

require_once '../Classes/ExamEx.inc';

$cm = $_POST['command'];
//echo $cm;
$examid= $_POST['examid'];
$title= $_POST['title'];
$teacherid = $_POST['teacherid'];

$saal= $_POST['saal'];
$lectureid = $_POST['lectureid'];


$exam = new Exam();
$exam->ExamId= $examid;
$exam->Title= $title;
$exam->Teacher->TeacherId = $teacherid;
$exam->Saal= $saal;
$exam->Lecture->LectureId = $lectureid;

if ($cm == 'edit') {
    ExamEx::Update($exam);
} else {
    ExamEx::Insert($exam);
}

header("Location: Exams.php");



