<?php
require_once '../Classes/TeacherEx.inc';
?>
<?php
include_once 'Template/header.php';
include_once 'Template/menu.php';
?>

<?php
if ($_SESSION['UserType'] == "Admin") {
    echo "<a href='Teacher.php'  class='SubmitButton'> ثبت مدرس جدید </a>";
    $teachers = TeacherEx::Fill();
} elseif ($_SESSION['UserType'] == "Student") {

    $student = new Student();
    $v = $_SESSION['User'];
    $student = StudentEx::GetOnStudentBasedOnCoeMelli($v);
    $id = $student->StudentId;
    $content = $student->Name;
    $family = $student->Family;
    $codemelli = $student->CodeMelli;
    $termid = OptionEx::GetValue("ActiveTerm");
    $classrooms = ClassRoomEx::GetClassRoomsOfActiveTermForStudent($id, $termid);
    ?>

    <table  border="1" cellpadding="5" cellspacing="5"  class="ViewTable">
        <tr>
            <td>
                <?php echo $content . " " . $family; ?>
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
echo "<th>نام خانوادگی</th>";
echo "<th>کد ملی</th>";
if ($_SESSION['UserType'] == "Admin") {

    echo "<th>نام کاربری</th>";
    echo "<th>رمز عبور </th>";
    echo "<th>ویرایش</th>";
    echo "<th>حذف </th>";
}
echo "</tr>";
if ($_SESSION['UserType'] == "Admin") {
    foreach ($teachers as $teacher) {
        echo "<tr>";
        echo "<td>" . $teacher->TeacherId . "</td>";
        echo "<td>" . $teacher->Name . "</td>";
        echo "<td>" . $teacher->Family . "</td>";
        echo "<td>" . $teacher->CodeMelli . "</td>";

        echo "<td>" . $teacher->Username . "</td>";
        echo "<td>" . $teacher->Passwd . "</td>";
        echo "<td><a href='Teacher.php?cm=edit&id=" . $teacher->TeacherId . "' class='Edit' > ویرایش </a></td>";
        echo "<td><a href='DeleteTeacher.php?id=" . $teacher->TeacherId . "' class='Delete' >حذف</a></td>";

        echo "</tr>";
    }
} elseif ($_SESSION['UserType'] == "Student") {
    foreach ($classrooms as $classroom) {
        echo "<tr>";
        echo "<td>" . $classroom->Teacher->TeacherId . "</td>";
        echo "<td>" . $classroom->Teacher->Name . "</td>";
        echo "<td>" . $classroom->Teacher->Family . "</td>";
        echo "<td>" . $classroom->Teacher->CodeMelli . "</td>";
        //    echo "<td>" . $teacher->Username . "</td>";
        //    echo "<td>" . $teacher->Passwd . "</td>";
        //    echo "<td><a href='Teacher.php?cm=edit&id=" . $teacher->TeacherId . "' class='Edit' > ویرایش </a></td>";
        //    echo "<td><a href='DeleteTeacher.php?id=" . $teacher->TeacherId . "' class='Delete' >حذف</a></td>";

        echo "</tr>";
    }
}
echo "</table>";
//include_once '../Pages/DisplayTeachers.php';
?>
<?php
include_once 'Template/footer.php';
?>

