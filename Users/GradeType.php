<?php
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
$min = "";
$max = "";
$pass = "";
if (isset($_GET['id'])) {

    $cm = "edit";
    $id = $_GET['id'];
    $gradeType = new GradeType();
    $gradeType = GradeTypeEx::GetOnGradeType($id);
    $content = $gradeType->Name;
    $min = $gradeType->Min;
    $max = $gradeType->Max;
    $pass = $gradeType->Pass;
}
//echo $gradeType->Name;
?>
<form method="post" id="form1" name="form1" action="UpdateGradeType.php" >
    <input type="hidden" name="gradetypeid" id="gradetypeid" value='<?php echo $id; ?>' />
    <input type="hidden" name="command" id="command" value='<?php echo $cm; ?>' />
    <table  border="1" cellpadding="5" cellspacing="5"  class="ViewTable">
        <tr>
            <td colspan="2">GradeType Form</td>
        </tr>
        <tr>
            <td>نام:</td>
            <td><input type="text" name="name" id="name" value="<?php echo $content ?>"  /></td>
        </tr>
        <tr>
            <td>حداقل:</td>
            <td><input type="text" name="min" id="min" value="<?php echo $min ?>" /></td>
        </tr>
        <tr>
            <td>حداکثر:</td>
            <td><input type="text" name="max" id="max" value="<?php echo $max ?>" /></td>
        </tr>
        <tr>
            <td>نمره ی قبولی:</td>
            <td><input type="text" name="pass" id="pass" value="<?php echo $pass ?>" /></td>
        </tr>
        <tr>
            <td>قابلیت تعریف گزینه ها:</td>
            <td><input type="checkbox" name="definedvalues" id="definedvalues" value="1" /></td>
        </tr>
        <tr>
            <td colspan="2"><input type="submit" name="button" id="button" value="ثبت" /></td>
        </tr>
    </table>
</form> 


<?php
include_once 'Template/footer.php';
?>

