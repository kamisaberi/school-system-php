<?php

require_once 'DataAccess.inc';
require_once 'Student.inc';
require_once 'Question.inc';
require_once 'Exam.inc';
//use DataAccess;

/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/**
 * Description of Teacher
 *
 * @author kami
 */
class Answer {

    public $AnswerId = 1;
    public $Content;
    public $Exam;
    public $Question;
    public $Student;
    
    public function __construct() {
        $student = new Student();
        $exam = new Exam();
        $question = new Question();
        $this->Student=$student;
        $this->Exam=$exam;
        $this->Question=$question;
    }
    

}
