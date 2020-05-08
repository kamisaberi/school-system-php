<?php


$id = $_GET['id'];
require_once '../Classes/StudentEx.inc';
$student= new Student();
$student->StudentId = $id;
StudentEx::Delete($student);


header("Location: Students.php");



