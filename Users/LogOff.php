<?php

session_start();
require_once '../Classes/UserEx.inc';
require_once '../Classes/StudentEx.inc';
require_once '../Classes/TeacherEx.inc';
//$username = $_POST['username'];
//$password = $_POST['password'];

if ($_SESSION['UserType'] == "Admin") {
    $_SESSION['AdminLoggedin'] = "NO";
    $_SESSION['User'] = "";
    $_SESSION['UserType'] = "";
    setcookie("AdminUser", '', time() - 3600);
    setcookie("UserType", '', time() - 3600);
    header("Location: ../index.php");
} elseif ($_SESSION['UserType'] == "Teacher") {
    $_SESSION['TeacherLoggedin'] = "NO";
    $_SESSION['User'] = "";
    $_SESSION['UserType'] = "";
    setcookie("TeacherUser", '', time() - 3600);
    setcookie("UserType", '', time() - 3600);
    header("Location: ../index.php");
} elseif ($_SESSION['UserType'] == "Student") {
    $_SESSION['StudentLoggedin'] = "NO";
    $_SESSION['User'] = "";
    $_SESSION['UserType'] = "";
    setcookie("StudentUser", '', time() - 3600);
    setcookie("UserType", '', time() - 3600);
    header("Location: ../index.php");
}






