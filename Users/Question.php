<?php
require_once '../Classes/QuestionEx.inc';
require_once '../Classes/LectureEx.inc';
require_once '../Classes/TeacherEx.inc';
require_once '../Classes/TermEx.inc';
require_once '../Classes/QuestionTypeEx.inc';
?>
<?php
include_once 'Template/header.php';
?>

<script>
    var roxyFileman = '../fileman/index.html?integration=ckeditor';
    $(function () {
        CKEDITOR.replace('content', {filebrowserBrowseUrl: roxyFileman,
            filebrowserImageBrowseUrl: roxyFileman + '&type=image',
            removeDialogTabs: 'link:upload;image:upload'});
    });
</script>
<?php
include_once 'Template/menu.php';
?>


<?php
$id = "";
$cm = "add";
$content = "";
$lectureid = "";
$saal = "";
$teacherid = "";
$questiontypeid = "";

if (isset($_GET['id'])) {

    $cm = "edit";
    $id = $_GET['id'];
    $question = new Question();
    $question = QuestionEx::GetOneQuestion($id);
    $content = $question->Content;
    $lectureid = $question->Lecture->LectureId;
    $saal = $question->Saal;
    $teacherid = $question->Teacher->TeacherId;
    $questiontypeid = $question->QuestionType->QuestionTypeId;
    //echo $questiontypeid ;
//$gradetypeid = $question->GradeType->GradeTypeId;
}
//echo $question->Name;

//include_once '../ckeditor/ckeditor.php';
//$ckeditor = new CKEditor();
//$ckeditor->basePath = 'ckeditor/';
//$ckeditor->config['filebrowserBrowseUrl'] = '/ckfinder/ckfinder.html';
//$ckeditor->config['filebrowserImageBrowseUrl'] = '/ckfinder/ckfinder.html?type=Images';
//$ckeditor->config['filebrowserFlashBrowseUrl'] = '/ckfinder/ckfinder.html?type=Flash';
//$ckeditor->config['filebrowserUploadUrl'] = '/ckfinder/core/connector/php/connector.php?command=QuickUpload&type=Files';
//$ckeditor->config['filebrowserImageUploadUrl'] = '/ckfinder/core/connector/php/connector.php?command=QuickUpload&type=Images';
//$ckeditor->config['filebrowserFlashUploadUrl'] = '/ckfinder/core/connector/php/connector.php?command=QuickUpload&type=Flash';
//$ckeditor->config['toolbar'] = array(
//    array('Source', '-',
//        'NewPage', 'Preview', 'Templates', '-',
//        'Cut', 'Copy', 'Paste', 'PasteText', 'PasteFromWord', '-',
//        'Undo', 'Redo', '-',
//        'Find', 'Replace', '-',
//        'SelectAll', 'RemoveFormat', '-',
//        'Maximize', 'ShowBlocks'),
//    '/',
//    array('Bold', 'Italic', 'Underline', 'Strike', '-',
//        'Subscript', 'Superscript', '-',
//        'NumberedList', 'BulletedList', '-',
//        'Outdent', 'Indent', 'Blockquote', '-',
//        'JustifyLeft', 'JustifyCenter', 'JustifyRight', 'JustifyBlock', '-', 'BidiLtr', 'BidiRtl', '-',
//        'Link', 'Unlink', 'Anchor', '-',
//        'Image', 'Flash', 'Table', 'HorizontalRule', 'SpecialChar', 'Smiley'
//    ),
//    '/',
//    array('Format', 'Font', 'FontSize', '-',
//        'TextColor', 'BGColor')
//);
//$ckeditor->config['contentsLangDirection'] = 'rtl';
//$ckeditor->config['toolbarDirection'] = 'right';
?>



<!--<script type="text/javascript" src="../ckeditor/ckeditor.js"></script>-->
<form method="post" id="form1" name="form1" action="UpdateQuestion.php" >
    <input type="hidden" name="questionid" id="questionid" value='<?php echo $id; ?>' />
    <input type="hidden" name="command" id="command" value='<?php echo $cm; ?>' />
    <table  border="1" cellpadding="5" cellspacing="5"  class="ViewTable">
        <tr>
            <td colspan="2">Question Form</td>
        </tr>
        <tr>
            <td>متن سوال:</td>
            <td>//<?php
//                $ckeditor->editor('content', $content);
                ?>
                <textarea id="content" name="content" rows="10" cols="80"><?php echo $content; ?></textarea>
                <!--                <textarea maxlength="10000" rows="5" cols="100"  name="content" id="content"  ><?php echo trim($content) ?></textarea>-->
            </td>    
        </tr>
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
            <td>نوع سوال:</td>
            <td><select name="questiontypeid" id="questiontypeid">
                    <?php
                    $questiontypes = QuestionTypeEx::Fill();
                    foreach ($questiontypes as $questiontype) {
                        $selected = "";
                        if ($questiontypeid == $questiontype->QuestionTypeId) {
                            $selected = "selected";
                        }
                        echo "<option value='" . $questiontype->QuestionTypeId . "' " . $selected . ">" . $questiontype->Name . "</option>";
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
            <td>طراح:</td>
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
        </tr>
        <tr>
            <td colspan="2"><input type="submit" name="button" id="button" value="Submit" /></td>
        </tr>
    </table>
</form> 


<?php
include_once 'Template/footer.php';
?>

