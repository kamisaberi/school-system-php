<?php


$id = $_GET['id'];
require_once '../Classes/GradeValueEx.inc';
$gradeValue = new GradeValue();
$gradeValue->GradeValueId = $id;
GradeValueEx::Delete($gradeValue);


header("Location: GradeValues.php");



