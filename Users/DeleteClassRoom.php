<?php

$id = $_GET['id'];
require_once '../Classes/ClassRoomEx.inc';
$classroom = new ClassRoom();
$classroom->ClassRoomId = $id;
ClassRoomEx::Delete($classroom);

header("Location: ClassRooms.php");



