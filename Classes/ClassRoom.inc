<?php

require_once 'Term.inc';
require_once 'Teacher.inc';
require_once 'Lecture.inc';
require_once 'GradeType.inc';
//use DataAccess;

/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/**
 * Description of ClassRoom
 *
 * @author kami
 */
class ClassRoom {

public $ClassRoomId = 1;
public $Name;
public $Term;
public $Lecture;
public $Saal;
public $Teacher;
public $GradeType;
        
function __construct() {
    $term = new Term();
    $teacher = new Teacher();
    $lecture = new Lecture();
    $gradeType= new GradeType();
    $this->Term =$term;
    $this->Teacher=$teacher;
    $this->Lecture =$lecture;
    $this->GradeType =$gradeType;
}

}
