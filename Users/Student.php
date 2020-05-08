<?php
require_once '../Classes/StudentEx.inc';
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
$codemelli = "";
$passwd = "";
if (isset($_GET['id'])) {

    $cm = "edit";
    $id = $_GET['id'];
    $student = new Student();
    $student = StudentEx::GetOnStudent($id);
    $content = $student->Name;
    $family = $student->Family;
    $codemelli = $student->CodeMelli;
    $passwd = $student->Passwd;
}
//echo $teacher->Name;
if ($cm == "add") {
    ?>
    <form method="post" id="form2" name="form2" action="UploadStudents.php" enctype="multipart/form-data" >
        <div class="FormMain">
            <table  border="0" cellpadding="0" cellspacing="0"  class="FormsContainer">
                <tbody>
                    <tr>
                        <td colspan="2">
                            <div class="FormTitle">
                                <h3>
                                    اطلاعات دانش آموز</h3>
                            </div>
                        </td>
                    </tr>
                    <tr>
                        <td><label> Name: </label></td>
                        <td><input type="file" name="students" id="students" /></td>
                    </tr>
                    <tr>
                        
                        <td colspan="2"><input type="submit" name="button" id="button" value="uplaod" /></td>
                    </tr>
                </tbody>
            </table>
        </div>

    </form>
    <br/>
    <?php
}
?>
<form method="post" id="form1" name="form1" action="UpdateStudent.php" >
    <input type="hidden" name="studentid" id="studentid" value='<?php echo $id; ?>' />
    <input type="hidden" name="command" id="command" value='<?php echo $cm; ?>' />
    <div class="FormMain">
        <table  border="1" cellpadding="5" cellspacing="5"  class="FormsContainer">
            <tbody>
                <tr>
                    <td colspan="2">
                        <div class="FormTitle">
                            <h3>
                                اطلاعات دانش آموز</h3>
                        </div>
                    </td>
                </tr>
                <tr>
                    <td><label>نام:</label></td>
                    <td><input type="text" name="name" id="name" value="<?php echo $content ?>"  /></td>
                </tr>
                <tr>
                    <td><label>نام خانوادگی:</label></td>
                    <td><input type="text" name="family" id="family" value="<?php echo $family ?>" /></td>
                </tr>
                <tr>
                    <td><label>کد ملی:</label></td>
                    <td><input type="text" name="codemelli" id="codemelli" value="<?php echo $codemelli ?>" /></td>
                </tr>
                <tr>
                    <td><label>رمز عبور:</label></td>
                    <td><input type="password" name="password" id="password" value="<?php /* echo $passwd */ ?>" /></td>
                </tr>
                <tr>
                    <td colspan="2" ><input type="submit" name="button" id="button" value="ثبت" /></td>
                </tr>
            </tbody>
        </table>
    </div>
</form> 


<?php
include_once 'Template/footer.php';
?>

