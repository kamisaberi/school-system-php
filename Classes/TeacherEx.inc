<?php

require_once  'Teacher.inc';
require_once  'ClassRoomEx.inc';
//use DataAccess;
/**
 * Description of Teacher
 *
 * @author kami
 */
class TeacherEx {

    public static function Insert(Teacher $teacher) {
        $SQL = "INSERT INTO Teachers (Name,Family,Username,Passwd,CodeMelli) VALUES ('" . $teacher->Name . "','" . $teacher->Family . "','" . $teacher->Username . "','" . md5($teacher->Passwd) . "','" . $teacher->CodeMelli        . "')";
        echo $SQL;
        $db = new DataAccess();
        $db->Execute($SQL);
    }

    //$ts= new Teacher();

    public static function Update(Teacher $teacher) {
        $SQL = "UPDATE Teachers SET Name = '" . $teacher->Name . "',Family = '" . $teacher->Family . "',Username='" . $teacher->Username . "',Passwd= '" . md5($teacher->Passwd) . "', CodeMelli ='" . $teacher->CodeMelli . "' WHERE TeacherId=" . $teacher->TeacherId;
        $db = new DataAccess();
        echo $SQL;
        $db->Execute($SQL);
    }

    public static function Delete(Teacher $teacher) {
        if (count(ClassRoomEx::GetClassRoomsForTeacher($teacher->TeacherId)) > 0) {
            return;
        }
        $SQL = "DELETE FROM Teachers WHERE TeacherId=" . $teacher->TeacherId;
        $db = new DataAccess();
        $db->Execute($SQL);
    }

    function Test(Teacher $teacher) {
        $s = array();
        $t = new Teacher();
        $t->Name = "ali";
        $s[0] = $t;
        $t1 = new Teacher();
        $t1->Name = "reza";
        $s[1] = $t1;
        return $s;
    }

    public static function Fill() {
        $SQL = "SELECT * FROM Teachers ";
        $db = new DataAccess();
        $result = $db->ExecuteSelect($SQL);
        $teachers = array();
        $i = 0;
        while ($row = mysqli_fetch_array($result)) {
            //echo 'aasdas<br/>';
            $t = new Teacher();
            $t->TeacherId = $row['TeacherId'];
            $t->Name = $row['Name'];
            $t->Family = $row['Family'];
            $t->Username = $row['Username'];
            $t->Passwd = $row['Passwd'];
            $t->CodeMelli = $row['CodeMelli'];
            $teachers[$i] = $t;
            $i++;
        }
        return $teachers;
    }

    public static function GetOnTeacher($Id) {
        $SQL = "SELECT * FROM Teachers WHERE TeacherId= " . $Id;
        $db = new DataAccess();
        $result = $db->ExecuteSelect($SQL);

        while ($row = mysqli_fetch_array($result)) {
            $t = new Teacher();
            $t->TeacherId = $row['TeacherId'];
            $t->Name = $row['Name'];
            $t->Family = $row['Family'];
            $t->Username = $row['Username'];
            $t->Passwd = $row['Passwd'];
            $t->CodeMelli = $row['CodeMelli'];
            return $t;
        }
    }

        public static function GetOnTeacherBasedOnUsername($Id) {
        $SQL = "SELECT * FROM Teachers WHERE Username= '" . $Id ."'";
        $db = new DataAccess();
        $result = $db->ExecuteSelect($SQL);

        while ($row = mysqli_fetch_array($result)) {
            $t = new Teacher();
            $t->TeacherId = $row['TeacherId'];
            $t->Name = $row['Name'];
            $t->Family = $row['Family'];
            $t->Username = $row['Username'];
            $t->Passwd = $row['Passwd'];
            $t->CodeMelli = $row['CodeMelli'];
            return $t;
        }
    }

    public static function Login($username, $password) {
        $SQL = "SELECT * FROM Teachers WHERE Username= '" . $username . "' AND Passwd='" . md5($password) . "'";
        //echo $SQL;
        $db = new DataAccess();
        $result = $db->ExecuteSelect($SQL);
        if (mysqli_num_rows($result) > 0)
            return TRUE;
        return FALSE;
    }

    
    

    
    
//put your code here
}
