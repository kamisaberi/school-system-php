<?php
require_once  'Classes/TeacherEx.inc';



$teachers = TeacherEx::Fill();
//echo ' sadasdasdsadasdsadasdasdasd';
echo "<table>";

foreach ($teachers as $student) {
    echo "<tr>";
    echo "<td>" . $student->Name . "</td>";
    echo "<td>" . $student->Family . "</td>";
    echo "</tr>";
}
echo "</table>";
