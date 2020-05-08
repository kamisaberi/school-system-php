<?php

require_once 'Question.inc';
require_once 'QuestionType.inc';
require_once 'Lecture.inc';
require_once 'Teacher.inc';

//use DataAccess;
/**
 * Description of Question
 *
 * @author kami
 */
class QuestionEx {

    public static function Insert(Question $question) {
        $SQL = "INSERT INTO Questions (Content,QuestionType,Teacher,Lecture,Saal) VALUES ('" . $question->Content . "'," . $question->QuestionType->QuestionTypeId . "," . $question->Teacher->TeacherId . "," . $question->Lecture->LectureId . "," . $question->Saal . ")";
        //echo $SQL;
        $db = new DataAccess();
        $db->Execute($SQL);
    }

    public static function Update(Question $question) {
        $SQL = "UPDATE Questions SET Content = '" . $question->Content . "',QuestionType = " . $question->QuestionType->QuestionTypeId . ",Teacher=" . $question->Teacher->TeacherId . ",Lecture= " . $question->Lecture->LectureId . ",Saal= " . $question->Saal . " WHERE QuestionId=" . $question->QuestionId;
        echo $SQL;
        $db = new DataAccess();
        $db->Execute($SQL);
    }

    public static function Delete(Question $question) {
        $SQL = "DELETE FROM Questions WHERE QuestionId=" . $question->QuestionId;
        $db = new DataAccess();
        $db->Execute($SQL);
    }

    public static function Fill($teacherId = 0) {
        $SQL = "SELECT
QuestionTypes.QuestionTypeId AS `QuestionType.QuestionTypeId`,
QuestionTypes.`Name` AS `QuestionType.Name`,
QuestionTypes.Tozihat AS `QuestionType.Tozihat`,
Questions.Content AS `Question.Content`,
Questions.QuestionType AS `Question.QuestionType`,
Questions.Teacher AS `Question.Teacher`,
Questions.Lecture AS `Question.Lecture`,
Questions.Saal AS `Question.Saal`,
Questions.QuestionId AS `Question.QuestionId`,
Lectures.LectureId AS `Lecture.LectureId`,
Lectures.`Name` AS `Lecture.Name`,
Lectures.TedadVahed AS `Lecture.TedadVahed`,
Lectures.Tozihat AS `Lecture.Tozihat`,
Teachers.TeacherId AS `Teacher.TeacherId`,
Teachers.`Name` AS `Teacher.Name`,
Teachers.Family AS `Teacher.Family`,
Teachers.Username AS `Teacher.Username`,
Teachers.CodeMelli AS `Teacher.CodeMelli`,
Teachers.Passwd AS `Teacher.Passwd`
FROM
Questions
INNER JOIN QuestionTypes ON QuestionTypes.QuestionTypeId = Questions.QuestionType
INNER JOIN Lectures ON Lectures.LectureId = Questions.Lecture
INNER JOIN Teachers ON Teachers.TeacherId = Questions.Teacher ";
        if ($teacherId > 0) {
            $SQL.=" WHERE Questions.Teacher=" . $teacherId;
        }
        $db = new DataAccess();
        $result = $db->ExecuteSelect($SQL);
        $Questions = array();
        $i = 0;
        while ($row = mysqli_fetch_array($result)) {
            $q = new Question();
            $q->QuestionId = $row['Question.QuestionId'];
            $q->Content = $row['Question.Content'];
            $q->Saal = $row['Question.Saal'];


            $questionType = new QuestionType();
            $questionType->QuestionTypeId = $row['QuestionType.QuestionTypeId'];
            $questionType->Name = $row['QuestionType.Name'];
            $questionType->Tozihat = $row['QuestionType.Tozihat'];
            $q->QuestionType = $questionType;

            $teacher = new Teacher();
            $teacher->TeacherId = $row['Teacher.TeacherId'];
            $teacher->Name = $row['Teacher.Name'];
            $teacher->Family = $row['Teacher.Family'];
            $teacher->Username = $row['Teacher.Username'];
            $teacher->CodeMelli = $row['Teacher.CodeMelli'];
            $teacher->Passwd = $row['Teacher.Passwd'];
            $q->Teacher = $teacher;

            $lecture = new Lecture();
            $lecture->LectureId = $row['Lecture.LectureId'];
            $lecture->Name = $row['Lecture.Name'];
            $lecture->TedadVahed = $row['Lecture.TedadVahed'];
            $lecture->Tozihat = $row['Lecture.Tozihat'];
            $q->Lecture = $lecture;
            $Questions[$i] = $q;
            $i++;
        }
        return $Questions;
    }

