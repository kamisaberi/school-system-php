<?php

require_once 'ClassRoom.inc';
require_once 'GradeEx.inc';
require_once 'DataAccess.inc';

//use DataAccess;
/**
 * Description of ClassRoom
 *
 * @author kami
 */
class ClassRoomEx {

    public static function Insert(ClassRoom $classRoom) {
        $SQL = "INSERT INTO ClassRooms (Name,Term,Lecture,Saal,Teacher,GradeType) VALUES ('" . $classRoom->Name . "'," . $classRoom->Term->TermId . "," . $classRoom->Lecture->LectureId . "," . $classRoom->Saal . "," . $classRoom->Teacher->TeacherId . "," . $classRoom->GradeType->GradeTypeId . ")";
        echo $SQL;
        $db = new DataAccess();
        $db->Execute($SQL);
    }

    //$ts= new ClassRoom();

    public static function Update(ClassRoom $classRoom) {
        $SQL = "UPDATE ClassRooms SET Name = '" . $classRoom->Name . "',Term = " . $classRoom->Term->TermId . ",Lecture=" . $classRoom->Lecture->LectureId . ",Saal= " . $classRoom->Saal . ",Teacher=" . $classRoom->Teacher->TeacherId . ",GradeType=" . $classRoom->GradeType->GradeTypeId . " WHERE ClassRoomId=" . $classRoom->ClassRoomId;
        $db = new DataAccess();
        echo $SQL;
        $db->Execute($SQL);
    }

    public static function Delete(ClassRoom $classRoom) {

        if (count(GradeEx::GetGradesForClassroom($classRoom->ClassRoomId)) > 0) {
            return;
        }
        $SQL = "DELETE FROM ClassRooms WHERE ClassRoomId=" . $classRoom->ClassRoomId;
        $db = new DataAccess();
        $db->Execute($SQL);
    }

    public static function Fill() {
        $SQL = "SELECT
ClassRooms.ClassRoomId AS `ClassRoom.ClassRoomId`,
ClassRooms.`Name` AS `ClassRoom.Name`,
ClassRooms.Saal AS `ClassRoom.Saal`,
Terms.TermId AS `Term.TermId`,
Terms.SalShoroo AS `Term.SalShoroo`,
Terms.SalPayan AS `Term.SalPayan`,
Terms.NimSal AS `Term.NimSal`,
Terms.Tozihat AS `Term.Tozihat`,
Teachers.TeacherId AS `Teacher.TeacherId`,
Teachers.`Name` AS `Teacher.Name`,
Teachers.Family AS `Teacher.Family`,
Teachers.Username AS `Teacher.Username`,
Teachers.CodeMelli AS `Teacher.CodeMelli`,
Teachers.Passwd AS `Teacher.Passwd`,
Lectures.LectureId AS `Lecture.LectureId`,
Lectures.`Name` AS `Lecture.Name`,
Lectures.TedadVahed AS `Lecture.TedadVahed`,
Lectures.Tozihat AS `Lecture.Tozihat`,
GradeTypes.GradeTypeId AS `GradeType.GradeTypeId` ,
GradeTypes.`Name` AS `GradeType.Name` ,
GradeTypes.Min AS `GradeType.Min`,
GradeTypes.Max AS `GradeType.Max`,
GradeTypes.Pass AS `GradeType.Pass` ,
GradeTypes.DefinedValues AS `GradeType.DefinedValues`
FROM
ClassRooms
INNER JOIN Teachers ON Teachers.TeacherId = ClassRooms.Teacher
INNER JOIN Terms ON Terms.TermId = ClassRooms.Term
INNER JOIN Lectures ON Lectures.LectureId = ClassRooms.Lecture
INNER JOIN GradeTypes ON GradeTypes.GradeTypeId = ClassRooms.GradeType

 ";
        $db = new DataAccess();
        $result = $db->ExecuteSelect($SQL);
        $classRooms = array();
        $i = 0;
        while ($row = mysqli_fetch_array($result)) {
            //echo 'aasdas<br/>';
            $classroom = new ClassRoom();
            $classroom->ClassRoomId = $row['ClassRoom.ClassRoomId'];
            $classroom->Name = $row['ClassRoom.Name'];
            $classroom->Saal = $row['ClassRoom.Saal'];
            $term = new Term();
            $term->TermId = $row['Term.TermId'];
            $term->SalShoroo = $row['Term.SalShoroo'];
            $term->SalPayan = $row['Term.SalPayan'];
            $term->NimSal = $row['Term.NimSal'];
            $term->Tozihat = $row['Term.Tozihat'];
            $classroom->Term = $term;

            $lecture = new Lecture();
            $lecture->LectureId = $row['Lecture.LectureId'];
            $lecture->Name = $row['Lecture.Name'];
            $lecture->TedadVahed = $row['Lecture.TedadVahed'];
            $lecture->Tozihat = $row['Lecture.Tozihat'];
            $classroom->Lecture = $lecture;

            $teacher = new Teacher();
            $teacher->TeacherId = $row['Teacher.TeacherId'];
            $teacher->Name = $row['Teacher.Name'];
            $teacher->Family = $row['Teacher.Family'];
            $teacher->Username = $row['Teacher.Username'];
            $teacher->CodeMelli = $row['Teacher.CodeMelli'];
            $teacher->Passwd = $row['Teacher.Passwd'];
            $classroom->Teacher = $teacher;


            $gradeType = new GradeType();
            $gradeType->GradeTypeId = $row['GradeType.GradeTypeId'];
            $gradeType->Name = $row['GradeType.Name'];
            $gradeType->Min = $row['GradeType.Min'];
            $gradeType->Max = $row['GradeType.Max'];
            $gradeType->Pass = $row['GradeType.Pass'];
            $gradeType->DefinedValues = $row['GradeType.DefinedValues'];
            $classroom->GradeType = $gradeType;



            $classRooms[$i] = $classroom;
            $i++;
        }
        return $classRooms;
    }

