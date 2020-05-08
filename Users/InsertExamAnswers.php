
<?php
session_start();
require_once '../Classes/ExamEx.inc';
require_once '../Classes/AnswerEx.inc';
require_once '../Classes/StudentEx.inc';

//$cm = $_POST['command'];
//echo $cm;
$examid = $_POST['examid'];
$answers = $_POST['answer'];
$questions = $_POST['question'];


print_r($questions);
print_r($answers);
$exam = new Exam();
$exam = ExamEx::GetOneExam($examid);
$student = new Student();
$v = $_SESSION['User'];
$student = StudentEx::GetOnStudentBasedOnCoeMelli($v);
$id = $student->StudentId;
AnswerEx::InsertExamAnswers($exam, $questions, $answers, $id);
//$exam->ExamId= $examid;
//$exam->Title= $title;
//$exam->Teacher->TeacherId = $teacherid;
//$exam->Saal= $saal;
//$exam->Lecture->LectureId = $lectureid;

//if ($cm == 'edit') {
//    ExamEx::Update($exam);
//} else {
//    ExamEx::Insert($exam);
//}

header("Location: ClassRooms.php");



