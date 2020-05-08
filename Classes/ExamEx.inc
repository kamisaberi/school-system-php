<?php

require_once 'Exam.inc';
require_once 'ClassRoomEx.inc';
require_once 'QuestionEx.inc';

//use DataAccess;
/**
 * Description of Exam
 *
 * @author kami
 */
class ExamEx {

    public static function Insert(Exam $exam) {
        $SQL = "INSERT INTO Exams (Title,Teacher,Saal,Lecture) VALUES ('" . $exam->Title . "'," . $exam->Teacher->TeacherId . "," . $exam->Saal . "," . $exam->Lecture->LectureId . ")";
        $db = new DataAccess();
        $db->Execute($SQL);
    }

    //$ts= new Exam();

    public static function Update(Exam $exam) {
        $SQL = "UPDATE Exams SET Title = '" . $exam->Title . "',Teacher= " . $exam->Teacher->TeacherId . ",Saal= " . $exam->Saal . ",Lecture= " . $exam->Lecture->LectureId . "  WHERE ExamId=" . $exam->ExamId;
        echo $SQL;
        //echo $SQL;
        $db = new DataAccess();
        $db->Execute($SQL);
    }

    public static function Delete(Exam $exam) {
        $SQL = "DELETE FROM Exams WHERE ExamId=" . $exam->ExamId;
        $db = new DataAccess();
        $db->Execute($SQL);
    }

    public static function Fill($teacherId = 0) {
        $SQL = "SELECT
Teachers.TeacherId AS `Teacher.TeacherId`,
Teachers.`Name` AS `Teacher.Name`,
Teachers.Family AS `Teacher.Family`,
Teachers.Username AS `Teacher.UserName`,
Teachers.CodeMelli AS `Teacher.CodeMelli`,
Teachers.Passwd AS `Teacher.Passwd`,
Lectures.`Name` AS `Lecture.Name`,
Lectures.LectureId AS `Lecture.LectureId`,
Lectures.TedadVahed AS `Lecture.TedadVahed`,
Lectures.Tozihat AS `Lecture.Tozihat`,
Exams.ExamId AS `Exam.ExamId`,
Exams.Title AS `Exam.Title`,
Exams.Teacher AS `Exam.Teacher` ,
Exams.Saal AS `Exam.Saal`
FROM
Exams
INNER JOIN Teachers ON Teachers.TeacherId = Exams.Teacher
INNER JOIN Lectures ON Lectures.LectureId= Exams.Lecture
";
        if ($teacherId > 0) {
            $SQL.= " WHERE Exams.Teacher=" . $teacherId;
        }

        $db = new DataAccess();
        $result = $db->ExecuteSelect($SQL);
        $exams = array();
        $i = 0;
        while ($row = mysqli_fetch_array($result)) {
            //echo 'aasdas<br/>';
            $t = new Exam();
            $t->ExamId = $row['Exam.ExamId'];
            $t->Title = $row['Exam.Title'];
            $t->Saal = $row['Exam.Saal'];

            $teacher = new Teacher();
            $teacher->LectureId = $row['Teacher.TeacherId'];
            $teacher->Name = $row['Teacher.Name'];
            $teacher->Family = $row['Teacher.Family'];
            $teacher->CodeMelli = $row['Teacher.CodeMelli'];
            $teacher->Username = $row['Teacher.UserName'];
            $teacher->Passwd = $row['Teacher.Passwd'];

            $t->Teacher = $teacher;

            $lecture = new Lecture();
            $lecture->LectureId = $row['Lecture.LectureId'];
            $lecture->Name = $row['Lecture.Name'];
            $lecture->TedadVahed = $row['Lecture.TedadVahed'];
            $lecture->Tozihat = $row['Lecture.Tozihat'];
            $t->Lecture = $lecture;

            $exams[$i] = $t;
            $i++;
        }
        return $exams;
    }

