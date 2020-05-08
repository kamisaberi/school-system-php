<?php
require_once '../Classes/ClassRoomEx.inc';
require_once '../Classes/StudentEx.inc';
require_once '../Classes/OptionEx.inc';
?>
<?php
include_once 'Template/header.php';
include_once 'Template/menu.php';
?>

<?php
$id = "";
$cm = "add";
$content = "";
$family = "";
$username = "";
$passwd = "";
if (isset($_GET['classroom'])) {

    $cm = "edit";
    $id = $_GET['classroom'];
    $classroom = new Student();
    $classroom = ClassRoomEx::GetOnClassRoom($id);
    $content = $classroom->Name;
    $termid = OptionEx::GetValue("ActiveTerm");
    //$passwd = $classroom->Passwd;
}
//echo $teacher->Name;
?>


<form method="post" id="form1" name="form1" action="UpdateAssignedClassRoomsStudents.php" >
    <input type="hidden" name="classroom" id="classroom" value="<?php echo $id ?>"/>
    <?php
    $students = StudentEx::Fill();
    $i = 1;
    ?>
    <table border="1" cellpadding="5" cellspacing="5"  class="ViewTable">
        <tr>
            <td>
                <?php echo $content; ?>                  
            </td>
            <td>
                <?php echo $classroom->Teacher->Name . " " . $classroom->Teacher->Family ?>                  
            </td>
        </tr>
    </table>

    <table border="1" cellpadding="5" cellspacing="5"  class="ViewTable">
        <?php
        foreach ($students as $student) {
            echo '<tr>';
            echo '<td>';
            echo "<input type='checkbox' name='students[]' id='student[]' value=" . $student->StudentId . " " . (StudentEx::CheckStudentIsRegisterInClassRoomForActiveTerm($id, $student->StudentId) == TRUE ? 'checked ' : '') . "/>";
            echo '</td>';
            echo '<td>';
            echo $student->StudentId;
            echo '</td>';
            echo '<td>';
            echo $student->Name . " " . $student->Family;
            echo '</td>';

            echo '</tr >';

            $i++;
        }
        ?>

        <tr>
            <td colspan="2">
                <input type="submit" name="button" id="button" value="Submit" />
            </td>
        </tr>


    </table>
</form> 

<?php
include_once 'Template/footer.php';
?>

