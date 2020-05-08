-- MySQL dump 10.13  Distrib 5.6.11, for Win32 (x86)
--
-- Host: 127.0.0.1    Database: school
-- ------------------------------------------------------
-- Server version	5.6.11

/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8 */;
/*!40103 SET @OLD_TIME_ZONE=@@TIME_ZONE */;
/*!40103 SET TIME_ZONE='+00:00' */;
/*!40014 SET @OLD_UNIQUE_CHECKS=@@UNIQUE_CHECKS, UNIQUE_CHECKS=0 */;
/*!40014 SET @OLD_FOREIGN_KEY_CHECKS=@@FOREIGN_KEY_CHECKS, FOREIGN_KEY_CHECKS=0 */;
/*!40101 SET @OLD_SQL_MODE=@@SQL_MODE, SQL_MODE='NO_AUTO_VALUE_ON_ZERO' */;
/*!40111 SET @OLD_SQL_NOTES=@@SQL_NOTES, SQL_NOTES=0 */;

--
-- Table structure for table `Answers`
--

DROP TABLE IF EXISTS `Answers`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `Answers` (
  `AnswerId` bigint(255) NOT NULL AUTO_INCREMENT,
  `Content` text COLLATE utf8_persian_ci,
  `ExamQuestion` bigint(255) DEFAULT NULL,
  `Student` bigint(255) DEFAULT NULL,
  PRIMARY KEY (`AnswerId`)
) ENGINE=InnoDB AUTO_INCREMENT=9 DEFAULT CHARSET=utf8 COLLATE=utf8_persian_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `Answers`
--