    public static function GetOnClassRoom($Id) {
        $SQL = "SELECT
ClassRooms.ClassRoomId AS `ClassRoom.ClassRoomId`,
ClassRooms.`Name` AS `ClassRoom.Name`,
ClassRooms.Saal AS `ClassRoom.Saal`,
Terms.TermId AS `Term.TermId`,
Terms.SalShoroo AS `Term.SalShoroo`,
Terms.SalPayan AS `Term.SalPayan`,
Terms.NimSal AS `Term.NimSal`,
Terms.Tozihat AS `Term.Tozihat`,
Teachers.TeacherId AS `Teacher.TeacherId`,
Teachers.`Name` AS `Teacher.Name`,
Teachers.Family AS `Teacher.Family`,
Teachers.Username AS `Teacher.Username`,
Teachers.Passwd AS `Teacher.Passwd`,
Lectures.LectureId AS `Lecture.LectureId`,
Lectures.`Name` AS `Lecture.Name`,
Lectures.TedadVahed AS `Lecture.TedadVahed`,
Lectures.Tozihat AS `Lecture.Tozihat`,
GradeTypes.GradeTypeId AS `GradeType.GradeTypeId` ,
GradeTypes.`Name` AS `GradeType.Name` ,
GradeTypes.Min AS `GradeType.Min`,
GradeTypes.Max AS `GradeType.Max`,
GradeTypes.Pass AS `GradeType.Pass` ,
GradeTypes.DefinedValues AS `GradeType.DefinedValues` 
FROM
ClassRooms
INNER JOIN Teachers ON Teachers.TeacherId = ClassRooms.Teacher
INNER JOIN Terms ON Terms.TermId = ClassRooms.Term
INNER JOIN Lectures ON Lectures.LectureId = ClassRooms.Lecture
INNER JOIN GradeTypes ON GradeTypes.GradeTypeId = ClassRooms.GradeType

  WHERE ClassRoomId= " . $Id;
        $db = new DataAccess();
        $result = $db->ExecuteSelect($SQL);

        while ($row = mysqli_fetch_array($result)) {
            $classroom = new ClassRoom();
            $classroom->ClassRoomId = $row['ClassRoom.ClassRoomId'];
            $classroom->Name = $row['ClassRoom.Name'];
            $classroom->Saal = $row['ClassRoom.Saal'];
            $term = new Term();
            $term->TermId = $row['Term.TermId'];
            $term->SalShoroo = $row['Term.SalShoroo'];
            $term->SalPayan = $row['Term.SalPayan'];
            $term->NimSal = $row['Term.NimSal'];
            $term->Tozihat = $row['Term.Tozihat'];
            $classroom->Term = $term;

            $lecture = new Lecture();
            $lecture->LectureId = $row['Lecture.LectureId'];
            $lecture->Name = $row['Lecture.Name'];
            $lecture->TedadVahed = $row['Lecture.TedadVahed'];
            $lecture->Tozihat = $row['Lecture.Tozihat'];
            $classroom->Lecture = $lecture;

            $teacher = new Teacher();
            $teacher->TeacherId = $row['Teacher.TeacherId'];
            $teacher->Name = $row['Teacher.Name'];
            $teacher->Family = $row['Teacher.Family'];
            $teacher->Username = $row['Teacher.Username'];
            $teacher->Passwd = $row['Teacher.Passwd'];
            $classroom->Teacher = $teacher;

            $gradeType = new GradeType();
            $gradeType->GradeTypeId = $row['GradeType.GradeTypeId'];
            $gradeType->Name = $row['GradeType.Name'];
            $gradeType->Min = $row['GradeType.Min'];
            $gradeType->Max = $row['GradeType.Max'];
            $gradeType->Pass = $row['GradeType.Pass'];
            $gradeType->DefinedValues = $row['GradeType.DefinedValues'];
            $classroom->GradeType = $gradeType;


            //$classRooms[$i] = $classroom;
            return $classroom;
        }
    }

