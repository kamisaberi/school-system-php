<?php
require_once '../Classes/LectureEx.inc';
?>
<?php
include_once 'Template/header.php';
include_once 'Template/menu.php';
?>

<?php
$id = "";
$cm = "add";
$content = "";
$tedadvahed = "";
$tozihat = "";
if (isset($_GET['id'])) {

    $cm = "edit";
    $id = $_GET['id'];
    $lecture= new Lecture();
    $lecture= LectureEx::GetOnLecture($id);
    $content= $lecture->Name;
    $tedadvahed= $lecture->TedadVahed;
    $tozihat= $lecture->Tozihat;
}
//echo $teacher->Name;
?>
<form method="post" id="form1" name="form1" action="UpdateLecture.php" >
    <input type="hidden" name="lectureid" id="lectureid" value='<?php echo $id; ?>' />
    <input type="hidden" name="command" id="command" value='<?php echo $cm; ?>' />
    <table  border="1" cellpadding="5" cellspacing="5"  class="ViewTable">
        <tr>
            <td colspan="2">Teacher Form</td>
        </tr>
        <tr>
            <td>نام:</td>
            <td><input type="text" name="name" id="name" value="<?php echo $content ?>"  /></td>
        </tr>
        <tr>
            <td>تعداد واحد:</td>
            <td><input type="text" name="tedadvahed" id="tedadvahed" value="<?php echo $tedadvahed ?>" /></td>
        </tr>
        <tr>
            <td>توضیحات:</td>
            <td><input type="text" name="tozihat" id="tozihat" value="<?php echo $tozihat ?>" /></td>
        </tr>
        <tr>
            <td colspan="2"><input type="submit" name="button" id="button" value="Submit" /></td>
        </tr>
    </table>
</form> 


<?php
include_once 'Template/footer.php';
?>