    public static function GetQuestionsForLectureAndSaal($lectureId, $saal) {
        // echo $saal . "<br/>";
        $SQL = "SELECT
QuestionTypes.QuestionTypeId AS `QuestionType.QuestionTypeId`,
QuestionTypes.`Name` AS `QuestionType.Name`,
QuestionTypes.Tozihat AS `QuestionType.Tozihat`,
Questions.Content AS `Question.Content`,
Questions.QuestionType AS `Question.QuestionType`,
Questions.Teacher AS `Question.Teacher`,
Questions.Lecture AS `Question.Lecture`,
Questions.Saal AS `Question.Saal`,
Questions.QuestionId AS `Question.QuestionId`,
Lectures.LectureId AS `Lecture.LectureId`,
Lectures.`Name` AS `Lecture.Name`,
Lectures.TedadVahed AS `Lecture.TedadVahed`,
Lectures.Tozihat AS `Lecture.Tozihat`,
Teachers.TeacherId AS `Teacher.TeacherId`,
Teachers.`Name` AS `Teacher.Name`,
Teachers.Family AS `Teacher.Family`,
Teachers.Username AS `Teacher.Username`,
Teachers.CodeMelli AS `Teacher.CodeMelli`,
Teachers.Passwd AS `Teacher.Passwd`
FROM
Questions
INNER JOIN QuestionTypes ON QuestionTypes.QuestionTypeId = Questions.QuestionType
INNER JOIN Lectures ON Lectures.LectureId = Questions.Lecture
INNER JOIN Teachers ON Teachers.TeacherId = Questions.Teacher 
 WHERE Questions.Lecture=" . $lectureId . " AND Questions.Saal=" . $saal;
        //echo $SQL;
        $db = new DataAccess();
        $result = $db->ExecuteSelect($SQL);
        $Questions = array();
        $i = 0;
        while ($row = mysqli_fetch_array($result)) {
            $q = new Question();
            $q->QuestionId = $row['Question.QuestionId'];
            $q->Content = $row['Question.Content'];
            $q->Saal = $row['Question.Saal'];


            $questionType = new QuestionType();
            $questionType->QuestionTypeId = $row['QuestionType.QuestionTypeId'];
            $questionType->Name = $row['QuestionType.Name'];
            $questionType->Tozihat = $row['QuestionType.Tozihat'];
            $q->QuestionType = $questionType;

            $teacher = new Teacher();
            $teacher->TeacherId = $row['Teacher.TeacherId'];
            $teacher->Name = $row['Teacher.Name'];
            $teacher->Family = $row['Teacher.Family'];
            $teacher->Username = $row['Teacher.Username'];
            $teacher->CodeMelli = $row['Teacher.CodeMelli'];
            $teacher->Passwd = $row['Teacher.Passwd'];
            $q->Teacher = $teacher;

            $lecture = new Lecture();
            $lecture->LectureId = $row['Lecture.LectureId'];
            $lecture->Name = $row['Lecture.Name'];
            $lecture->TedadVahed = $row['Lecture.TedadVahed'];
            $lecture->Tozihat = $row['Lecture.Tozihat'];
            $q->Lecture = $lecture;
            $Questions[$i] = $q;
            $i++;
        }
        return $Questions;
    }

