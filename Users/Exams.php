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
<a href="Exam.php"  class="SubmitButton">ثبت آزمون جدید </a>
<?php
if ($_SESSION['UserType'] == "Admin") {

$exams = ExamEx::Fill();
}elseif ($_SESSION['UserType'] == "Teacher") {
    $v = $_SESSION['User'];
    $teacher = new Teacher();
    $teacher = TeacherEx::GetOnTeacherBasedOnUsername($v);
    $exams = ExamEx::Fill($teacher->TeacherId);
}
echo " <table border='1' cellpadding='5' cellspacing='5' class='ViewTable'>";
echo "<tr>";
echo "<th> شناسه</th>";
echo "<th> عنوان </th>";
echo "<th>نام درس </th>";
echo "<th>مدرس </th>";
//echo "<th>ترم  </th>";
echo "<th>سال مقطع تحصیلی</th>";
//echo "<th> نوع نمرات</th>";
echo "<th>ویرایش</th>";
echo "<th>حذف </th>";
echo "<th>ثبت سوالات </th>";
echo "<th>ثبت کلاسها </th>";
echo "<th>مشاهده ی نتایج</th>";
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
    echo "<td><a href='Exam.php?cm=edit&id=" . $exam->ExamId . "' class='Edit' > ویرایش </a></td>";
    echo "<td><a href='DeleteExam.php?id=" . $exam->ExamId . "' class='Delete' >حذف</a></td>";
    echo "<td><a href='AssignQuestionsToExam.php?exam=" . $exam->ExamId . "'>ثبت سوالات </a></td>";
    echo "<td><a href='AssignClassRoomsToExam.php?exam=" . $exam->ExamId . "'>ثبت کلاسها </a></td>";
echo "<td><a href='ViewExamResults.php?examid=" . $exam->ExamId . "'>مشاهده ی نتایج</a></td>";
    echo "</tr>";
}
echo "</table>";
//include_once '../Pages/DisplayClassRooms.php';
?>
<?php
include_once 'Template/footer.php';
?>

