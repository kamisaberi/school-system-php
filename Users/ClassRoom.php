<?php
require_once '../Classes/ClassRoomEx.inc';
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
$content = "";
$lectureid = "";
$saal = "";
$teacherid = "";
$termid = "";
$gradetypeid = "";
if (isset($_GET['id'])) {

    $cm = "edit";
    $id = $_GET['id'];
    $exam = new ClassRoom();
    $exam = ClassRoomEx::GetOnClassRoom($id);
    $content = $exam->Name;
    $lectureid = $exam->Lecture->LectureId;
    $saal = $exam->Saal;
    $teacherid = $exam->Teacher->TeacherId;
    $termid = $exam->Term->TermId;
    $gradetypeid = $exam->GradeType->GradeTypeId;
}
//echo $classRoom->Name;
?>
<form method="post" id="form1" name="form1" action="UpdateClassRoom.php" >
    <input type="hidden" name="classroomid" id="classroomid" value='<?php echo $id; ?>' />
    <input type="hidden" name="command" id="command" value='<?php echo $cm; ?>' />
    <table  border="1" cellpadding="5" cellspacing="5"  class="ViewTable">
        <tr>
            <td colspan="2">ClassRoom Form</td>
        </tr>
        <tr>
            <td>نام:</td>
            <td><input type="text" name="name" id="name" value="<?php echo $content ?>"  /></td>
        </tr>
<!--        <tr>
            <td>Family:</td>
            <td><input type="text" name="lecture" id="lecture" value="<?php echo $family ?>" /></td>
        </tr>-->
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
            <td>ترم:</td>
            <td><select name="termid" id="termid">
                    <?php
                    $terms = TermEx::Fill();
                    foreach ($terms as $term) {
                        $selected = "";
                        if ($termid == $term->TermId) {
                            $selected = "selected";
                        }
                        echo "<option value='" . $term->TermId . "' " . $selected . ">" . $term->SalShoroo . "-" . $term->SalPayan . " " . $term->NimSal . "</option>";
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
            <td>Teacher:</td>
            <td><select name="teacherid" id="teacherid">
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
            </td>
        </tr>

        <tr>
            <td>نوع نمره دهی:</td>
            <td><select name="gradetypeid" id="gradetypeid">
                    <?php
                    $gradetypes = GradeTypeEx::Fill();
                    foreach ($gradetypes as $gradetype) {
                        $selected = "";
                        if ($gradetypeid == $gradetype->GradeTypeId) {
                            $selected = "selected";
                        }
                        echo "<option value='" . $gradetype->GradeTypeId . "' " . $selected . ">" . $gradetype->Name . "</option>";
                    }
                    ?>
                </select>
            </td>
        </tr>



        <tr>
            <td colspan="2"><input type="submit" name="button" id="button" value="Submit" /></td>
        </tr>
    </table>
</form> 


<?php
include_once 'Template/footer.php';
?>