    public static function GetQuestionsForLectureAndSaalAndTeacher($lectureId, $saal, $teacherId) {
        //echo $saal;
        $SQL = "SELECT
QuestionTypes.QuestionTypeId AS `QuestionType.QuestionTypeId`,
QuestionTypes.`Name` AS `QuestionType.Name`,
QuestionTypes.Tozihat AS `QuestionType.Tozihat`,
Questions.Content AS `Question.Content`,
Questions.QuestionType AS `Question.QuestionType`,
Questions.Teacher AS `Question.Teacher`,
Questions.Lecture AS `Question.Lecture`,
Questions.Saal AS `Question.Saal`,
Questions.QuestionId AS `Question.QuestionId`,
Lectures.LectureId AS `Lecture.LectureId`,
Lectures.`Name` AS `Lecture.Name`,
Lectures.TedadVahed AS `Lecture.TedadVahed`,
Lectures.Tozihat AS `Lecture.Tozihat`,
Teachers.TeacherId AS `Teacher.TeacherId`,
Teachers.`Name` AS `Teacher.Name`,
Teachers.Family AS `Teacher.Family`,
Teachers.Username AS `Teacher.Username`,
Teachers.CodeMelli AS `Teacher.CodeMelli`,
Teachers.Passwd AS `Teacher.Passwd`
FROM
Questions
INNER JOIN QuestionTypes ON QuestionTypes.QuestionTypeId = Questions.QuestionType
INNER JOIN Lectures ON Lectures.LectureId = Questions.Lecture
INNER JOIN Teachers ON Teachers.TeacherId = Questions.Teacher 
 WHERE Questions.Lecture=$lectureId AND Questions.Saal=$saal AND Questions.Teacher=$teacherId";
        // echo $SQL;
        $db = new DataAccess();
        $result = $db->ExecuteSelect($SQL);
        $Questions = array();
        $i = 0;
        while ($row = mysqli_fetch_array($result)) {
            $q = new Question();
            $q->QuestionId = $row['Question.QuestionId'];
            $q->Content = $row['Question.Content'];
            $q->Saal = $row['Question.Saal'];


            $questionType = new QuestionType();
            $questionType->QuestionTypeId = $row['QuestionType.QuestionTypeId'];
            $questionType->Name = $row['QuestionType.Name'];
            $questionType->Tozihat = $row['QuestionType.Tozihat'];
            $q->QuestionType = $questionType;

            $teacher = new Teacher();
            $teacher->TeacherId = $row['Teacher.TeacherId'];
            $teacher->Name = $row['Teacher.Name'];
            $teacher->Family = $row['Teacher.Family'];
            $teacher->Username = $row['Teacher.Username'];
            $teacher->CodeMelli = $row['Teacher.CodeMelli'];
            $teacher->Passwd = $row['Teacher.Passwd'];
            $q->Teacher = $teacher;

            $lecture = new Lecture();
            $lecture->LectureId = $row['Lecture.LectureId'];
            $lecture->Name = $row['Lecture.Name'];
            $lecture->TedadVahed = $row['Lecture.TedadVahed'];
            $lecture->Tozihat = $row['Lecture.Tozihat'];
            $q->Lecture = $lecture;
            $Questions[$i] = $q;
            $i++;
        }
        return $Questions;
    }

