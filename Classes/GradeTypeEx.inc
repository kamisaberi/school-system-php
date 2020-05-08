<?php

require_once 'GradeType.inc';
require_once 'ClassRoomEx.inc';

//use DataAccess;
/**
 * Description of GradeType
 *
 * @author kami
 */
class GradeTypeEx {

    public static function Insert(GradeType $gradeType) {
        $SQL = "INSERT INTO GradeTypes (Name,Min,Max,Pass,DefinedValues) VALUES  ('" . $gradeType->Name . "','" . $gradeType->Min . "','" . $gradeType->Max . "','" . $gradeType->Pass . "'," . ($gradeType->DefinedValues==TRUE ? 1 : 0) . ")";
        $db = new DataAccess();
        $db->Execute($SQL);
    }

    //$ts= new GradeType();

    public static function Update(GradeType $gradeType) {
        $SQL = "UPDATE GradeTypes SET Name = '" . $gradeType->Name . "',Min = '" . $gradeType->Min . "',Max='" . $gradeType->Max . "',Pass= '" . $gradeType->Pass . "' WHERE GradeTypeId=" . $gradeType->GradeTypeId;
        echo $SQL;
        $db = new DataAccess();
        echo $SQL;
        $db->Execute($SQL);
    }

    public static function Delete(GradeType $gradeType) {
        if (count(ClassRoomEx::GetClassRoomsForGradeType($teacher->TeacherId)) > 0) {
            return;
        }
        $SQL = "DELETE FROM GradeTypes WHERE GradeTypeId=" . $gradeType->GradeTypeId;
        $db = new DataAccess();
        $db->Execute($SQL);
    }

    public static function Fill() {
        $SQL = "SELECT * FROM GradeTypes ";
        $db = new DataAccess();
        $result = $db->ExecuteSelect($SQL);
        $gradeTypes = array();
        $i = 0;
        while ($row = mysqli_fetch_array($result)) {
            //echo 'aasdas<br/>';
            $t = new GradeType();
            $t->GradeTypeId = $row['GradeTypeId'];
            $t->Name = $row['Name'];
            $t->Min = $row['Min'];
            $t->Max = $row['Max'];
            $t->Pass = $row['Pass'];
            $t->DefinedValues = $row['DefinedValues'];
            $gradeTypes[$i] = $t;
            $i++;
        }
        return $gradeTypes;
    }

    public static function GetOnGradeType($Id) {
        $SQL = "SELECT * FROM GradeTypes WHERE GradeTypeId= " . $Id;
        $db = new DataAccess();
        $result = $db->ExecuteSelect($SQL);

        while ($row = mysqli_fetch_array($result)) {
            $t = new GradeType();
            $t->GradeTypeId = $row['GradeTypeId'];
            $t->Name = $row['Name'];
            $t->Min = $row['Min'];
            $t->Max = $row['Max'];
            $t->Pass = $row['Pass'];
            return $t;
        }
    }

//put your code here
}
