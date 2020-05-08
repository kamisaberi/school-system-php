<?php
require_once '../Classes/ExamEx.inc';
require_once '../Classes/LectureEx.inc';
require_once '../Classes/TeacherEx.inc';
require_once '../Classes/TermEx.inc';
require_once '../Classes/GradeTypeEx.inc';
?>
<?php
include_once 'Template/header.php';
include_once 'Template/menu.php';
?>


<?php
$id = "";
$cm = "add";
$title = "";
$teacherid = "";
$saal = "";
$lectureid = "";
if (isset($_GET['id'])) {

    $cm = "edit";
    $id = $_GET['id'];
    $exam = new Exam();
    $exam = ExamEx::GetOneExam($id);
    $title = $exam->Title;
    $teacherid = $exam->Teacher->TeacherId;
    $saal = $exam->Saal;
    $lectureid = $exam->Lecture->LectureId;
    $questions = QuestionEx::GetQuestionsForExam($id);
}
//echo $classRoom->Name;
?>
<form method="post" id="form1" name="form1" action="InsertExamAnswers.php" >
    <input type="hidden" name="examid" id="examid" value='<?php echo $id; ?>' />
<!--    <input type="hidden" name="command" id="command" value='<?php echo $cm; ?>' />-->
    <table  border="1" cellpadding="5" cellspacing="5"  class="ViewTable">
        <tr>
            <td colspan="2">ClassRoom Form</td>
        </tr>
        <?php
        foreach ($questions as $question) {
            echo '<tr><td>';
            echo $question->Content;
            echo '</td></tr>';
            echo '<tr><td>';
            echo "<input type='hidden' id='question[]' name='question[]' value='$question->QuestionId' />";
            echo "<input type='text' id='answer[]' name='answer[]' value='' />";
            echo '</td></tr>';

        }
        ?>
        <tr>
            <td colspan="2"><input type="submit" name="button" id="button" value="Submit" /></td>
        </tr>
    </table>
</form> 


<?php
include_once 'Template/footer.php';
?>

