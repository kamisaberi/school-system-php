<?php
require_once '../Classes/GradeTypeEx.inc';
?>
<?php
include_once 'Template/header.php';
include_once 'Template/menu.php';
?>
<a href="GradeType.php"   class="SubmitButton">ثبت نوع نمرات </a>
<?php
$gradeTypes = GradeTypeEx::Fill();
echo " <table border='1' cellpadding='5' cellspacing='5' class='ViewTable'>";
echo "<tr>";
echo "<th> شناسه</th>";
echo "<th> نام </th>";
echo "<th>حداقل نمره </th>";
echo "<th>حداکثر نمره </th>";
echo "<th>نمره قبولی  </th>";
echo "<th>ویرایش</th>";
echo "<th>حذف </th>";
echo "<th>گزینه های ثبت شده</th>";
echo "</tr>";
foreach ($gradeTypes as $gradeType) {
    echo "<tr>";
    echo "<td>" . $gradeType->GradeTypeId . "</td>";
    echo "<td>" . $gradeType->Name . "</td>";
    echo "<td>" . $gradeType->Min . "</td>";
    echo "<td>" . $gradeType->Max . "</td>";
    echo "<td>" . $gradeType->Pass . "</td>";
    echo "<td><a href='GradeType.php?cm=edit&id=" . $gradeType->GradeTypeId . "'  class='Edit' > ویرایش </a></td>";
    echo "<td><a href='DeleteGradeType.php?id=" . $gradeType->GradeTypeId . "'  class='Delete' >حذف</a></td>";
    echo '<td>';
    if($gradeType->DefinedValues==TRUE) {
        echo "<a href='GradeValues.php?type=" . $gradeType->GradeTypeId . "'   >گزینه ها  </a>";
    }
    echo '</td>';
    echo "</tr>";
}
echo "</table>";
//include_once '../Pages/DisplayGradeTypes.php';
?>
<?php
include_once 'Template/footer.php';
?>