LOCK TABLES `Answers` WRITE;
/*!40000 ALTER TABLE `Answers` DISABLE KEYS */;
INSERT INTO `Answers` VALUES (8,'4 ',4,1);
/*!40000 ALTER TABLE `Answers` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `Exams`
--

DROP TABLE IF EXISTS `Exams`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `Exams` (
  `ExamId` bigint(20) NOT NULL AUTO_INCREMENT,
  `Title` text COLLATE utf8_persian_ci,
  `Teacher` bigint(255) DEFAULT NULL,
  `Lecture` bigint(255) DEFAULT NULL,
  `Saal` bigint(255) DEFAULT NULL,
  PRIMARY KEY (`ExamId`)
) ENGINE=InnoDB AUTO_INCREMENT=4 DEFAULT CHARSET=utf8 COLLATE=utf8_persian_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `Exams`
--

LOCK TABLES `Exams` WRITE;
/*!40000 ALTER TABLE `Exams` DISABLE KEYS */;
INSERT INTO `Exams` VALUES (1,'آزمون ریاضی میان ترم',2,1,1),(3,'test',5,1,6);
/*!40000 ALTER TABLE `Exams` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `ExamsClassRooms`
--

DROP TABLE IF EXISTS `ExamsClassRooms`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `ExamsClassRooms` (
  `ExamClassRoomId` bigint(20) NOT NULL AUTO_INCREMENT,
  `Exam` bigint(255) DEFAULT NULL,
  `ClassRoom` bigint(255) DEFAULT NULL,
  PRIMARY KEY (`ExamClassRoomId`)
) ENGINE=InnoDB AUTO_INCREMENT=9 DEFAULT CHARSET=utf8 COLLATE=utf8_persian_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `ExamsClassRooms`
--

LOCK TABLES `ExamsClassRooms` WRITE;
/*!40000 ALTER TABLE `ExamsClassRooms` DISABLE KEYS */;
INSERT INTO `ExamsClassRooms` VALUES (7,1,1),(8,1,8);
/*!40000 ALTER TABLE `ExamsClassRooms` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `ExamsQuestions`
--

DROP TABLE IF EXISTS `ExamsQuestions`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `ExamsQuestions` (
  `ExamQuestionId` bigint(20) NOT NULL AUTO_INCREMENT,
  `Exam` bigint(255) DEFAULT NULL,
  `Question` bigint(255) DEFAULT NULL,
  PRIMARY KEY (`ExamQuestionId`)
) ENGINE=InnoDB AUTO_INCREMENT=5 DEFAULT CHARSET=utf8 COLLATE=utf8_persian_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `ExamsQuestions`
--

LOCK TABLES `ExamsQuestions` WRITE;
/*!40000 ALTER TABLE `ExamsQuestions` DISABLE KEYS */;
INSERT INTO `ExamsQuestions` VALUES (4,1,1);
/*!40000 ALTER TABLE `ExamsQuestions` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `QuestionChoices`
--

DROP TABLE IF EXISTS `QuestionChoices`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `QuestionChoices` (
  `QuestionChoiceId` bigint(20) NOT NULL AUTO_INCREMENT,
  `Content` varchar(255) COLLATE utf8_persian_ci DEFAULT NULL,
  `Question` bigint(255) DEFAULT NULL,
  PRIMARY KEY (`QuestionChoiceId`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8 COLLATE=utf8_persian_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `QuestionChoices`
--

LOCK TABLES `QuestionChoices` WRITE;
/*!40000 ALTER TABLE `QuestionChoices` DISABLE KEYS */;
/*!40000 ALTER TABLE `QuestionChoices` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `QuestionTypes`
--

DROP TABLE IF EXISTS `QuestionTypes`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `QuestionTypes` (
  `QuestionTypeId` bigint(20) NOT NULL AUTO_INCREMENT,
  `Name` varchar(255) COLLATE utf8_persian_ci DEFAULT NULL,
  `Tozihat` varchar(255) COLLATE utf8_persian_ci DEFAULT NULL,
  PRIMARY KEY (`QuestionTypeId`)
) ENGINE=InnoDB AUTO_INCREMENT=4 DEFAULT CHARSET=utf8 COLLATE=utf8_persian_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `QuestionTypes`
--

LOCK TABLES `QuestionTypes` WRITE;
/*!40000 ALTER TABLE `QuestionTypes` DISABLE KEYS */;
INSERT INTO `QuestionTypes` VALUES (1,'تشریحی','-'),(2,'چند گزینه ای(انتخاب یک گزینه)','-'),(3,'چند گزینه ای(انتخاب چند گزینه)','-');
/*!40000 ALTER TABLE `QuestionTypes` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `Questions`
--

DROP TABLE IF EXISTS `Questions`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `Questions` (
  `QuestionId` bigint(20) NOT NULL AUTO_INCREMENT,
  `Content` text COLLATE utf8_persian_ci,
  `QuestionType` bigint(255) DEFAULT NULL,
  `Teacher` bigint(255) DEFAULT NULL,
  `Lecture` bigint(255) DEFAULT NULL,
  `Saal` bigint(255) DEFAULT NULL,
  PRIMARY KEY (`QuestionId`)
) ENGINE=InnoDB AUTO_INCREMENT=2 DEFAULT CHARSET=utf8 COLLATE=utf8_persian_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `Questions`
--

LOCK TABLES `Questions` WRITE;
/*!40000 ALTER TABLE `Questions` DISABLE KEYS */;
INSERT INTO `Questions` VALUES (1,'<p><img alt=\"\" src=\"/School/Uploads//reza/5.jpg\" style=\"height:240px; width:320px\" />sdad asd</p>\r\n\r\n<p>&nbsp;</p>\r\n\r\n<p>as</p>\r\n\r\n<p>as</p>\r\n\r\n<p>&nbsp;</p>\r\n\r\n<p>as</p>\r\n\r\n<p>d</p>\r\n\r\n<p>as</p>\r\n\r\n<p>&nbsp;a</p>\r\n\r\n<p>&nbsp;</p>\r\n\r\n<p>&nbsp;</p>\r\n',1,2,1,1);
/*!40000 ALTER TABLE `Questions` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `TrueAnswers`
--

DROP TABLE IF EXISTS `TrueAnswers`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `TrueAnswers` (
  `TrueAnswerId` bigint(20) NOT NULL AUTO_INCREMENT,
  `Content` text COLLATE utf8_persian_ci,
  `Question` bigint(255) DEFAULT NULL,
  PRIMARY KEY (`TrueAnswerId`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8 COLLATE=utf8_persian_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `TrueAnswers`
--

LOCK TABLES `TrueAnswers` WRITE;
/*!40000 ALTER TABLE `TrueAnswers` DISABLE KEYS */;
/*!40000 ALTER TABLE `TrueAnswers` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `answers1`
--

DROP TABLE IF EXISTS `answers1`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `answers1` (
  `ExamQuestion.ExamQuestionId` tinyint(4) NOT NULL,
  `ExamQuestion.Exam` tinyint(4) NOT NULL,
  `ExamQuestion.Question` tinyint(4) NOT NULL,
  `Question.QuestionId` tinyint(4) NOT NULL,
  `Question.Content` tinyint(4) NOT NULL,
  `Question.Type` tinyint(4) NOT NULL,
  `Question.Teacher` tinyint(4) NOT NULL,
  `Question.Lecture` tinyint(4) NOT NULL,
  `Question.Saal` tinyint(4) NOT NULL,
  `Exam.ExamId` tinyint(4) NOT NULL,
  `Exam.Title` tinyint(4) NOT NULL,
  `Exam.Teacher` tinyint(4) NOT NULL,
  `Exam.Lecture` tinyint(4) NOT NULL,
  `Exam.Saal` tinyint(4) NOT NULL,
  `Answer.AnswerId` tinyint(4) NOT NULL,
  `Answer.Content` tinyint(4) NOT NULL,
  `Answer.ExamQuestion` tinyint(4) NOT NULL,
  `Answer.Student` tinyint(4) NOT NULL
) ENGINE=MyISAM DEFAULT CHARSET=utf8 COLLATE=utf8_persian_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `answers1`
--

LOCK TABLES `answers1` WRITE;
/*!40000 ALTER TABLE `answers1` DISABLE KEYS */;
/*!40000 ALTER TABLE `answers1` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `classrooms`
--

DROP TABLE IF EXISTS `classrooms`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
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
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `classrooms`
--

LOCK TABLES `classrooms` WRITE;
/*!40000 ALTER TABLE `classrooms` DISABLE KEYS */;
INSERT INTO `classrooms` VALUES (1,'ریاضی الف',1,1,1,5,1),(4,'فیزیک الف',2,2,1,2,1),(5,'دینی الف',1,3,10,2,2),(7,'فیزیک ج',1,3,1,2,1),(8,'ریاضی  اول',1,1,1,5,6);
/*!40000 ALTER TABLE `classrooms` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `grades`
--

DROP TABLE IF EXISTS `grades`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `grades` (
  `GardeId` bigint(255) NOT NULL AUTO_INCREMENT,
  `Value` varchar(255) COLLATE utf8_persian_ci DEFAULT NULL,
  `StudentClassRoom` bigint(255) DEFAULT NULL,
  `GradeType` bigint(255) DEFAULT NULL,
  PRIMARY KEY (`GardeId`)
) ENGINE=InnoDB AUTO_INCREMENT=135 DEFAULT CHARSET=utf8 COLLATE=utf8_persian_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `grades`
--

LOCK TABLES `grades` WRITE;
/*!40000 ALTER TABLE `grades` DISABLE KEYS */;
INSERT INTO `grades` VALUES (50,'10',43,1),(56,'17',0,1),(62,'12.2',32,1),(63,'13.25',33,1),(64,'18.75',34,1),(65,'15.25',35,1),(66,'16.00',36,1),(94,'خیلی بد',44,2),(96,'15',31,1),(97,'15',45,1),(98,'18',46,1),(99,'خیلی بد',50,2),(100,'B',58,6),(102,'C',61,6),(104,'B',60,6),(106,'متوسط',70,2),(117,'18',75,1),(118,'14',100,1),(127,'خیلی بد',51,2),(128,'بد',52,2),(129,'خیلی بد',53,2),(130,'خیلی بد',54,2),(131,'متوسط',55,2),(132,'خیلی بد',56,2),(133,'خیلی بد',57,2),(134,'خیلی بد',74,2);
/*!40000 ALTER TABLE `grades` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `gradetypes`
--

DROP TABLE IF EXISTS `gradetypes`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `gradetypes` (
  `GradeTypeId` bigint(20) NOT NULL AUTO_INCREMENT,
  `Name` varchar(255) COLLATE utf8_persian_ci DEFAULT NULL,
  `Min` varchar(255) COLLATE utf8_persian_ci DEFAULT NULL,
  `Max` varchar(255) COLLATE utf8_persian_ci DEFAULT NULL,
  `Pass` varchar(255) COLLATE utf8_persian_ci DEFAULT NULL,
  `DefinedValues` bigint(255) DEFAULT NULL,
  PRIMARY KEY (`GradeTypeId`)
) ENGINE=InnoDB AUTO_INCREMENT=7 DEFAULT CHARSET=utf8 COLLATE=utf8_persian_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `gradetypes`
--

LOCK TABLES `gradetypes` WRITE;
/*!40000 ALTER TABLE `gradetypes` DISABLE KEYS */;
INSERT INTO `gradetypes` VALUES (1,'عددی','0','20','10',0),(2,'درجه بندی (خوب , بد)','بد','خیلی خوب','متوسط',1),(6,'امتیاز دهی انگلیسی','E','A++','C',1);
/*!40000 ALTER TABLE `gradetypes` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `gradevalues`
--

DROP TABLE IF EXISTS `gradevalues`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `gradevalues` (
  `GradeValueId` bigint(11) NOT NULL AUTO_INCREMENT,
  `Value` varchar(255) COLLATE utf8_persian_ci DEFAULT NULL,
  `GradeType` bigint(255) DEFAULT NULL,
  PRIMARY KEY (`GradeValueId`)
) ENGINE=InnoDB AUTO_INCREMENT=8 DEFAULT CHARSET=utf8 COLLATE=utf8_persian_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `gradevalues`
--

LOCK TABLES `gradevalues` WRITE;
/*!40000 ALTER TABLE `gradevalues` DISABLE KEYS */;
INSERT INTO `gradevalues` VALUES (2,'خیلی بد',2),(3,'بد',2),(4,'متوسط',2),(5,'A',6),(6,'B',6),(7,'C',6);
/*!40000 ALTER TABLE `gradevalues` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `lectures`
--

DROP TABLE IF EXISTS `lectures`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `lectures` (
  `LectureId` bigint(20) NOT NULL AUTO_INCREMENT,
  `Name` varchar(255) COLLATE utf8_persian_ci DEFAULT NULL,
  `TedadVahed` bigint(255) DEFAULT NULL,
  `Tozihat` varchar(255) COLLATE utf8_persian_ci DEFAULT NULL,
  PRIMARY KEY (`LectureId`)
) ENGINE=InnoDB AUTO_INCREMENT=4 DEFAULT CHARSET=utf8 COLLATE=utf8_persian_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `lectures`
--

LOCK TABLES `lectures` WRITE;
/*!40000 ALTER TABLE `lectures` DISABLE KEYS */;
INSERT INTO `lectures` VALUES (1,'ریاضی',4,'3333333'),(2,'شیمی',2,'iiiiiii'),(3,'فیزیک',3,'iiiiiii');
/*!40000 ALTER TABLE `lectures` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `options`
--

DROP TABLE IF EXISTS `options`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `options` (
  `OptionId` bigint(20) NOT NULL AUTO_INCREMENT,
  `Name` varchar(255) COLLATE utf8_persian_ci DEFAULT NULL,
  `Value` varchar(255) COLLATE utf8_persian_ci DEFAULT NULL,
  PRIMARY KEY (`OptionId`)
) ENGINE=InnoDB AUTO_INCREMENT=3 DEFAULT CHARSET=utf8 COLLATE=utf8_persian_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `options`
--

LOCK TABLES `options` WRITE;
/*!40000 ALTER TABLE `options` DISABLE KEYS */;
INSERT INTO `options` VALUES (1,'ActiveTerm','1'),(2,'NumberOfRecords','30');
/*!40000 ALTER TABLE `options` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `questionview`
--

DROP TABLE IF EXISTS `questionview`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `questionview` (
  `QuestionType.QuestionTypeId` tinyint(4) NOT NULL,
  `QuestionType.Name` tinyint(4) NOT NULL,
  `QuestionType.Tozihat` tinyint(4) NOT NULL,
  `Question.Content` tinyint(4) NOT NULL,
  `Question.QuestionType` tinyint(4) NOT NULL,
  `Question.Teacher` tinyint(4) NOT NULL,
  `Question.Lecture` tinyint(4) NOT NULL,
  `Question.Saal` tinyint(4) NOT NULL,
  `Question.QuestionId` tinyint(4) NOT NULL,
  `Lecture.LectureId` tinyint(4) NOT NULL,
  `Lecture.Name` tinyint(4) NOT NULL,
  `Lecture.TedadVahed` tinyint(4) NOT NULL,
  `Lecture.Tozihat` tinyint(4) NOT NULL,
  `Teacher.TeacherId` tinyint(4) NOT NULL,
  `Teacher.Name` tinyint(4) NOT NULL,
  `Teacher.Family` tinyint(4) NOT NULL,
  `Teacher.Username` tinyint(4) NOT NULL,
  `Teacher.CodeMelli` tinyint(4) NOT NULL,
  `Teacher.Passwd` tinyint(4) NOT NULL
) ENGINE=MyISAM DEFAULT CHARSET=utf8 COLLATE=utf8_persian_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `questionview`
--

LOCK TABLES `questionview` WRITE;
/*!40000 ALTER TABLE `questionview` DISABLE KEYS */;
/*!40000 ALTER TABLE `questionview` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `students`
--

DROP TABLE IF EXISTS `students`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `students` (
  `StudentId` bigint(20) NOT NULL AUTO_INCREMENT,
  `Name` varchar(255) COLLATE utf8_persian_ci DEFAULT NULL,
  `Family` varchar(255) COLLATE utf8_persian_ci DEFAULT NULL,
  `CodeMelli` varchar(255) COLLATE utf8_persian_ci DEFAULT NULL,
  `Passwd` varchar(255) COLLATE utf8_persian_ci DEFAULT NULL,
  PRIMARY KEY (`StudentId`)
) ENGINE=InnoDB AUTO_INCREMENT=20 DEFAULT CHARSET=utf8 COLLATE=utf8_persian_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `students`
--

LOCK TABLES `students` WRITE;
/*!40000 ALTER TABLE `students` DISABLE KEYS */;
INSERT INTO `students` VALUES (1,'علی','رضایی','1234','81dc9bdb52d04dc20036dbd8313ed055'),(2,'رضا','احمدی','4321','81dc9bdb52d04dc20036dbd8313ed055'),(3,'حسن','رضایی نژاد','14525254452','81dc9bdb52d04dc20036dbd8313ed055'),(4,'حسین','علی نیا','15236987545','81dc9bdb52d04dc20036dbd8313ed055'),(5,'احمد','حدادی','77896541232','81dc9bdb52d04dc20036dbd8313ed055'),(6,'محمود','احمدی','47854785478','81dc9bdb52d04dc20036dbd8313ed055'),(7,'فرهاد','رضایی','45645645644','81dc9bdb52d04dc20036dbd8313ed055'),(8,'کامبیز','حسینی','14785214785','81dc9bdb52d04dc20036dbd8313ed055'),(9,'رضا','رضایی','14785693212','81dc9bdb52d04dc20036dbd8313ed055'),(10,'فربد','تسلیمی','12598745632','81dc9bdb52d04dc20036dbd8313ed055'),(13,'ali','karimi','777','81dc9bdb52d04dc20036dbd8313ed055'),(14,'reza','dfsdf','6667','81dc9bdb52d04dc20036dbd8313ed055'),(15,'hasan','reza','3424','81dc9bdb52d04dc20036dbd8313ed055'),(16,'ahmad','alinia','7777777','81dc9bdb52d04dc20036dbd8313ed055'),(17,'mahmood','taghipoor','77','81dc9bdb52d04dc20036dbd8313ed055'),(18,'hasan','ali','1254125','81dc9bdb52d04dc20036dbd8313ed055'),(19,'hossein','reza','234','81dc9bdb52d04dc20036dbd8313ed055');
/*!40000 ALTER TABLE `students` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `studentsclassrooms`
--

DROP TABLE IF EXISTS `studentsclassrooms`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `studentsclassrooms` (
  `StudentClassRoomId` bigint(20) NOT NULL AUTO_INCREMENT,
  `Student` bigint(255) DEFAULT NULL,
  `ClassRoom` bigint(255) DEFAULT NULL,
  PRIMARY KEY (`StudentClassRoomId`)
) ENGINE=InnoDB AUTO_INCREMENT=109 DEFAULT CHARSET=utf8 COLLATE=utf8_persian_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `studentsclassrooms`
--

LOCK TABLES `studentsclassrooms` WRITE;
/*!40000 ALTER TABLE `studentsclassrooms` DISABLE KEYS */;
INSERT INTO `studentsclassrooms` VALUES (31,2,7),(32,6,7),(33,8,7),(34,13,7),(35,17,7),(36,18,7),(51,2,5),(52,3,5),(53,4,5),(54,5,5),(55,6,5),(56,7,5),(57,8,5),(59,2,8),(60,3,8),(61,4,8),(62,5,8),(74,1,5),(75,1,7),(100,1,1),(106,14,1),(107,18,1),(108,19,1);
/*!40000 ALTER TABLE `studentsclassrooms` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `t1`
--

DROP TABLE IF EXISTS `t1`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `t1` (
  `ClassRoom.ClassRoomId` tinyint(4) NOT NULL,
  `ClassRoom.Name` tinyint(4) NOT NULL,
  `ClassRoom.Saal` tinyint(4) NOT NULL,
  `Term.TermId` tinyint(4) NOT NULL,
  `Term.SalShoroo` tinyint(4) NOT NULL,
  `Term.SalPayan` tinyint(4) NOT NULL,
  `Term.NimSal` tinyint(4) NOT NULL,
  `Term.Tozihat` tinyint(4) NOT NULL,
  `Teacher.TeacherId` tinyint(4) NOT NULL,
  `Teacher.Name` tinyint(4) NOT NULL,
  `Teacher.Family` tinyint(4) NOT NULL,
  `Teacher.Username` tinyint(4) NOT NULL,
  `Teacher.Passwd` tinyint(4) NOT NULL,
  `Lecture.LectureId` tinyint(4) NOT NULL,
  `Lecture.Name` tinyint(4) NOT NULL,
  `Lecture.TedadVahed` tinyint(4) NOT NULL,
  `Lecture.Tozihat` tinyint(4) NOT NULL,
  `GradeType.GradeTypeId` tinyint(4) NOT NULL,
  `GradeType.Name` tinyint(4) NOT NULL,
  `GradeType.Min` tinyint(4) NOT NULL,
  `GradeType.Max` tinyint(4) NOT NULL,
  `GradeType.Pass` tinyint(4) NOT NULL
) ENGINE=MyISAM DEFAULT CHARSET=utf8 COLLATE=utf8_persian_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `t1`
--

LOCK TABLES `t1` WRITE;
/*!40000 ALTER TABLE `t1` DISABLE KEYS */;
/*!40000 ALTER TABLE `t1` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `t2`
--

DROP TABLE IF EXISTS `t2`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `t2` (
  `GradeValue.Value` tinyint(4) NOT NULL,
  `GradeValue.GradeValueId` tinyint(4) NOT NULL,
  `GradeType.GradeTypeId` tinyint(4) NOT NULL,
  `GradeType.Name` tinyint(4) NOT NULL,
  `GradeType.Min` tinyint(4) NOT NULL,
  `GradeType.Max` tinyint(4) NOT NULL,
  `GradeType.Pass` tinyint(4) NOT NULL
) ENGINE=MyISAM DEFAULT CHARSET=utf8 COLLATE=utf8_persian_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `t2`
--

LOCK TABLES `t2` WRITE;
/*!40000 ALTER TABLE `t2` DISABLE KEYS */;
/*!40000 ALTER TABLE `t2` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `t3`
--

DROP TABLE IF EXISTS `t3`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `t3` (
  `ClassRoom.Lecture` tinyint(4) NOT NULL,
  `ClassRoom.Saal` tinyint(4) NOT NULL,
  `ClassRoom.Teacher` tinyint(4) NOT NULL,
  `ClassRoom.Name` tinyint(4) NOT NULL,
  `Student.Name` tinyint(4) NOT NULL,
  `Student.Family` tinyint(4) NOT NULL,
  `Student.CodeMelli` tinyint(4) NOT NULL,
  `Student.StudentId` tinyint(4) NOT NULL,
  `ClassRoom.ClassRoomId` tinyint(4) NOT NULL,
  `ClassRoom.Term` tinyint(4) NOT NULL,
  `Student.Passwd` tinyint(4) NOT NULL,
  `StudentClassRoom.StudentClassRoomId` tinyint(4) NOT NULL,
  `StudentClassRoom.Student` tinyint(4) NOT NULL,
  `StudentClassRoom.ClassRoom` tinyint(4) NOT NULL,
  `Lecture.LectureId` tinyint(4) NOT NULL,
  `Lecture.Name` tinyint(4) NOT NULL,
  `Lecture.TedadVahed` tinyint(4) NOT NULL,
  `Lecture.Tozihat` tinyint(4) NOT NULL,
  `Teacher.TeacherId` tinyint(4) NOT NULL,
  `Teacher.Name` tinyint(4) NOT NULL,
  `Teacher.Family` tinyint(4) NOT NULL,
  `Teacher.UserName` tinyint(4) NOT NULL,
  `Teacher.Passwd` tinyint(4) NOT NULL,
  `Term.TermId` tinyint(4) NOT NULL,
  `Term.SalShoroo` tinyint(4) NOT NULL,
  `Term.SalPayan` tinyint(4) NOT NULL,
  `Term.NimSal` tinyint(4) NOT NULL,
  `Term.Tozihat` tinyint(4) NOT NULL
) ENGINE=MyISAM DEFAULT CHARSET=utf8 COLLATE=utf8_persian_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `t3`
--

LOCK TABLES `t3` WRITE;
/*!40000 ALTER TABLE `t3` DISABLE KEYS */;
/*!40000 ALTER TABLE `t3` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `t4`
--

DROP TABLE IF EXISTS `t4`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `t4` (
  `ClassRoom.Lecture` tinyint(4) NOT NULL,
  `ClassRoom.Saal` tinyint(4) NOT NULL,
  `ClassRoom.Teacher` tinyint(4) NOT NULL,
  `ClassRoom.Name` tinyint(4) NOT NULL,
  `Student.Name` tinyint(4) NOT NULL,
  `Student.Family` tinyint(4) NOT NULL,
  `Student.CodeMelli` tinyint(4) NOT NULL,
  `Student.StudentId` tinyint(4) NOT NULL,
  `ClassRoom.ClassRoomId` tinyint(4) NOT NULL,
  `ClassRoom.Term` tinyint(4) NOT NULL,
  `Student.Passwd` tinyint(4) NOT NULL,
  `StudentClassRoom.StudentClassRoomId` tinyint(4) NOT NULL,
  `StudentClassRoom.Student` tinyint(4) NOT NULL,
  `StudentClassRoom.ClassRoom` tinyint(4) NOT NULL,
  `Value` tinyint(4) NOT NULL,
  `GardeId` tinyint(4) NOT NULL
) ENGINE=MyISAM DEFAULT CHARSET=utf8 COLLATE=utf8_persian_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `t4`
--

LOCK TABLES `t4` WRITE;
/*!40000 ALTER TABLE `t4` DISABLE KEYS */;
/*!40000 ALTER TABLE `t4` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `teachers`
--

DROP TABLE IF EXISTS `teachers`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `teachers` (
  `TeacherId` int(11) NOT NULL AUTO_INCREMENT,
  `Name` text COLLATE utf8_persian_ci NOT NULL,
  `Family` text COLLATE utf8_persian_ci NOT NULL,
  `Username` text COLLATE utf8_persian_ci NOT NULL,
  `CodeMelli` text COLLATE utf8_persian_ci,
  `Passwd` text COLLATE utf8_persian_ci NOT NULL,
  PRIMARY KEY (`TeacherId`)
) ENGINE=InnoDB AUTO_INCREMENT=7 DEFAULT CHARSET=utf8 COLLATE=utf8_persian_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `teachers`
--

LOCK TABLES `teachers` WRITE;
/*!40000 ALTER TABLE `teachers` DISABLE KEYS */;
INSERT INTO `teachers` VALUES (2,'رضا','علی نژاد','reza','2701512542','81dc9bdb52d04dc20036dbd8313ed055'),(5,'تقی','حسینی','ali','280145287965','81dc9bdb52d04dc20036dbd8313ed055'),(6,'aaaaaaaaa','ddddddd','657','75665','81dc9bdb52d04dc20036dbd8313ed055');
/*!40000 ALTER TABLE `teachers` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `terms`
--

DROP TABLE IF EXISTS `terms`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `terms` (
  `TermId` bigint(20) NOT NULL AUTO_INCREMENT,
  `SalShoroo` bigint(255) DEFAULT NULL,
  `SalPayan` bigint(255) DEFAULT NULL,
  `NimSal` bigint(255) DEFAULT NULL,
  `Tozihat` varchar(255) COLLATE utf8_persian_ci DEFAULT NULL,
  PRIMARY KEY (`TermId`)
) ENGINE=InnoDB AUTO_INCREMENT=4 DEFAULT CHARSET=utf8 COLLATE=utf8_persian_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `terms`
--

LOCK TABLES `terms` WRITE;
/*!40000 ALTER TABLE `terms` DISABLE KEYS */;
INSERT INTO `terms` VALUES (1,1393,1394,111111,'-'),(2,1390,1391,2,'-'),(3,1389,1390,3,'-');
/*!40000 ALTER TABLE `terms` ENABLE KEYS */;
UNLOCK TABLES;
