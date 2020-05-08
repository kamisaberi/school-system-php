<?php
require_once '../Classes/GradeValueEx.inc';
require_once '../Classes/GradeTypeEx.inc';
?>
<?php
include_once 'Template/header.php';
include_once 'Template/menu.php';
?>

<?php
$id = "";
$cm = "add";
$value = "";
$gradetypeid = "";
if (isset($_GET['id'])) {

    $cm = "edit";
    $id = $_GET['id'];
    $gradeValue = new GradeValue();
    $gradeValue = GradeValueEx::GetOnGradeValue($id);
    $value = $gradeValue->Value;
    $gradetypeid = $gradeValue->GradeType->GradeTypeId;
} elseif (isset($_GET['type'])) {
    $gradetypeid = $_GET['type'];
}

//echo $gradeValue->Name;
?>
<form method="post" id="form1" name="form1" action="UpdateGradeValue.php" >
    <input type="hidden" name="gradevalueid" id="gradevalueid" value='<?php echo $id; ?>' />
    <input type="hidden" name="command" id="command" value='<?php echo $cm; ?>' />
    <table  border="1" cellpadding="5" cellspacing="5"  class="ViewTable">
        <tr>
            <td colspan="2">Grade Value Form</td>
        </tr>
        <tr>
            <td>نوع:</td>
            <td><select name="gradetypeid" id="gradetypeid" >
                    <?php
                    $gradetypes = GradeTypeEx::Fill();
                    foreach ($gradetypes as $gradetype) {
                        $selected = "";
                        if ($gradetypeid == $gradetype->GradeTypeId) {
                            $selected = "selected";
                        }
                        if ($gradetype->DefinedValues == TRUE) {
                            echo "<option value='" . $gradetype->GradeTypeId . "' " . $selected . ">" . $gradetype->Name . "</option>";
                        }
                    }
                    ?>
                </select>
            </td>
        </tr>
        <tr>
            <td>مقدار:</td>
            <td><input type="text" name="value" id="value" value="<?php echo $value ?>"  /></td>
        </tr>

        <tr>
            <td colspan="2"><input type="submit" name="button" id="button" value="ثبت" /></td>
        </tr>
    </table>
</form> 


<?php
include_once 'Template/footer.php';
?>

