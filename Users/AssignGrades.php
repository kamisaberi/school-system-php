<?php
require_once '../Classes/ClassRoomEx.inc';
require_once '../Classes/StudentEx.inc';
require_once '../Classes/OptionEx.inc';
require_once '../Classes/GradeValueEx.inc';
?>
<?php
include_once 'Template/header.php';
include_once 'Template/menu.php';
?>

<?php
if ($_SESSION['UserType'] == "Admin") {




    $id = "";
    $cm = "add";
    $content = "";
    $family = "";
    $username = "";
    $passwd = "";
    if (isset($_GET['student'])) {

        $cm = "edit";
        $id = $_GET['student'];
        $student = new Student();
        $student = StudentEx::GetOnStudent($id);
        $content = $student->Name;
        $family = $student->Family;
        $codemelli = $student->CodeMelli;
        $termid = OptionEx::GetValue("ActiveTerm");
        //$passwd = $student->Passwd;
    }
//echo $teacher->Name;
    ?>
        <!--<p> <?php echo $content; ?>  </p>
        <p> <?php echo $family; ?>  </p>
        <p> <?php echo $codemelli; ?>  </p>-->

    <form method="post" id="form1" name="form1" action="UpdateAssignedGrades.php" >
        <input type="hidden" name="student" id="student" value="<?php echo $id ?>"/>
        <?php
        $classroms = ClassRoomEx::GetClassRoomsOfActiveTermForStudent($id, $termid);
        $i = 1;
        ?>    
        <table  border="1" cellpadding="5" cellspacing="5"  class="ViewTable">
            <tr>
                <td>
                    <?php echo $content . " " . $family; ?>
                </td>
                <td>
                    <?php echo $codemelli; ?>
                </td>
            </tr>
        </table>

        <table  border="1" cellpadding="5" cellspacing="5"  class="ViewTable">

            <?php
            foreach ($classroms as $classrom) {
                echo '<tr>';
                echo '<td>';
                echo "<input type='hidden' name='classrooms[]' id='classrooms[]' value='" . $classrom->ClassRoomId . "' />";
                echo $classrom->Name . ":";
                echo '</td>';
                echo '<td>';
                if ($classrom->GradeType->DefinedValues == TRUE) {
                    $gradevalues = GradeValueEx::GetGradeValuesBasedOnGradeTypeId($classrom->GradeType->GradeTypeId);
                    echo '<select name="values[]" id="values[]" >';
                    foreach ($gradevalues as $gradevalue) {
                        $selected = "";
                        if ($gradevalue->Value == GradeEx::GetGradesForStudentInClassRoom($id, $classrom->ClassRoomId)) {
                            $selected = "selected";
                        }
                        echo "<option value='" . $gradevalue->Value . "' " . $selected . ">" . $gradevalue->Value . "</option>";
                    }
                    echo '</select>';
                } else {
                    echo "<input type='text' name='values[]' id='values[]' value='" . GradeEx::GetGradesForStudentInClassRoom($id, $classrom->ClassRoomId) . "' />";
                }

                echo '</td>';
                $i++;
                echo '</tr>';
            }
            ?>
            <tr>
                <td colspan="2">
                    <input type="submit" name="button" id="button" value="Submit" />
                </td>
            </tr>
        </table>
    </form> 

    <?php
} elseif ($_SESSION['UserType'] == "Teacher") {
    ?>
    <?php
    $id = "";
    $cm = "add";
    $content = "";
    $family = "";
    $username = "";
    $passwd = "";
    if (isset($_GET['classroom'])) {

        $cm = "edit";
        $id = $_GET['classroom'];
        $classroom = new ClassRoom();
        $classroom = ClassRoomEx::GetOnClassRoom($id);
        $content = $classroom->Name;
//    $family = $student->Family;
//    $codemelli = $student->CodeMelli;
        $termid = OptionEx::GetValue("ActiveTerm");
        //$passwd = $student->Passwd;
    }
//echo $teacher->Name;
    ?>
    <!--<p> <?php echo $content; ?>  </p>
    <p> <?php echo $family; ?>  </p>
    <p> <?php echo $codemelli; ?>  </p>-->

    <form method="post" id="form1" name="form1" action="UpdateAssignedGrades.php" >
        <input type="hidden" name="classroom" id="classroom" value="<?php echo $id ?>"/>
        <?php
        $students = StudentEx::GetStudentsOfActiveTermForClassRoom($id, $termid);
        $i = 1;
        ?>
        <table  border="1" cellpadding="5" cellspacing="5"  class="ViewTable">
            <tr>
                <td>
                    <?php echo $content ?>  
                </td>
                <td>
                    <?php echo $classroom->Teacher->Name . " " . $classroom->Teacher->Family; ?>  
                </td>
            </tr>
        </table>    



        <table  border="1" cellpadding="5" cellspacing="5"  class="ViewTable">
            <?php
            foreach ($students as $student) {
                echo "<tr>";
                echo "<input type='hidden' name='students[]' id='students[]' value='" . $student->StudentId . "' />";
                echo "<td>";

                echo $student->Name . " " . $student->Family;
                echo "</td>";

                echo "<td>";

                $classrom = ClassRoomEx::GetOnClassRoom($id);
                if ($classrom->GradeType->DefinedValues == TRUE) {
                    $gradevalues = GradeValueEx::GetGradeValuesBasedOnGradeTypeId($classrom->GradeType->GradeTypeId);
                    echo '<select name="values[]" id="values[]" >';
                    foreach ($gradevalues as $gradevalue) {
                        $selected = "";
                        if ($gradevalue->Value == GradeEx::GetGradesForStudentInClassRoom($student->StudentId, $id)) {
                            $selected = "selected";
                        }
                        echo "<option value='" . $gradevalue->Value . "' " . $selected . ">" . $gradevalue->Value . "</option>";
                    }
                    echo '</select>';
                } else {
                    echo "<input type='text' name='values[]' id='values[]' value='" . GradeEx::GetGradesForStudentInClassRoom($student->StudentId, $id) . "' />";
                }
                echo "</td>";
                echo "</tr>";
                $i++;
            }
            ?>
            <tr>
                <td colspan="2">
                    <input type="submit" name="button" id="button" value="ثبت نمرات" />
                </td>
            </tr>
        </table>
    </form> 















    <?php
}
include_once 'Template/footer.php';
?>

