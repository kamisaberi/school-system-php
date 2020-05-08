
<?php

require_once '../Classes/ExamEx.inc';
require_once '../Classes/ClassRoomEx.inc';
require_once '../Classes/OptionEx.inc';

if (isset($_POST['exam'])) {
    $termid = OptionEx::GetValue("ActiveTerm");
    $classrooms = array();
    if (isset($_POST['classrooms'])) {
        $classrooms = $_POST['classrooms'];
    }
    $id = $_POST['exam'];
    $exam = new Exam();
    $exam=  ExamEx::GetOneExam($id);
    $exam->ExamId = $id;
    ExamEx::AssignClassRooms($exam, $classrooms ,$termid);
    header("Location: Exams.php");
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



