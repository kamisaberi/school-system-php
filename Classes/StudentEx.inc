<?php

require_once 'Student.inc';

//use DataAccess;
/**
 * Description of Student
 *
 * @author kami
 */
class StudentEx {

    public static function Insert(Student $student) {
        $SQL = "INSERT INTO Students (Name,Family,CodeMelli,Passwd) VALUES ('" . $student->Name . "','" . $student->Family . "','" . $student->CodeMelli . "','" . md5($student->Passwd) . "')";
        $db = new DataAccess();
        $db->Execute($SQL);
    }

    //$ts= new Student();

    public static function Update(Student $student) {
        $SQL = "UPDATE Students SET Name = '" . $student->Name . "',Family = '" . $student->Family . "',CodeMelli='" . $student->CodeMelli . "',Passwd= '" . md5($student->Passwd) . "' WHERE StudentId=" . $student->StudentId;
        echo $SQL;
        $db = new DataAccess();
        $db->Execute($SQL);
    }

    public static function UpdateByCodeMelli(Student $student) {
        $SQL = "UPDATE Students SET Name = '" . $student->Name . "',Family = '" . $student->Family . "',Passwd= '" . md5($student->Passwd) . "' WHERE CodeMelli=" . $student->CodeMelli;
        echo $SQL;
        $db = new DataAccess();
        $db->Execute($SQL);
    }

    public static function Delete(Student $student) {
        $SQL = "DELETE FROM Students WHERE StudentId=" . $student->StudentId;
        $db = new DataAccess();
        $db->Execute($SQL);
    }

    function Test(Student $student) {
        $s = array();
        $t = new Student();
        $t->Name = "ali";
        $s[0] = $t;
        $t1 = new Student();
        $t1->Name = "reza";
        $s[1] = $t1;
        return $s;
    }

    public static function Fill() {
        $SQL = "SELECT * FROM Students ";
        $db = new DataAccess();
        $result = $db->ExecuteSelect($SQL);
        $Students = array();
        $i = 0;
        while ($row = mysqli_fetch_array($result)) {
            $t = new Student();
            $t->StudentId = $row['StudentId'];
            $t->Name = $row['Name'];
            $t->Family = $row['Family'];
            $t->CodeMelli = $row['CodeMelli'];
            $t->Passwd = $row['Passwd'];
            $Students[$i] = $t;
            $i++;
        }
        return $Students;
    }

    public static function GetOnStudent($Id) {
        $SQL = "SELECT * FROM Students WHERE StudentId= " . $Id;
        $db = new DataAccess();
        $result = $db->ExecuteSelect($SQL);

        while ($row = mysqli_fetch_array($result)) {
            $t = new Student();
            $t->StudentId = $row['StudentId'];
            $t->Name = $row['Name'];
            $t->Family = $row['Family'];
            $t->CodeMelli = $row['CodeMelli'];
            $t->Passwd = $row['Passwd'];
            return $t;
        }
    }

    public static function GetOnStudentBasedOnCoeMelli($codemelli) {
        $SQL = "SELECT * FROM Students WHERE CodeMelli= '" . $codemelli . "'";
        $db = new DataAccess();
        $result = $db->ExecuteSelect($SQL);

        while ($row = mysqli_fetch_array($result)) {
            $t = new Student();
            $t->StudentId = $row['StudentId'];
            $t->Name = $row['Name'];
            $t->Family = $row['Family'];
            $t->CodeMelli = $row['CodeMelli'];
            $t->Passwd = $row['Passwd'];
            return $t;
        }
    }

