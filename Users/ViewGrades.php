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
//$id = "";
//$cm = "add";
//$name = "";
//$family = "";
//$username = "";
//$passwd = "";
//
$student = new Student();
$v = $_SESSION['User'];

$student = StudentEx::GetOnStudentBasedOnCoeMelli($v);

$id = $student->StudentId;
$content = $student->Name;
$family = $student->Family;
$codemelli = $student->CodeMelli;

$termid = OptionEx::GetValue("ActiveTerm");
?>
<!--<p> <?php echo $content; ?>  </p>
<p> <?php echo $family; ?>  </p>
<p> <?php echo $codemelli; ?>  </p>-->

<form method="post" id="form1" name="form1" action="UpdateAssignedGrades.php" >
    <input type="hidden" name="student" id="student" value="<?php echo $id ?>"/>
    <?php
    $classroms = ClassRoomEx::GetClassRoomsOfActiveTermForStudent($id, $termid);
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
            echo "<input type='hidden' name='classrooms[]' id='classrooms[]' value='" . $classrom->ClassRoomId . "' />";
            echo $classrom->Name . ":";
            echo '</td>';
            echo '<td>';
            echo GradeEx::GetGradesForStudentInClassRoom($id, $classrom->ClassRoomId);
            echo '</td>';
            $i++;
            echo '</tr>';
        }
        ?>
<!--        <tr>
            <td colspan="2">
                <input type="submit" name="button" id="button" value="Submit" />
            </td>
        </tr>-->
    </table>
</form> 

<?php
include_once 'Template/footer.php';
?>

