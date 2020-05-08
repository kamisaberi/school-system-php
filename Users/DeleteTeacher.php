<?php


$id = $_GET['id'];
require_once '../Classes/TeacherEx.inc';
$teacher = new Teacher();
$teacher->TeacherId = $id;
TeacherEx::Delete($teacher);


header("Location: Teachers.php");