    public static function GetStudentsForTeacher($teacherId) {
        $SQL = "SELECT * FROM Students INNER  JOIN Grades On Students.StudentId = Grades.Student INNER JOIN  ClassRooms On Grades.ClassRoom = ClassRooms.ClassRoomId  WHERE ClassRooms.Teacher = " . $teacherId;
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

    public static function AssignClassRooms(Student $student, $ClassRooms, $termId) {

        $classrooms = ClassRoomEx::GetClassRoomsForTerm($termId);
        foreach ($ClassRooms as $class) {
            echo $class . "<br/>";
            $SQL = "SELECT * FROM StudentsClassRooms WHERE Student=" . $student->StudentId . " AND ClassRoom= " . $class;
            $db = new DataAccess();
            if (mysqli_num_rows($db->ExecuteSelect($SQL)) == 0) {
                $SQL = "INSERT INTO StudentsClassRooms (Student,ClassRoom) VALUES (" . $student->StudentId . "," . $class . ")";
                $db = new DataAccess();
                $db->Execute($SQL);
            }

            for ($i = 0; $i < count($classrooms); $i++) {
                $id = $classrooms[$i]->ClassRoomId;
                if ($class == $id) {
                    unset($classrooms[$i]);
                    $classrooms = array_values($classrooms);
                    break;
                }
            }
        }

        foreach ($classrooms as $classroom) {
            $SQL = "SELECT * FROM StudentsClassRooms WHERE Student=" . $student->StudentId . " AND ClassRoom=" . $classroom->ClassRoomId;
            $db = new DataAccess();
            $cls = $db->ExecuteSelect($SQL);
            if (mysqli_num_rows($cls) > 0) {
                $rows=  mysqli_fetch_array($cls);
                $clsstd=$rows["StudentClassRoomId"];
                $SQL = "DELETE FROM Grades WHERE StudentClassRoom=" . $clsstd;
                $db = new DataAccess();
                $db->Execute($SQL);
            }
            $SQL = "DELETE FROM StudentsClassRooms WHERE Student=" . $student->StudentId . " AND ClassRoom=" . $classroom->ClassRoomId;
            $db = new DataAccess();
            $db->Execute($SQL);
        }
    }

    public static function AssignTerms(Student $student, $Terms) {
        //echo $student->StudentId . "<br/>";
        foreach ($Terms as $term) {
            //echo $class . "<br/>";
            $SQL = "INSERT INTO StudentsTerms (Student,Term) VALUES (" . $student->StudentId . "," . $term . ")";
            $db = new DataAccess();
            $db->Execute($SQL);
        }
    }

    public static function GetStudentsOfActiveTermForClassRoom($classroomId, $termId) {
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
Teachers.Username AS `Teacher.UserName`,
Teachers.Passwd AS `Teacher.Passwd`,
Terms.TermId AS `Term.TermId`,
Terms.SalShoroo AS `Term.SalShoroo`,
Terms.SalPayan AS 'Term.SalPayan',
Terms.NimSal AS `Term.NimSal`,
Terms.Tozihat AS `Term.Tozihat`
FROM
ClassRooms
INNER JOIN StudentsClassRooms ON ClassRooms.ClassRoomId = StudentsClassRooms.ClassRoom
INNER JOIN Students ON Students.StudentId = StudentsClassRooms.Student
INNER JOIN Lectures ON Lectures.LectureId = ClassRooms.Lecture
INNER JOIN Teachers ON Teachers.TeacherId = ClassRooms.Teacher
INNER JOIN Terms ON Terms.TermId = ClassRooms.Term
WHERE
ClassRooms.ClassRoomId =" . $classroomId . " AND ClassRooms.Term= " . $termId . " ";

        $db = new DataAccess();
        $result = $db->ExecuteSelect($SQL);
        $Students = array();
        $i = 0;
        while ($row = mysqli_fetch_array($result)) {
            //echo 'aasdas<br/>';
            $student = new Student();
            $student->StudentId = $row['Student.StudentId'];
            $student->Name = $row['Student.Name'];
            $student->Family = $row['Student.Family'];
            $student->CodeMelli = $row['Student.CodeMelli'];
            $student->Passwd = $row['Student.Passwd'];
            $Students[$i] = $student;
            $i++;
        }
        return $Students;
    }

    public static function GetStudentsOfActiveTermForTeacher($teacherId, $termId) {
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
Teachers.Username AS `Teacher.UserName`,
Teachers.Passwd AS `Teacher.Passwd`,
Terms.TermId AS `Term.TermId`,
Terms.SalShoroo AS `Term.SalShoroo`,
Terms.SalPayan AS 'Term.SalPayan',
Terms.NimSal AS `Term.NimSal`,
Terms.Tozihat AS `Term.Tozihat`
FROM
ClassRooms
INNER JOIN StudentsClassRooms ON ClassRooms.ClassRoomId = StudentsClassRooms.ClassRoom
INNER JOIN Students ON Students.StudentId = StudentsClassRooms.Student
INNER JOIN Lectures ON Lectures.LectureId = ClassRooms.Lecture
INNER JOIN Teachers ON Teachers.TeacherId = ClassRooms.Teacher
INNER JOIN Terms ON Terms.TermId = ClassRooms.Term  
WHERE
ClassRooms.Teacher=" . $teacherId . " AND ClassRooms.Term= " . $termId . " ";
        //echo $SQL;
        $db = new DataAccess();
        $result = $db->ExecuteSelect($SQL);
        $Students = array();
        $i = 0;
        while ($row = mysqli_fetch_array($result)) {
            //echo 'aasdas<br/>';
            $student = new Student();
            $student->StudentId = $row['Student.StudentId'];
            $student->Name = $row['Student.Name'];
            $student->Family = $row['Student.Family'];
            $student->CodeMelli = $row['Student.CodeMelli'];
            $student->Passwd = $row['Student.Passwd'];
            $Students[$i] = $student;
            $i++;
        }
        return $Students;
    }

    public static function CheckStudentIsRegisterInClassRoomForActiveTerm($classroomId, $studentId) {
        $SQL = "SELECT * FROM StudentsClassRooms WHERE Student=" . $studentId . " AND ClassRoom=" . $classroomId;
        //echo $SQL;
        $db = new DataAccess();
        $result = $db->ExecuteSelect($SQL);
        if (mysqli_num_rows($result) > 0)
            return TRUE;
        return FALSE;
    }

    public static function Login($username, $password) {
        $SQL = "SELECT * FROM Students WHERE CodeMelli= '" . $username . "' AND Passwd='" . md5($password) . "'";
        //echo $SQL;
        $db = new DataAccess();
        $result = $db->ExecuteSelect($SQL);
        if (mysqli_num_rows($result) > 0)
            return TRUE;
        return FALSE;
    }

    public static function CheckExists($codemelli) {
        $SQL = "SELECT * FROM Students WHERE CodeMelli= '" . $codemelli . "'";
        //echo $SQL;
        $db = new DataAccess();
        $result = $db->ExecuteSelect($SQL);
        if (mysqli_num_rows($result) > 0)
            return TRUE;
        return FALSE;
    }

//put your code here
}