    public static function GetClassRoomsForTeacher($teacherId) {
        $SQL = "SELECT
ClassRooms.ClassRoomId AS `ClassRoom.ClassRoomId`,
ClassRooms.`Name` AS `ClassRoom.Name`,
ClassRooms.Saal AS `ClassRoom.Saal`,
Terms.TermId AS `Term.TermId`,
Terms.SalShoroo AS `Term.SalShoroo`,
Terms.SalPayan AS `Term.SalPayan`,
Terms.NimSal AS `Term.NimSal`,
Terms.Tozihat AS `Term.Tozihat`,
Teachers.TeacherId AS `Teacher.TeacherId`,
Teachers.`Name` AS `Teacher.Name`,
Teachers.Family AS `Teacher.Family`,
Teachers.Username AS `Teacher.Username`,
Teachers.Passwd AS `Teacher.Passwd`,
Lectures.LectureId AS `Lecture.LectureId`,
Lectures.`Name` AS `Lecture.Name`,
Lectures.TedadVahed AS `Lecture.TedadVahed`,
Lectures.Tozihat AS `Lecture.Tozihat`,
GradeTypes.GradeTypeId AS `GradeType.GradeTypeId` ,
GradeTypes.`Name` AS `GradeType.Name` ,
GradeTypes.Min AS `GradeType.Min`,
GradeTypes.Max AS `GradeType.Max`,
GradeTypes.Pass AS `GradeType.Pass` ,
GradeTypes.DefinedValues AS `GradeType.DefinedValues`

FROM
ClassRooms
INNER JOIN Teachers ON Teachers.TeacherId = ClassRooms.Teacher
INNER JOIN Terms ON Terms.TermId = ClassRooms.Term
INNER JOIN Lectures ON Lectures.LectureId = ClassRooms.Lecture
INNER JOIN GradeTypes ON GradeTypes.GradeTypeId = ClassRooms.GradeType
WHERE ClassRooms.Teacher = " . $teacherId;
        $db = new DataAccess();
        $result = $db->ExecuteSelect($SQL);
        $classRooms = array();
        $i = 0;
        while ($row = mysqli_fetch_array($result)) {
            //echo 'aasdas<br/>';
            $classroom = new ClassRoom();
            $classroom->ClassRoomId = $row['ClassRoom.ClassRoomId'];
            $classroom->Name = $row['ClassRoom.Name'];
            $classroom->Saal = $row['ClassRoom.Saal'];
            $term = new Term();
            $term->TermId = $row['Term.TermId'];
            $term->SalShoroo = $row['Term.SalShoroo'];
            $term->SalPayan = $row['Term.SalPayan'];
            $term->NimSal = $row['Term.NimSal'];
            $term->Tozihat = $row['Term.Tozihat'];
            $classroom->Term = $term;

            $lecture = new Lecture();
            $lecture->LectureId = $row['Lecture.LectureId'];
            $lecture->Name = $row['Lecture.Name'];
            $lecture->TedadVahed = $row['Lecture.TedadVahed'];
            $lecture->Tozihat = $row['Lecture.Tozihat'];
            $classroom->Lecture = $lecture;

            $teacher = new Teacher();
            $teacher->TeacherId = $row['Teacher.TeacherId'];
            $teacher->Name = $row['Teacher.Name'];
            $teacher->Family = $row['Teacher.Family'];
            $teacher->Username = $row['Teacher.Username'];
            $teacher->Passwd = $row['Teacher.Passwd'];
            $classroom->Teacher = $teacher;


            $gradeType = new GradeType();
            $gradeType->GradeTypeId = $row['GradeType.GradeTypeId'];
            $gradeType->Name = $row['GradeType.Name'];
            $gradeType->Min = $row['GradeType.Min'];
            $gradeType->Max = $row['GradeType.Max'];
            $gradeType->Pass = $row['GradeType.Pass'];
            $gradeType->DefinedValues = $row['GradeType.DefinedValues'];
            $classroom->GradeType = $gradeType;



            $classRooms[$i] = $classroom;
            $i++;
        }
        return $classRooms;
    }

