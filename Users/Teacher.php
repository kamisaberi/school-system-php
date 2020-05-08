<?php
require_once '../Classes/TeacherEx.inc';
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
$codemelli="";
if (isset($_GET['id'])) {

    $cm = "edit";
    $id = $_GET['id'];
    $student = new Teacher();
    $student = TeacherEx::GetOnTeacher($id);
    $content = $student->Name;
    $family = $student->Family;
    $codemelli= $student->CodeMelli;
    $username = $student->Username;
    $passwd = $student->Passwd;
}
//echo $teacher->Name;
?>
<form method="post" id="form1" name="form1" action="UpdateTeacher.php" >
    <input type="hidden" name="teacherid" id="teacherid" value='<?php echo $id; ?>' />
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
            <td>نام خانوادگی:</td>
            <td><input type="text" name="family" id="family" value="<?php echo $family ?>" /></td>
        </tr>
        <tr>
            <td>کد ملی:</td>
            <td><input type="text" name="codemelli" id="codemelli" value="<?php echo $codemelli ?>" /></td>
        </tr>

        <tr>
            <td>نام کاربری:</td>
            <td><input type="text" name="username" id="username" value="<?php echo $username ?>" /></td>
        </tr>
        <tr>
            <td>رمز عبور:</td>
            <td><input type="password" name="password" id="password" value="<?php /* echo $passwd */?>" /></td>
        </tr>
        <tr>
            <td colspan="2"><input type="submit" name="button" id="button" value="ثبت" /></td>
        </tr>
    </table>
</form> 


<?php
include_once 'Template/footer.php';
?>

