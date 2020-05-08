
<?php

session_start();
require_once '../Classes/ExamEx.inc';
require_once '../Classes/ClassRoomEx.inc';
require_once '../Classes/OptionEx.inc';
require_once '../Classes/TeacherEx.inc';

if ($_SESSION['UserType'] == "Admin") {
    if (isset($_POST['exam'])) {
        $termid = OptionEx::GetValue("ActiveTerm");
        $questions = array();
        if (isset($_POST['questions'])) {
            $questions = $_POST['questions'];
        }
        $id = $_POST['exam'];
        $exam = new Exam();
        $exam->ExamId = $id;
        $exam = ExamEx::GetOneExam($id);
        ExamEx::AssignQuestions($exam, $questions);
        header("Location: Exams.php");
    }
}
if ($_SESSION['UserType'] == "Teacher") {
    if (isset($_POST['exam'])) {
        $termid = OptionEx::GetValue("ActiveTerm");
        $questions = array();
        if (isset($_POST['questions'])) {
            $questions = $_POST['questions'];
        }
        $id = $_POST['exam'];
        $exam = new Exam();
        $exam = ExamEx::GetOneExam($id);
        $exam->ExamId = $id;
        $v = $_SESSION['User'];
        $teacher = new Teacher();
        $teacher = TeacherEx::GetOnTeacherBasedOnUsername($v);
        ExamEx::AssignQuestions($exam, $questions,$teacher->TeacherId);
        header("Location: Exams.php");
    }
}

//if (isset($_POST['classroom'])) {
//    $students = array();
//    if (isset($_POST['students'])) {
//        $students = $_POST['students'];
//    }
//    $id = $_POST['classroom'];
//    $classroom = new ClassRoom();
//    $classroom->ClassRoomId = $id;
//    ClassRoomEx::AssignStudents($classroom, $students);
//    header("Location: ClassRooms.php");
//}




//echo implode(', ',$classes);



