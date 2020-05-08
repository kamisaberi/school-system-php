<?php
require_once '../Classes/LectureEx.inc';
?>
<?php
include_once 'Template/header.php';
include_once 'Template/menu.php';
?>
<a href="Lecture.php"  class="SubmitButton">ثبت درس   جدید </a>
<?php
$lectures = LectureEx::Fill();
echo " <table border='1' cellpadding='5' cellspacing='5' class='ViewTable'>";
echo "<tr>";
echo "<th> شناسه</th>";
echo "<th> نام درس </th>";
echo "<th>تعداد واحد </th>";
echo "<th>توضیحات </th>";
echo "<th>ویرایش</th>";
echo "<th>حذف </th>";

echo "</tr>";
foreach ($lectures as $lecture) {
    echo "<tr>";
    echo "<td>" . $lecture->LectureId . "</td>";
    echo "<td>" . $lecture->Name . "</td>";
    echo "<td>" . $lecture->TedadVahed . "</td>";
    echo "<td>" . $lecture->Tozihat . "</td>";
    echo "<td><a href='Lecture.php?cm=edit&id=" . $lecture->LectureId . "'  class='Edit' > ویرایش </a></td>";
    echo "<td><a href='DeleteLecture.php?id=" . $lecture->LectureId . "'  class='Delete' >حذف</a></td>";

    echo "</tr>";
}
echo "</table>";
//include_once '../Pages/DisplayLectures.php';
?>
<?php
include_once 'Template/footer.php';
?>

