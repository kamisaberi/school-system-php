<?php

session_start();
require_once '../Classes/StudentEx.inc';

$username = $_POST['username'];
$password = $_POST['password'];

if (StudentEx::Login($username, $password) == TRUE) {

    $_SESSION['StudentLoggedin'] = "YES";
    $_SESSION['User'] = $username;
    setcookie("StudentUser", $username, time() + 60 * 60 * 24 * 7);
    $_SESSION['UserType'] = "Student";
    setcookie("UserType", "Student", time() + 60 * 60 * 24 * 7);

    header("Location: Index.php");
} else {
    header("Location: Login.php");
}


