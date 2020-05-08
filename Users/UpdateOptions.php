
<?php

require_once '../Classes/OptionEx.inc';
$option = new Option();

$option->Value = $_POST['termid'];
$option->Name = "ActiveTerm";
OptionEx::SetValue($option);

$option->Value = $_POST['recordnumber'];
$option->Name = "NumberOfRecords";
OptionEx::SetValue($option);

header("Location: Index.php");



