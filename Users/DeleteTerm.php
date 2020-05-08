<?php


$id = $_GET['id'];
require_once '../Classes/TermEx.inc';
$term = new Term();
$term->TermId = $id;
TermEx::Delete($term);


header("Location: Terms.php");



