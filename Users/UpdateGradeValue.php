
<?php

require_once '../Classes/GradeValueEx.inc';
require_once '../Classes/GradeTypeEx.inc';

$cm = $_POST['command'];
//echo $cm;
$gradevalueid = $_POST['gradevalueid'];
$value = $_POST['value'];
$gradetypeid = $_POST['gradetypeid'];

$gradeValue = new GradeValue();
$gradeValue->GradeValueId = $gradevalueid;
$gradeValue->Value= $value;
$gradeValue->GradeType->GradeTypeId= $gradetypeid;
//echo $gradeType->GradeTypeId ;
//echo $gradeType->Name ;
//echo $gradeType->Family ;
//echo $gradeType->Username ;
//echo $gradeType->Passwd ;
//echo $cm;
if ($cm == 'edit') {
    GradeValueEx::Update($gradeValue);
} else {
    GradeValueEx::Insert($gradeValue);
}

header("Location: GradeValues.php");



