/*
Navicat MySQL Data Transfer

Source Server         : MySQL
Source Server Version : 50611
Source Host           : localhost:3306
Source Database       : school

Target Server Type    : MYSQL
Target Server Version : 50611
File Encoding         : 65001

Date: 2014-11-07 09:23:54
*/

SET FOREIGN_KEY_CHECKS=0;

-- ----------------------------
-- Table structure for Answers
-- ----------------------------
DROP TABLE IF EXISTS `Answers`;
CREATE TABLE `Answers` (
  `AnswerId` bigint(255) NOT NULL AUTO_INCREMENT,
  `Content` text COLLATE utf8_persian_ci,
  `ExamQuestion` bigint(255) DEFAULT NULL,
  `Student` bigint(255) DEFAULT NULL,
  PRIMARY KEY (`AnswerId`)
) ENGINE=InnoDB AUTO_INCREMENT=9 DEFAULT CHARSET=utf8 COLLATE=utf8_persian_ci;

-- ----------------------------
-- Records of Answers
-- ----------------------------
INSERT INTO `Answers` VALUES ('8', '4 ', '4', '1');

-- ----------------------------
-- Table structure for classrooms
-- ----------------------------
DROP TABLE IF EXISTS `classrooms`;
CREATE TABLE `classrooms` (
  `ClassRoomId` bigint(20) NOT NULL AUTO_INCREMENT,
  `Name` varchar(255) COLLATE utf8_persian_ci DEFAULT NULL,
  `Term` bigint(255) DEFAULT NULL,
  `Lecture` bigint(255) DEFAULT NULL,
  `Saal` bigint(255) DEFAULT NULL COMMENT 'saal chandom madrese mesal : saal 1 , 2 , 3',
  `Teacher` bigint(255) DEFAULT NULL,
  `GradeType` bigint(255) DEFAULT NULL,
  PRIMARY KEY (`ClassRoomId`)
) ENGINE=InnoDB AUTO_INCREMENT=9 DEFAULT CHARSET=utf8 COLLATE=utf8_persian_ci;

-- ----------------------------
-- Records of classrooms
-- ----------------------------
INSERT INTO `classrooms` VALUES ('1', 'ریاضی الف', '1', '1', '1', '5', '1');
INSERT INTO `classrooms` VALUES ('4', 'فیزیک الف', '2', '2', '1', '2', '1');
INSERT INTO `classrooms` VALUES ('5', 'دینی الف', '1', '3', '10', '2', '2');
INSERT INTO `classrooms` VALUES ('7', 'فیزیک ج', '1', '3', '1', '2', '1');
INSERT INTO `classrooms` VALUES ('8', 'ریاضی  اول', '1', '1', '1', '5', '6');

-- ----------------------------
-- Table structure for Exams
-- ----------------------------
DROP TABLE IF EXISTS `Exams`;
CREATE TABLE `Exams` (
  `ExamId` bigint(20) NOT NULL AUTO_INCREMENT,
  `Title` text COLLATE utf8_persian_ci,
  `Teacher` bigint(255) DEFAULT NULL,
  `Lecture` bigint(255) DEFAULT NULL,
  `Saal` bigint(255) DEFAULT NULL,
  PRIMARY KEY (`ExamId`)
) ENGINE=InnoDB AUTO_INCREMENT=4 DEFAULT CHARSET=utf8 COLLATE=utf8_persian_ci;

-- ----------------------------
-- Records of Exams
-- ----------------------------
INSERT INTO `Exams` VALUES ('1', 'آزمون ریاضی میان ترم', '2', '1', '1');
INSERT INTO `Exams` VALUES ('3', 'test', '5', '1', '6');

-- ----------------------------
-- Table structure for ExamsClassRooms
-- ----------------------------
DROP TABLE IF EXISTS `ExamsClassRooms`;
CREATE TABLE `ExamsClassRooms` (
  `ExamClassRoomId` bigint(20) NOT NULL AUTO_INCREMENT,
  `Exam` bigint(255) DEFAULT NULL,
  `ClassRoom` bigint(255) DEFAULT NULL,
  PRIMARY KEY (`ExamClassRoomId`)
) ENGINE=InnoDB AUTO_INCREMENT=9 DEFAULT CHARSET=utf8 COLLATE=utf8_persian_ci;

-- ----------------------------
-- Records of ExamsClassRooms
-- ----------------------------
INSERT INTO `ExamsClassRooms` VALUES ('7', '1', '1');
INSERT INTO `ExamsClassRooms` VALUES ('8', '1', '8');

