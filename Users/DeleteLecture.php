<?php


$id = $_GET['id'];
require_once '../Classes/LectureEx.inc';
$lecture = new Lecture();
$lecture->LectureId = $id;
LectureEx::Delete($lecture);


header("Location: Lectures.php");



