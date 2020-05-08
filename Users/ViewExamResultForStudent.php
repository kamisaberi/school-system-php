<?php

require_once '../Classes/ExamEx.inc';
require_once '../Classes/LectureEx.inc';
require_once '../Classes/TeacherEx.inc';
require_once '../Classes/TermEx.inc';
require_once '../Classes/GradeTypeEx.inc';
require_once '../Classes/AnswerEx.inc';
?>
<?php

include_once 'Template/header.php';
include_once 'Template/menu.php';
?>


<?php

if (isset($_GET['examid']) && isset($_GET['studentid'])) {
    $examid = $_GET['examid'];
    $studentid = $_GET['studentid'];
//    $exam = new Exam();
//    $exam = ExamEx::GetOneExam($id);
//    $title = $exam->Title;
//    $teacherid = $exam->Teacher->TeacherId;
//    $saal = $exam->Saal;
//    $lectureid = $exam->Lecture->LectureId;
    $answers = AnswerEx::GetAnswersForStudentAndExam($studentid, $examid);
}
//echo $classRoom->Name;
?>
<table  border="1" cellpadding="5" cellspacing="5"  class="ViewTable">
    <?php

    foreach ($answers as $answer) {
        echo '<tr><td>';
        echo $answer->Question->Content;
        echo '</td></tr>';
        echo '<tr><td>';
        echo $answer->Content;
        echo '</td></tr>';
    }
    ?>
</table>
<?php

include_once 'Template/footer.php';
?>

