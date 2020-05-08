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
$saal= "";
$lectureid = "";
if (isset($_GET['id'])) {

    $cm = "edit";
    $id = $_GET['id'];
    $exam = new Exam();
    $exam = ExamEx::GetOneExam($id);
    $title = $exam->Title;
    $teacherid = $exam->Teacher->TeacherId;
    $saal= $exam->Saal;
    $lectureid= $exam->Lecture->LectureId;
    
}
//echo $classRoom->Name;
?>
<form method="post" id="form1" name="form1" action="UpdateExam.php" >
    <input type="hidden" name="examid" id="examid" value='<?php echo $id; ?>' />
    <input type="hidden" name="command" id="command" value='<?php echo $cm; ?>' />
    <table  border="1" cellpadding="5" cellspacing="5"  class="ViewTable">
        <tr>
            <td colspan="2">ClassRoom Form</td>
        </tr>
        <tr>
            <td>عنوان:</td>
            <td><input type="text" name="title" id="title" value="<?php echo $title ?>"  /></td>
        </tr>
<!--        <tr>
            <td>Family:</td>
            <td><input type="text" name="lecture" id="lecture" value="<?php echo $family ?>" /></td>
        </tr>-->

            <td>
                <?php
                if ($_SESSION['UserType'] == "Teacher") {
                    $v = $_SESSION['User'];
                    $teacher = new Teacher();
                    $teacher = TeacherEx::GetOnTeacherBasedOnUsername($v);
                    ?>
                    <input type="hidden" name="teacherid" id="teacherid"  value="<?php echo $teacher->TeacherId; ?>" />

                    <?php
                    echo $teacher->Name . " " . $teacher->Family;
                } else {
                    ?>
                    <select name="teacherid" id="teacherid">
                        <?php
                        $teachers = TeacherEx::Fill();
                        foreach ($teachers as $teacher) {
                            $selected = "";
                            if ($teacherid == $teacher->TeacherId) {
                                $selected = "selected";
                            }
                            echo "<option value='" . $teacher->TeacherId . "' " . $selected . ">" . $teacher->Name . " " . $teacher->Family . "</option>";
                        }
                        ?>
                    </select>
                    <?php
                }
                ?>


            </td>

        <tr>
            <td>نام درس:</td>
            <td><select name="lectureid" id="lectureid" >
                    <?php
                    $lectures = LectureEx::Fill();
                    foreach ($lectures as $lecture) {
                        $selected = "";
                        if ($lectureid == $lecture->LectureId) {
                            $selected = "selected";
                        }
                        echo "<option value='" . $lecture->LectureId . "' " . $selected . ">" . $lecture->Name . "</option>";
                    }
                    ?>
                </select>
            </td>
        </tr>
        <tr>
            <td>سال مقطع تحصیلی:</td>
            <td><input type="text" name="saal" id="saal" value="<?php echo $saal ?>" /></td>
        </tr>



        <tr>
            <td colspan="2"><input type="submit" name="button" id="button" value="Submit" /></td>
        </tr>
    </table>
</form> 


<?php
include_once 'Template/footer.php';
?>