-- ----------------------------
-- Table structure for ExamsQuestions
-- ----------------------------
DROP TABLE IF EXISTS `ExamsQuestions`;
CREATE TABLE `ExamsQuestions` (
  `ExamQuestionId` bigint(20) NOT NULL AUTO_INCREMENT,
  `Exam` bigint(255) DEFAULT NULL,
  `Question` bigint(255) DEFAULT NULL,
  PRIMARY KEY (`ExamQuestionId`)
) ENGINE=InnoDB AUTO_INCREMENT=5 DEFAULT CHARSET=utf8 COLLATE=utf8_persian_ci;

-- ----------------------------
-- Records of ExamsQuestions
-- ----------------------------
INSERT INTO `ExamsQuestions` VALUES ('4', '1', '1');

-- ----------------------------
-- Table structure for grades
-- ----------------------------
DROP TABLE IF EXISTS `grades`;
CREATE TABLE `grades` (
  `GardeId` bigint(255) NOT NULL AUTO_INCREMENT,
  `Value` varchar(255) COLLATE utf8_persian_ci DEFAULT NULL,
  `StudentClassRoom` bigint(255) DEFAULT NULL,
  `GradeType` bigint(255) DEFAULT NULL,
  PRIMARY KEY (`GardeId`)
) ENGINE=InnoDB AUTO_INCREMENT=135 DEFAULT CHARSET=utf8 COLLATE=utf8_persian_ci;

-- ----------------------------
-- Records of grades
-- ----------------------------
INSERT INTO `grades` VALUES ('50', '10', '43', '1');
INSERT INTO `grades` VALUES ('56', '17', '0', '1');
INSERT INTO `grades` VALUES ('62', '12.2', '32', '1');
INSERT INTO `grades` VALUES ('63', '13.25', '33', '1');
INSERT INTO `grades` VALUES ('64', '18.75', '34', '1');
INSERT INTO `grades` VALUES ('65', '15.25', '35', '1');
INSERT INTO `grades` VALUES ('66', '16.00', '36', '1');
INSERT INTO `grades` VALUES ('94', 'خیلی بد', '44', '2');
INSERT INTO `grades` VALUES ('96', '15', '31', '1');
INSERT INTO `grades` VALUES ('97', '15', '45', '1');
INSERT INTO `grades` VALUES ('98', '18', '46', '1');
INSERT INTO `grades` VALUES ('99', 'خیلی بد', '50', '2');
INSERT INTO `grades` VALUES ('100', 'B', '58', '6');
INSERT INTO `grades` VALUES ('102', 'C', '61', '6');
INSERT INTO `grades` VALUES ('104', 'B', '60', '6');
INSERT INTO `grades` VALUES ('106', 'متوسط', '70', '2');
INSERT INTO `grades` VALUES ('117', '18', '75', '1');
INSERT INTO `grades` VALUES ('118', '14', '100', '1');
INSERT INTO `grades` VALUES ('127', 'خیلی بد', '51', '2');
INSERT INTO `grades` VALUES ('128', 'بد', '52', '2');
INSERT INTO `grades` VALUES ('129', 'خیلی بد', '53', '2');
INSERT INTO `grades` VALUES ('130', 'خیلی بد', '54', '2');
INSERT INTO `grades` VALUES ('131', 'متوسط', '55', '2');
INSERT INTO `grades` VALUES ('132', 'خیلی بد', '56', '2');
INSERT INTO `grades` VALUES ('133', 'خیلی بد', '57', '2');
INSERT INTO `grades` VALUES ('134', 'خیلی بد', '74', '2');

-- ----------------------------
-- Table structure for gradetypes
-- ----------------------------
DROP TABLE IF EXISTS `gradetypes`;
CREATE TABLE `gradetypes` (
  `GradeTypeId` bigint(20) NOT NULL AUTO_INCREMENT,
  `Name` varchar(255) COLLATE utf8_persian_ci DEFAULT NULL,
  `Min` varchar(255) COLLATE utf8_persian_ci DEFAULT NULL,
  `Max` varchar(255) COLLATE utf8_persian_ci DEFAULT NULL,
  `Pass` varchar(255) COLLATE utf8_persian_ci DEFAULT NULL,
  `DefinedValues` bigint(255) DEFAULT NULL,
  PRIMARY KEY (`GradeTypeId`)
) ENGINE=InnoDB AUTO_INCREMENT=7 DEFAULT CHARSET=utf8 COLLATE=utf8_persian_ci;

-- ----------------------------
-- Records of gradetypes
-- ----------------------------
INSERT INTO `gradetypes` VALUES ('1', 'عددی', '0', '20', '10', '0');
INSERT INTO `gradetypes` VALUES ('2', 'درجه بندی (خوب , بد)', 'بد', 'خیلی خوب', 'متوسط', '1');
INSERT INTO `gradetypes` VALUES ('6', 'امتیاز دهی انگلیسی', 'E', 'A++', 'C', '1');

