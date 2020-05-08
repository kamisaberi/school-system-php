<?php
require_once '../Classes/GradeEx.inc';
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
if (isset($_GET['id'])) {

    $cm = "edit";
    $id = $_GET['id'];
    $grade = new Grade();
    $grade = GradeEx::GetOnGrade($id);
    $content = $grade->Name;
    $family = $grade->Family;
    $username = $grade->Username;
    $passwd = $grade->Passwd;
}
//echo $grade->Name;
?>
<form method="post" id="form1" name="form1" action="UpdateGrade.php" >
    <input type="hidden" name="gradeid" id="gradeid" value='<?php echo $id; ?>' />
    <input type="hidden" name="command" id="command" value='<?php echo $cm; ?>' />
    <table  border="1" cellpadding="5" cellspacing="5"  class="ViewTable">
        <tr>
            <td colspan="2">Grade Form</td>
        </tr>
        <tr>
            <td>Name:</td>
            <td><input type="text" name="name" id="name" value="<?php echo $content ?>"  /></td>
        </tr>
        <tr>
            <td>Family:</td>
            <td><input type="text" name="family" id="family" value="<?php echo $family ?>" /></td>
        </tr>
        <tr>
            <td>Username:</td>
            <td><input type="text" name="username" id="username" value="<?php echo $username ?>" /></td>
        </tr>
        <tr>
            <td>Password:</td>
            <td><input type="password" name="password" id="password" value="<?php echo $passwd ?>" /></td>
        </tr>
        <tr>
            <td>&nbsp;</td>
            <td><input type="submit" name="button" id="button" value="Submit" /></td>
        </tr>
    </table>
</form> 


<?php
include_once 'Template/footer.php';
?>

