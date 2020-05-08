DROP TABLE IF EXISTS Answers;

CREATE TABLE `Answers` (
  `AnswerId` bigint(255) NOT NULL AUTO_INCREMENT,
  `Content` text COLLATE utf8_persian_ci,
  `ExamQuestion` bigint(255) DEFAULT NULL,
  `Student` bigint(255) DEFAULT NULL,
  PRIMARY KEY (`AnswerId`)
) ENGINE=InnoDB AUTO_INCREMENT=9 DEFAULT CHARSET=utf8 COLLATE=utf8_persian_ci;

INSERT INTO Answers VALUES("8","4 ","4","1");



DROP TABLE IF EXISTS Exams;

CREATE TABLE `Exams` (
  `ExamId` bigint(20) NOT NULL AUTO_INCREMENT,
  `Title` text COLLATE utf8_persian_ci,
  `Teacher` bigint(255) DEFAULT NULL,
  `Lecture` bigint(255) DEFAULT NULL,
  `Saal` bigint(255) DEFAULT NULL,
  PRIMARY KEY (`ExamId`)
) ENGINE=InnoDB AUTO_INCREMENT=4 DEFAULT CHARSET=utf8 COLLATE=utf8_persian_ci;

INSERT INTO Exams VALUES("1","آزمون ریاضی میان ترم","2","1","1");
INSERT INTO Exams VALUES("3","test","5","1","6");



DROP TABLE IF EXISTS ExamsClassRooms;

CREATE TABLE `ExamsClassRooms` (
  `ExamClassRoomId` bigint(20) NOT NULL AUTO_INCREMENT,
  `Exam` bigint(255) DEFAULT NULL,
  `ClassRoom` bigint(255) DEFAULT NULL,
  PRIMARY KEY (`ExamClassRoomId`)
) ENGINE=InnoDB AUTO_INCREMENT=9 DEFAULT CHARSET=utf8 COLLATE=utf8_persian_ci;

INSERT INTO ExamsClassRooms VALUES("7","1","1");
INSERT INTO ExamsClassRooms VALUES("8","1","8");



DROP TABLE IF EXISTS ExamsQuestions;

CREATE TABLE `ExamsQuestions` (
  `ExamQuestionId` bigint(20) NOT NULL AUTO_INCREMENT,
  `Exam` bigint(255) DEFAULT NULL,
  `Question` bigint(255) DEFAULT NULL,
  PRIMARY KEY (`ExamQuestionId`)
) ENGINE=InnoDB AUTO_INCREMENT=5 DEFAULT CHARSET=utf8 COLLATE=utf8_persian_ci;

INSERT INTO ExamsQuestions VALUES("4","1","1");



DROP TABLE IF EXISTS QuestionChoices;

