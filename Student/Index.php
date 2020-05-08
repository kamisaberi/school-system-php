<?php

require_once '../Classes/TeacherEx.inc';
?>
<?php

include_once 'Template/header.php';
include_once 'Template/menu.php';
?>
<table border="1" cellpadding="0" cellspacing="0" class="Center">
    <tr>
        <td>
            <div class="Item">
                <a href="Teachers.php">
                    <img src="../Images/Teacher.png" class="ItemPictureBox" alt="معلم" /></a> <span>معلم</span>
            </div>
        </td>
        <td>
            <div class="Item">
                <a href="ClassRooms.php">
                    <img src="../Images/ClassRoom.png" class="ItemPictureBox" alt="کلاس" /></a> <span>کلاس</span>
            </div>
        </td>
        <td>
            <div class="Item">
                <a href="ViewGrades.php">
                    <img src="../Images/ClassRoom.png" class="ItemPictureBox" alt="کلاس" /></a> <span>نمرات</span>
            </div>
        </td>
    </tr>
</table>







<!--<a style="color: black" href="Teachers.php"> Teachers  </a><br />
<a style="color: black"  href="Students.php"> Students </a><br />
<a style="color: black"  href="Terms.php"> Terms  </a><br />
<a style="color: black"  href="Lectures.php"> Lectures </a><br />-->
<?php

include_once 'Template/footer.php';
?>

