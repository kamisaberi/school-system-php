<?php
require_once '../Classes/GradeValueEx.inc';
?>
<?php
include_once 'Template/header.php';
include_once 'Template/menu.php';
?>
<?php
$gradetypeid = 0;
if (isset($_GET['type'])) {
    $gradetypeid = $_GET['type'];
}
?>
<a href="GradeValue.php?type=<?php echo $gradetypeid; ?>"  class="SubmitButton">ثبت مقادیر نمرات </a>
<?php
if ($gradetypeid == 0) {
    $gradeValues = GradeValueEx::Fill();
} else {
    $gradeValues = GradeValueEx::GetGradeValuesBasedOnGradeTypeId($gradetypeid);
}

echo " <table border='1' cellpadding='5' cellspacing='5' class='ViewTable'>";
echo "<tr>";
echo "<th> شناسه</th>";
echo "<th>نوع نمره </th>";
echo "<th> مقدار </th>";
echo "<th>ویرایش</th>";
echo "<th>حذف </th>";

echo "</tr>";
foreach ($gradeValues as $gradeValue) {
    echo "<tr>";
    echo "<td>" . $gradeValue->GradeValueId . "</td>";
    echo "<td>" . $gradeValue->GradeType->Name . "</td>";
    echo "<td>" . $gradeValue->Value . "</td>";
    echo "<td><a href='GradeValue.php?cm=edit&id=" . $gradeValue->GradeValueId . "'  class='Edit' > ویرایش </a></td>";
    echo "<td><a href='DeleteGradeValue.php?id=" . $gradeValue->GradeValueId . "'  class='Delete' >حذف</a></td>";
    echo "</tr>";
}
echo "</table>";
//include_once '../Pages/DisplayGradeValues.php';
?>
<?php
include_once 'Template/footer.php';
?>