    public static function GetClassRoomsForExam($examId, $teacherId = 0) {
        $SQL = "SELECT
ClassRooms.ClassRoomId AS `ClassRoom.ClassRoomId`,
ClassRooms.`Name` AS `ClassRoom.Name`,
ClassRooms.Saal AS `ClassRoom.Saal`,
Terms.TermId AS `Term.TermId`,
Terms.SalShoroo AS `Term.SalShoroo`,
Terms.SalPayan AS `Term.SalPayan`,
Terms.NimSal AS `Term.NimSal`,
Terms.Tozihat AS `Term.Tozihat`,
Teachers.TeacherId AS `Teacher.TeacherId`,
Teachers.`Name` AS `Teacher.Name`,
Teachers.Family AS `Teacher.Family`,
Teachers.Username AS `Teacher.Username`,
Teachers.Passwd AS `Teacher.Passwd`,
Lectures.LectureId AS `Lecture.LectureId`,
Lectures.`Name` AS `Lecture.Name`,
Lectures.TedadVahed AS `Lecture.TedadVahed`,
Lectures.Tozihat AS `Lecture.Tozihat`,
GradeTypes.GradeTypeId AS `GradeType.GradeTypeId` ,
GradeTypes.`Name` AS `GradeType.Name` ,
GradeTypes.Min AS `GradeType.Min`,
GradeTypes.Max AS `GradeType.Max`,
GradeTypes.Pass AS `GradeType.Pass` ,
GradeTypes.DefinedValues AS `GradeType.DefinedValues`

FROM
ClassRooms
INNER JOIN Teachers ON Teachers.TeacherId = ClassRooms.Teacher
INNER JOIN Terms ON Terms.TermId = ClassRooms.Term
INNER JOIN Lectures ON Lectures.LectureId = ClassRooms.Lecture
INNER JOIN GradeTypes ON GradeTypes.GradeTypeId = ClassRooms.GradeType
INNER JOIN ExamsClassRooms ON ClassRooms.ClassRoomId = ExamsClassRooms.ClassRoom
WHERE ExamsClassRooms.Exam = " . $examId;
        if ($teacherId > 0) {
            $SQL .= " AND Teachers.TeacherId =" . $teacherId;
        }
        $db = new DataAccess();
        $result = $db->ExecuteSelect($SQL);
        $classRooms = array();
        $i = 0;
        while ($row = mysqli_fetch_array($result)) {
            //echo 'aasdas<br/>';
            $classroom = new ClassRoom();
            $classroom->ClassRoomId = $row['ClassRoom.ClassRoomId'];
            $classroom->Name = $row['ClassRoom.Name'];
            $classroom->Saal = $row['ClassRoom.Saal'];
            $term = new Term();
            $term->TermId = $row['Term.TermId'];
            $term->SalShoroo = $row['Term.SalShoroo'];
            $term->SalPayan = $row['Term.SalPayan'];
            $term->NimSal = $row['Term.NimSal'];
            $term->Tozihat = $row['Term.Tozihat'];
            $classroom->Term = $term;

            $lecture = new Lecture();
            $lecture->LectureId = $row['Lecture.LectureId'];
            $lecture->Name = $row['Lecture.Name'];
            $lecture->TedadVahed = $row['Lecture.TedadVahed'];
            $lecture->Tozihat = $row['Lecture.Tozihat'];
            $classroom->Lecture = $lecture;

            $teacher = new Teacher();
            $teacher->TeacherId = $row['Teacher.TeacherId'];
            $teacher->Name = $row['Teacher.Name'];
            $teacher->Family = $row['Teacher.Family'];
            $teacher->Username = $row['Teacher.Username'];
            $teacher->Passwd = $row['Teacher.Passwd'];
            $classroom->Teacher = $teacher;


            $gradeType = new GradeType();
            $gradeType->GradeTypeId = $row['GradeType.GradeTypeId'];
            $gradeType->Name = $row['GradeType.Name'];
            $gradeType->Min = $row['GradeType.Min'];
            $gradeType->Max = $row['GradeType.Max'];
            $gradeType->Pass = $row['GradeType.Pass'];
            $gradeType->DefinedValues = $row['GradeType.DefinedValues'];
            $classroom->GradeType = $gradeType;



            $classRooms[$i] = $classroom;
            $i++;
        }
        return $classRooms;
    }

    public static function GetClassRoomsForTeacherForActiveTerm($teacherId, $termId) {
        $SQL = "SELECT
ClassRooms.ClassRoomId AS `ClassRoom.ClassRoomId`,
ClassRooms.`Name` AS `ClassRoom.Name`,
ClassRooms.Saal AS `ClassRoom.Saal`,
Terms.TermId AS `Term.TermId`,
Terms.SalShoroo AS `Term.SalShoroo`,
Terms.SalPayan AS `Term.SalPayan`,
Terms.NimSal AS `Term.NimSal`,
Terms.Tozihat AS `Term.Tozihat`,
Teachers.TeacherId AS `Teacher.TeacherId`,
Teachers.`Name` AS `Teacher.Name`,
Teachers.Family AS `Teacher.Family`,
Teachers.Username AS `Teacher.Username`,
Teachers.Passwd AS `Teacher.Passwd`,
Lectures.LectureId AS `Lecture.LectureId`,
Lectures.`Name` AS `Lecture.Name`,
Lectures.TedadVahed AS `Lecture.TedadVahed`,
Lectures.Tozihat AS `Lecture.Tozihat`,
GradeTypes.GradeTypeId AS `GradeType.GradeTypeId` ,
GradeTypes.`Name` AS `GradeType.Name` ,
GradeTypes.Min AS `GradeType.Min`,
GradeTypes.Max AS `GradeType.Max`,
GradeTypes.Pass AS `GradeType.Pass` ,
GradeTypes.DefinedValues AS `GradeType.DefinedValues` 
FROM
ClassRooms
INNER JOIN Teachers ON Teachers.TeacherId = ClassRooms.Teacher
INNER JOIN Terms ON Terms.TermId = ClassRooms.Term
INNER JOIN Lectures ON Lectures.LectureId = ClassRooms.Lecture
INNER JOIN GradeTypes ON GradeTypes.GradeTypeId = ClassRooms.GradeType
WHERE ClassRooms.Teacher = " . $teacherId . " AND ClassRooms.Term=" . $termId;
        $db = new DataAccess();
        $result = $db->ExecuteSelect($SQL);
        $classRooms = array();
        $i = 0;
        while ($row = mysqli_fetch_array($result)) {
            //echo 'aasdas<br/>';
            $classroom = new ClassRoom();
            $classroom->ClassRoomId = $row['ClassRoom.ClassRoomId'];
            $classroom->Name = $row['ClassRoom.Name'];
            $classroom->Saal = $row['ClassRoom.Saal'];
            $term = new Term();
            $term->TermId = $row['Term.TermId'];
            $term->SalShoroo = $row['Term.SalShoroo'];
            $term->SalPayan = $row['Term.SalPayan'];
            $term->NimSal = $row['Term.NimSal'];
            $term->Tozihat = $row['Term.Tozihat'];
            $classroom->Term = $term;

            $lecture = new Lecture();
            $lecture->LectureId = $row['Lecture.LectureId'];
            $lecture->Name = $row['Lecture.Name'];
            $lecture->TedadVahed = $row['Lecture.TedadVahed'];
            $lecture->Tozihat = $row['Lecture.Tozihat'];
            $classroom->Lecture = $lecture;

            $teacher = new Teacher();
            $teacher->TeacherId = $row['Teacher.TeacherId'];
            $teacher->Name = $row['Teacher.Name'];
            $teacher->Family = $row['Teacher.Family'];
            $teacher->Username = $row['Teacher.Username'];
            $teacher->Passwd = $row['Teacher.Passwd'];
            $classroom->Teacher = $teacher;


            $gradeType = new GradeType();
            $gradeType->GradeTypeId = $row['GradeType.GradeTypeId'];
            $gradeType->Name = $row['GradeType.Name'];
            $gradeType->Min = $row['GradeType.Min'];
            $gradeType->Max = $row['GradeType.Max'];
            $gradeType->Pass = $row['GradeType.Pass'];
            $gradeType->DefinedValues = $row['GradeType.DefinedValues'];
            $classroom->GradeType = $gradeType;



            $classRooms[$i] = $classroom;
            $i++;
        }
        return $classRooms;
    }

