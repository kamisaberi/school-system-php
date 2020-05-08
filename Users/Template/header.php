<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">
<?php
require_once '../fileman/system.inc.php';
require_once '../fileman/php/functions.inc.php';
if(!isset($_SESSION)){
    session_start();
}

$_SESSION[SESSION_PATH_KEY]="";

require_once '../Classes/StudentEx.inc';
require_once '../Classes/TeacherEx.inc';
require_once '../Classes/OptionEx.inc';
require_once '../Classes/ClassRoomEx.inc';
require_once '../Classes/TermEx.inc';
require_once '../Classes/TeacherEx.inc';
require_once '../Classes/LectureEx.inc';
require_once '../Classes/ClassRoomEx.inc';
require_once '../Classes/StudentEx.inc';
require_once '../Classes/OptionEx.inc';
require_once '../Classes/GradeValueEx.inc';
require_once '../Classes/ClassRoomEx.inc';
require_once '../Classes/StudentEx.inc';
require_once '../Classes/OptionEx.inc';
require_once '../Classes/GradeValueEx.inc';




if (isset($_COOKIE["AdminUser"])) {
    $_SESSION['User'] = $_COOKIE["AdminUser"];
    //echo $_SESSION['User'] ;
    $_SESSION['AdminLoggedin'] = "YES";
} elseif (isset($_COOKIE["TeacherUser"])) {
    $_SESSION['User'] = $_COOKIE["TeacherUser"];
    //echo $_SESSION['User'] ;
    $_SESSION['TeacherLoggedin'] = "YES";
} elseif (isset($_COOKIE["StudentUser"])) {
    $_SESSION['User'] = $_COOKIE["StudentUser"];
    //echo $_SESSION['User'] ;
    $_SESSION['StudentLoggedin'] = "YES";
}


if ($_SESSION['UserType'] == "Admin") {
    if ($_SESSION['AdminLoggedin'] != "YES") {
        header("Location: Login.php");
    }
} elseif ($_SESSION['UserType'] == "Teacher") {
    if ($_SESSION['TeacherLoggedin'] != "YES") {
        header("Location: Login.php");
    }
} elseif ($_SESSION['UserType'] == "Student") {
    if ($_SESSION['StudentLoggedin'] != "YES") {
        header("Location: Login.php");
    }
}
?>
<html xmlns="http://www.w3.org/1999/xhtml" >

    <head>
        <title>مدرسه غیرانتفاهی شفق</title>
        <meta http-equiv="Content-Type" content="text/html; charset=utf-8" />
        <link href="../Styles/Style.css" rel="stylesheet" type="text/css" />
        <link rel="shortcut icon" href="../Images/students.ico" />
        <script src="../Scripts/jquery-1.10.2.min.js" type="text/javascript"></script>
        <script type="text/javascript" language="javascript">
            $(document).ready(function() {
                $('.Nav li').hover(
                        function() {
                            $('ul', this).stop().slideDown(100);
                        },
                        function() {
                            $('ul', this).stop().slideUp(100);
                        });
            });
        </script>
    
        <script type="text/javascript" src="../ckeditor/ckeditor.js"></script>
