<?php
require_once '../Classes/StudentEx.inc';
require_once '../Classes/PHPExcel/IOFactory.php';
?>
<?php
include_once 'Template/header.php';
include_once 'Template/menu.php';
?>

<?php
//$cm = $_POST['command'];
//echo $cm;
//$studentid= $_POST['students'];

$allowedExts = array("gif", "jpeg", "jpg", "png", "txt", "xlsx", "xls");
$temp = explode(".", $_FILES["students"]["name"]);
$extension = end($temp);
//echo $_FILES["students"]["type"];
if ((($_FILES["students"]["type"] == "image/gif") || ($_FILES["students"]["type"] == "image/jpeg") || ($_FILES["students"]["type"] == "image/jpg") || ($_FILES["students"]["type"] == "image/pjpeg") || ($_FILES["students"]["type"] == "image/x-png") || ($_FILES["students"]["type"] == "text/plain") || ($_FILES["students"]["type"] == "application/vnd.openxmlformats-officedocument.spreadsheetml.sheet") || ($_FILES["students"]["type"] == "application/vnd.ms-excel") || ($_FILES["students"]["type"] == "image/png")) && ($_FILES["students"]["size"] < 20000) && in_array($extension, $allowedExts)) {
    if ($_FILES["students"]["error"] > 0) {
        //echo "Return Code: " . $_FILES["students"]["error"] . "<br>";
    } else {
        //echo "Upload: " . $_FILES["students"]["name"] . "<br>";
        //echo "Type: " . $_FILES["students"]["type"] . "<br>";
        //echo "Size: " . ($_FILES["students"]["size"] / 1024) . " kB<br>";
        //echo "Temp file: " . $_FILES["students"]["tmp_name"] . "<br>";
        if (file_exists("upload/" . $_FILES["students"]["name"])) {
            //echo $_FILES["students"]["name"] . " already exists. ";
        } else {
            $content = time() . $_FILES["students"]["name"];
            move_uploaded_file($_FILES["students"]["tmp_name"], "../Uploads/" . $content);
            //echo "Stored in: " . "Uploads/" . $name;
        }
    }
} else {
    //echo "Invalid file";
}
?>



<?php
//date_default_timezone_set('America/Los_Angeles');
include_once '../Classes/PHPExcel/IOFactory.php';

$inputFileName = '../Uploads/' . $content;

//  Read your Excel workbook
try {
    $inputFileType = PHPExcel_IOFactory::identify($inputFileName);
    $objReader = PHPExcel_IOFactory::createReader($inputFileType);
    $objPHPExcel = $objReader->load($inputFileName);
} catch (Exception $e) {
    die('Error loading file "' . pathinfo($inputFileName, PATHINFO_BASENAME)
            . '": ' . $e->getMessage());
}

//  Get worksheet dimensions
$sheet = $objPHPExcel->getSheet(0);
$highestRow = $sheet->getHighestRow();
$highestColumn = $sheet->getHighestColumn();

//  Loop through each row of the worksheet in turn
?>
<form method="post" id="form1" name="form1" action="UploadingStudentsDone.php" >
    <input type="hidden" name="filename" id="filename" value='<?php echo $inputFileName; ?>' />
    <table  border="1" cellpadding="5" cellspacing="5"  class="ViewTable">
        <tr>
            <th>نوع عملیات</th>
            <th>انتخاب</th>
            <th>نام</th>
            <th>نام خانوادگی</th>
            <th>کد ملی</th>
            <th>رمز عبور</th>
        </tr>

        <?php
        for ($row = 1; $row <= $highestRow; $row++) {
            //  Read a row of data into an array
            $rowData = $sheet->rangeToArray('A' . $row . ':' . $highestColumn . $row, NULL, TRUE, FALSE);
            //foreach ($rowData[0] as $k => $v)
            //   echo "Row: " . $row . "- Col: " . ($k + 1) . " = " . $v . "<br />";
            //$string=implode(",",$rowData[0]);
            echo '<tr>';
            //echo $string . "<br />";
            if (StudentEx::CheckExists($rowData[0][2]) == TRUE) {
                echo '<td>' . 'ویرایش' . '</td>';
            } else {
                echo '<td>' . 'درج' . '</td>';
            }
            echo "<td><input type='checkbox' id='checked[]' name='checked[]' value='" . $row . "' checked='1' /></td>";
            echo "<td>" . $rowData[0][0] . "</td>";
            echo "<td>" . $rowData[0][1] . "</td>";
            echo "<td>" . $rowData[0][2] . "</td>";
            echo "<td>" . $rowData[0][3] . "</td>";
            echo "</tr>";
        }
        ?>
        <tr>
            <td colspan="6" ><input type="submit" name="button" id="button" value="ثبت" /> </td>
        </tr>
    </table>
    
</form> 




<?php
//if ($cm == 'edit') {
//    StudentEx::Update($student);
//} else {
//    StudentEx::Insert($student);
//}
//
//header("Location: Students.php");
?>


<?php
include_once 'Template/footer.php';
?>