CREATE TABLE `QuestionChoices` (
  `QuestionChoiceId` bigint(20) NOT NULL AUTO_INCREMENT,
  `Content` varchar(255) COLLATE utf8_persian_ci DEFAULT NULL,
  `Question` bigint(255) DEFAULT NULL,
  PRIMARY KEY (`QuestionChoiceId`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8 COLLATE=utf8_persian_ci;




DROP TABLE IF EXISTS QuestionTypes;

CREATE TABLE `QuestionTypes` (
  `QuestionTypeId` bigint(20) NOT NULL AUTO_INCREMENT,
  `Name` varchar(255) COLLATE utf8_persian_ci DEFAULT NULL,
  `Tozihat` varchar(255) COLLATE utf8_persian_ci DEFAULT NULL,
  PRIMARY KEY (`QuestionTypeId`)
) ENGINE=InnoDB AUTO_INCREMENT=4 DEFAULT CHARSET=utf8 COLLATE=utf8_persian_ci;

INSERT INTO QuestionTypes VALUES("1","تشریحی","-");
INSERT INTO QuestionTypes VALUES("2","چند گزینه ای(انتخاب یک گزینه)","-");
INSERT INTO QuestionTypes VALUES("3","چند گزینه ای(انتخاب چند گزینه)","-");



DROP TABLE IF EXISTS Questions;

CREATE TABLE `Questions` (
  `QuestionId` bigint(20) NOT NULL AUTO_INCREMENT,
  `Content` text COLLATE utf8_persian_ci,
  `QuestionType` bigint(255) DEFAULT NULL,
  `Teacher` bigint(255) DEFAULT NULL,
  `Lecture` bigint(255) DEFAULT NULL,
  `Saal` bigint(255) DEFAULT NULL,
  PRIMARY KEY (`QuestionId`)
) ENGINE=InnoDB AUTO_INCREMENT=2 DEFAULT CHARSET=utf8 COLLATE=utf8_persian_ci;

INSERT INTO Questions VALUES("1","<p><img alt=\"\" src=\"/School/Uploads//reza/5.jpg\" style=\"height:240px; width:320px\" />sdad asd</p>\n\n<p>&nbsp;</p>\n\n<p>as</p>\n\n<p>as</p>\n\n<p>&nbsp;</p>\n\n<p>as</p>\n\n<p>d</p>\n\n<p>as</p>\n\n<p>&nbsp;a</p>\n\n<p>&nbsp;</p>\n\n<p>&nbsp;</p>\n","1","2","1","1");



DROP TABLE IF EXISTS TrueAnswers;

CREATE TABLE `TrueAnswers` (
  `TrueAnswerId` bigint(20) NOT NULL AUTO_INCREMENT,
  `Content` text COLLATE utf8_persian_ci,
  `Question` bigint(255) DEFAULT NULL,
  PRIMARY KEY (`TrueAnswerId`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8 COLLATE=utf8_persian_ci;




DROP TABLE IF EXISTS answers1;

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




DROP TABLE IF EXISTS classrooms;

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

INSERT INTO classrooms VALUES("1","ریاضی الف","1","1","1","5","1");
INSERT INTO classrooms VALUES("4","فیزیک الف","2","2","1","2","1");
INSERT INTO classrooms VALUES("5","دینی الف","1","3","10","2","2");
INSERT INTO classrooms VALUES("7","فیزیک ج","1","3","1","2","1");
INSERT INTO classrooms VALUES("8","ریاضی  اول","1","1","1","5","6");



DROP TABLE IF EXISTS grades;

CREATE TABLE `grades` (
  `GardeId` bigint(255) NOT NULL AUTO_INCREMENT,
  `Value` varchar(255) COLLATE utf8_persian_ci DEFAULT NULL,
  `StudentClassRoom` bigint(255) DEFAULT NULL,
  `GradeType` bigint(255) DEFAULT NULL,
  PRIMARY KEY (`GardeId`)
) ENGINE=InnoDB AUTO_INCREMENT=135 DEFAULT CHARSET=utf8 COLLATE=utf8_persian_ci;

INSERT INTO grades VALUES("50","10","43","1");
INSERT INTO grades VALUES("56","17","0","1");
INSERT INTO grades VALUES("62","12.2","32","1");
INSERT INTO grades VALUES("63","13.25","33","1");
INSERT INTO grades VALUES("64","18.75","34","1");
INSERT INTO grades VALUES("65","15.25","35","1");
INSERT INTO grades VALUES("66","16.00","36","1");
INSERT INTO grades VALUES("94","خیلی بد","44","2");
INSERT INTO grades VALUES("96","15","31","1");
INSERT INTO grades VALUES("97","15","45","1");
INSERT INTO grades VALUES("98","18","46","1");
INSERT INTO grades VALUES("99","خیلی بد","50","2");
INSERT INTO grades VALUES("100","B","58","6");
INSERT INTO grades VALUES("102","C","61","6");
INSERT INTO grades VALUES("104","B","60","6");
INSERT INTO grades VALUES("106","متوسط","70","2");
INSERT INTO grades VALUES("117","18","75","1");
INSERT INTO grades VALUES("118","14","100","1");
INSERT INTO grades VALUES("127","خیلی بد","51","2");
INSERT INTO grades VALUES("128","بد","52","2");
INSERT INTO grades VALUES("129","خیلی بد","53","2");
INSERT INTO grades VALUES("130","خیلی بد","54","2");
INSERT INTO grades VALUES("131","متوسط","55","2");
INSERT INTO grades VALUES("132","خیلی بد","56","2");
INSERT INTO grades VALUES("133","خیلی بد","57","2");
INSERT INTO grades VALUES("134","خیلی بد","74","2");



DROP TABLE IF EXISTS gradetypes;

CREATE TABLE `gradetypes` (
  `GradeTypeId` bigint(20) NOT NULL AUTO_INCREMENT,
  `Name` varchar(255) COLLATE utf8_persian_ci DEFAULT NULL,
  `Min` varchar(255) COLLATE utf8_persian_ci DEFAULT NULL,
  `Max` varchar(255) COLLATE utf8_persian_ci DEFAULT NULL,
  `Pass` varchar(255) COLLATE utf8_persian_ci DEFAULT NULL,
  `DefinedValues` bigint(255) DEFAULT NULL,
  PRIMARY KEY (`GradeTypeId`)
) ENGINE=InnoDB AUTO_INCREMENT=7 DEFAULT CHARSET=utf8 COLLATE=utf8_persian_ci;

INSERT INTO gradetypes VALUES("1","عددی","0","20","10","0");
INSERT INTO gradetypes VALUES("2","درجه بندی (خوب , بد)","بد","خیلی خوب","متوسط","1");
INSERT INTO gradetypes VALUES("6","امتیاز دهی انگلیسی","E","A++","C","1");



DROP TABLE IF EXISTS gradevalues;

CREATE TABLE `gradevalues` (
  `GradeValueId` bigint(11) NOT NULL AUTO_INCREMENT,
  `Value` varchar(255) COLLATE utf8_persian_ci DEFAULT NULL,
  `GradeType` bigint(255) DEFAULT NULL,
  PRIMARY KEY (`GradeValueId`)
) ENGINE=InnoDB AUTO_INCREMENT=8 DEFAULT CHARSET=utf8 COLLATE=utf8_persian_ci;

INSERT INTO gradevalues VALUES("2","خیلی بد","2");
INSERT INTO gradevalues VALUES("3","بد","2");
INSERT INTO gradevalues VALUES("4","متوسط","2");
INSERT INTO gradevalues VALUES("5","A","6");
INSERT INTO gradevalues VALUES("6","B","6");
INSERT INTO gradevalues VALUES("7","C","6");



DROP TABLE IF EXISTS lectures;

CREATE TABLE `lectures` (
  `LectureId` bigint(20) NOT NULL AUTO_INCREMENT,
  `Name` varchar(255) COLLATE utf8_persian_ci DEFAULT NULL,
  `TedadVahed` bigint(255) DEFAULT NULL,
  `Tozihat` varchar(255) COLLATE utf8_persian_ci DEFAULT NULL,
  PRIMARY KEY (`LectureId`)
) ENGINE=InnoDB AUTO_INCREMENT=4 DEFAULT CHARSET=utf8 COLLATE=utf8_persian_ci;

INSERT INTO lectures VALUES("1","ریاضی","4","3333333");
INSERT INTO lectures VALUES("2","شیمی","2","iiiiiii");
INSERT INTO lectures VALUES("3","فیزیک","3","iiiiiii");



DROP TABLE IF EXISTS options;

CREATE TABLE `options` (
  `OptionId` bigint(20) NOT NULL AUTO_INCREMENT,
  `Name` varchar(255) COLLATE utf8_persian_ci DEFAULT NULL,
  `Value` varchar(255) COLLATE utf8_persian_ci DEFAULT NULL,
  PRIMARY KEY (`OptionId`)
) ENGINE=InnoDB AUTO_INCREMENT=3 DEFAULT CHARSET=utf8 COLLATE=utf8_persian_ci;

INSERT INTO options VALUES("1","ActiveTerm","1");
INSERT INTO options VALUES("2","NumberOfRecords","30");



DROP TABLE IF EXISTS questionview;

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




DROP TABLE IF EXISTS students;

CREATE TABLE `students` (
  `StudentId` bigint(20) NOT NULL AUTO_INCREMENT,
  `Name` varchar(255) COLLATE utf8_persian_ci DEFAULT NULL,
  `Family` varchar(255) COLLATE utf8_persian_ci DEFAULT NULL,
  `CodeMelli` varchar(255) COLLATE utf8_persian_ci DEFAULT NULL,
  `Passwd` varchar(255) COLLATE utf8_persian_ci DEFAULT NULL,
  PRIMARY KEY (`StudentId`)
) ENGINE=InnoDB AUTO_INCREMENT=20 DEFAULT CHARSET=utf8 COLLATE=utf8_persian_ci;

INSERT INTO students VALUES("1","علی","رضایی","1234","81dc9bdb52d04dc20036dbd8313ed055");
INSERT INTO students VALUES("2","رضا","احمدی","4321","81dc9bdb52d04dc20036dbd8313ed055");
INSERT INTO students VALUES("3","حسن","رضایی نژاد","14525254452","81dc9bdb52d04dc20036dbd8313ed055");
INSERT INTO students VALUES("4","حسین","علی نیا","15236987545","81dc9bdb52d04dc20036dbd8313ed055");
INSERT INTO students VALUES("5","احمد","حدادی","77896541232","81dc9bdb52d04dc20036dbd8313ed055");
INSERT INTO students VALUES("6","محمود","احمدی","47854785478","81dc9bdb52d04dc20036dbd8313ed055");
INSERT INTO students VALUES("7","فرهاد","رضایی","45645645644","81dc9bdb52d04dc20036dbd8313ed055");
INSERT INTO students VALUES("8","کامبیز","حسینی","14785214785","81dc9bdb52d04dc20036dbd8313ed055");
INSERT INTO students VALUES("9","رضا","رضایی","14785693212","81dc9bdb52d04dc20036dbd8313ed055");
INSERT INTO students VALUES("10","فربد","تسلیمی","12598745632","81dc9bdb52d04dc20036dbd8313ed055");
INSERT INTO students VALUES("13","ali","karimi","777","81dc9bdb52d04dc20036dbd8313ed055");
INSERT INTO students VALUES("14","reza","dfsdf","6667","81dc9bdb52d04dc20036dbd8313ed055");
INSERT INTO students VALUES("15","hasan","reza","3424","81dc9bdb52d04dc20036dbd8313ed055");
INSERT INTO students VALUES("16","ahmad","alinia","7777777","81dc9bdb52d04dc20036dbd8313ed055");
INSERT INTO students VALUES("17","mahmood","taghipoor","77","81dc9bdb52d04dc20036dbd8313ed055");
INSERT INTO students VALUES("18","hasan","ali","1254125","81dc9bdb52d04dc20036dbd8313ed055");
INSERT INTO students VALUES("19","hossein","reza","234","81dc9bdb52d04dc20036dbd8313ed055");



DROP TABLE IF EXISTS studentsclassrooms;

CREATE TABLE `studentsclassrooms` (
  `StudentClassRoomId` bigint(20) NOT NULL AUTO_INCREMENT,
  `Student` bigint(255) DEFAULT NULL,
  `ClassRoom` bigint(255) DEFAULT NULL,
  PRIMARY KEY (`StudentClassRoomId`)
) ENGINE=InnoDB AUTO_INCREMENT=109 DEFAULT CHARSET=utf8 COLLATE=utf8_persian_ci;

INSERT INTO studentsclassrooms VALUES("31","2","7");
INSERT INTO studentsclassrooms VALUES("32","6","7");
INSERT INTO studentsclassrooms VALUES("33","8","7");
INSERT INTO studentsclassrooms VALUES("34","13","7");
INSERT INTO studentsclassrooms VALUES("35","17","7");
INSERT INTO studentsclassrooms VALUES("36","18","7");
INSERT INTO studentsclassrooms VALUES("51","2","5");
INSERT INTO studentsclassrooms VALUES("52","3","5");
INSERT INTO studentsclassrooms VALUES("53","4","5");
INSERT INTO studentsclassrooms VALUES("54","5","5");
INSERT INTO studentsclassrooms VALUES("55","6","5");
INSERT INTO studentsclassrooms VALUES("56","7","5");
INSERT INTO studentsclassrooms VALUES("57","8","5");
INSERT INTO studentsclassrooms VALUES("59","2","8");
INSERT INTO studentsclassrooms VALUES("60","3","8");
INSERT INTO studentsclassrooms VALUES("61","4","8");
INSERT INTO studentsclassrooms VALUES("62","5","8");
INSERT INTO studentsclassrooms VALUES("74","1","5");
INSERT INTO studentsclassrooms VALUES("75","1","7");
INSERT INTO studentsclassrooms VALUES("100","1","1");
INSERT INTO studentsclassrooms VALUES("106","14","1");
INSERT INTO studentsclassrooms VALUES("107","18","1");
INSERT INTO studentsclassrooms VALUES("108","19","1");



DROP TABLE IF EXISTS t1;

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




DROP TABLE IF EXISTS t2;

CREATE TABLE `t2` (
  `GradeValue.Value` tinyint(4) NOT NULL,
  `GradeValue.GradeValueId` tinyint(4) NOT NULL,
  `GradeType.GradeTypeId` tinyint(4) NOT NULL,
  `GradeType.Name` tinyint(4) NOT NULL,
  `GradeType.Min` tinyint(4) NOT NULL,
  `GradeType.Max` tinyint(4) NOT NULL,
  `GradeType.Pass` tinyint(4) NOT NULL
) ENGINE=MyISAM DEFAULT CHARSET=utf8 COLLATE=utf8_persian_ci;




DROP TABLE IF EXISTS t3;

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




DROP TABLE IF EXISTS t4;

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




DROP TABLE IF EXISTS teachers;

CREATE TABLE `teachers` (
  `TeacherId` int(11) NOT NULL AUTO_INCREMENT,
  `Name` text COLLATE utf8_persian_ci NOT NULL,
  `Family` text COLLATE utf8_persian_ci NOT NULL,
  `Username` text COLLATE utf8_persian_ci NOT NULL,
  `CodeMelli` text COLLATE utf8_persian_ci,
  `Passwd` text COLLATE utf8_persian_ci NOT NULL,
  PRIMARY KEY (`TeacherId`)
) ENGINE=InnoDB AUTO_INCREMENT=7 DEFAULT CHARSET=utf8 COLLATE=utf8_persian_ci;

INSERT INTO teachers VALUES("2","رضا","علی نژاد","reza","2701512542","81dc9bdb52d04dc20036dbd8313ed055");
INSERT INTO teachers VALUES("5","تقی","حسینی","ali","280145287965","81dc9bdb52d04dc20036dbd8313ed055");
INSERT INTO teachers VALUES("6","aaaaaaaaa","ddddddd","657","75665","81dc9bdb52d04dc20036dbd8313ed055");



DROP TABLE IF EXISTS terms;

CREATE TABLE `terms` (
  `TermId` bigint(20) NOT NULL AUTO_INCREMENT,
  `SalShoroo` bigint(255) DEFAULT NULL,
  `SalPayan` bigint(255) DEFAULT NULL,
  `NimSal` bigint(255) DEFAULT NULL,
  `Tozihat` varchar(255) COLLATE utf8_persian_ci DEFAULT NULL,
  PRIMARY KEY (`TermId`)
) ENGINE=InnoDB AUTO_INCREMENT=4 DEFAULT CHARSET=utf8 COLLATE=utf8_persian_ci;

INSERT INTO terms VALUES("1","1393","1394","111111","-");
INSERT INTO terms VALUES("2","1390","1391","2","-");
INSERT INTO terms VALUES("3","1389","1390","3","-");



DROP TABLE IF EXISTS users;

CREATE TABLE `users` (
  `UserId` bigint(20) NOT NULL AUTO_INCREMENT,
  `Username` varchar(255) COLLATE utf8_persian_ci DEFAULT NULL,
  `Passwd` varchar(255) COLLATE utf8_persian_ci DEFAULT NULL,
  PRIMARY KEY (`UserId`)
) ENGINE=InnoDB AUTO_INCREMENT=2 DEFAULT CHARSET=utf8 COLLATE=utf8_persian_ci;

INSERT INTO users VALUES("1","admin","81dc9bdb52d04dc20036dbd8313ed055");



