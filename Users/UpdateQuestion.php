
<?php

require_once '../Classes/QuestionEx.inc';

$cm = $_POST['command'];
//echo $cm;
$questionid = $_POST['questionid'];
$content = $_POST['content'];
//echo $content;
$lectureid = $_POST['lectureid'];
//echo $lectureid;
//echo '<br/>';
$teacherid = $_POST['teacherid'];
//echo $teacherid;
//echo '<br/>';
$saal = $_POST['saal'];
$questiontypeid= $_POST['questiontypeid'];
//echo $questiontypeid;
//echo '<br/>';

$question = new Question();
$question->QuestionId = $questionid;
$question->Content = $content;
$question->Lecture->LectureId = $lectureid;
$question->Teacher->TeacherId = $teacherid;
$question->Saal = $saal;
$question->QuestionType->QuestionTypeId = $questiontypeid;
//echo $question->QuestionId ;
//echo $question->Name ;
//echo $question->Family ;
//echo $question->Username ;
//echo $question->Passwd ;
//echo $cm;
if ($cm == 'edit') {
    QuestionEx::Update($question);
} else {
    QuestionEx::Insert($question);
}

header("Location: Questions.php");



