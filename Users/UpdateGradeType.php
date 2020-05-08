
<?php

require_once '../Classes/GradeTypeEx.inc';

$cm = $_POST['command'];
//echo $cm;
$gradetypeid = $_POST['gradetypeid'];
$content = $_POST['name'];
$min = $_POST['min'];
$max = $_POST['max'];
$pass = $_POST['pass'];
$definedvalues = 0;
if (isset($_POST['definedvalues'])) {
    $definedvalues = $_POST['definedvalues'];
}
echo $definedvalues;

$gradeType = new GradeType();
$gradeType->GradeTypeId = $gradetypeid;
$gradeType->Name = $content;
$gradeType->Min = $min;
$gradeType->Max= $max;
$gradeType->Pass = $pass;
$gradeType->DefinedValues = ($definedvalues==1 ? TRUE : FALSE);

//echo $gradeType->GradeTypeId ;
//echo $gradeType->Name ;
//echo $gradeType->Family ;
//echo $gradeType->Username ;
//echo $gradeType->Passwd ;
//echo $cm;
if ($cm == 'edit') {
    GradeTypeEx::Update($gradeType);
} else {
    GradeTypeEx::Insert($gradeType);
}

header("Location: GradeTypes.php");



