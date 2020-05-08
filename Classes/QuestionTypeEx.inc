<?php

require_once  'QuestionType.inc';
require_once 'ClassRoomEx.inc';

//use DataAccess;
/**
 * Description of QuestionType
 *
 * @author kami
 */
class QuestionTypeEx {

    public static function Insert(QuestionType $questionType) {
        $SQL = "INSERT INTO QuestionTypes (Name,Tozihat) VALUES ('" . $questionType->Name . "','" . $questionType->Tozihat . "')";
        $db = new DataAccess();
        $db->Execute($SQL);
    }

    //$ts= new QuestionType();

    public static function Update(QuestionType $questionType) {
        $SQL = "UPDATE QuestionTypes SET Name = '" . $questionType->Name . "',Tozihat='" . $questionType->Tozihat . "'  WHERE QuestionTypeId=" . $questionType->QuestionTypeId;
        //echo $SQL;
        $db = new DataAccess();
        $db->Execute($SQL);
    }

    public static function Delete(QuestionType $questionType) {
        if (count(ClassRoomEx::GetClassRoomsForQuestionType($questionType->QuestionTypeId)) > 0) {
            return;
        }
        $SQL = "DELETE FROM QuestionTypes WHERE QuestionTypeId=" . $questionType->QuestionTypeId;
        $db = new DataAccess();
        $db->Execute($SQL);
    }

    public static function Fill() {
        $SQL = "SELECT * FROM QuestionTypes ";
        //echo $SQL;
        $db = new DataAccess();
        $result = $db->ExecuteSelect($SQL);
        $questionTypes = array();
        $i = 0;
        while ($row = mysqli_fetch_array($result)) {
            //echo 'aasdas<br/>';
            $t = new QuestionType();
            $t->QuestionTypeId = $row['QuestionTypeId'];
            $t->Name = $row['Name'];
            $t->Tozihat = $row['Tozihat'];
            $questionTypes[$i] = $t;
            $i++;
        }
        return $questionTypes;
    }

    public static function GetOnQuestionType($Id) {
        $SQL = "SELECT * FROM QuestionTypes WHERE QuestionTypeId= " . $Id;
        $db = new DataAccess();
        $result = $db->ExecuteSelect($SQL);

        while ($row = mysqli_fetch_array($result)) {
            $t = new QuestionType();
            $t->QuestionTypeId = $row['QuestionTypeId'];
            $t->Name = $row['Name'];
            $t->Tozihat = $row['Tozihat'];
            return $t;
        }
    }

//put your code here
}
