
<?php

require_once '../Classes/ClassRoomEx.inc';

$cm = $_POST['command'];
//echo $cm;
$classroomid = $_POST['classroomid'];
$content = $_POST['name'];
$lectureid = $_POST['lectureid'];
$teacherid = $_POST['teacherid'];
$termid = $_POST['termid'];
$saal = $_POST['saal'];
$gradetypeid= $_POST['gradetypeid'];


$exam = new ClassRoom();
$exam->ClassRoomId = $classroomid;
$exam->Name = $content;
$exam->Lecture->LectureId = $lectureid;
$exam->Teacher->TeacherId = $teacherid;
$exam->Term->TermId = $termid;
$exam->Saal = $saal;
$exam->GradeType->GradeTypeId = $gradetypeid;
//echo $classRoom->ClassRoomId ;
//echo $classRoom->Name ;
//echo $classRoom->Family ;
//echo $classRoom->Username ;
//echo $classRoom->Passwd ;
//echo $cm;
if ($cm == 'edit') {
    ClassRoomEx::Update($exam);
} else {
    ClassRoomEx::Insert($exam);
}

header("Location: ClassRooms.php");



