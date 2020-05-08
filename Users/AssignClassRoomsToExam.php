<?php
require_once '../Classes/ExamEx.inc';
require_once '../Classes/ClassRoomEx.inc';
require_once '../Classes/OptionEx.inc';
?>
<?php
include_once 'Template/header.php';
include_once 'Template/menu.php';
?>

<?php
$cm = "add";
if (isset($_GET['exam'])) {

    $cm = "edit";
    $id = $_GET['exam'];
    $exam = new Exam();
    $exam = ExamEx::GetOneExam($id);
    $title = $exam->Title;
    $teacherid = $exam->Teacher->TeacherId;
    $saal = $exam->Saal;
    $lectureid= $exam->Lecture->LectureId;

    $termid = OptionEx::GetValue("ActiveTerm");
    //$passwd = $student->Passwd;
}
//echo $teacher->Name;
?>

<form method="post" id="form1" name="form1" action="UpdateAssignedClassRoomsToExam.php" >
    <input type="hidden" name="exam" id="exam" value="<?php echo $id ?>"/>
    <?php
    $classrooms= ClassRoomEx::GetClassRoomsForTermBasedOnLectureAndSaal($termid,$lectureid,$saal);
    //echo count($classrooms);
    $i = 1;
    ?>
    <table  border="1" cellpadding="5" cellspacing="5"  class="ViewTable">
        <tr>
            <td>
                <?php echo $title ?>
            </td>
            <td>
                <?php echo $exam->Teacher->Name . " " . $exam->Teacher->Family; ?>
            </td>
        </tr>
    </table>
    <table  border="1" cellpadding="5" cellspacing="5"  class="ViewTable">
        <?php
        foreach ($classrooms as $classroom) {
            echo '<tr>';
            echo '<td>';
            echo "<input type='checkbox' name='classrooms[]' id='classrooms[]' value=" . $classroom->ClassRoomId. " " . (ClassRoomEx::CheckClassRoomIsRegisterForExam($classroom->ClassRoomId, $id) == TRUE ? 'checked ' : '') . "/>";
            echo '</td>';
            echo '<td>';
            echo $classroom->ClassRoomId;
            echo '</td>';
            echo '<td>';
            echo $classroom->Lecture->Name;
            echo '</td>';
            echo '</tr >';
            $i++;
        }
        ?>
        <tr>
            <td colspan="3">
                <input type="submit" name="button" id="button" value="Submit" />
            </td>
        </tr>
    </table>
</form> 

<?php
include_once 'Template/footer.php';
?>