    public static function GetOneQuestion($Id) {
        $SQL = "SELECT
QuestionTypes.QuestionTypeId AS `QuestionType.QuestionTypeId`,
QuestionTypes.`Name` AS `QuestionType.Name`,
QuestionTypes.Tozihat AS `QuestionType.Tozihat`,
Questions.Content AS `Question.Content`,
Questions.QuestionType AS `Question.QuestionType`,
Questions.Teacher AS `Question.Teacher`,
Questions.Lecture AS `Question.Lecture`,
Questions.Saal AS `Question.Saal`,
Questions.QuestionId AS `Question.QuestionId`,
Lectures.LectureId AS `Lecture.LectureId`,
Lectures.`Name` AS `Lecture.Name`,
Lectures.TedadVahed AS `Lecture.TedadVahed`,
Lectures.Tozihat AS `Lecture.Tozihat`,
Teachers.TeacherId AS `Teacher.TeacherId`,
Teachers.`Name` AS `Teacher.Name`,
Teachers.Family AS `Teacher.Family`,
Teachers.Username AS `Teacher.Username`,
Teachers.CodeMelli AS `Teacher.CodeMelli`,
Teachers.Passwd AS `Teacher.Passwd`
FROM
Questions
INNER JOIN QuestionTypes ON QuestionTypes.QuestionTypeId = Questions.QuestionType
INNER JOIN Lectures ON Lectures.LectureId = Questions.Lecture
INNER JOIN Teachers ON Teachers.TeacherId = Questions.Teacher 
 WHERE QuestionId= " . $Id;
        $db = new DataAccess();
        $result = $db->ExecuteSelect($SQL);

        while ($row = mysqli_fetch_array($result)) {
            $q = new Question();
            $q->QuestionId = $row['Question.QuestionId'];
            $q->Content = $row['Question.Content'];
            $q->Saal = $row['Question.Saal'];

            $questionType = new QuestionType();
            $questionType->QuestionTypeId = $row['QuestionType.QuestionTypeId'];
            $questionType->Name = $row['QuestionType.Name'];
            $questionType->Tozihat = $row['QuestionType.Tozihat'];
            $q->QuestionType = $questionType;

            $teacher = new Teacher();
            $teacher->TeacherId = $row['Teacher.TeacherId'];
            $teacher->Name = $row['Teacher.Name'];
            $teacher->Family = $row['Teacher.Family'];
            $teacher->Username = $row['Teacher.Username'];
            $teacher->CodeMelli = $row['Teacher.CodeMelli'];
            $teacher->Passwd = $row['Teacher.Passwd'];
            $q->Teacher = $teacher;

            $lecture = new Lecture();
            $lecture->LectureId = $row['Lecture.LectureId'];
            $lecture->Name = $row['Lecture.Name'];
            $lecture->TedadVahed = $row['Lecture.TedadVahed'];
            $lecture->Tozihat = $row['Lecture.Tozihat'];
            $q->Lecture = $lecture;
            return $q;
        }
    }

    public static function GetQuestionsForTeacher($teacherId) {
        $SQL = "SELECT
QuestionTypes.QuestionTypeId AS `QuestionType.QuestionTypeId`,
QuestionTypes.`Name` AS `QuestionType.Name`,
QuestionTypes.Tozihat AS `QuestionType.Tozihat`,
Questions.Content AS `Question.Content`,
Questions.QuestionType AS `Question.QuestionType`,
Questions.Teacher AS `Question.Teacher`,
Questions.Lecture AS `Question.Lecture`,
Questions.Saal AS `Question.Saal`,
Questions.QuestionId AS `Question.QuestionId`,
Lectures.LectureId AS `Lecture.LectureId`,
Lectures.`Name` AS `Lecture.Name`,
Lectures.TedadVahed AS `Lecture.TedadVahed`,
Lectures.Tozihat AS `Lecture.Tozihat`,
Teachers.TeacherId AS `Teacher.TeacherId`,
Teachers.`Name` AS `Teacher.Name`,
Teachers.Family AS `Teacher.Family`,
Teachers.Username AS `Teacher.Username`,
Teachers.CodeMelli AS `Teacher.CodeMelli`,
Teachers.Passwd AS `Teacher.Passwd`
FROM
Questions
INNER JOIN QuestionTypes ON QuestionTypes.QuestionTypeId = Questions.QuestionType
INNER JOIN Lectures ON Lectures.LectureId = Questions.Lecture
INNER JOIN Teachers ON Teachers.TeacherId = Questions.Teacher 
 WHERE Questions.Teacher = " . $teacherId;
        $db = new DataAccess();
        $result = $db->ExecuteSelect($SQL);
        $Questions = array();
        $i = 0;
        while ($row = mysqli_fetch_array($result)) {
            $q = new Question();
            $q->QuestionId = $row['Question.QuestionId'];
            $q->Content = $row['Question.Content'];
            $q->Saal = $row['Question.Saal'];


            $questionType = new QuestionType();
            $questionType->QuestionTypeId = $row['QuestionType.QuestionTypeId'];
            $questionType->Name = $row['QuestionType.Name'];
            $questionType->Tozihat = $row['QuestionType.Tozihat'];
            $q->QuestionType = $questionType;

            $teacher = new Teacher();
            $teacher->TeacherId = $row['Teacher.TeacherId'];
            $teacher->Name = $row['Teacher.Name'];
            $teacher->Family = $row['Teacher.Family'];
            $teacher->Username = $row['Teacher.Username'];
            $teacher->CodeMelli = $row['Teacher.CodeMelli'];
            $teacher->Passwd = $row['Teacher.Passwd'];
            $q->Teacher = $teacher;

            $lecture = new Lecture();
            $lecture->LectureId = $row['Lecture.LectureId'];
            $lecture->Name = $row['Lecture.Name'];
            $lecture->TedadVahed = $row['Lecture.TedadVahed'];
            $lecture->Tozihat = $row['Lecture.Tozihat'];
            $q->Lecture = $lecture;
            $Questions[$i] = $q;
            $i++;
        }
        return $Questions;
    }