    public static function GetClassRoomsForActiveTerm($termId) {
        $SQL = "SELECT
ClassRooms.ClassRoomId AS `ClassRoom.ClassRoomId`,
ClassRooms.`Name` AS `ClassRoom.Name`,
ClassRooms.Saal AS `ClassRoom.Saal`,
Terms.TermId AS `Term.TermId`,
Terms.SalShoroo AS `Term.SalShoroo`,
Terms.SalPayan AS `Term.SalPayan`,
Terms.NimSal AS `Term.NimSal`,
Terms.Tozihat AS `Term.Tozihat`,
Teachers.TeacherId AS `Teacher.TeacherId`,
Teachers.`Name` AS `Teacher.Name`,
Teachers.Family AS `Teacher.Family`,
Teachers.Username AS `Teacher.Username`,
Teachers.Passwd AS `Teacher.Passwd`,
Lectures.LectureId AS `Lecture.LectureId`,
Lectures.`Name` AS `Lecture.Name`,
Lectures.TedadVahed AS `Lecture.TedadVahed`,
Lectures.Tozihat AS `Lecture.Tozihat`,
GradeTypes.GradeTypeId AS `GradeType.GradeTypeId` ,
GradeTypes.`Name` AS `GradeType.Name` ,
GradeTypes.Min AS `GradeType.Min`,
GradeTypes.Max AS `GradeType.Max`,
GradeTypes.Pass AS `GradeType.Pass` ,
GradeTypes.DefinedValues AS `GradeType.DefinedValues` 
FROM
ClassRooms
INNER JOIN Teachers ON Teachers.TeacherId = ClassRooms.Teacher
INNER JOIN Terms ON Terms.TermId = ClassRooms.Term
INNER JOIN Lectures ON Lectures.LectureId = ClassRooms.Lecture
INNER JOIN GradeTypes ON GradeTypes.GradeTypeId = ClassRooms.GradeType
WHERE  ClassRooms.Term=" . $termId;
        $db = new DataAccess();
        $result = $db->ExecuteSelect($SQL);
        $classRooms = array();
        $i = 0;
        while ($row = mysqli_fetch_array($result)) {
            //echo 'aasdas<br/>';
            $classroom = new ClassRoom();
            $classroom->ClassRoomId = $row['ClassRoom.ClassRoomId'];
            $classroom->Name = $row['ClassRoom.Name'];
            $classroom->Saal = $row['ClassRoom.Saal'];
            $term = new Term();
            $term->TermId = $row['Term.TermId'];
            $term->SalShoroo = $row['Term.SalShoroo'];
            $term->SalPayan = $row['Term.SalPayan'];
            $term->NimSal = $row['Term.NimSal'];
            $term->Tozihat = $row['Term.Tozihat'];
            $classroom->Term = $term;

            $lecture = new Lecture();
            $lecture->LectureId = $row['Lecture.LectureId'];
            $lecture->Name = $row['Lecture.Name'];
            $lecture->TedadVahed = $row['Lecture.TedadVahed'];
            $lecture->Tozihat = $row['Lecture.Tozihat'];
            $classroom->Lecture = $lecture;

            $teacher = new Teacher();
            $teacher->TeacherId = $row['Teacher.TeacherId'];
            $teacher->Name = $row['Teacher.Name'];
            $teacher->Family = $row['Teacher.Family'];
            $teacher->Username = $row['Teacher.Username'];
            $teacher->Passwd = $row['Teacher.Passwd'];
            $classroom->Teacher = $teacher;


            $gradeType = new GradeType();
            $gradeType->GradeTypeId = $row['GradeType.GradeTypeId'];
            $gradeType->Name = $row['GradeType.Name'];
            $gradeType->Min = $row['GradeType.Min'];
            $gradeType->Max = $row['GradeType.Max'];
            $gradeType->Pass = $row['GradeType.Pass'];
            $gradeType->DefinedValues = $row['GradeType.DefinedValues'];
            $classroom->GradeType = $gradeType;



            $classRooms[$i] = $classroom;
            $i++;
        }
        return $classRooms;
    }

