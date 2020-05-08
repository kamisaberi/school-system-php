<?php

$id = $_GET['id'];
require_once '../Classes/QuestionEx.inc';
$question = new Question();
$question ->QuestionId= $id;
QuestionEx::Delete($question);

header("Location: Questions.php");



