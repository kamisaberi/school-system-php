<?php

require_once  'Lecture.inc';
require_once 'ClassRoomEx.inc';

//use DataAccess;
/**
 * Description of Lecture
 *
 * @author kami
 */
class LectureEx {

    public static function Insert(Lecture $lecture) {
        $SQL = "INSERT INTO Lectures (Name,TedadVahed,Tozihat) VALUES ('" . $lecture->Name . "'," . $lecture->TedadVahed . ",'" . $lecture->Tozihat . "')";
        $db = new DataAccess();
        $db->Execute($SQL);
    }

    //$ts= new Lecture();

    public static function Update(Lecture $lecture) {
        $SQL = "UPDATE Lectures SET Name = '" . $lecture->Name . "',TedadVahed = " . $lecture->TedadVahed . ",Tozihat='" . $lecture->Tozihat . "'  WHERE LectureId=" . $lecture->LectureId;
        //echo $SQL;
        $db = new DataAccess();
        $db->Execute($SQL);
    }

    public static function Delete(Lecture $lecture) {
        if (count(ClassRoomEx::GetClassRoomsForLecture($lecture->LectureId)) > 0) {
            return;
        }
        $SQL = "DELETE FROM Lectures WHERE LectureId=" . $lecture->LectureId;
        $db = new DataAccess();
        $db->Execute($SQL);
    }

    function Test(Lecture $lecture) {
        $s = array();
        $t = new Lecture();
        $t->Name = "ali";
        $s[0] = $t;
        $t1 = new Lecture();
        $t1->Name = "reza";
        $s[1] = $t1;
        return $s;
    }

    public static function Fill() {
        $SQL = "SELECT * FROM Lectures ";
        $db = new DataAccess();
        $result = $db->ExecuteSelect($SQL);
        $lectures = array();
        $i = 0;
        while ($row = mysqli_fetch_array($result)) {
            //echo 'aasdas<br/>';
            $t = new Lecture();
            $t->LectureId = $row['LectureId'];
            $t->Name = $row['Name'];
            $t->TedadVahed = $row['TedadVahed'];
            $t->Tozihat = $row['Tozihat'];
            $lectures[$i] = $t;
            $i++;
        }
        return $lectures;
    }

    public static function GetOnLecture($Id) {
        $SQL = "SELECT * FROM Lectures WHERE LectureId= " . $Id;
        $db = new DataAccess();
        $result = $db->ExecuteSelect($SQL);

        while ($row = mysqli_fetch_array($result)) {
            $t = new Lecture();
            $t->LectureId = $row['LectureId'];
            $t->Name = $row['Name'];
            $t->TedadVahed = $row['TedadVahed'];
            $t->Tozihat = $row['Tozihat'];
            return $t;
        }
    }

//put your code here
}