    public static function GetClassRoomsForTerm($termId) {
        $SQL = "SELECT * FROM ClassRooms WHERE Term = " . $termId;
        $db = new DataAccess();
        $result = $db->ExecuteSelect($SQL);
        $classRooms = array();
        $i = 0;
        while ($row = mysqli_fetch_array($result)) {
            //echo 'aasdas<br/>';
            $t = new ClassRoom();
            $t->ClassRoomId = $row['ClassRoomId'];
            $t->Name = $row['Name'];
            $t->Term = $row['Term'];
            $t->Lecture = $row['Lecture'];
            $t->Saal = $row['Saal'];
            $classRooms[$i] = $t;
            $i++;
        }
        return $classRooms;
    }

    public static function GetClassRoomsForTermBasedOnLectureAndSaal($termId, $lectureId, $saal) {
        $SQL = "SELECT
ClassRooms.ClassRoomId AS `ClassRoom.ClassRoomId`,
ClassRooms.`Name` AS `ClassRoom.Name`,
ClassRooms.Saal AS `ClassRoom.Saal`,
Terms.TermId AS `Term.TermId`,
Terms.SalShoroo AS `Term.SalShoroo`,
Terms.SalPayan AS `Term.SalPayan`,
Terms.NimSal AS `Term.NimSal`,
Terms.Tozihat AS `Term.Tozihat`,
Teachers.TeacherId AS `Teacher.TeacherId`,
Teachers.`Name` AS `Teacher.Name`,
Teachers.Family AS `Teacher.Family`,
Teachers.Username AS `Teacher.Username`,
Teachers.Passwd AS `Teacher.Passwd`,
Lectures.LectureId AS `Lecture.LectureId`,
Lectures.`Name` AS `Lecture.Name`,
Lectures.TedadVahed AS `Lecture.TedadVahed`,
Lectures.Tozihat AS `Lecture.Tozihat`,
GradeTypes.GradeTypeId AS `GradeType.GradeTypeId` ,
GradeTypes.`Name` AS `GradeType.Name` ,
GradeTypes.Min AS `GradeType.Min`,
GradeTypes.Max AS `GradeType.Max`,
GradeTypes.Pass AS `GradeType.Pass` ,
GradeTypes.DefinedValues AS `GradeType.DefinedValues` 
FROM
ClassRooms
INNER JOIN Teachers ON Teachers.TeacherId = ClassRooms.Teacher
INNER JOIN Terms ON Terms.TermId = ClassRooms.Term
INNER JOIN Lectures ON Lectures.LectureId = ClassRooms.Lecture
INNER JOIN GradeTypes ON GradeTypes.GradeTypeId = ClassRooms.GradeType
 WHERE ClassRooms.Term =  $termId AND ClassRooms.Lecture= $lectureId AND ClassRooms.Saal= $saal ";
        $db = new DataAccess();
        $result = $db->ExecuteSelect($SQL);
        $classRooms = array();
        $i = 0;
        while ($row = mysqli_fetch_array($result)) {
            $classroom = new ClassRoom();
            $classroom->ClassRoomId = $row['ClassRoom.ClassRoomId'];
            $classroom->Name = $row['ClassRoom.Name'];
            $classroom->Saal = $row['ClassRoom.Saal'];
            $term = new Term();
            $term->TermId = $row['Term.TermId'];
            $term->SalShoroo = $row['Term.SalShoroo'];
            $term->SalPayan = $row['Term.SalPayan'];
            $term->NimSal = $row['Term.NimSal'];
            $term->Tozihat = $row['Term.Tozihat'];
            $classroom->Term = $term;

            $lecture = new Lecture();
            $lecture->LectureId = $row['Lecture.LectureId'];
            $lecture->Name = $row['Lecture.Name'];
            $lecture->TedadVahed = $row['Lecture.TedadVahed'];
            $lecture->Tozihat = $row['Lecture.Tozihat'];
            $classroom->Lecture = $lecture;

            $teacher = new Teacher();
            $teacher->TeacherId = $row['Teacher.TeacherId'];
            $teacher->Name = $row['Teacher.Name'];
            $teacher->Family = $row['Teacher.Family'];
            $teacher->Username = $row['Teacher.Username'];
            $teacher->Passwd = $row['Teacher.Passwd'];
            $classroom->Teacher = $teacher;


            $gradeType = new GradeType();
            $gradeType->GradeTypeId = $row['GradeType.GradeTypeId'];
            $gradeType->Name = $row['GradeType.Name'];
            $gradeType->Min = $row['GradeType.Min'];
            $gradeType->Max = $row['GradeType.Max'];
            $gradeType->Pass = $row['GradeType.Pass'];
            $gradeType->DefinedValues = $row['GradeType.DefinedValues'];
            $classroom->GradeType = $gradeType;



            $classRooms[$i] = $classroom;
            $i++;
        }
        return $classRooms;
    }