    public static function GetQuestionsForExam($examId) {
        $SQL = "SELECT
Questions.QuestionId AS `Question.QuestionId`,
Questions.Content AS `Question.Content`,
Questions.QuestionType AS `Question.QuestionType`,
Questions.Teacher AS `Question.Teacher`,
Questions.Lecture AS `Question.Lecture`,
Questions.Saal AS `Question.Saal`
FROM
Exams
INNER JOIN ExamsQuestions ON ExamsQuestions.Exam = Exams.ExamId
INNER JOIN Questions ON Questions.QuestionId = ExamsQuestions.Question
 WHERE Exams.ExamId= " . $examId;
        $db = new DataAccess();
        $result = $db->ExecuteSelect($SQL);
        $Questions = array();
        $i = 0;
        while ($row = mysqli_fetch_array($result)) {
            $q = new Question();
            $q->QuestionId = $row['Question.QuestionId'];
            $q->Content = $row['Question.Content'];
            $q->Saal = $row['Question.Saal'];

            $questionType = new QuestionType();
            $questionType->QuestionTypeId = $row['Question.QuestionType'];
//            $questionType->Name = $row['QuestionType.Name'];
//            $questionType->Tozihat = $row['QuestionType.Tozihat'];
            $q->QuestionType = $questionType;

            $teacher = new Teacher();
            $teacher->TeacherId = $row['Question.Teacher'];
//            $teacher->Name = $row['Teacher.Name'];
//            $teacher->Family = $row['Teacher.Family'];
//            $teacher->Username = $row['Teacher.Username'];
//            $teacher->CodeMelli = $row['Teacher.CodeMelli'];
//            $teacher->Passwd = $row['Teacher.Passwd'];
            $q->Teacher = $teacher;

            $lecture = new Lecture();
            $lecture->LectureId = $row['Question.Lecture'];
//            $lecture->Name = $row['Lecture.Name'];
//            $lecture->TedadVahed = $row['Lecture.TedadVahed'];
//            $lecture->Tozihat = $row['Lecture.Tozihat'];
            $q->Lecture = $lecture;
            $Questions[$i] = $q;
            $i++;
        }
        return $Questions;
    }

