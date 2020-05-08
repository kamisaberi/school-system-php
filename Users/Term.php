<?php
require_once '../Classes/TermEx.inc';
?>
<?php
include_once 'Template/header.php';
include_once 'Template/menu.php';
?>

<?php
$id = "";
$cm = "add";
$salshoroo = "";
$salpayan= "";
$nimsal = "";
$tozihat = "";
if (isset($_GET['id'])) {

    $cm = "edit";
    $id = $_GET['id'];
    $term= new Term();
    $term= TermEx::GetOnTerm($id);
    $salshoroo= $term->SalShoroo;
    $salpayan= $term->SalPayan;
    $nimsal = $term->NimSal;
    $tozihat = $term->Tozihat;
}
//echo $teacher->Name;
?>
<form method="post" id="form1" name="form1" action="UpdateTerm.php" >
    <input type="hidden" name="termid" id="termid" value='<?php echo $id; ?>' />
    <input type="hidden" name="command" id="command" value='<?php echo $cm; ?>' />
    <table  border="1" cellpadding="5" cellspacing="5"  class="ViewTable">
        <tr>
            <td colspan="2">Teacher Form</td>
        </tr>
        <tr>
            <td>سال شروع:</td>
            <td><input type="text" name="salshoroo" id="salshoroo" value="<?php echo $salshoroo ?>"  /></td>
        </tr>
        <tr>
            <td>سال پایان:</td>
            <td><input type="text" name="salpayan" id="salpayan" value="<?php echo $salpayan ?>" /></td>
        </tr>
        <tr>
            <td>نیمسال:</td>
            <td><input type="text" name="nimsal" id="nimsal" value="<?php echo $nimsal ?>" /></td>
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

