<?php

session_start();
require_once '../Classes/UserEx.inc';
require_once '../Classes/TeacherEx.inc';
require_once '../Classes/StudentEx.inc';
$username = $_POST['username'];
$password = $_POST['password'];

if (UserEx::Login($username, $password) == TRUE) {

    $_SESSION['AdminLoggedin'] = "YES";
    $_SESSION['User'] = $username;
    setcookie("AdminUser", $username, time() + 60 * 60 * 24 * 7);
    $_SESSION['UserType'] = "Admin";
    setcookie("UserType", "Admin", time() + 60 * 60 * 24 * 7);
    //if ($_SERVER['DOCUMENT_ROOT'] == "C:/xampp/htdocs") {
    //mkdir($_SERVER['DOCUMENT_ROOT'] . "/School/Uploads/" . $_SESSION['User'], 0777, true);
    if (!file_exists("../Uploads/" . $_SESSION['User'])) {
        mkdir("../Uploads/" . $_SESSION['User'], 0777, true);
    }
    //} else {
    //mkdir($_SERVER['DOCUMENT_ROOT'] . "/Uploads/" . $_SESSION['User'], 0777, true);
    //mkdir("../Uploads/" . $_SESSION['User'], 0777, true);
    //}

    header("Location: Index.php");
} elseif (TeacherEx::Login($username, $password) == TRUE) {

    $_SESSION['TeacherLoggedin'] = "YES";
    $_SESSION['User'] = $username;
    setcookie("TeacherUser", $username, time() + 60 * 60 * 24 * 7);
    $_SESSION['UserType'] = "Teacher";
    setcookie("UserType", "Teacher", time() + 60 * 60 * 24 * 7);
    if (!file_exists("../Uploads/" . $_SESSION['User'])) {
        mkdir("../Uploads/" . $_SESSION['User'], 0777, true);
    }
//    if ($_SERVER['DOCUMENT_ROOT'] == "C:/xampp/htdocs") {
//        mkdir($_SERVER['DOCUMENT_ROOT'] . "/School/Uploads/Teachers/" . $_SESSION['User'], 0777, true);
//    } else {
//        mkdir($_SERVER['DOCUMENT_ROOT'] . "/Uploads/Teachers/" . $_SESSION['User'], 0777, true);
//    }


    header("Location: Index.php");
} elseif (StudentEx::Login($username, $password) == TRUE) {

    $_SESSION['StudentLoggedin'] = "YES";
    $_SESSION['User'] = $username;
    setcookie("StudentUser", $username, time() + 60 * 60 * 24 * 7);
    $_SESSION['UserType'] = "Student";
    setcookie("UserType", "Student", time() + 60 * 60 * 24 * 7);
//if ($_SERVER['DOCUMENT_ROOT'] == "C:/xampp/htdocs") {
//    mkdir($_SERVER['DOCUMENT_ROOT'] . "/School/Uploads/Students/" . $_SESSION['User'], 0777, true);
//} else {
//    mkdir($_SERVER['DOCUMENT_ROOT'] . "/Uploads/Students/" . $_SESSION['User'], 0777, true);
//}

    header("Location: Index.php");
} else {
    $_SESSION['LoginError'] = "نام کاربری یا رمز عبور اشتباه می باشد";
    header("Location: ../index.php");
}









