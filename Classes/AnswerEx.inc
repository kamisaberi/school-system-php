<?php

require_once 'Answer.inc';
require_once 'ClassRoomEx.inc';

//use DataAccess;
/**
 * Description of Answer
 *
 * @author kami
 */
class AnswerEx {

    public static function Insert(Answer $answer) {
        $SQL = "INSERT INTO Answers (Name,TedadVahed,Tozihat) VALUES ('" . $answer->Name . "'," . $answer->TedadVahed . ",'" . $answer->Tozihat . "')";
        $db = new DataAccess();
        $db->Execute($SQL);
    }

//$ts= new Answer();

    public static function Update(Answer $answer) {
        $SQL = "UPDATE Answers SET Name = '" . $answer->Name . "',TedadVahed = " . $answer->TedadVahed . ",Tozihat='" . $answer->Tozihat . "'  WHERE AnswerId=" . $answer->AnswerId;
//echo $SQL;
        $db = new DataAccess();
        $db->Execute($SQL);
    }

    public static function Delete(Answer $answer) {
        if (count(ClassRoomEx::GetClassRoomsForAnswer($answer->AnswerId)) > 0) {
            return;
        }
        $SQL = "DELETE FROM Answers WHERE AnswerId=" . $answer->AnswerId;
        $db = new DataAccess();
        $db->Execute($SQL);
    }

    function Test(Answer $answer) {
        $s = array();
        $t = new Answer();
        $t->Name = "ali";
        $s[0] = $t;
        $t1 = new Answer();
        $t1->Name = "reza";
        $s[1] = $t1;
        return $s;
    }

    public static function Fill() {
        $SQL = "SELECT * FROM Answers ";
        $db = new DataAccess();
        $result = $db->ExecuteSelect($SQL);
        $answers = array();
        $i = 0;
        while ($row = mysqli_fetch_array($result)) {
//echo 'aasdas<br/>';
            $t = new Answer();
            $t->AnswerId = $row['AnswerId'];
            $t->Name = $row['Name'];
            $t->TedadVahed = $row['TedadVahed'];
            $t->Tozihat = $row['Tozihat'];
            $answers[$i] = $t;
            $i++;
        }
        return $answers;
    }

    public static function GetOnAnswer($Id) {
        $SQL = "SELECT * FROM Answers WHERE AnswerId= " . $Id;
        $db = new DataAccess();
        $result = $db->ExecuteSelect($SQL);

        while ($row = mysqli_fetch_array($result)) {
            $t = new Answer();
            $t->AnswerId = $row['AnswerId'];
            $t->Name = $row['Name'];
            $t->TedadVahed = $row['TedadVahed'];
            $t->Tozihat = $row['Tozihat'];
            return $t;
        }
    }

    public static function InsertExamAnswers(Exam $exam, $questions, $answers, $studentid) {
        for ($i = 0; $i < count($questions); $i++) {
            $SQL = "SELECT * FROM ExamsQuestions WHERE Exam=" . $exam->ExamId . " AND Question= " . $questions[$i];
            $db = new DataAccess();
            $result = $db->ExecuteSelect($SQL);
            while ($row = mysqli_fetch_array($result)) {
                $id = $row['ExamQuestionId'];
//                $SQL = "SELECT * FROM Answers WHERE ExamQuestion=" . $id;
//                $db = new DataAccess();
//                $result = $db->ExecuteSelect($SQL);
                $SQL = "DELETE  FROM Answers WHERE ExamQuestion=" . $id . " AND Student=" . $studentid;
                $db = new DataAccess();
                $db->Execute($SQL);
                $SQL = "INSERT INTO Answers (Content,ExamQuestion,Student) VALUES('{$answers[$i]} ',$id , $studentid )";
                $db = new DataAccess();
                $db->Execute($SQL);
            }
        }
    }

    public static function GetAnswersForStudentAndExam($studentId, $examId) {
        $SQL = "SELECT
ExamsQuestions.ExamQuestionId AS `ExamQuestion.ExamQuestionId`,
ExamsQuestions.Exam AS `ExamQuestion.Exam`,
ExamsQuestions.Question AS `ExamQuestion.Question`,
Questions.QuestionId AS `Question.QuestionId`,
Questions.Content AS `Question.Content`,
Questions.QuestionType AS `Question.Type`,
Questions.Teacher AS `Question.Teacher`,
Questions.Lecture AS `Question.Lecture`,
Questions.Saal AS `Question.Saal`,
Exams.ExamId AS `Exam.ExamId`,
Exams.Title AS `Exam.Title`,
Exams.Teacher AS `Exam.Teacher`,
Exams.Lecture AS `Exam.Lecture`,
Exams.Saal AS `Exam.Saal`,
Answers.AnswerId AS `Answer.AnswerId`,
Answers.Content AS `Answer.Content`,
Answers.ExamQuestion AS `Answer.ExamQuestion`,
Answers.Student AS `Answer.Student`
FROM
ExamsQuestions
INNER JOIN Questions ON Questions.QuestionId = ExamsQuestions.Question
INNER JOIN Exams ON Exams.ExamId = ExamsQuestions.Exam
INNER JOIN Answers ON ExamsQuestions.ExamQuestionId = Answers.ExamQuestion
 WHERE Answers.Student= " . $studentId . " AND Exams.ExamId=" . $examId;
        $db = new DataAccess();
        $result = $db->ExecuteSelect($SQL);
        $answers = array();
        $i = 0;
        while ($row = mysqli_fetch_array($result)) {
//echo 'aasdas<br/>';
            $t = new Answer();
            $t->AnswerId = $row['Answer.AnswerId'];
            $t->Content = $row['Answer.Content'];
            $question= new Question();
            $question->Content=$row['Question.Content'];
            $t->Question =$question;
            $answers[$i] = $t;
            $i++;
        }
        return $answers;
    }

//put your code here
}
