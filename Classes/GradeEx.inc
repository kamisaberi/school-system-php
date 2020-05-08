<?php

require_once 'Grade.inc';

//use DataAccess;
/**
 * Description of Grade
 *
 * @author kami
 */
class GradeEx {

    public static function Insert(Grade $grade) {
        $SQL = "INSERT INTO Grades (StudentClassRoom,Value , GradeType ) VALUES (" . $grade->StudentClassRoom . ",'" . $grade->Value . "'," . $grade->GradeType->GradeTypeId . ")";
        //echo $grade->GradeType->GradeTypeId;
        $db = new DataAccess();
        $db->Execute($SQL);
    }

    public static function Update(Grade $grade) {
        $SQL = "UPDATE Grades SET Student = " . $grade->Student . ",Teacher = " . $grade->Teacher . ",Value='" . $grade->Value . "',ClassRoom= " . $grade->ClassRoom . " WHERE GradeId=" . $grade->GradeId;
        $db = new DataAccess();
        echo $SQL;
        $db->Execute($SQL);
    }

    public static function Delete(Grade $grade) {
        $SQL = "DELETE FROM Grades WHERE GradeId=" . $grade->GradeId;
        $db = new DataAccess();
        $db->Execute($SQL);
    }

    public static function Fill() {
        $SQL = "SELECT * FROM Grades ";
        $db = new DataAccess();
        $result = $db->ExecuteSelect($SQL);
        $grades = array();
        $i = 0;
        while ($row = mysqli_fetch_array($result)) {
            //echo 'aasdas<br/>';
            $t = new Grade();
            $t->GradeId = $row['GradeId'];
            $t->Student = $row['Student'];
            $t->Teacher = $row['Teacher'];
            $t->Value = $row['Value'];
            $t->ClassRoom = $row['ClassRoom'];
            $grades[$i] = $t;
            $i++;
        }
        return $grades;
    }

    public static function GetOnGrade($Id) {
        $SQL = "SELECT * FROM Grades WHERE GradeId= " . $Id;
        $db = new DataAccess();
        $result = $db->ExecuteSelect($SQL);

        while ($row = mysqli_fetch_array($result)) {
            $t = new Grade();
            $t->GradeId = $row['GradeId'];
            $t->Student = $row['Student'];
            $t->Teacher = $row['Teacher'];
            $t->Value = $row['Value'];
            $t->ClassRoom = $row['ClassRoom'];
            return $t;
        }
    }

    public static function GetGradesForClassroom($classRoomId) {
        $SQL = "SELECT * FROM Grades WHERE ClassRoom = " . $classRoomId;
        $db = new DataAccess();
        $result = $db->ExecuteSelect($SQL);
        $grades = array();
        $i = 0;
        while ($row = mysqli_fetch_array($result)) {
            //echo 'aasdas<br/>';
            $t = new Grade();
            $t->GradeId = $row['GradeId'];
            $t->Student = $row['Student'];
            $t->Teacher = $row['Teacher'];
            $t->Value = $row['Value'];
            $t->ClassRoom = $row['ClassRoom'];
            $grades[$i] = $t;
            $i++;
        }
        return $grades;
    }

    public static function AssignGrades($classrooms, $values, $studentId) {
        for ($i = 0; $i < count($classrooms); $i++) {
            //echo "STID: " . $studentId . "<br/>";
            //echo "CLID: " . $classrooms[$i] . "<br/>";
            //echo "CLVL: " . $values[$i] . "<br/>";

            $SQL = "SELECT * FROM StudentsClassRooms WHERE Student=" . $studentId . " AND ClassRoom =" . $classrooms[$i];
            //echo $SQL . "<br/>";
            $studentClassRoomId = 0;
            $db = new DataAccess();
            $result = $db->ExecuteSelect($SQL);
            while ($row = mysqli_fetch_array($result)) {
                $studentClassRoomId = $row['StudentClassRoomId'];
                break;
            }



            $classRoom = new ClassRoom();
            $classRoom = ClassRoomEx::GetOnClassRoom($classrooms[$i]);



            $SQL = "DELETE FROM Grades WHERE StudentClassRoom=" . $studentClassRoomId;
            $db = new DataAccess();
            $db->Execute($SQL);


            $grade = new Grade();
            $grade->StudentClassRoom = 0;
            $grade->Value = $values[$i];
            $grade->StudentClassRoom = $studentClassRoomId;
            $grade->GradeType->GradeTypeId = $classRoom->GradeType->GradeTypeId;
            GradeEx::Insert($grade);
        }
    }

    public static function AssignGradesForStudents($students, $values, $classroomId) {
        for ($i = 0; $i < count($students); $i++) {
//            echo "STID: " . $students[$i] . "<br/>";
//            echo "CLID: " . $classroomId . "<br/>";
//            echo "CLVL: " . $values[$i] . "<br/>";

            $SQL = "SELECT * FROM StudentsClassRooms WHERE Student=" . $students[$i] . " AND ClassRoom =" . $classroomId;
            //echo $SQL . "<br/>";
            $studentClassRoomId = 0;
            $db = new DataAccess();
            $result = $db->ExecuteSelect($SQL);
            while ($row = mysqli_fetch_array($result)) {
                $studentClassRoomId = $row['StudentClassRoomId'];
                break;
            }


            $classRoom = new ClassRoom();
            $classRoom = ClassRoomEx::GetOnClassRoom($classroomId);

            //echo  $classRoom->GradeType->GradeTypeId;

            $SQL = "DELETE FROM Grades WHERE StudentClassRoom=" . $studentClassRoomId;
            $db = new DataAccess();
            $db->Execute($SQL);


            $grade = new Grade();
            $grade->StudentClassRoom = 0;
            $grade->Value = $values[$i];
            $grade->StudentClassRoom = $studentClassRoomId;
            $grade->GradeType->GradeTypeId = $classRoom->GradeType->GradeTypeId;
            GradeEx::Insert($grade);
        }
    }

    public static function GetGradesForStudentInClassRoom($studentId, $classroomId) {
        $SQL = "SELECT * FROM StudentsClassRooms WHERE ClassRoom=" . $classroomId . " AND Student=" . $studentId;
        //echo $SQL . "<br/>";
        $studentClassRoomId = "0";
        $db = new DataAccess();
        $result = $db->ExecuteSelect($SQL);
        while ($row = mysqli_fetch_array($result)) {
            $studentClassRoomId = $row['StudentClassRoomId'];
            break;
        }

        $SQL = "SELECT * FROM Grades WHERE StudentClassRoom=" . $studentClassRoomId;
        $db = new DataAccess();
        $result = $db->ExecuteSelect($SQL);
        while ($row = mysqli_fetch_array($result)) {
            $value = $row['Value'];
            return $value;
        }
        return "-";
    }

//put your code here
}