    public static function CheckClassRoomIsRegisterForExam($classroomId, $examId) {
        $SQL = "SELECT * FROM ExamsClassRooms WHERE Exam= $examId AND ClassRoom=$classroomId";
        $db = new DataAccess();
        $result = $db->ExecuteSelect($SQL);
        if (mysqli_num_rows($result) > 0)
            return TRUE;
        return FALSE;
    }

    public static function GetClassRoomsForLecture($lectureId) {
        $SQL = "SELECT * FROM ClassRooms WHERE Lecture = " . $lectureId;
        $db = new DataAccess();
        $result = $db->ExecuteSelect($SQL);
        $classRooms = array();
        $i = 0;
        while ($row = mysqli_fetch_array($result)) {
            //echo 'aasdas<br/>';
            $t = new ClassRoom();
            $t->ClassRoomId = $row['ClassRoomId'];
            $t->Name = $row['Name'];
            $t->Term = $row['Term'];
            $t->Lecture = $row['Lecture'];
            $t->Saal = $row['Saal'];
            $classRooms[$i] = $t;
            $i++;
        }
        return $classRooms;
    }

    public static function GetClassRoomsForGradeType($gradeTypeId) {
        $SQL = "SELECT * FROM ClassRooms WHERE GradeType = " . $gradeTypeId;
        $db = new DataAccess();
        $result = $db->ExecuteSelect($SQL);
        $classRooms = array();
        $i = 0;
        while ($row = mysqli_fetch_array($result)) {
            //echo 'aasdas<br/>';
            $t = new ClassRoom();
            $t->ClassRoomId = $row['ClassRoomId'];
            $t->Name = $row['Name'];
            $t->Term = $row['Term'];
            $t->Lecture = $row['Lecture'];
            $t->Saal = $row['Saal'];
            $classRooms[$i] = $t;
            $i++;
        }
        return $classRooms;
    }

    public static function AssignStudents(ClassRoom $classroom, $Students) {
        //echo $classroom->ClassRoomId . "<br/>";
//        $SQL = "DELETE FROM StudentsClassRooms WHERE ClassRoom=" . $classroom->ClassRoomId;
//        $db = new DataAccess();
//        $db->Execute($SQL);
//
//        foreach ($Students as $student) {
//            echo $class . "<br/>";
//            $SQL = "INSERT INTO StudentsClassRooms (Student,ClassRoom) VALUES (" . $student . "," . $classroom->ClassRoomId . ")";
//            $db = new DataAccess();
//            $db->Execute($SQL);
//        }



        $stds = StudentEx::Fill();
        foreach ($Students as $student) {
            //echo $class . "<br/>";
            $SQL = "SELECT * FROM StudentsClassRooms WHERE Student=" . $student . " AND ClassRoom= " . $classroom->ClassRoomId;
            $db = new DataAccess();
            if (mysqli_num_rows($db->ExecuteSelect($SQL)) == 0) {
                $SQL = "INSERT INTO StudentsClassRooms (Student,ClassRoom) VALUES (" . $student . "," . $classroom->ClassRoomId . ")";
                $db = new DataAccess();
                $db->Execute($SQL);
            }

            for ($i = 0; $i < count($stds); $i++) {
                $id = $stds[$i]->StudentId;
                if ($student == $id) {
                    unset($stds[$i]);
                    $stds = array_values($stds);
                    break;
                }
            }
        }

        foreach ($stds as $std) {
            $SQL = "SELECT * FROM StudentsClassRooms WHERE Student=" . $std->StudentId . " AND ClassRoom=" . $classroom->ClassRoomId;
            $db = new DataAccess();
            $cls = $db->ExecuteSelect($SQL);
            if (mysqli_num_rows($cls) > 0) {
                $rows = mysqli_fetch_array($cls);
                $clsstd = $rows["StudentClassRoomId"];
                $SQL = "DELETE FROM Grades WHERE StudentClassRoom=" . $clsstd;
                $db = new DataAccess();
                $db->Execute($SQL);
            }
            $SQL = "DELETE FROM StudentsClassRooms WHERE Student=" . $std->StudentId . " AND ClassRoom=" . $classroom->ClassRoomId;
            $db = new DataAccess();
            $db->Execute($SQL);
        }
    }

