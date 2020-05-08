
<?php

require_once '../Classes/StudentEx.inc';
require_once '../Classes/TermEx.inc';

if (isset($_POST['student'])) {
    $classes = $_POST['classrooms'];
    $id = $_POST['student'];
    $student = new Student();
    $student->StudentId = $id;
    StudentEx::AssignClassRooms($student, $classes);
    header("Location: Students.php");
}
if (isset($_POST['classroom'])) {
    $students = $_POST['students'];
    $id = $_POST['classroom'];
    $classroom = new ClassRoom();
    $classroom->ClassRoomId = $id;
    ClassRoomEx::AssignStudents($classroom, $students);
    header("Location: ClassRooms.php");
}



//echo implode(', ',$classes);