    public static function GetExamsForClassRoom($classroomId) {
        $SQL = "SELECT
Teachers.TeacherId AS `Teacher.TeacherId`,
Teachers.`Name` AS `Teacher.Name`,
Teachers.Family AS `Teacher.Family`,
Teachers.Username AS `Teacher.UserName`,
Teachers.CodeMelli AS `Teacher.CodeMelli`,
Teachers.Passwd AS `Teacher.Passwd`,
Lectures.`Name` AS `Lecture.Name`,
Lectures.LectureId AS `Lecture.LectureId`,
Lectures.TedadVahed AS `Lecture.TedadVahed`,
Lectures.Tozihat AS `Lecture.Tozihat`,
Exams.ExamId AS `Exam.ExamId`,
Exams.Title AS `Exam.Title`,
Exams.Teacher AS `Exam.Teacher` ,
Exams.Saal AS `Exam.Saal`
FROM
Exams
INNER JOIN Teachers ON Teachers.TeacherId = Exams.Teacher
INNER JOIN Lectures ON Lectures.LectureId= Exams.Lecture
INNER JOIN ExamsClassRooms ON ExamsClassRooms.Exam= Exams.ExamId
 WHERE ExamsClassRooms.ClassRoom= $classroomId ";

        $db = new DataAccess();
        $result = $db->ExecuteSelect($SQL);
        $exams = array();
        $i = 0;
        while ($row = mysqli_fetch_array($result)) {
            //echo 'aasdas<br/>';
            $t = new Exam();
            $t->ExamId = $row['Exam.ExamId'];
            $t->Title = $row['Exam.Title'];
            $t->Saal = $row['Exam.Saal'];

            $teacher = new Teacher();
            $teacher->LectureId = $row['Teacher.TeacherId'];
            $teacher->Name = $row['Teacher.Name'];
            $teacher->Family = $row['Teacher.Family'];
            $teacher->CodeMelli = $row['Teacher.CodeMelli'];
            $teacher->Username = $row['Teacher.UserName'];
            $teacher->Passwd = $row['Teacher.Passwd'];

            $t->Teacher = $teacher;

            $lecture = new Lecture();
            $lecture->LectureId = $row['Lecture.LectureId'];
            $lecture->Name = $row['Lecture.Name'];
            $lecture->TedadVahed = $row['Lecture.TedadVahed'];
            $lecture->Tozihat = $row['Lecture.Tozihat'];
            $t->Lecture = $lecture;

            $exams[$i] = $t;
            $i++;
        }
        return $exams;
    }

    public static function GetOneExam($Id) {
        $SQL = "SELECT
Teachers.TeacherId AS `Teacher.TeacherId`,
Teachers.`Name` AS `Teacher.Name`,
Teachers.Family AS `Teacher.Family`,
Teachers.Username AS `Teacher.UserName`,
Teachers.CodeMelli AS `Teacher.CodeMelli`,
Teachers.Passwd AS `Teacher.Passwd`,
Lectures.`Name` AS `Lecture.Name`,
Lectures.LectureId AS `Lecture.LectureId`,
Lectures.TedadVahed AS `Lecture.TedadVahed`,
Lectures.Tozihat AS `Lecture.Tozihat`,
Exams.ExamId AS `Exam.ExamId`,
Exams.Title AS `Exam.Title`,
Exams.Teacher AS `Exam.Teacher` ,
Exams.Saal AS `Exam.Saal`
FROM
Exams
INNER JOIN Teachers ON Teachers.TeacherId = Exams.Teacher
INNER JOIN Lectures ON Lectures.LectureId= Exams.Lecture
 WHERE Exams.ExamId= " . $Id;
        $db = new DataAccess();
        $result = $db->ExecuteSelect($SQL);

        while ($row = mysqli_fetch_array($result)) {
            $t = new Exam();
            $t->ExamId = $row['Exam.ExamId'];
            $t->Title = $row['Exam.Title'];
            $t->Saal = $row['Exam.Saal'];

            $teacher = new Teacher();
            $teacher->LectureId = $row['Teacher.TeacherId'];
            $teacher->Name = $row['Teacher.Name'];
            $teacher->Family = $row['Teacher.Family'];
            $teacher->CodeMelli = $row['Teacher.CodeMelli'];
            $teacher->Username = $row['Teacher.UserName'];
            $teacher->Passwd = $row['Teacher.Passwd'];
            $t->Teacher = $teacher;

            $lecture = new Lecture();
            $lecture->LectureId = $row['Lecture.LectureId'];
            $lecture->Name = $row['Lecture.Name'];
            $lecture->TedadVahed = $row['Lecture.TedadVahed'];
            $lecture->Tozihat = $row['Lecture.Tozihat'];
            $t->Lecture = $lecture;
            return $t;
        }
    }