-- ----------------------------
-- Table structure for gradevalues
-- ----------------------------
DROP TABLE IF EXISTS `gradevalues`;
CREATE TABLE `gradevalues` (
  `GradeValueId` bigint(11) NOT NULL AUTO_INCREMENT,
  `Value` varchar(255) COLLATE utf8_persian_ci DEFAULT NULL,
  `GradeType` bigint(255) DEFAULT NULL,
  PRIMARY KEY (`GradeValueId`)
) ENGINE=InnoDB AUTO_INCREMENT=8 DEFAULT CHARSET=utf8 COLLATE=utf8_persian_ci;

-- ----------------------------
-- Records of gradevalues
-- ----------------------------
INSERT INTO `gradevalues` VALUES ('2', 'خیلی بد', '2');
INSERT INTO `gradevalues` VALUES ('3', 'بد', '2');
INSERT INTO `gradevalues` VALUES ('4', 'متوسط', '2');
INSERT INTO `gradevalues` VALUES ('5', 'A', '6');
INSERT INTO `gradevalues` VALUES ('6', 'B', '6');
INSERT INTO `gradevalues` VALUES ('7', 'C', '6');

-- ----------------------------
-- Table structure for lectures
-- ----------------------------
DROP TABLE IF EXISTS `lectures`;
CREATE TABLE `lectures` (
  `LectureId` bigint(20) NOT NULL AUTO_INCREMENT,
  `Name` varchar(255) COLLATE utf8_persian_ci DEFAULT NULL,
  `TedadVahed` bigint(255) DEFAULT NULL,
  `Tozihat` varchar(255) COLLATE utf8_persian_ci DEFAULT NULL,
  PRIMARY KEY (`LectureId`)
) ENGINE=InnoDB AUTO_INCREMENT=4 DEFAULT CHARSET=utf8 COLLATE=utf8_persian_ci;

-- ----------------------------
-- Records of lectures
-- ----------------------------
INSERT INTO `lectures` VALUES ('1', 'ریاضی', '4', '3333333');
INSERT INTO `lectures` VALUES ('2', 'شیمی', '2', 'iiiiiii');
INSERT INTO `lectures` VALUES ('3', 'فیزیک', '3', 'iiiiiii');

-- ----------------------------
-- Table structure for options
-- ----------------------------
DROP TABLE IF EXISTS `options`;
CREATE TABLE `options` (
  `OptionId` bigint(20) NOT NULL AUTO_INCREMENT,
  `Name` varchar(255) COLLATE utf8_persian_ci DEFAULT NULL,
  `Value` varchar(255) COLLATE utf8_persian_ci DEFAULT NULL,
  PRIMARY KEY (`OptionId`)
) ENGINE=InnoDB AUTO_INCREMENT=3 DEFAULT CHARSET=utf8 COLLATE=utf8_persian_ci;

-- ----------------------------
-- Records of options
-- ----------------------------
INSERT INTO `options` VALUES ('1', 'ActiveTerm', '1');
INSERT INTO `options` VALUES ('2', 'NumberOfRecords', '30');

