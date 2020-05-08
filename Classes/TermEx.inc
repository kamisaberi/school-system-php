<?php

require_once 'Term.inc';
require_once 'ClassRoomEx.inc';

//use DataAccess;
/**
 * Description of Term
 *
 * @author kami
 */
class TermEx {

    public static function Insert(Term $term) {
        $SQL = "INSERT INTO Terms (SalShoroo,SalPayan,NimSal,Tozihat) VALUES (" . $term->SalShoroo . "," . $term->SalPayan . "," . $term->NimSal . ",'" . $term->Tozihat . "')";
        $db = new DataAccess();
        $db->Execute($SQL);
    }

    //$ts= new Term();

    public static function Update(Term $term) {
        $SQL = "UPDATE Terms SET SalShoroo = " . $term->SalShoroo . ",SalPayan = " . $term->SalPayan . ",NimSal=" . $term->NimSal . ",Tozihat='" . $term->Tozihat. "' WHERE TermId=" . $term->TermId;
        $db = new DataAccess();
        $db->Execute($SQL);
    }

    public static function Delete(Term $term) {
        if (count(ClassRoomEx::GetClassRoomsForTerm($term->TermId)) > 0) {
            return;
        }
        $SQL = "DELETE FROM Terms WHERE TermId=" . $term->TermId;
        $db = new DataAccess();
        $db->Execute($SQL);
    }

    public static function Fill() {
        $SQL = "SELECT * FROM Terms ";
        $db = new DataAccess();
        $result = $db->ExecuteSelect($SQL);
        $terms = array();
        $i = 0;
        while ($row = mysqli_fetch_array($result)) {
            //echo 'aasdas<br/>';
            $t = new Term();
            $t->TermId = $row['TermId'];
            $t->SalShoroo= $row['SalShoroo'];
            $t->SalPayan = $row['SalPayan'];
            $t->NimSal = $row['NimSal'];
            $t->Tozihat = $row['Tozihat'];
            $terms[$i] = $t;
            $i++;
        }
        return $terms;
    }

    public static function GetOnTerm($Id) {
        $SQL = "SELECT * FROM Terms WHERE TermId= " . $Id;
        $db = new DataAccess();
        $result = $db->ExecuteSelect($SQL);

        while ($row = mysqli_fetch_array($result)) {
            $t = new Term();
            $t->TermId = $row['TermId'];
            $t->SalShoroo= $row['SalShoroo'];
            $t->SalPayan = $row['SalPayan'];
            $t->NimSal = $row['NimSal'];
            $t->Tozihat = $row['Tozihat'];
            return $t;
        }
    }

    public static function AssignStudents(Term $term, $students) {
        echo $term->TermId . "<br/>";
        foreach ($students as $student) {
            echo $class . "<br/>";
            $SQL = "INSERT INTO StudentsTerms (Student,Term) VALUES (" . $term->TermId . "," . $student . ")";
            $db = new DataAccess();
            $db->Execute($SQL);
        }
    }

//put your code here
}
