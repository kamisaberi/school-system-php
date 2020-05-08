<?php

?>
<?php

include_once 'Template/header.php';
include_once 'Template/menu.php';
?>
<?php

if ($_SESSION['UserType'] == "Admin") {
    echo "<a href='Student.php'  class='SubmitButton'>ثبت دانش آموز جدید </a>";
    $students = StudentEx::Fill();
} elseif ($_SESSION['UserType'] == "Teacher") {
    $teacher = new Teacher();
    $v = $_SESSION['User'];
    $teacher = TeacherEx::GetOnTeacherBasedOnUsername($v);
    $id = $teacher->TeacherId;
    $content = $teacher->Name;
    $family = $teacher->Family;
    $codemelli = $teacher->CodeMelli;
    $username = $teacher->Username;
    $passwd = $teacher->Passwd;
    $termid = OptionEx::GetValue("ActiveTerm");
    $students = StudentEx::GetStudentsOfActiveTermForTeacher($id, $termid);
}
//$students = StudentEx::Fill();
echo " <table border='1' cellpadding='5' cellspacing='5' class='ViewTable'>";
echo "<tr>";
echo "<th> شناسه</th>";
echo "<th> نام </th>";
echo "<th>نام خانوادگی</th>";
echo "<th>کد ملی</th>";

if ($_SESSION['UserType'] == "Admin") {
    echo "<th>رمز عبور </th>";
    echo "<th>ویرایش</th>";
    echo "<th>حذف </th>";
    echo "<th>ثبت کلاسها </th>";
    echo "<th>ثبت نمرات </th>";
}
echo "</tr>";
foreach ($students as $student) {
    echo "<tr>";
    echo "<td>" . $student->StudentId . "</td>";
    echo "<td>" . $student->Name . "</td>";
    echo "<td>" . $student->Family . "</td>";
    echo "<td>" . $student->CodeMelli . "</td>";
    if ($_SESSION['UserType'] == "Admin") {

        echo "<td>" . $student->Passwd . "</td>";
        echo "<td><a href='Student.php?cm=edit&id=" . $student->StudentId . "'  class='Edit' > ویرایش </a></td>";
        echo "<td><a href='DeleteStudent.php?id=" . $student->StudentId . "'  class='Delete' >حذف</a></td>";
        echo "<td><a href='AssignClassRoomsToStudent.php?student=" . $student->StudentId . "'>ثبت کلاسها</a></td>";
        echo "<td><a href='AssignGrades.php?student=" . $student->StudentId . "'>ثبت نمرات</a></td>";
    }
    echo "</tr>";
}
echo "</table>";
//include_once '../Pages/DisplayTeachers.php';
?>
<?php

include_once 'Template/footer.php';
?>

