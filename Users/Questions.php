<?php
require_once '../Classes/QuestionEx.inc';
require_once '../Classes/QuestionTypeEx.inc';
require_once '../Classes/TeacherEx.inc';
require_once '../Classes/LectureEx.inc';
?>
<?php
include_once 'Template/header.php';
include_once 'Template/menu.php';
?>
<a href="Question.php"  class="SubmitButton">ثبت سوال جدید </a>
<?php
if ($_SESSION['UserType'] == "Admin") {
    $questions = QuestionEx::Fill();
    
} elseif ($_SESSION['UserType'] == "Teacher") {
    $v = $_SESSION['User'];
    $teacher = new Teacher();
    $teacher = TeacherEx::GetOnTeacherBasedOnUsername($v);
    $questions = QuestionEx::Fill($teacher->TeacherId);
}

echo " <table border='1' cellpadding='5' cellspacing='5' class='ViewTable'>";
echo "<tr>";
echo "<th> شناسه</th>";
echo "<th> متن سوال</th>";
echo "<th>نوع سوال</th>";
echo "<th>نام درس</th>";
echo "<th>طراح </th>";
echo "<th>سال مقطع تحصیلی</th>";
//echo "<th> نوع نمرات</th>";
echo "<th>ویرایش</th>";
echo "<th>حذف </th>";
//echo "<th>ثبت دانش آموزان</th>";
echo "</tr>";
foreach ($questions as $question) {
    echo "<tr>";
    echo "<td>" . $question->QuestionId . "</td>";
    echo "<td>" . $question->Content . "</td>";
    echo "<td>" . $question->QuestionType->Name . "</td>";
    echo "<td>" . $question->Lecture->Name . "</td>";
    echo "<td>" . $question->Teacher->Name . " " . $question->Teacher->Family . "</td>";
    echo "<td>" . $question->Saal . "</td>";
    //echo "<td>" . $question->GradeType->Name . "</td>";
    echo "<td><a href='Question.php?cm=edit&id=" . $question->QuestionId . "' class='Edit' > ویرایش </a></td>";
    echo "<td><a href='DeleteQuestion.php?id=" . $question->QuestionId . "' class='Delete' >حذف</a></td>";
    //echo "<td><a href='AssignStudentsToQuestion.php?classroom=" . $question->QuestionId . "'>ثبت دانش آموزان</a></td>";

    echo "</tr>";
}
echo "</table>";
//include_once '../Pages/DisplayQuestions.php';
?>
<?php
include_once 'Template/footer.php';
?>

