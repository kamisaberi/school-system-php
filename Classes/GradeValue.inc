<?php

require_once 'DataAccess.inc';
require_once 'GradeType.inc';
//use DataAccess;

/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/**
 * Description of GradeValue
 *
 * @author kami
 */
class GradeValue {

    public $GradeValueId = 1;
    public $Value;
    public $GradeType;
    
            
    
    function __construct() {
        $this->GradeValueId=0;
        $this->Value="";
        $gradeType= new GradeType();
        $this->GradeType=$gradeType;
    
        
    }
}
