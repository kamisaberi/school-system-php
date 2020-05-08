<?php

require_once 'GradeValue.inc';

//use DataAccess;
/**
 * Description of GradeValue
 *
 * @author kami
 */
class GradeValueEx {

    public static function Insert(GradeValue $gradeValue) {
        $SQL = "INSERT INTO GradeValues (Value,GradeType) VALUES ('" . $gradeValue->Value . "'," . $gradeValue->GradeType->GradeTypeId . ")";
        $db = new DataAccess();
        $db->Execute($SQL);
    }

    //$ts= new GradeValue();

    public static function Update(GradeValue $gradeValue) {
        $SQL = "UPDATE GradeValues SET Value = '" . $gradeValue->Value . "',GradeType = " . $gradeValue->GradeType->GradeTypeId . "  WHERE GradeValueId=" . $gradeValue->GradeValueId;
        $db = new DataAccess();
        echo $SQL;
        $db->Execute($SQL);
    }

    public static function Delete(GradeValue $gradeValue) {
        $SQL = "DELETE FROM GradeValues WHERE GradeValueId=" . $gradeValue->GradeValueId;
        $db = new DataAccess();
        $db->Execute($SQL);
    }

    public static function Fill() {
        $SQL = "SELECT
GradeValues.`Value` AS `GradeValue.Value`,
GradeValues.GradeValueId AS `GradeValue.GradeValueId`,
GradeTypes.GradeTypeId AS `GradeType.GradeTypeId`,
GradeTypes.`Name` AS `GradeType.Name`,
GradeTypes.Min AS `GradeType.Min`,
GradeTypes.Max AS `GradeType.Max`,
GradeTypes.Pass AS `GradeType.Pass`
FROM
GradeValues
INNER JOIN GradeTypes ON GradeTypes.GradeTypeId = GradeValues.GradeType ";
        $db = new DataAccess();
        $result = $db->ExecuteSelect($SQL);
        $gradeValues = array();
        $i = 0;
        while ($row = mysqli_fetch_array($result)) {
            //echo 'aasdas<br/>';
            $t = new GradeValue();
            $t->GradeValueId = $row['GradeValue.GradeValueId'];
            $t->Value = $row['GradeValue.Value'];

            $gradeType = new GradeType();
            $gradeType->GradeTypeId = $row['GradeType.GradeTypeId'];
            $gradeType->Name = $row['GradeType.Name'];
            $gradeType->Min = $row['GradeType.Min'];
            $gradeType->Max = $row['GradeType.Max'];
            $gradeType->Max = $row['GradeType.Pass'];
            $t->GradeType = $gradeType;

            $gradeValues[$i] = $t;
            $i++;
        }
        return $gradeValues;
    }

    public static function GetGradeValuesBasedOnGradeTypeId($typeId) {
        $SQL = "SELECT
GradeValues.`Value` AS `GradeValue.Value`,
GradeValues.GradeValueId AS `GradeValue.GradeValueId`,
GradeTypes.GradeTypeId AS `GradeType.GradeTypeId`,
GradeTypes.`Name` AS `GradeType.Name`,
GradeTypes.Min AS `GradeType.Min`,
GradeTypes.Max AS `GradeType.Max`,
GradeTypes.Pass AS `GradeType.Pass`
FROM
GradeValues
INNER JOIN GradeTypes ON GradeTypes.GradeTypeId = GradeValues.GradeType WHERE GradeTypes.GradeTypeId= " . $typeId;
        $db = new DataAccess();
        $result = $db->ExecuteSelect($SQL);
        $gradeValues = array();
        $i = 0;
        while ($row = mysqli_fetch_array($result)) {
            //echo 'aasdas<br/>';
            $t = new GradeValue();
            $t->GradeValueId = $row['GradeValue.GradeValueId'];
            $t->Value = $row['GradeValue.Value'];

            $gradeType = new GradeType();
            $gradeType->GradeTypeId = $row['GradeType.GradeTypeId'];
            $gradeType->Name = $row['GradeType.Name'];
            $gradeType->Min = $row['GradeType.Min'];
            $gradeType->Max = $row['GradeType.Max'];
            $gradeType->Max = $row['GradeType.Pass'];
            $t->GradeType = $gradeType;

            $gradeValues[$i] = $t;
            $i++;
        }
        return $gradeValues;
    }

    public static function GetOnGradeValue($Id) {
        $SQL = "SELECT
GradeValues.`Value` AS `GradeValue.Value`,
GradeValues.GradeValueId AS `GradeValue.GradeValueId`,
GradeTypes.GradeTypeId AS `GradeType.GradeTypeId`,
GradeTypes.`Name` AS `GradeType.Name`,
GradeTypes.Min AS `GradeType.Min`,
GradeTypes.Max AS `GradeType.Max`,
GradeTypes.Pass AS `GradeType.Pass`
FROM
GradeValues
INNER JOIN GradeTypes ON GradeTypes.GradeTypeId = GradeValues.GradeType WHERE GradeValueId= " . $Id;
        $db = new DataAccess();
        $result = $db->ExecuteSelect($SQL);

        while ($row = mysqli_fetch_array($result)) {
            $t = new GradeValue();
            $t->GradeValueId = $row['GradeValue.GradeValueId'];
            $t->Value = $row['GradeValue.Value'];

            $gradeType = new GradeType();
            $gradeType->GradeTypeId = $row['GradeType.GradeTypeId'];
            $gradeType->Name = $row['GradeType.Name'];
            $gradeType->Min = $row['GradeType.Min'];
            $gradeType->Max = $row['GradeType.Max'];
            $gradeType->Max = $row['GradeType.Pass'];
            $t->GradeType = $gradeType;

            return $t;
        }
    }

//put your code here
}
