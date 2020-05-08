<?php
require_once 'Classes/TeacherEx.inc';
require_once 'Classes/ClassRoom.inc';
require_once 'Classes/ClassRoomEx.inc';
?>
<?php
include_once 'Template/header.php';
//session_start();
//$_SESSION['FILES_ROOT'] = 'Techer';
?>
<script src="ckeditor/ckeditor.js" type="text/javascript"></script>
<!-- Place inside the <head> of your HTML -->
<!--<script type="text/javascript" src="Scripts/tinymce/js/tinymce/tinymce.min.js"></script>
<script type="text/javascript">
tinymce.init({
    selector: "textarea",theme: "modern",width: 680,height: 300,
    plugins: [
         "advlist autolink link image lists charmap print preview hr anchor pagebreak",
         "searchreplace wordcount visualblocks visualchars insertdatetime media nonbreaking",
         "table contextmenu directionality emoticons paste textcolor responsivefilemanager"
   ],
   toolbar1: "undo redo | bold italic underline | alignleft aligncenter alignright alignjustify | bullist numlist outdent indent | styleselect",
   toolbar2: "| responsivefilemanager | link unlink anchor | image media | forecolor backcolor  | print preview code ",
   image_advtab: true ,
   
   external_filemanager_path:"/filemanager/",
   filemanager_title:"Responsive Filemanager" ,
   external_plugins: { "filemanager" : "/filemanager/plugin.min.js"}
 });
</script>-->
<?php
include_once 'Template/menu.php';
//echo dirname(__FILE__) . "<br />";
//echo $_SERVER['DOCUMENT_ROOT'] . "<br />";
//echo  $_SERVER['DOCUMENT_ROOT'] . "/School/Uploads/" . $_SESSION['User']  . "<br/>";
//echo file_exists($_SERVER['DOCUMENT_ROOT'] . "/School/Uploads/" . $_SESSION['User'] );
//if (!file_exists($_SERVER['DOCUMENT_ROOT'] . "/School/Uploads/" . $_SESSION['User'] )) {
//    mkdir($_SERVER['DOCUMENT_ROOT'] . "/School/Uploads/" . $_SESSION['User'], 0777, true);
//}
//$path=$_SERVER['DOCUMENT_ROOT'] . "/School/Uploads/" . $_SESSION['User'];
//$path = mb_ereg_replace('[\\\/]+', '/', $path);
//echo $path;

//if (!file_exists($_SERVER['DOCUMENT_ROOT'] . "/School/Uploads" . $_SESSION['User'] ."/")) {
       // mkdir($_SERVER['DOCUMENT_ROOT'] . "/School/Uploads"  . $_SESSION['User'], 0777, true);
  //  }





   //echo "<script type='text/javascript'>alert('" . BASE_PATH."');</script>";
//    if (!file_exists($_SERVER['DOCUMENT_ROOT'] . FILES_ROOT . $_SESSION['User'])) {
//        mkdir($_SERVER['DOCUMENT_ROOT'] . FILES_ROOT . $_SESSION['User'], 0777, true);
//    }
//    $ret= $_SERVER['DOCUMENT_ROOT'] . "/School/Uploads/" . $_SESSION['User'];
    //return BASE_PATH . '/Uploads/T1';
    //echo "<script type='text/javascript'>alert('$ret');</script>";
//    return $_SERVER['DOCUMENT_ROOT'] . FILES_ROOT . $_SESSION['User'] ;
//    if ($_SESSION['UserType'] == 'Admin') {
//        return $_SERVER['DOCUMENT_ROOT'] . $ret;
//    } else {
//        return $_SERVER['DOCUMENT_ROOT'] . $ret . $_SESSION['User'];
//    }
//    if ($_SERVER['DOCUMENT_ROOT'] == "C:/xampp/htdocs") {
//        return RoxyFile::FixPath($_SERVER['DOCUMENT_ROOT'] . FILES_ROOT . $_SESSION['User']);
//    } else {
//        return $_SERVER['DOCUMENT_ROOT'] . FILES_ROOT . $_SESSION['User'];
//    }

    //return $_SERVER['DOCUMENT_ROOT'] . FILES_ROOT . "Admin";
   //return $ret ;



?>

<script type="text/javascript" src="ckeditor/ckeditor.js"></script>
<!--<script type="text/javascript" src="/ckeditor/ckeditor.js"></script>-->
<!--<textarea class="ckeditor" name="editor"></textarea>-->
<!--<form method="get" id="form1" action="Test.php">
    <script>
        var roxyFileman = 'fileman/index.html?integration=ckeditor';
        $(function () {
            CKEDITOR.replace('editor1', {filebrowserBrowseUrl: roxyFileman,
                filebrowserImageBrowseUrl: roxyFileman + '&type=image',
                removeDialogTabs: 'link:upload;image:upload'});
        });
    </script>
    <textarea id="editor1" name="editor1" rows="10" cols="80"></textarea>
    <input type="submit" id="s1" name="s" />
</form>-->
<?php
if (isset($_SESSION['UserType']) == FALSE) {
    $_SESSION['UserType'] = "";
}
if ($_SESSION['UserType'] == "Admin" || $_SESSION['UserType'] == "Teacher" || $_SESSION['UserType'] == "Student") {
    ?>
    <table  border="0" align="center">
        <?php
        echo $_SESSION['User'];
        ?>
        <tr>
            <td>

                <a href="Users/Index.php"  class="SubmitButton">کنترل پانل</a>
            </td>
        </tr>
    </table>
    <?php
} else {
    ?>

    <table  border="1" cellpadding="5" cellspacing="5"  class="ViewTable" >
        <?php
        if (isset($_SESSION['LoginError'])) {
            echo "<tr><td style='color:red;'>" . $_SESSION['LoginError'] . "</td></tr>";
            unset($_SESSION['LoginError']);
        }
        ?>
        <tr>
            <td>
                <form id="form1" name="form1" method="post" action="Users/CheckLogin.php">
                    <table width="510" border="0" align="center">
                        <tr>
                            <td colspan="2">ورود به سایت</td>
                        </tr>
                        <tr>
                            <td>نام کاربری/کد ملی:</td>
                            <td><input type="text" name="username" id="username" /></td>
                        </tr>
                        <tr>
                            <td>رمز عبور:</td>
                            <td><input type="password" name="password" id="password" /></td>
                        </tr>
                        <tr>
                            <td colspan="2"><input type="submit" name="button" id="button" value="ورود" /></td>
                        </tr>
                    </table>
                </form>
            </td>
        </tr>
    </table>

    <?php
}
//echo md5("1234");
?>

<!--<table>
    <tr>
        <td>
            <a href="Admin/Login.php"  class="SubmitButton"> مدیر سایت </a>
        </td>
        <td>
            <a href="Teacher/Login.php"  class="SubmitButton"> ورود مدرس</a>
        </td>
        <td>
            <a href="Student/Login.php"  class="SubmitButton">ورود دانش آموز </a>
        </td>

    </tr>
</table>-->






<!--<form method="post">
    <textarea></textarea>
</form>-->










<?php
//$test =parse_ini_file("Config/Connection.ini",FALSE);
//print_r(parse_ini_file("Config/Connection.ini",FALSE));
//echo $test['host'];

include_once 'Template/footer.php';
?>

