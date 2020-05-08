<?php
require_once '../Classes/ExamEx.inc';
require_once '../Classes/TermEx.inc';
require_once '../Classes/TeacherEx.inc';
require_once '../Classes/LectureEx.inc';
?>
<?php
include_once 'Template/header.php';
include_once 'Template/menu.php';
?>
<!--<a href="Exam.php"  class="SubmitButton">ثبت آزمون جدید </a>-->
<?php
if (isset($_GET['classroom'])) {

    $cm = "edit";
    $id = $_GET['classroom'];
    $exams = new Exam();
    $exams = ExamEx::GetExamsForClassRoom($id);
//    $title = $exams->Title;
//    $teacherid = $exams->Teacher->TeacherId;
//    $saal = $exams->Saal;
//    //echo $saal;
//    $lectureid = $exams->Lecture->LectureId;
    //$termid = OptionEx::GetValue("ActiveTerm");
    //$passwd = $student->Passwd;
}



if ($_SESSION['UserType'] == "Admin") {

    $exams = ExamEx::Fill();
} elseif ($_SESSION['UserType'] == "Teacher") {
    $v = $_SESSION['User'];
    $teacher = new Teacher();
    $teacher = TeacherEx::GetOnTeacherBasedOnUsername($v);
    $exams = ExamEx::Fill($teacher->TeacherId);
}

$student = new Student();
$v = $_SESSION['User'];
$student = StudentEx::GetOnStudentBasedOnCoeMelli($v);
$studentid = $student->StudentId;



echo " <table border='1' cellpadding='5' cellspacing='5' class='ViewTable'>";
echo "<tr>";
echo "<th> شناسه</th>";
echo "<th> عنوان </th>";
echo "<th>نام درس </th>";
echo "<th>مدرس </th>";
//echo "<th>ترم  </th>";
echo "<th>سال مقطع تحصیلی</th>";
echo "<th> اجرای آزمون</th>";
//echo "<th>ویرایش</th>";
//echo "<th>حذف </th>";
//echo "<th>ثبت سوالات </th>";
//echo "<th>ثبت کلاسها </th>";
echo "</tr>";
foreach ($exams as $exam) {
    echo "<tr>";
    echo "<td>" . $exam->ExamId . "</td>";
    echo "<td>" . $exam->Title . "</td>";
    echo "<td>" . $exam->Lecture->Name . "</td>";
    echo "<td>" . $exam->Teacher->Name . " " . $exam->Teacher->Family . "</td>";
    //echo "<td>" . $exam->Term->SalPayan . " - " . $exam->Term->SalShoroo . "</td>";
    echo "<td>" . $exam->Saal . "</td>";
    //echo "<td>" . $exam->GradeType->Name . "</td>";
//    echo "<td><a href='Exam.php?cm=edit&id=" . $exam->ExamId . "' class='Edit' > ویرایش </a></td>";
    if (ExamEx::IsExamAnswered($exam, $studentid)) {
        echo "<td>جواب داده شده</td>";
    } else {
        echo "<td><a href='RunExam.php?id=" . $exam->ExamId . "' >اجرای آزمون</a></td>";
    }

//    echo "<td><a href='AssignQuestionsToExam.php?exam=" . $exam->ExamId . "'>ثبت سوالات </a></td>";
//    echo "<td><a href='AssignClassRoomsToExam.php?exam=" . $exam->ExamId . "'>ثبت کلاسها </a></td>";

    echo "</tr>";
}
echo "</table>";
//include_once '../Pages/DisplayClassRooms.php';
?>
<?php
include_once 'Template/footer.php';
?>