-- ----------------------------
-- Table structure for QuestionChoices
-- ----------------------------
DROP TABLE IF EXISTS `QuestionChoices`;
CREATE TABLE `QuestionChoices` (
  `QuestionChoiceId` bigint(20) NOT NULL AUTO_INCREMENT,
  `Content` varchar(255) COLLATE utf8_persian_ci DEFAULT NULL,
  `Question` bigint(255) DEFAULT NULL,
  PRIMARY KEY (`QuestionChoiceId`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8 COLLATE=utf8_persian_ci;

-- ----------------------------
-- Records of QuestionChoices
-- ----------------------------

-- ----------------------------
-- Table structure for Questions
-- ----------------------------
DROP TABLE IF EXISTS `Questions`;
CREATE TABLE `Questions` (
  `QuestionId` bigint(20) NOT NULL AUTO_INCREMENT,
  `Content` text COLLATE utf8_persian_ci,
  `QuestionType` bigint(255) DEFAULT NULL,
  `Teacher` bigint(255) DEFAULT NULL,
  `Lecture` bigint(255) DEFAULT NULL,
  `Saal` bigint(255) DEFAULT NULL,
  PRIMARY KEY (`QuestionId`)
) ENGINE=InnoDB AUTO_INCREMENT=2 DEFAULT CHARSET=utf8 COLLATE=utf8_persian_ci;

-- ----------------------------
-- Records of Questions
-- ----------------------------
INSERT INTO `Questions` VALUES ('1', '<p dir=\"rtl\"><span style=\"color:rgb(178, 34, 34)\"><span style=\"font-size:14px\"><span style=\"font-family:tahoma,geneva,sans-serif\">مجموع 2+2 چند میشود؟</span></span><img alt=\"wink\" src=\"http://localhost/School/ckeditor/plugins/smiley/images/wink_smile.png\" style=\"height:23px; width:23px\" title=\"wink\" /></span></p>\r\n', '1', '2', '1', '1');

-- ----------------------------
-- Table structure for QuestionTypes
-- ----------------------------
DROP TABLE IF EXISTS `QuestionTypes`;
CREATE TABLE `QuestionTypes` (
  `QuestionTypeId` bigint(20) NOT NULL AUTO_INCREMENT,
  `Name` varchar(255) COLLATE utf8_persian_ci DEFAULT NULL,
  `Tozihat` varchar(255) COLLATE utf8_persian_ci DEFAULT NULL,
  PRIMARY KEY (`QuestionTypeId`)
) ENGINE=InnoDB AUTO_INCREMENT=4 DEFAULT CHARSET=utf8 COLLATE=utf8_persian_ci;

-- ----------------------------
-- Records of QuestionTypes
-- ----------------------------
INSERT INTO `QuestionTypes` VALUES ('1', 'تشریحی', '-');
INSERT INTO `QuestionTypes` VALUES ('2', 'چند گزینه ای(انتخاب یک گزینه)', '-');
INSERT INTO `QuestionTypes` VALUES ('3', 'چند گزینه ای(انتخاب چند گزینه)', '-');

-- ----------------------------
-- Table structure for students
-- ----------------------------
DROP TABLE IF EXISTS `students`;
CREATE TABLE `students` (
  `StudentId` bigint(20) NOT NULL AUTO_INCREMENT,
  `Name` varchar(255) COLLATE utf8_persian_ci DEFAULT NULL,
  `Family` varchar(255) COLLATE utf8_persian_ci DEFAULT NULL,
  `CodeMelli` varchar(255) COLLATE utf8_persian_ci DEFAULT NULL,
  `Passwd` varchar(255) COLLATE utf8_persian_ci DEFAULT NULL,
  PRIMARY KEY (`StudentId`)
) ENGINE=InnoDB AUTO_INCREMENT=20 DEFAULT CHARSET=utf8 COLLATE=utf8_persian_ci;

-- ----------------------------
-- Records of students
-- ----------------------------
INSERT INTO `students` VALUES ('1', 'علی', 'رضایی', '1234', '81dc9bdb52d04dc20036dbd8313ed055');
INSERT INTO `students` VALUES ('2', 'رضا', 'احمدی', '4321', '81dc9bdb52d04dc20036dbd8313ed055');
INSERT INTO `students` VALUES ('3', 'حسن', 'رضایی نژاد', '14525254452', '81dc9bdb52d04dc20036dbd8313ed055');
INSERT INTO `students` VALUES ('4', 'حسین', 'علی نیا', '15236987545', '81dc9bdb52d04dc20036dbd8313ed055');
INSERT INTO `students` VALUES ('5', 'احمد', 'حدادی', '77896541232', '81dc9bdb52d04dc20036dbd8313ed055');
INSERT INTO `students` VALUES ('6', 'محمود', 'احمدی', '47854785478', '81dc9bdb52d04dc20036dbd8313ed055');
INSERT INTO `students` VALUES ('7', 'فرهاد', 'رضایی', '45645645644', '81dc9bdb52d04dc20036dbd8313ed055');
INSERT INTO `students` VALUES ('8', 'کامبیز', 'حسینی', '14785214785', '81dc9bdb52d04dc20036dbd8313ed055');
INSERT INTO `students` VALUES ('9', 'رضا', 'رضایی', '14785693212', '81dc9bdb52d04dc20036dbd8313ed055');
INSERT INTO `students` VALUES ('10', 'فربد', 'تسلیمی', '12598745632', '81dc9bdb52d04dc20036dbd8313ed055');
INSERT INTO `students` VALUES ('13', 'ali', 'karimi', '777', '81dc9bdb52d04dc20036dbd8313ed055');
INSERT INTO `students` VALUES ('14', 'reza', 'dfsdf', '6667', '81dc9bdb52d04dc20036dbd8313ed055');
INSERT INTO `students` VALUES ('15', 'hasan', 'reza', '3424', '81dc9bdb52d04dc20036dbd8313ed055');
INSERT INTO `students` VALUES ('16', 'ahmad', 'alinia', '7777777', '81dc9bdb52d04dc20036dbd8313ed055');
INSERT INTO `students` VALUES ('17', 'mahmood', 'taghipoor', '77', '81dc9bdb52d04dc20036dbd8313ed055');
INSERT INTO `students` VALUES ('18', 'hasan', 'ali', '1254125', '81dc9bdb52d04dc20036dbd8313ed055');
INSERT INTO `students` VALUES ('19', 'hossein', 'reza', '234', '81dc9bdb52d04dc20036dbd8313ed055');

-- ----------------------------
-- Table structure for studentsclassrooms
-- ----------------------------
DROP TABLE IF EXISTS `studentsclassrooms`;
CREATE TABLE `studentsclassrooms` (
  `StudentClassRoomId` bigint(20) NOT NULL AUTO_INCREMENT,
  `Student` bigint(255) DEFAULT NULL,
  `ClassRoom` bigint(255) DEFAULT NULL,
  PRIMARY KEY (`StudentClassRoomId`)
) ENGINE=InnoDB AUTO_INCREMENT=109 DEFAULT CHARSET=utf8 COLLATE=utf8_persian_ci;

-- ----------------------------
-- Records of studentsclassrooms
-- ----------------------------
INSERT INTO `studentsclassrooms` VALUES ('31', '2', '7');
INSERT INTO `studentsclassrooms` VALUES ('32', '6', '7');
INSERT INTO `studentsclassrooms` VALUES ('33', '8', '7');
INSERT INTO `studentsclassrooms` VALUES ('34', '13', '7');
INSERT INTO `studentsclassrooms` VALUES ('35', '17', '7');
INSERT INTO `studentsclassrooms` VALUES ('36', '18', '7');
INSERT INTO `studentsclassrooms` VALUES ('51', '2', '5');
INSERT INTO `studentsclassrooms` VALUES ('52', '3', '5');
INSERT INTO `studentsclassrooms` VALUES ('53', '4', '5');
INSERT INTO `studentsclassrooms` VALUES ('54', '5', '5');
INSERT INTO `studentsclassrooms` VALUES ('55', '6', '5');
INSERT INTO `studentsclassrooms` VALUES ('56', '7', '5');
INSERT INTO `studentsclassrooms` VALUES ('57', '8', '5');
INSERT INTO `studentsclassrooms` VALUES ('59', '2', '8');
INSERT INTO `studentsclassrooms` VALUES ('60', '3', '8');
INSERT INTO `studentsclassrooms` VALUES ('61', '4', '8');
INSERT INTO `studentsclassrooms` VALUES ('62', '5', '8');
INSERT INTO `studentsclassrooms` VALUES ('74', '1', '5');
INSERT INTO `studentsclassrooms` VALUES ('75', '1', '7');
INSERT INTO `studentsclassrooms` VALUES ('100', '1', '1');
INSERT INTO `studentsclassrooms` VALUES ('106', '14', '1');
INSERT INTO `studentsclassrooms` VALUES ('107', '18', '1');
INSERT INTO `studentsclassrooms` VALUES ('108', '19', '1');

-- ----------------------------
-- Table structure for teachers
-- ----------------------------
DROP TABLE IF EXISTS `teachers`;
CREATE TABLE `teachers` (
  `TeacherId` int(11) NOT NULL AUTO_INCREMENT,
  `Name` text COLLATE utf8_persian_ci NOT NULL,
  `Family` text COLLATE utf8_persian_ci NOT NULL,
  `Username` text COLLATE utf8_persian_ci NOT NULL,
  `CodeMelli` text COLLATE utf8_persian_ci,
  `Passwd` text COLLATE utf8_persian_ci NOT NULL,
  PRIMARY KEY (`TeacherId`)
) ENGINE=InnoDB AUTO_INCREMENT=7 DEFAULT CHARSET=utf8 COLLATE=utf8_persian_ci;

-- ----------------------------
-- Records of teachers
-- ----------------------------
INSERT INTO `teachers` VALUES ('2', 'رضا', 'علی نژاد', 'reza', '2701512542', '81dc9bdb52d04dc20036dbd8313ed055');
INSERT INTO `teachers` VALUES ('5', 'تقی', 'حسینی', 'ali', '280145287965', '81dc9bdb52d04dc20036dbd8313ed055');
INSERT INTO `teachers` VALUES ('6', 'aaaaaaaaa', 'ddddddd', '657', '75665', '81dc9bdb52d04dc20036dbd8313ed055');

-- ----------------------------
-- Table structure for terms
-- ----------------------------
DROP TABLE IF EXISTS `terms`;
CREATE TABLE `terms` (
  `TermId` bigint(20) NOT NULL AUTO_INCREMENT,
  `SalShoroo` bigint(255) DEFAULT NULL,
  `SalPayan` bigint(255) DEFAULT NULL,
  `NimSal` bigint(255) DEFAULT NULL,
  `Tozihat` varchar(255) COLLATE utf8_persian_ci DEFAULT NULL,
  PRIMARY KEY (`TermId`)
) ENGINE=InnoDB AUTO_INCREMENT=4 DEFAULT CHARSET=utf8 COLLATE=utf8_persian_ci;

-- ----------------------------
-- Records of terms
-- ----------------------------
INSERT INTO `terms` VALUES ('1', '1393', '1394', '111111', '-');
INSERT INTO `terms` VALUES ('2', '1390', '1391', '2', '-');
INSERT INTO `terms` VALUES ('3', '1389', '1390', '3', '-');

-- ----------------------------
-- Table structure for TrueAnswers
-- ----------------------------
DROP TABLE IF EXISTS `TrueAnswers`;
CREATE TABLE `TrueAnswers` (
  `TrueAnswerId` bigint(20) NOT NULL AUTO_INCREMENT,
  `Content` text COLLATE utf8_persian_ci,
  `Question` bigint(255) DEFAULT NULL,
  PRIMARY KEY (`TrueAnswerId`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8 COLLATE=utf8_persian_ci;

-- ----------------------------
-- Records of TrueAnswers
-- ----------------------------

-- ----------------------------
-- Table structure for users
-- ----------------------------
DROP TABLE IF EXISTS `users`;
CREATE TABLE `users` (
  `UserId` bigint(20) NOT NULL AUTO_INCREMENT,
  `Username` varchar(255) COLLATE utf8_persian_ci DEFAULT NULL,
  `Passwd` varchar(255) COLLATE utf8_persian_ci DEFAULT NULL,
  PRIMARY KEY (`UserId`)
) ENGINE=InnoDB AUTO_INCREMENT=2 DEFAULT CHARSET=utf8 COLLATE=utf8_persian_ci;

-- ----------------------------
-- Records of users
-- ----------------------------
INSERT INTO `users` VALUES ('1', 'admin', '81dc9bdb52d04dc20036dbd8313ed055');

-- ----------------------------
-- View structure for answers1
-- ----------------------------
DROP VIEW IF EXISTS `answers1`;
CREATE ALGORITHM=UNDEFINED DEFINER=`kami`@`localhost`  VIEW `answers1` AS SELECT
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
INNER JOIN Answers ON ExamsQuestions.ExamQuestionId = Answers.ExamQuestion ;

-- ----------------------------
-- View structure for questionview
-- ----------------------------
DROP VIEW IF EXISTS `questionview`;
CREATE ALGORITHM=UNDEFINED DEFINER=`kami`@`localhost` SQL SECURITY DEFINER  VIEW `questionview` AS SELECT
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
INNER JOIN Teachers ON Teachers.TeacherId = Questions.Teacher ;

-- ----------------------------
-- View structure for t1
-- ----------------------------
DROP VIEW IF EXISTS `t1`;
CREATE ALGORITHM=UNDEFINED DEFINER=`kami`@`localhost`  VIEW `t1` AS SELECT
classrooms.ClassRoomId AS `ClassRoom.ClassRoomId`,
classrooms.`Name` AS `ClassRoom.Name`,
classrooms.Saal AS `ClassRoom.Saal`,
terms.TermId AS `Term.TermId`,
terms.SalShoroo AS `Term.SalShoroo`,
terms.SalPayan AS `Term.SalPayan`,
terms.NimSal AS `Term.NimSal`,
terms.Tozihat AS `Term.Tozihat`,
teachers.TeacherId AS `Teacher.TeacherId`,
teachers.`Name` AS `Teacher.Name`,
teachers.Family AS `Teacher.Family`,
teachers.Username AS `Teacher.Username`,
teachers.Passwd AS `Teacher.Passwd`,
lectures.LectureId AS `Lecture.LectureId`,
lectures.`Name` AS `Lecture.Name`,
lectures.TedadVahed AS `Lecture.TedadVahed`,
lectures.Tozihat AS `Lecture.Tozihat`,
gradetypes.GradeTypeId AS `GradeType.GradeTypeId` ,
gradetypes.`Name` AS `GradeType.Name` ,
gradetypes.Min AS `GradeType.Min`,
gradetypes.Max AS `GradeType.Max`,
gradetypes.Pass AS `GradeType.Pass`
FROM
classrooms
INNER JOIN teachers ON teachers.TeacherId = classrooms.Teacher
INNER JOIN terms ON terms.TermId = classrooms.Term
INNER JOIN lectures ON lectures.LectureId = classrooms.Lecture
INNER JOIN gradetypes ON gradetypes.GradeTypeId = classrooms.GradeType ;

-- ----------------------------
-- View structure for t2
-- ----------------------------
DROP VIEW IF EXISTS `t2`;
CREATE ALGORITHM=UNDEFINED DEFINER=`kami`@`localhost`  VIEW `t2` AS SELECT
gradevalues.`Value` AS `GradeValue.Value`,
gradevalues.GradeValueId AS `GradeValue.GradeValueId`,
gradetypes.GradeTypeId AS `GradeType.GradeTypeId`,
gradetypes.`Name` AS `GradeType.Name`,
gradetypes.Min AS `GradeType.Min`,
gradetypes.Max AS `GradeType.Max`,
gradetypes.Pass AS `GradeType.Pass`
FROM
gradevalues
INNER JOIN gradetypes ON gradetypes.GradeTypeId = gradevalues.GradeType ;

-- ----------------------------
-- View structure for t3
-- ----------------------------
DROP VIEW IF EXISTS `t3`;
CREATE ALGORITHM=UNDEFINED DEFINER=`kami`@`localhost` SQL SECURITY DEFINER  VIEW `t3` AS SELECT
classrooms.Lecture AS `ClassRoom.Lecture`,
classrooms.Saal AS `ClassRoom.Saal`,
classrooms.Teacher AS `ClassRoom.Teacher`,
classrooms.`Name` AS `ClassRoom.Name`,
students.`Name` AS `Student.Name`,
students.Family AS `Student.Family`,
students.CodeMelli AS `Student.CodeMelli`,
students.StudentId AS `Student.StudentId`,
classrooms.ClassRoomId AS `ClassRoom.ClassRoomId`,
classrooms.Term AS `ClassRoom.Term`,
students.Passwd AS `Student.Passwd`,
studentsclassrooms.StudentClassRoomId AS `StudentClassRoom.StudentClassRoomId`,
studentsclassrooms.Student AS `StudentClassRoom.Student`,
studentsclassrooms.ClassRoom AS `StudentClassRoom.ClassRoom`,
lectures.LectureId AS `Lecture.LectureId`,
lectures.`Name` AS `Lecture.Name`,
lectures.TedadVahed AS `Lecture.TedadVahed`,
lectures.Tozihat AS `Lecture.Tozihat`,
teachers.TeacherId AS `Teacher.TeacherId`,
teachers.`Name` AS `Teacher.Name`,
teachers.Family AS `Teacher.Family`,
teachers.Username AS `Teacher.UserName`,
teachers.Passwd AS `Teacher.Passwd`,
terms.TermId AS `Term.TermId`,
terms.SalShoroo AS `Term.SalShoroo`,
terms.SalPayan AS `Term.SalPayan`,
terms.NimSal AS `Term.NimSal`,
terms.Tozihat AS `Term.Tozihat`
FROM
classrooms
INNER JOIN studentsclassrooms ON classrooms.ClassRoomId = studentsclassrooms.ClassRoom
INNER JOIN students ON students.StudentId = studentsclassrooms.Student
INNER JOIN lectures ON lectures.LectureId = classrooms.Lecture
INNER JOIN teachers ON teachers.TeacherId = classrooms.Teacher
INNER JOIN terms ON terms.TermId = classrooms.Term
WHERE
classrooms.ClassRoomId =1 AND classrooms.Term= 1 ;

-- ----------------------------
-- View structure for t4
-- ----------------------------
DROP VIEW IF EXISTS `t4`;
CREATE ALGORITHM=UNDEFINED DEFINER=`kami`@`localhost` SQL SECURITY DEFINER  VIEW `t4` AS SELECT
classrooms.Lecture AS `ClassRoom.Lecture`,
classrooms.Saal AS `ClassRoom.Saal`,
classrooms.Teacher AS `ClassRoom.Teacher`,
classrooms.`Name` AS `ClassRoom.Name`,
students.`Name` AS `Student.Name`,
students.Family AS `Student.Family`,
students.CodeMelli AS `Student.CodeMelli`,
students.StudentId AS `Student.StudentId`,
classrooms.ClassRoomId AS `ClassRoom.ClassRoomId`,
classrooms.Term AS `ClassRoom.Term`,
students.Passwd AS `Student.Passwd`,
studentsclassrooms.StudentClassRoomId AS `StudentClassRoom.StudentClassRoomId`,
studentsclassrooms.Student AS `StudentClassRoom.Student`,
studentsclassrooms.ClassRoom AS `StudentClassRoom.ClassRoom`,
grades.`Value`,
grades.GardeId
FROM
classrooms
INNER JOIN studentsclassrooms ON classrooms.ClassRoomId = studentsclassrooms.ClassRoom
INNER JOIN students ON students.StudentId = studentsclassrooms.Student
INNER JOIN grades ON grades.StudentClassRoom = studentsclassrooms.StudentClassRoomId
WHERE
classrooms.ClassRoomId =1 AND classrooms.Term= 1 ;

-- ----------------------------
-- View structure for test
-- ----------------------------
DROP VIEW IF EXISTS `test`;
CREATE ALGORITHM=UNDEFINED DEFINER=`kami`@`localhost` SQL SECURITY DEFINER  VIEW `test` AS SELECT
classrooms.Lecture AS `ClassRooms.Lecture`,
classrooms.Saal AS `ClassRooms.Saal`,
classrooms.Teacher AS `ClassRooms.Teacher`,
classrooms.`Name` AS `ClassRooms.Name`,
students.`Name` AS `Students.Name`,
students.Family AS `Students.Family`,
students.CodeMelli AS `Students.CodeMelli`,
students.StudentId AS `Students.StudentId`,
classrooms.ClassRoomId AS `ClassRooms.ClassRoomId`,
classrooms.Term AS `ClassRooms.Term`,
students.Passwd AS `Students.Passwd`,
studentsclassrooms.StudentClassRoomId AS `StudentsClassRooms.StudentClassRoomId`,
studentsclassrooms.Student AS `StudentsClassRooms.Student`,
studentsclassrooms.ClassRoom AS `StudentsClassRooms.ClassRoom`,
lectures.LectureId AS `Lectures.LectureId`,
lectures.`Name` AS `Lectures.Name`,
lectures.TedadVahed AS `Lectures.TedadVahed`,
lectures.Tozihat AS `Lectures.Tozihat`,
teachers.TeacherId AS `Teachers.TeacherId`,
teachers.`Name` AS `Teachers.Name`,
teachers.Family AS `Teachers.Family`,
teachers.Username AS `Teachers.UserName`,
teachers.Passwd AS `Teachers.Passwd`,
terms.TermId AS `Terms.TermId`,
terms.SallShoroo AS `Terms.SalShoroo`,
terms.SalPayan AS SalPayan,
terms.NimSal AS `Terms.NimSal`,
terms.Tozihat AS `Terms.Tozihat`
FROM
classrooms
INNER JOIN studentsclassrooms ON classrooms.ClassRoomId = studentsclassrooms.ClassRoom
INNER JOIN students ON students.StudentId = studentsclassrooms.Student
INNER JOIN lectures ON lectures.LectureId = classrooms.Lecture
INNER JOIN teachers ON teachers.TeacherId = classrooms.Teacher
INNER JOIN terms ON terms.TermId = classrooms.Term
WHERE
students.StudentId = 1 AND classrooms.Term=1 ;

-- ----------------------------
-- View structure for v1
-- ----------------------------
DROP VIEW IF EXISTS `v1`;
CREATE ALGORITHM=UNDEFINED DEFINER=`kami`@`localhost` SQL SECURITY DEFINER  VIEW `v1` AS SELECT
teachers.TeacherId AS `Teacher.TeacherId`,
teachers.`Name` AS `Teacher.Name`,
teachers.Family AS `Teacher.Family`,
teachers.Username AS `Teacher.UserName`,
teachers.CodeMelli AS `Teacher.CodeMelli`,
teachers.Passwd AS `Teacher.Passwd`,
Exams.ExamId AS `Exam.ExamId`,
Exams.Title AS `Exam.Title`,
Exams.Teacher AS `Exam.Teacher`,
lectures.LectureId,
lectures.`Name`,
lectures.TedadVahed,
lectures.Tozihat,
Exams.Lecture,
Exams.Saal,
ExamsClassRooms.ExamClassRoomId,
ExamsClassRooms.Exam,
ExamsClassRooms.ClassRoom
FROM
Exams
INNER JOIN teachers ON teachers.TeacherId = Exams.Teacher
INNER JOIN lectures ON lectures.LectureId = Exams.Lecture
INNER JOIN ExamsClassRooms ON ExamsClassRooms.Exam = Exams.ExamId ;

-- ----------------------------
-- View structure for viewexamresults
-- ----------------------------
DROP VIEW IF EXISTS `viewexamresults`;
CREATE ALGORITHM=UNDEFINED DEFINER=`kami`@`localhost`  VIEW `viewexamresults` AS SELECT
Exams.ExamId,
Exams.Title,
ExamsClassRooms.ExamClassRoomId,
ExamsClassRooms.Exam,
ExamsClassRooms.ClassRoom,
classrooms.ClassRoomId,
classrooms.`Name`,
classrooms.Term,
classrooms.Lecture,
classrooms.Saal,
classrooms.Teacher,
classrooms.GradeType
FROM
Exams
INNER JOIN ExamsClassRooms ON ExamsClassRooms.Exam = Exams.ExamId
INNER JOIN classrooms ON classrooms.ClassRoomId = ExamsClassRooms.ClassRoom ;

-- ----------------------------
-- View structure for vv1
-- ----------------------------
DROP VIEW IF EXISTS `vv1`;
CREATE ALGORITHM=UNDEFINED DEFINER=`kami`@`localhost`  VIEW `vv1` AS SELECT
Questions.QuestionId AS `Question.QuestionId`,
Questions.Content AS `Question.Content`,
Questions.QuestionType AS `Question.QuestionType`,
Questions.Teacher AS `Question.Teacher`,
Questions.Lecture AS `Question.Lecture`,
Questions.Saal AS `Question.Sall`
FROM
Exams
INNER JOIN ExamsQuestions ON ExamsQuestions.Exam = Exams.ExamId
INNER JOIN Questions ON Questions.QuestionId = ExamsQuestions.Question ;
