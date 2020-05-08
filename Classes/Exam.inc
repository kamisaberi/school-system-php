<?php

require_once  'DataAccess.inc';
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
class Exam {
    public $ExamId = 1;
    public $Title;
    public $Saal;
    public $Teacher;
    public $Lecture;
    
    function __construct() {
    $teacher = new Teacher();
    $lecture= new Lecture();
    $this->Teacher=$teacher;
    $this->Lecture=$lecture;
}

    
    
}
