
<?php

require_once '../Classes/StudentEx.inc';
require_once '../Classes/ClassRoomEx.inc';
require_once '../Classes/OptionEx.inc';

if (isset($_POST['student'])) {
    $termid = OptionEx::GetValue("ActiveTerm");
    $classes = array();
    if (isset($_POST['classrooms'])) {
        $classes = $_POST['classrooms'];
    }
    $id = $_POST['student'];
    $student = new Student();
    $student->StudentId = $id;
    StudentEx::AssignClassRooms($student, $classes, $termid);
    header("Location: Students.php");
}
if (isset($_POST['classroom'])) {
    $students = array();
    if (isset($_POST['students'])) {
        $students = $_POST['students'];
    }
    $id = $_POST['classroom'];
    $classroom = new ClassRoom();
    $classroom->ClassRoomId = $id;
    ClassRoomEx::AssignStudents($classroom, $students);
    header("Location: ClassRooms.php");
}


//echo implode(', ',$classes);



