<?php


$id = $_GET['id'];
require_once '../Classes/GradeTypeEx.inc';
$gradeType = new GradeType();
$gradeType->GradeTypeId = $id;
GradeTypeEx::Delete($gradeType);


header("Location: GradeTypes.php");