    public static function GetClassRoomsForLectureAndSaal($lectureId, $saal) {

        $SQL = "SELECT
QuestionTypes.QuestionTypeId AS `QuestionType.QuestionTypeId`,
QuestionTypes.`Name` AS `QuestionType.Name`,
QuestionTypes.Tozihat AS `QuestionType.Tozihat`,
Questions.Content AS `Question.Content`,
Questions.QuestionType AS `Question.QuestionType`,
Questions.Teacher AS `Question.Teacher`,
Questions.Lecture AS `Question.Lecture`,
Questions.Saal AS `Question.Saal`,
Questions.QuestionId AS `Question.QuestionId`,
Lectures.LectureId AS `Lecture.LectureId`,
Lectures.`Name` AS `Lecture.Name`,
Lectures.TedadVahed AS `Lecture.TedadVahed`,
Lectures.Tozihat AS `Lecture.Tozihat`,
Teachers.TeacherId AS `Teacher.TeacherId`,
Teachers.`Name` AS `Teacher.Name`,
Teachers.Family AS `Teacher.Family`,
Teachers.Username AS `Teacher.Username`,
Teachers.CodeMelli AS `Teacher.CodeMelli`,
Teachers.Passwd AS `Teacher.Passwd`
FROM
Questions
INNER JOIN QuestionTypes ON QuestionTypes.QuestionTypeId = Questions.QuestionType
INNER JOIN Lectures ON Lectures.LectureId = Questions.Lecture
INNER JOIN Teachers ON Teachers.TeacherId = Questions.Teacher 
 WHERE Questions.Lecture =  $lectureId  AND Questions.Saal = $saal";
        $db = new DataAccess();
        $result = $db->ExecuteSelect($SQL);
        $Questions = array();
        $i = 0;
        while ($row = mysqli_fetch_array($result)) {
            $q = new Question();
            $q->QuestionId = $row['Question.QuestionId'];
            $q->Content = $row['Question.Content'];
            $q->Saal = $row['Question.Saal'];


            $questionType = new QuestionType();
            $questionType->QuestionTypeId = $row['QuestionType.QuestionTypeId'];
            $questionType->Name = $row['QuestionType.Name'];
            $questionType->Tozihat = $row['QuestionType.Tozihat'];
            $q->QuestionType = $questionType;

            $teacher = new Teacher();
            $teacher->TeacherId = $row['Teacher.TeacherId'];
            $teacher->Name = $row['Teacher.Name'];
            $teacher->Family = $row['Teacher.Family'];
            $teacher->Username = $row['Teacher.Username'];
            $teacher->CodeMelli = $row['Teacher.CodeMelli'];
            $teacher->Passwd = $row['Teacher.Passwd'];
            $q->Teacher = $teacher;

            $lecture = new Lecture();
            $lecture->LectureId = $row['Lecture.LectureId'];
            $lecture->Name = $row['Lecture.Name'];
            $lecture->TedadVahed = $row['Lecture.TedadVahed'];
            $lecture->Tozihat = $row['Lecture.Tozihat'];
            $q->Lecture = $lecture;
            $Questions[$i] = $q;
            $i++;
        }
        return $Questions;
    }

    public static function AssignClassRooms(Question $question, $ClassRooms) {
        //echo $question->QuestionId . "<br/>";
        $SQL = "DELETE FROM QuestionsClassRooms WHERE Question=" . $question->QuestionId;
        $db = new DataAccess();
        $db->Execute($SQL);
        foreach ($ClassRooms as $class) {
            //echo $class . "<br/>";
            $SQL = "INSERT INTO QuestionsClassRooms (Question,ClassRoom) VALUES (" . $question->QuestionId . "," . $class . ")";
            $db = new DataAccess();
            $db->Execute($SQL);
        }
    }

    public static function AssignTerms(Question $question, $Terms) {
        //echo $question->QuestionId . "<br/>";
        foreach ($Terms as $term) {
            //echo $class . "<br/>";
            $SQL = "INSERT INTO QuestionsTerms (Question,Term) VALUES (" . $question->QuestionId . "," . $term . ")";
            $db = new DataAccess();
            $db->Execute($SQL);
        }
    }

