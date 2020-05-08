<?php


$id = $_GET['id'];
require_once '../Classes/GradeEx.inc';
$grade = new Grade();
$grade->GradeId = $id;
GradeEx::Delete($grade);


header("Location: Grades.php");



