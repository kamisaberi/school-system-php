<?php
require_once '../Classes/TeacherEx.inc';
?>
<?php
include_once 'Template/header.php';
include_once 'Template/menu.php';
?>


<?php

if ($_SESSION['UserType'] == "Admin") {
    ?>
    <table class="Center">
        <tr>
            <td>
                <a href="Options.php"  class="SubmitButton"> تنظیمات</a>
            </td>
        </tr>
    </table>
    <table border="1" cellpadding="0" cellspacing="0" class="Center">
        <tr>
            <td>
                <div class="Item">
                    <a href="Students.php">
                        <img src="../Images/Student.png" class="ItemPictureBox" alt="دانش آموز" /></a>
                    <span>دانش آموز</span>
                </div>
            </td>
            <td>
                <div class="Item">
                    <a href="Teachers.php">
                        <img src="../Images/Teacher.png" class="ItemPictureBox" alt="معلم" /></a> <span>معلم</span>
                </div>
            </td>
            <td>
                <div class="Item">
                    <a href="Lectures.php">
                        <img src="../Images/Lecture.png" class="ItemPictureBox" alt="درس" /></a> <span>درس</span>
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
                    <a href="Terms.php">
                        <img src="../Images/Term.png" class="ItemPictureBox" alt="ترم" /></a> <span>ترم</span>
                </div>
            </td>
        </tr>
    </table>
    <?php
} elseif ($_SESSION['UserType'] == "Teacher") {
    ?>
    <table border="1" cellpadding="0" cellspacing="0" class="Center">
        <tr>
            <td>
                <div class="Item">
                    <a href="Students.php">
                        <img src="../Images/Student.png" class="ItemPictureBox" alt="معلم" /></a> <span>دانش آموزان</span>
                </div>
            </td>
            <td>
                <div class="Item">
                    <a href="ClassRooms.php">
                        <img src="../Images/ClassRoom.png" class="ItemPictureBox" alt="کلاس" /></a> <span>کلاس</span>
                </div>
            </td>
        </tr>
    </table>
    <?php
} elseif ($_SESSION['UserType'] == "Student") {
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
    <?php
}
?>




<?php
//$classroms = ClassRoomEx::GetClassRoomsForTerm(1);
//echo count($classroms) ."<br />" ;
//foreach ($classroms as $classroom) {
//    if ($classroom->ClassRoomId == 5) {
//        unset($classroom);
//    }
//}
//echo count($classroms)."<br />" ;
//        unset($classroms[0]);
//echo count($classroms)."<br />" ;
//
//        unset($classroms[1]);
//echo count($classroms)."<br />" ;
?>





<!--<a style="color: black" href="Teachers.php"> Teachers  </a><br />
<a style="color: black"  href="Students.php"> Students </a><br />
<a style="color: black"  href="Terms.php"> Terms  </a><br />
<a style="color: black"  href="Lectures.php"> Lectures </a><br />-->
<?php
include_once 'Template/footer.php';
?>

