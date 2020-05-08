<?php

session_start();
require_once '../Classes/StudentEx.inc';

$_SESSION['StudentLoggedin'] = "NO";
$_SESSION['User'] = "";
setcookie("StudentUser", '', time() - 3600);
setcookie("UserType", '', time() - 3600);
header("Location: ../index.php");