    public static function GetQuestionsOfActiveTermForClassRoom($classroomId, $termId) {
        $SQL = "SELECT
ClassRooms.Lecture AS `ClassRoom.Lecture`,
ClassRooms.Saal AS `ClassRoom.Saal`,
ClassRooms.Teacher AS `ClassRoom.Teacher`,
ClassRooms.`Content` AS `ClassRoom.Content`,
Questions.`Content` AS `Question.Content`,
Questions.QuestionType AS `Question.QuestionType`,
Questions.Teacher AS `Question.Teacher`,
Questions.QuestionId AS `Question.QuestionId`,
ClassRooms.ClassRoomId AS `ClassRoom.ClassRoomId`,
ClassRooms.Term AS `ClassRoom.Term`,
Questions.Lecture AS `Question.Lecture`,
QuestionsClassRooms.QuestionClassRoomId AS `QuestionClassRoom.QuestionClassRoomId`,
QuestionsClassRooms.Question AS `QuestionClassRoom.Question`,
QuestionsClassRooms.ClassRoom AS `QuestionClassRoom.ClassRoom`,
Lectures.LectureId AS `Lecture.LectureId`,
Lectures.`Content` AS `Lecture.Content`,
Lectures.TedadVahed AS `Lecture.TedadVahed`,
Lectures.Tozihat AS `Lecture.Tozihat`,
Teachers.TeacherId AS `Teacher.TeacherId`,
Teachers.`Content` AS `Teacher.Content`,
Teachers.QuestionType AS `Teacher.QuestionType`,
Teachers.Username AS `Teacher.UserContent`,
Teachers.Lecture AS `Teacher.Lecture`,
Terms.TermId AS `Term.TermId`,
Terms.SalShoroo AS `Term.SalShoroo`,
Terms.SalPayan AS 'Term.SalPayan',
Terms.NimSal AS `Term.NimSal`,
Terms.Tozihat AS `Term.Tozihat`
FROM
ClassRooms
INNER JOIN QuestionsClassRooms ON ClassRooms.ClassRoomId = QuestionsClassRooms.ClassRoom
INNER JOIN Questions ON Questions.QuestionId = QuestionsClassRooms.Question
INNER JOIN Lectures ON Lectures.LectureId = ClassRooms.Lecture
INNER JOIN Teachers ON Teachers.TeacherId = ClassRooms.Teacher
INNER JOIN Terms ON Terms.TermId = ClassRooms.Term
WHERE
ClassRooms.ClassRoomId =" . $classroomId . " AND ClassRooms.Term= " . $termId . " ";

        $db = new DataAccess();
        $result = $db->ExecuteSelect($SQL);
        $Questions = array();
        $i = 0;
        while ($row = mysqli_fetch_array($result)) {
            //echo 'aasdas<br/>';
            $question = new Question();
            $question->QuestionId = $row['Question.QuestionId'];
            $question->Content = $row['Question.Content'];
            $question->QuestionType = $row['Question.QuestionType'];
            $question->Teacher = $row['Question.Teacher'];
            $question->Lecture = $row['Question.Lecture'];
            $Questions[$i] = $question;
            $i++;
        }
        return $Questions;
    }

