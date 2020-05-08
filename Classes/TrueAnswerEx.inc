<?php

require_once  'TrueAnswer.inc';
require_once 'ClassRoomEx.inc';

//use DataAccess;
/**
 * Description of TrueAnswer
 *
 * @author kami
 */
class TrueAnswerEx {

    public static function Insert(TrueAnswer $trueAnswer) {
        $SQL = "INSERT INTO TrueAnswers (Name,TedadVahed,Tozihat) VALUES ('" . $trueAnswer->Name . "'," . $trueAnswer->TedadVahed . ",'" . $trueAnswer->Tozihat . "')";
        $db = new DataAccess();
        $db->Execute($SQL);
    }

    //$ts= new TrueAnswer();

    public static function Update(TrueAnswer $trueAnswer) {
        $SQL = "UPDATE TrueAnswers SET Name = '" . $trueAnswer->Name . "',TedadVahed = " . $trueAnswer->TedadVahed . ",Tozihat='" . $trueAnswer->Tozihat . "'  WHERE TrueAnswerId=" . $trueAnswer->TrueAnswerId;
        //echo $SQL;
        $db = new DataAccess();
        $db->Execute($SQL);
    }

    public static function Delete(TrueAnswer $trueAnswer) {
        if (count(ClassRoomEx::GetClassRoomsForTrueAnswer($trueAnswer->TrueAnswerId)) > 0) {
            return;
        }
        $SQL = "DELETE FROM TrueAnswers WHERE TrueAnswerId=" . $trueAnswer->TrueAnswerId;
        $db = new DataAccess();
        $db->Execute($SQL);
    }

    function Test(TrueAnswer $trueAnswer) {
        $s = array();
        $t = new TrueAnswer();
        $t->Name = "ali";
        $s[0] = $t;
        $t1 = new TrueAnswer();
        $t1->Name = "reza";
        $s[1] = $t1;
        return $s;
    }

    public static function Fill() {
        $SQL = "SELECT * FROM TrueAnswers ";
        $db = new DataAccess();
        $result = $db->ExecuteSelect($SQL);
        $trueAnswers = array();
        $i = 0;
        while ($row = mysqli_fetch_array($result)) {
            //echo 'aasdas<br/>';
            $t = new TrueAnswer();
            $t->TrueAnswerId = $row['TrueAnswerId'];
            $t->Name = $row['Name'];
            $t->TedadVahed = $row['TedadVahed'];
            $t->Tozihat = $row['Tozihat'];
            $trueAnswers[$i] = $t;
            $i++;
        }
        return $trueAnswers;
    }

    public static function GetOnTrueAnswer($Id) {
        $SQL = "SELECT * FROM TrueAnswers WHERE TrueAnswerId= " . $Id;
        $db = new DataAccess();
        $result = $db->ExecuteSelect($SQL);

        while ($row = mysqli_fetch_array($result)) {
            $t = new TrueAnswer();
            $t->TrueAnswerId = $row['TrueAnswerId'];
            $t->Name = $row['Name'];
            $t->TedadVahed = $row['TedadVahed'];
            $t->Tozihat = $row['Tozihat'];
            return $t;
        }
    }

//put your code here
}
