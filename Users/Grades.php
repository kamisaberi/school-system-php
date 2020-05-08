<?php

require_once '../Classes/GradeEx.inc';
?>
<?php

include_once 'Template/header.php';
include_once 'Template/menu.php';
?>

<?php

$grades = GradeEx::Fill();
echo "<table>";
echo "<tr>";
echo "<th> شناسه</th>";
echo "<th> نام </th>";
echo "<th>نام خانوادگی</th>";
echo "<th>نام کاربری</th>";
echo "<th>رمز عبور </th>";
echo "<th>ویرایش</th>";
echo "<th>حذف </th>";

echo "</tr>";
foreach ($grades as $grade) {
    echo "<tr>";
    echo "<td>" . $grade->GradeId . "</td>";
    echo "<td>" . $grade->Name . "</td>";
    echo "<td>" . $grade->Family . "</td>";
    echo "<td>" . $grade->Username . "</td>";
    echo "<td>" . $grade->Passwd . "</td>";
    echo "<td><a href='Grade.php?cm=edit&id=" . $grade->GradeId . "'> ویرایش </a></td>";
    echo "<td><a href='Grade.php?cm=delete&id=" . $grade->GradeId . "'>حذف</a></td>";

    echo "</tr>";
}
echo "</table>";
//include_once '../Pages/DisplayGrades.php';
?>
<?php

include_once 'Template/footer.php';
?>

