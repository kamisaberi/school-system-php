<!DOCTYPE html>
use TeacherEx;
<!--
To change this license header, choose License Headers in Project Properties.
To change this template file, choose Tools | Templates
and open the template in the editor.
-->
<?php
require_once 'Classes/TeacherEx.inc';
?>
<html>
    <head>
        <meta charset="UTF-8">
        <title></title>
    </head>
    <body>
        <?php
// put your code here
//echo 'gjgjgdjhdgjhgdjhdg';
//$teacher= new TeacherEx();
//$t=new Teacher();
//$t->Name="ALIAIAIAIAIA";
//$t->Family="BBBBBBBBBBBB";
//echo $teacher->TeacherId;
//echo $teacher->Test($t);
        $s = TeacherEx::Fill();
        foreach ($s as $s1) {
            //echo 'HA<br/>';
            echo $s1->Name;
            echo '<BR />';
        }
        $url = $_SERVER['QUERY_STRING'];
        echo $url;










        $indicesServer = array('PHP_SELF',
            'argv',
            'argc',
            'GATEWAY_INTERFACE',
            'SERVER_ADDR',
            'SERVER_NAME',
            'SERVER_SOFTWARE',
            'SERVER_PROTOCOL',
            'REQUEST_METHOD',
            'REQUEST_TIME',
            'REQUEST_TIME_FLOAT',
            'QUERY_STRING',
            'DOCUMENT_ROOT',
            'HTTP_ACCEPT',
            'HTTP_ACCEPT_CHARSET',
            'HTTP_ACCEPT_ENCODING',
            'HTTP_ACCEPT_LANGUAGE',
            'HTTP_CONNECTION',
            'HTTP_HOST',
            'HTTP_REFERER',
            'HTTP_USER_AGENT',
            'HTTPS',
            'REMOTE_ADDR',
            'REMOTE_HOST',
            'REMOTE_PORT',
            'REMOTE_USER',
            'REDIRECT_REMOTE_USER',
            'SCRIPT_FILENAME',
            'SERVER_ADMIN',
            'SERVER_PORT',
            'SERVER_SIGNATURE',
            'PATH_TRANSLATED',
            'SCRIPT_NAME',
            'REQUEST_URI',
            'PHP_AUTH_DIGEST',
            'PHP_AUTH_USER',
            'PHP_AUTH_PW',
            'AUTH_TYPE',
            'PATH_INFO',
            'ORIG_PATH_INFO');

        echo '<table cellpadding="10">';
        foreach ($indicesServer as $arg) {
            if (isset($_SERVER[$arg])) {
                echo '<tr><td>' . $arg . '</td><td>' . $_SERVER[$arg] . '</td></tr>';
            } else {
                echo '<tr><td>' . $arg . '</td><td>-</td></tr>';
            }
        }
        echo '</table>';
        ?>










    </body>
</html>