    public static function AssignQuestions(Exam $exam, $questions, $teacherId = 0) {
        //echo $teacherId;
        if ($teacherId == 0) {
            $qustns = QuestionEx::GetQuestionsForLectureAndSaal($exam->Lecture->LectureId, $exam->Saal);
        } else {
            $qustns = QuestionEx::GetQuestionsForLectureAndSaalAndTeacher($exam->Lecture->LectureId, $exam->Saal, $teacherId);
        }
        foreach ($questions as $question) {
            $SQL = "SELECT * FROM ExamsQuestions WHERE Exam=" . $exam->ExamId . " AND Question= " . $question;
            $db = new DataAccess();
            if (mysqli_num_rows($db->ExecuteSelect($SQL)) == 0) {
                $SQL = "INSERT INTO ExamsQuestions (Exam,Question) VALUES (" . $exam->ExamId . "," . $question . ")";
                $db = new DataAccess();
                $db->Execute($SQL);
            }

            for ($i = 0; $i < count($qustns); $i++) {
                $id = $qustns[$i]->QuestionId;
                if ($question == $id) {
                    unset($qustns[$i]);
                    $qustns = array_values($qustns);
                    break;
                }
            }
        }

        foreach ($qustns as $qustn) {
//            $SQL = "SELECT * FROM StudentsClassRooms WHERE Student=" . $student->StudentId . " AND ClassRoom=" . $classroom->ClassRoomId;
//            $db = new DataAccess();
//            $cls = $db->ExecuteSelect($SQL);
//            if (mysqli_num_rows($cls) > 0) {
//                $rows = mysqli_fetch_array($cls);
//                $clsstd = $rows["StudentClassRoomId"];
//                $SQL = "DELETE FROM Grades WHERE StudentClassRoom=" . $clsstd;
//                $db = new DataAccess();
//                $db->Execute($SQL);
//            }
            $SQL = "DELETE FROM ExamsQuestions WHERE Exam=" . $exam->ExamId . " AND Question=" . $qustn->QuestionId;
            //echo $SQL;
            $db = new DataAccess();
            $db->Execute($SQL);
        }
    }

    public static function AssignClassRooms(Exam $exam, $classrooms, $termId) {
        //echo $exam->Saal;
        $clsrms = ClassRoomEx::GetClassRoomsForTermBasedOnLectureAndSaal($termId, $exam->Lecture->LectureId, $exam->Saal);
        //echo "E:" . count($clsrms);
        //echo "F:" .count($classrooms);
        foreach ($classrooms as $classroom) {
            $SQL = "SELECT * FROM ExamsClassRooms WHERE Exam=" . $exam->ExamId . " AND ClassRoom= " . $classroom;
            echo $SQL . "<br/>";
            $db = new DataAccess();
            if (mysqli_num_rows($db->ExecuteSelect($SQL)) == 0) {
                $SQL = "INSERT INTO ExamsClassRooms (Exam,ClassRoom) VALUES (" . $exam->ExamId . "," . $classroom . ")";
                $db = new DataAccess();
                $db->Execute($SQL);
            }

            for ($i = 0; $i < count($clsrms); $i++) {
                $id = $clsrms[$i]->ClassRoomId;
                if ($classroom == $id) {
                    unset($clsrms[$i]);
                    $clsrms = array_values($clsrms);
                    break;
                }
            }
        }

        foreach ($clsrms as $clsrm) {
//            $SQL = "SELECT * FROM StudentsClassRooms WHERE Student=" . $student->StudentId . " AND ClassRoom=" . $classroom->ClassRoomId;
//            $db = new DataAccess();
//            $cls = $db->ExecuteSelect($SQL);
//            if (mysqli_num_rows($cls) > 0) {
//                $rows = mysqli_fetch_array($cls);
//                $clsstd = $rows["StudentClassRoomId"];
//                $SQL = "DELETE FROM Grades WHERE StudentClassRoom=" . $clsstd;
//                $db = new DataAccess();
//                $db->Execute($SQL);
//            }
            $SQL = "DELETE FROM ExamsClassRooms WHERE Exam=" . $exam->ExamId . " AND ClassRoom=" . $clsrm->ClassRoomId;
            $db = new DataAccess();
            $db->Execute($SQL);
        }
    }

    public static function IsExamAnswered(Exam $exam, $studentId) {
        $SQL = "SELECT * FROM ExamsQuestions WHERE Exam=" . $exam->ExamId;
        $db = new DataAccess();
        $result = $db->ExecuteSelect($SQL);
        while ($row = mysqli_fetch_array($result)) {
            $id = $row['ExamQuestionId'];
            $SQL = "SELECT * FROM Answers WHERE ExamQuestion=" . $id . " AND Student=" . $studentId;
            $db = new DataAccess();
            $result = $db->ExecuteSelect($SQL);
            if (mysqli_num_rows($result) > 0) {
                return TRUE;    
            }
        }
        return FALSE;

//put your code here
    }

}
