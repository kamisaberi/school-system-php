<?php

require_once '../Classes/TermEx.inc';
?>
<?php

include_once 'Template/header.php';
include_once 'Template/menu.php';
?>
<a href="Term.php"  class="SubmitButton">ثبت ترم  جدید </a>

<?php

$terms = TermEx::Fill();
echo " <table border='1' cellpadding='5' cellspacing='5' class='ViewTable'>";
echo "<tr>";
echo "<th> شناسه</th>";
echo "<th> سال شروع </th>";
echo "<th>سال پایان </th>";
echo "<th>نیمسال </th>";
echo "<th>توضیحات  </th>";
echo "<th>ویرایش</th>";
echo "<th>حذف </th>";

echo "</tr>";
foreach ($terms as $term) {
    echo "<tr>";
    echo "<td>" . $term->TermId . "</td>";
    echo "<td>" . $term->SalShoroo . "</td>";
    echo "<td>" . $term->SalPayan . "</td>";
    echo "<td>" . $term->NimSal . "</td>";
    echo "<td>" . $term->Tozihat . "</td>";
    echo "<td><a href='Term.php?cm=edit&id=" . $term->TermId . "'  class='Edit' > ویرایش </a></td>";
    echo "<td><a href='DeleteTerm.php?id=" . $term->TermId . "'  class='Delete' >حذف</a></td>";

    echo "</tr>";
}
echo "</table>";
//include_once '../Pages/DisplayTeachers.php';
?>
<?php

include_once 'Template/footer.php';
?>

