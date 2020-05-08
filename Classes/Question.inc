<?php

require_once 'DataAccess.inc';
/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

class Question {

    public $QuestionId;
    public $Content;
    public $QuestionType;
    public $Teacher;
    public $Lecture;
    public $Saal;

    function __construct() {
        $teacher = new Teacher();
        $lecture = new Lecture();
        $questionType = new QuestionType();
        $this->Teacher = $teacher;
        $this->Lecture = $lecture;
        $this->QuestionType = $questionType;
    }

}
