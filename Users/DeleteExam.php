<?php

$id = $_GET['id'];
require_once '../Classes/ExamEx.inc';
$exam = new Exam();
$exam->ExamId= $id;
ExamEx::Delete($exam);

header("Location: Exams.php");



