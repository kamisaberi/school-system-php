<?php

require_once  'QuestionChoice.inc';
require_once 'ClassRoomEx.inc';

//use DataAccess;
/**
 * Description of QuestionChoice
 *
 * @author kami
 */
class QuestionChoiceEx {

    public static function Insert(QuestionChoice $questionChoice) {
        $SQL = "INSERT INTO QuestionChoices (Name,TedadVahed,Tozihat) VALUES ('" . $questionChoice->Name . "'," . $questionChoice->TedadVahed . ",'" . $questionChoice->Tozihat . "')";
        $db = new DataAccess();
        $db->Execute($SQL);
    }

    //$ts= new QuestionChoice();

    public static function Update(QuestionChoice $questionChoice) {
        $SQL = "UPDATE QuestionChoices SET Name = '" . $questionChoice->Name . "',TedadVahed = " . $questionChoice->TedadVahed . ",Tozihat='" . $questionChoice->Tozihat . "'  WHERE QuestionChoiceId=" . $questionChoice->QuestionChoiceId;
        //echo $SQL;
        $db = new DataAccess();
        $db->Execute($SQL);
    }

    public static function Delete(QuestionChoice $questionChoice) {
        if (count(ClassRoomEx::GetClassRoomsForQuestionChoice($questionChoice->QuestionChoiceId)) > 0) {
            return;
        }
        $SQL = "DELETE FROM QuestionChoices WHERE QuestionChoiceId=" . $questionChoice->QuestionChoiceId;
        $db = new DataAccess();
        $db->Execute($SQL);
    }

    function Test(QuestionChoice $questionChoice) {
        $s = array();
        $t = new QuestionChoice();
        $t->Name = "ali";
        $s[0] = $t;
        $t1 = new QuestionChoice();
        $t1->Name = "reza";
        $s[1] = $t1;
        return $s;
    }

    public static function Fill() {
        $SQL = "SELECT * FROM QuestionChoices ";
        $db = new DataAccess();
        $result = $db->ExecuteSelect($SQL);
        $questionChoices = array();
        $i = 0;
        while ($row = mysqli_fetch_array($result)) {
            //echo 'aasdas<br/>';
            $t = new QuestionChoice();
            $t->QuestionChoiceId = $row['QuestionChoiceId'];
            $t->Name = $row['Name'];
            $t->TedadVahed = $row['TedadVahed'];
            $t->Tozihat = $row['Tozihat'];
            $questionChoices[$i] = $t;
            $i++;
        }
        return $questionChoices;
    }

    public static function GetOnQuestionChoice($Id) {
        $SQL = "SELECT * FROM QuestionChoices WHERE QuestionChoiceId= " . $Id;
        $db = new DataAccess();
        $result = $db->ExecuteSelect($SQL);

        while ($row = mysqli_fetch_array($result)) {
            $t = new QuestionChoice();
            $t->QuestionChoiceId = $row['QuestionChoiceId'];
            $t->Name = $row['Name'];
            $t->TedadVahed = $row['TedadVahed'];
            $t->Tozihat = $row['Tozihat'];
            return $t;
        }
    }

//put your code here
}