    public static function GetClassRoomsOfActiveTermForStudent($studentId, $termId) {
        $SQL = "SELECT
ClassRooms.Lecture AS `ClassRoom.Lecture`,
ClassRooms.Saal AS `ClassRoom.Saal`,
ClassRooms.Teacher AS `ClassRoom.Teacher`,
ClassRooms.`Name` AS `ClassRoom.Name`,
Students.`Name` AS `Student.Name`,
Students.Family AS `Student.Family`,
Students.CodeMelli AS `Student.CodeMelli`,
Students.StudentId AS `Student.StudentId`,
ClassRooms.ClassRoomId AS `ClassRoom.ClassRoomId`,
ClassRooms.Term AS `ClassRoom.Term`,
Students.Passwd AS `Student.Passwd`,
StudentsClassRooms.StudentClassRoomId AS `StudentClassRoom.StudentClassRoomId`,
StudentsClassRooms.Student AS `StudentClassRoom.Student`,
StudentsClassRooms.ClassRoom AS `StudentClassRoom.ClassRoom`,
Lectures.LectureId AS `Lecture.LectureId`,
Lectures.`Name` AS `Lecture.Name`,
Lectures.TedadVahed AS `Lecture.TedadVahed`,
Lectures.Tozihat AS `Lecture.Tozihat`,
Teachers.TeacherId AS `Teacher.TeacherId`,
Teachers.`Name` AS `Teacher.Name`,
Teachers.Family AS `Teacher.Family`,
Teachers.CodeMelli AS `Teacher.CodeMelli`,
Teachers.Username AS `Teacher.UserName`,
Teachers.Passwd AS `Teacher.Passwd`,
Terms.TermId AS `Term.TermId`,
Terms.SalShoroo AS `Term.SalShoroo`,
Terms.SalPayan AS 'Term.SalPayan',
Terms.NimSal AS `Term.NimSal`,
Terms.Tozihat AS `Term.Tozihat` ,
GradeTypes.GradeTypeId AS `GradeType.GradeTypeId` ,
GradeTypes.`Name` AS `GradeType.Name` ,
GradeTypes.Min AS `GradeType.Min`,
GradeTypes.Max AS `GradeType.Max`,
GradeTypes.Pass AS `GradeType.Pass` ,
GradeTypes.DefinedValues AS `GradeType.DefinedValues` 
FROM
ClassRooms
INNER JOIN StudentsClassRooms ON ClassRooms.ClassRoomId = StudentsClassRooms.ClassRoom
INNER JOIN Students ON Students.StudentId = StudentsClassRooms.Student
INNER JOIN Lectures ON Lectures.LectureId = ClassRooms.Lecture
INNER JOIN Teachers ON Teachers.TeacherId = ClassRooms.Teacher
INNER JOIN GradeTypes ON GradeTypes.GradeTypeId = ClassRooms.GradeType
INNER JOIN Terms ON Terms.TermId = ClassRooms.Term
WHERE
Students.StudentId =" . $studentId . " AND ClassRooms.Term= " . $termId . " ";

        $db = new DataAccess();
        $result = $db->ExecuteSelect($SQL);
        $classRooms = array();
        $i = 0;
        while ($row = mysqli_fetch_array($result)) {
            //echo 'aasdas<br/>';
            $classroom = new ClassRoom();
            $classroom->ClassRoomId = $row['ClassRoom.ClassRoomId'];
            $classroom->Name = $row['ClassRoom.Name'];
            $classroom->Saal = $row['ClassRoom.Saal'];
            $term = new Term();
            $term->TermId = $row['Term.TermId'];
            $term->SalShoroo = $row['Term.SalShoroo'];
            $term->SalPayan = $row['Term.SalPayan'];
            $term->NimSal = $row['Term.NimSal'];
            $term->Tozihat = $row['Term.Tozihat'];
            $classroom->Term = $term;

            $lecture = new Lecture();
            $lecture->LectureId = $row['Lecture.LectureId'];
            $lecture->Name = $row['Lecture.Name'];
            $lecture->TedadVahed = $row['Lecture.TedadVahed'];
            $lecture->Tozihat = $row['Lecture.Tozihat'];
            $classroom->Lecture = $lecture;

            $teacher = new Teacher();
            $teacher->TeacherId = $row['Teacher.TeacherId'];
            $teacher->Name = $row['Teacher.Name'];
            $teacher->Family = $row['Teacher.Family'];
            $teacher->CodeMelli = $row['Teacher.CodeMelli'];
            $teacher->Username = $row['Teacher.UserName'];
            $teacher->Passwd = $row['Teacher.Passwd'];
            $classroom->Teacher = $teacher;

            $gradeType = new GradeType();
            $gradeType->GradeTypeId = $row['GradeType.GradeTypeId'];
            $gradeType->Name = $row['GradeType.Name'];
            $gradeType->Min = $row['GradeType.Min'];
            $gradeType->Max = $row['GradeType.Max'];
            $gradeType->Pass = $row['GradeType.Pass'];
            $gradeType->DefinedValues = $row['GradeType.DefinedValues'];
            $classroom->GradeType = $gradeType;


            $classRooms[$i] = $classroom;
            $i++;
        }
        return $classRooms;
    }

    public static function CheckClassRoomIsRegisterForStudentForActiveTerm($classroomId, $studentId) {
        $SQL = "SELECT * FROM StudentsClassRooms WHERE Student= $studentId AND ClassRoom=$classroomId ";
        //echo $SQL;
        $db = new DataAccess();
        $result = $db->ExecuteSelect($SQL);
        if (mysqli_num_rows($result) > 0)
            return TRUE;
        return FALSE;
    }

//put your code here
}
