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
if (isset($_GET['student'])) {

    $cm = "edit";
    $id = $_GET['student'];
    $student = new Student();
    $student = StudentEx::GetOnStudent($id);
    $content = $student->Name;
    $family = $student->Family;
    $codemelli = $student->CodeMelli;
    $termid = OptionEx::GetValue("ActiveTerm");
    //$passwd = $student->Passwd;
}
//echo $teacher->Name;
?>

<form method="post" id="form1" name="form1" action="UpdateAssignedClassRoomsStudents.php" >
    <input type="hidden" name="student" id="student" value="<?php echo $id ?>"/>
    <?php
    $classroms = ClassRoomEx::GetClassRoomsForTerm($termid);
    $i = 1;
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
    <table  border="1" cellpadding="5" cellspacing="5"  class="ViewTable">
        <?php
        foreach ($classroms as $classrom) {
            echo '<tr>';
            echo '<td>';
            echo "<input type='checkbox' name='classrooms[]' id='classroom[]' value=" . $classrom->ClassRoomId . " " . (ClassRoomEx::CheckClassRoomIsRegisterForStudentForActiveTerm($classrom->ClassRoomId, $id) == TRUE ? 'checked ' : '') . "/>";
            echo '</td>';
            echo '<td>';
            echo $classrom->ClassRoomId;
            echo '</td>';
            echo '<td>';
            echo $classrom->Name;
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

