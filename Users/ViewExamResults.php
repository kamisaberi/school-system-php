<?php

require_once '../Classes/ClassRoomEx.inc';
?>
<?php

include_once 'Template/header.php';
include_once 'Template/menu.php';
?>
<?php

$id;
if (isset($_GET['examid'])) {
    $id = $_GET['examid'];
}
$termid = OptionEx::GetValue("ActiveTerm");
//echo $termid;

if ($_SESSION['UserType'] == "Admin") {
    $classrooms = ClassRoomEx::GetClassRoomsForExam($id);
} elseif ($_SESSION['UserType'] == "Teacher") {
    $teacher = new Teacher();
    $v = $_SESSION['User'];
    $teacher = TeacherEx::GetOnTeacherBasedOnUsername($v);
    $teacherid = $teacher->TeacherId;
    $content = $teacher->Name;
    $family = $teacher->Family;
    $codemelli = $teacher->CodeMelli;
    $username = $teacher->Username;
    $passwd = $teacher->Passwd;
    $classrooms = ClassRoomEx::GetClassRoomsForExam($id, $teacherid);
}
//$classrooms = StudentEx::Fill();
foreach ($classrooms as $classroom) {
    echo " <table border='1' cellpadding='5' cellspacing='5' class='ViewTable'>";
    echo "<tr>";
    echo "<th> شناسه</th>";
    echo "<th> نام </th>";
    echo "<th>نام درس</th>";
    echo "</tr>";

    echo "<tr>";
    echo "<td>" . $classroom->ClassRoomId . "</td>";
    echo "<td>" . $classroom->Name . "</td>";
    echo "<td>" . $classroom->Lecture->Name . "</td>";
    echo "</tr>";
    echo "<tr>";
    echo "<td colspan='3'>";
    $students = StudentEx::GetStudentsOfActiveTermForClassRoom($classroom->ClassRoomId, $termid);
    echo " <table border='1' cellpadding='5' cellspacing='5' class='ViewTable'>";
    echo "<tr>";
    echo "<th> شناسه</th>";
    echo "<th> نام دانش آموز </th>";
    echo "<th> مشاهده ی جواب</th>";
    echo "</tr>";
    foreach ($students as $student) {
        echo "<tr>";
        echo "<td>" . $student->StudentId . "</td>";
        echo "<td>" . $student->Name . "  " . $student->Family . "</td>";
        echo "<td><a href='ViewExamResultForStudent.php?studentid=" .$student->StudentId ."&examid=" . $id . "'  > مشاهده ی جواب </a></td>";
//        echo "<td><a href='DeleteStudent.php?id=" . $classroom->StudentId . "'  class='Delete' >حذف</a></td>";
//        echo "<td><a href='AssignClassRoomsToStudent.php?student=" . $classroom->StudentId . "'>ثبت کلاسها</a></td>";
//        echo "<td><a href='AssignGrades.php?student=" . $classroom->StudentId . "'>ثبت نمرات</a></td>";
        echo "</tr>";
    }
//    echo "</td>";
//    echo "</tr>";
    echo "</table>";
    echo "</table>";
}
?>
<?php

include_once 'Template/footer.php';
?>