    public static function GetQuestionsOfActiveTermForTeacher($teacherId, $termId) {
        $SQL = "SELECT
ClassRooms.Lecture AS `ClassRoom.Lecture`,
ClassRooms.Saal AS `ClassRoom.Saal`,
ClassRooms.Teacher AS `ClassRoom.Teacher`,
ClassRooms.`Content` AS `ClassRoom.Content`,
Questions.`Content` AS `Question.Content`,
Questions.QuestionType AS `Question.QuestionType`,
Questions.Teacher AS `Question.Teacher`,
Questions.QuestionId AS `Question.QuestionId`,
ClassRooms.ClassRoomId AS `ClassRoom.ClassRoomId`,
ClassRooms.Term AS `ClassRoom.Term`,
Questions.Lecture AS `Question.Lecture`,
QuestionsClassRooms.QuestionClassRoomId AS `QuestionClassRoom.QuestionClassRoomId`,
QuestionsClassRooms.Question AS `QuestionClassRoom.Question`,
QuestionsClassRooms.ClassRoom AS `QuestionClassRoom.ClassRoom`,
Lectures.LectureId AS `Lecture.LectureId`,
Lectures.`Content` AS `Lecture.Content`,
Lectures.TedadVahed AS `Lecture.TedadVahed`,
Lectures.Tozihat AS `Lecture.Tozihat`,
Teachers.TeacherId AS `Teacher.TeacherId`,
Teachers.`Content` AS `Teacher.Content`,
Teachers.QuestionType AS `Teacher.QuestionType`,
Teachers.Username AS `Teacher.UserContent`,
Teachers.Lecture AS `Teacher.Lecture`,
Terms.TermId AS `Term.TermId`,
Terms.SalShoroo AS `Term.SalShoroo`,
Terms.SalPayan AS 'Term.SalPayan',
Terms.NimSal AS `Term.NimSal`,
Terms.Tozihat AS `Term.Tozihat`
FROM
ClassRooms
INNER JOIN QuestionsClassRooms ON ClassRooms.ClassRoomId = QuestionsClassRooms.ClassRoom
INNER JOIN Questions ON Questions.QuestionId = QuestionsClassRooms.Question
INNER JOIN Lectures ON Lectures.LectureId = ClassRooms.Lecture
INNER JOIN Teachers ON Teachers.TeacherId = ClassRooms.Teacher
INNER JOIN Terms ON Terms.TermId = ClassRooms.Term  
WHERE
ClassRooms.Teacher=" . $teacherId . " AND ClassRooms.Term= " . $termId . " ";
        //echo $SQL;
        $db = new DataAccess();
        $result = $db->ExecuteSelect($SQL);
        $Questions = array();
        $i = 0;
        while ($row = mysqli_fetch_array($result)) {
            //echo 'aasdas<br/>';
            $question = new Question();
            $question->QuestionId = $row['Question.QuestionId'];
            $question->Content = $row['Question.Content'];
            $question->QuestionType = $row['Question.QuestionType'];
            $question->Teacher = $row['Question.Teacher'];
            $question->Lecture = $row['Question.Lecture'];
            $Questions[$i] = $question;
            $i++;
        }
        return $Questions;
    }

    public static function CheckQuestionIsRegisterInClassRoomForActiveTerm($classroomId, $questionId) {
        $SQL = "SELECT * FROM QuestionsClassRooms WHERE Question=" . $questionId . " AND ClassRoom=" . $classroomId;
        //echo $SQL;
        $db = new DataAccess();
        $result = $db->ExecuteSelect($SQL);
        if (mysqli_num_rows($result) > 0)
            return TRUE;
        return FALSE;
    }

    public static function Login($username, $password) {
        $SQL = "SELECT * FROM Questions WHERE Teacher= '" . $username . "' AND Lecture='" . md5($password) . "'";
        //echo $SQL;
        $db = new DataAccess();
        $result = $db->ExecuteSelect($SQL);
        if (mysqli_num_rows($result) > 0)
            return TRUE;
        return FALSE;
    }

    public static function CheckExists($codemelli) {
        $SQL = "SELECT * FROM Questions WHERE Teacher= '" . $codemelli . "'";
        //echo $SQL;
        $db = new DataAccess();
        $result = $db->ExecuteSelect($SQL);
        if (mysqli_num_rows($result) > 0)
            return TRUE;
        return FALSE;
    }

    public static function CheckQuestionIsRegisterForExam($questionId, $examId) {
        $SQL = "SELECT * FROM ExamsQuestions WHERE Exam= $examId AND Question=$questionId";
        //echo $SQL;
        $db = new DataAccess();
        $result = $db->ExecuteSelect($SQL);
        if (mysqli_num_rows($result) > 0)
            return TRUE;
        return FALSE;
    }

//put your code here
}
