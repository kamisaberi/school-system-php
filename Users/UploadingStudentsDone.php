<?php

require_once '../Classes/StudentEx.inc';
require_once '../Classes/PHPExcel/IOFactory.php';
?>

<?php

//$cm = $_POST['command'];
//echo $cm;
$checkeds = $_POST['checked'];

//foreach ($checkeds as $checked) {
//    echo $checked . "<br />";
//}
?>

<?php

include_once '../Classes/PHPExcel/IOFactory.php';

$inputFileName = $_POST['filename'];

////  Read your Excel workbook
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

for ($row = 1; $row <= $highestRow; $row++) {
    //  Read a row of data into an array
    //foreach ($rowData[0] as $k => $v)
    //   echo "Row: " . $row . "- Col: " . ($k + 1) . " = " . $v . "<br />";
    //$string=implode(",",$rowData[0]);
    //echo $string . "<br />";

    foreach ($checkeds as $checked) {
        if ($checked == $row) {
            $rowData = $sheet->rangeToArray('A' . $row . ':' . $highestColumn . $row, NULL, TRUE, FALSE);
            $student = new Student();
            $student->Name =$rowData[0][0];
            $student->Family=$rowData[0][1];
            $student->CodeMelli =$rowData[0][2];
            $student->Passwd =$rowData[0][3];
            if (StudentEx::CheckExists($rowData[0][2]) == TRUE) {
                StudentEx::UpdateByCodeMelli($student);
            } else {
                StudentEx::Insert($student);
            }
            break;
        }
    }
}
header("Location: Students.php");
?>

