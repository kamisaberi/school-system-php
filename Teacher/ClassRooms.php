<?php

require_once '../Classes/ClassRoomEx.inc';
require_once '../Classes/TermEx.inc';
require_once '../Classes/TeacherEx.inc';
require_once '../Classes/LectureEx.inc';
require_once '../Classes/OptionEx.inc';
?>
<?php

include_once 'Template/header.php';
include_once 'Template/menu.php';
?>
<!--<a href="ClassRoom.php"  style="color: #000000">ثبت   کلاس جدید </a>-->
<?php
$v=$_SESSION['User'];

$teacher = new Teacher();
$teacher=  TeacherEx::GetOnTeacherBasedOnUsername($v);

$termid =OptionEx::GetValue("ActiveTerm");
$exams = ClassRoomEx::GetClassRoomsForTeacherForActiveTerm($teacher->TeacherId , $termid);
echo " <table border='1' cellpadding='5' cellspacing='5' class='ViewTable'>";
echo "<tr>";
echo "<th> شناسه</th>";
echo "<th> نام </th>";
echo "<th>نام درس </th>";
//echo "<th>مدرس </th>";
echo "<th>ترم  </th>";
echo "<th>سال مقطع تحصیلی</th>";
echo "<th> نوع نمرات</th>";
//echo "<th>ویرایش</th>";
//echo "<th>حذف </th>";
//echo "<th>ثبت دانش آموزان</th>";
echo "<th>ثبت نمرات </th>";
echo "</tr>";
foreach ($exams as $exam) {
    echo "<tr>"; 
    echo "<td>" . $exam->ClassRoomId . "</td>";
    echo "<td>" . $exam->Name . "</td>";
    echo "<td>" . $exam->Lecture->Name . "</td>";
    //echo "<td>" . $classRoom->Teacher->Name . " " . $classRoom->Teacher->Family . "</td>";
    echo "<td>" . $exam->Term->SalPayan . " - " . $exam->Term->SalShoroo . "</td>";
    echo "<td>" . $exam->Saal . "</td>";
    echo "<td>" . $exam->GradeType->Name . "</td>";
    //echo "<td><a href='ClassRoom.php?cm=edit&id=" . $classRoom->ClassRoomId . "'> ویرایش </a></td>";
    //echo "<td><a href='DeleteClassRoom.php?id=" . $classRoom->ClassRoomId . "'>حذف</a></td>";
    //echo "<td><a href='AssignStudentsToClassRoom.php?classroom=" . $classRoom->ClassRoomId . "'>ثبت دانش آموزان</a></td>";
    echo "<td><a href='AssignGrades.php?classroom=" . $exam->ClassRoomId . "'>ثبت نمرات</a></td>";
    echo "</tr>";
}
echo "</table>";
//include_once '../Pages/DisplayClassRooms.php';
?>
<?php

include_once 'Template/footer.php';
?>

