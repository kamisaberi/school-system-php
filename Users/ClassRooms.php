<?php
require_once '../Classes/ClassRoomEx.inc';
require_once '../Classes/TermEx.inc';
require_once '../Classes/TeacherEx.inc';
require_once '../Classes/LectureEx.inc';
?>
<?php
include_once 'Template/header.php';
include_once 'Template/menu.php';


$termid = OptionEx::GetValue("ActiveTerm");
if ($_SESSION['UserType'] == "Admin") {
    echo "<a href='ClassRoom.php'  class='SubmitButton'>ثبت   کلاس جدید </a>";
    $classrooms = ClassRoomEx::GetClassRoomsForActiveTerm($termid);
} elseif ($_SESSION['UserType'] == "Teacher") {
    $v = $_SESSION['User'];
    $teacher = new Teacher();
    $teacher = TeacherEx::GetOnTeacherBasedOnUsername($v);
    $classrooms = ClassRoomEx::GetClassRoomsForTeacherForActiveTerm($teacher->TeacherId, $termid);
    $name = $teacher->Name;
    $family = $teacher->Family;
    ?>
    <table  border="1" cellpadding="5" cellspacing="5"  class="ViewTable">
        <tr>
            <td>
                <?php echo $name . " " . $family; ?>
            </td>
        </tr>
    </table>

    <?php
} elseif ($_SESSION['UserType'] == "Student") {
    $student = new Student();
    $v = $_SESSION['User'];
    $student = StudentEx::GetOnStudentBasedOnCoeMelli($v);
    $id = $student->StudentId;
    $name = $student->Name;
    $family = $student->Family;
    $codemelli = $student->CodeMelli;
    $classrooms = ClassRoomEx::GetClassRoomsOfActiveTermForStudent($id, $termid);
    ?>
    <table  border="1" cellpadding="5" cellspacing="5"  class="ViewTable">
        <tr>
            <td>
                <?php echo $name . " " . $family; ?>
            </td>
            <td>
                <?php echo $codemelli; ?>
            </td>
        </tr>
    </table>
    <?php
}
echo " <table border='1' cellpadding='5' cellspacing='5' class='ViewTable'>";
echo "<tr>";
echo "<th> شناسه</th>";
echo "<th> نام </th>";
echo "<th>نام درس </th>";
if ($_SESSION['UserType'] == "Admin" || $_SESSION['UserType'] == "Student") {
    echo "<th>مدرس </th>";
}
echo "<th>ترم  </th>";
echo "<th>سال مقطع تحصیلی</th>";
echo "<th> نوع نمرات</th>";
if ($_SESSION['UserType'] == "Admin") {
    echo "<th>ویرایش</th>";
    echo "<th>حذف </th>";
    echo "<th>ثبت دانش آموزان</th>";
}
if ($_SESSION['UserType'] == "Teacher") {
    echo "<th>ثبت نمرات </th>";
}
if ($_SESSION['UserType'] == "Student") {
    echo "<th>مشاهده آزمون ها</th>";
}

echo "</tr>";
foreach ($classrooms as $classroom) {
    echo "<tr>";
    echo "<td>" . $classroom->ClassRoomId . "</td>";
    echo "<td>" . $classroom->Name . "</td>";
    echo "<td>" . $classroom->Lecture->Name . "</td>";
    if ($_SESSION['UserType'] == "Admin" || $_SESSION['UserType'] == "Student") {
        echo "<td>" . $classroom->Teacher->Name . " " . $classroom->Teacher->Family . "</td>";
    }
    echo "<td>" . $classroom->Term->SalPayan . " - " . $classroom->Term->SalShoroo . "</td>";
    echo "<td>" . $classroom->Saal . "</td>";
    echo "<td>" . $classroom->GradeType->Name . "</td>";
    if ($_SESSION['UserType'] == "Admin") {
        echo "<td><a href='ClassRoom.php?cm=edit&id=" . $classroom->ClassRoomId . "' class='Edit' > ویرایش </a></td>";
        echo "<td><a href='DeleteClassRoom.php?id=" . $classroom->ClassRoomId . "' class='Delete' >حذف</a></td>";
        echo "<td><a href='AssignStudentsToClassRoom.php?classroom=" . $classroom->ClassRoomId . "'>ثبت دانش آموزان</a></td>";
    }
    if ($_SESSION['UserType'] == "Teacher") {
        echo "<td><a href='AssignGrades.php?classroom=" . $classroom->ClassRoomId . "'>ثبت نمرات</a></td>";
    }
    if ($_SESSION['UserType'] == "Student") {
        echo "<td><a href='ViewExams.php?classroom=" . $classroom->ClassRoomId . "'>مشاهده آزمون ها</a></td>";
    }

    echo "</tr>";
}
echo "</table>";
//include_once '../Pages/DisplayClassRooms.php';
?>
<?php
include_once 'Template/footer.php';
?>

