<?php
require_once '../Classes/ExamEx.inc';
require_once '../Classes/QuestionEx.inc';
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
    //echo $saal;
    $lectureid = $exam->Lecture->LectureId;

    $termid = OptionEx::GetValue("ActiveTerm");
    //$passwd = $student->Passwd;
}
//echo $teacher->Name;
?>

<form method="post" id="form1" name="form1" action="UpdateAssignedQuestionsToExam.php" >
    <input type="hidden" name="exam" id="exam" value="<?php echo $id ?>"/>
    <?php
    if ($_SESSION['UserType'] == "Admin") {
        //echo "asdaasdsads" . $saal;
        $questions = QuestionEx::GetQuestionsForLectureAndSaal($lectureid, $saal);
    } else if ($_SESSION['UserType'] == "Teacher") {
        //echo " asasasas" .$saal;
        $v = $_SESSION['User'];
        $teacher = new Teacher();
        $teacher = TeacherEx::GetOnTeacherBasedOnUsername($v);
        $questions = QuestionEx::GetQuestionsForLectureAndSaalAndTeacher($lectureid, $saal, $teacher->TeacherId);
    }

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
        foreach ($questions as $question) {
            echo '<tr>';
            echo '<td>';
            echo "<input type='checkbox' name='questions[]' id='questions[]' value=" . $question->QuestionId . " " . (QuestionEx::CheckQuestionIsRegisterForExam($question->QuestionId, $id) == TRUE ? 'checked ' : '') . "/>";
            echo '</td>';
            echo '<td>';
            echo $question->QuestionId;
            echo '</td>';
            echo '<td>';
            echo $question->Content;
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

