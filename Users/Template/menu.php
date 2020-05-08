</head>
<body>
    <div class="Main">
        <div class="Banner">
            <a href="../index.php" ><img src="../Images/01.png" width="449" height="140" alt="" /> </a>
            <input type="text" id="txtSearch" value="جستجو . . . " />
        </div>
        <div class="Menu">
            <ul class="Nav">
                <li><a href="Index.php">صفحه اصلی</a></li>
                <!--                    <li><a href="#">اخبار و اطلاعیه ها</a>
                                        <ul>
                                            <li><a href="#">رویدادها</a></li>
                                        </ul>
                                        <div class="clear">
                                        </div>
                                    </li>-->
                <li><a href="#">ثبت اطلاعات </a>
                    <ul>
                        <?php
                        if ($_SESSION['UserType'] == "Admin" || $_SESSION['UserType'] == "Student") {
                            ?>
                            <li><a href="Teachers.php">مدرسان </a></li>
                            <?php
                        }
                        if ($_SESSION['UserType'] == "Admin" || $_SESSION['UserType'] == "Teacher") {
                            ?>
                            <li><a href="Students.php"> دانش آموزان </a></li>
                            <?php
                        }
                        ?>
                        <li><a href="ClassRooms.php"> کلاس ها </a></li>
                        <?php
                        if ($_SESSION['UserType'] == "Admin") {
                            ?>

                            <li><a href="Lectures.php"> دروس  </a></li>
                            <li><a href="Terms.php"> ترم ها</a></li>
                            <li><a href="GradeTypes.php">نوع نمره دهی</a></li>
                            <li><a href="GradeValues.php">مقادیر نمرات</a></li>
                            <?php
                        }
                        if ($_SESSION['UserType'] == "Student") {
                            ?>

                            <li><a href="ViewGrades.php">مشاهده نمرات</a></li>
                            <?php
                        }
                        ?>
                    </ul>
                    <div class="clear">
                    </div>
                </li>
                <?php
                if ($_SESSION['UserType'] == "Admin" || $_SESSION['UserType'] == "Teacher") {
                    ?>

                    <li><a href="#">سیستم آزمون </a>
                        <ul>

                            <li><a href="Questions.php">سوالات</a></li>

                            <li><a href="Exams.php">آزمون</a></li>
                        </ul>
                        <div class="clear">
                        </div>
                    </li>
                    <?php
                }
                ?>

                <?php
                if ($_SESSION['UserType'] == "Admin") {
                    ?>
                    <li><a href = "#">تنظیمات سایت</a>
                        <ul>
                            <li><a href = "Options.php">تنظیمات</a></li>
                            <li><a href = "Backup.php">پشتیبان گیری</a></li>
                            <li><a href = "Restore.php">باز گرداندن اطلاعات</a></li>
                        </ul>
                        <div class = "clear">
                        </div>
                    </li>
                    <?php
                }
                ?>

                <!--            <li><a href="#">درباره مدرسه</a>
                    <ul>
                        <li><a href="#">معرفی مدرسه</a></li>
                        <li><a href="#">افتخارات مدرسه</a></li>
                        <li><a href="#">گالری تصاویر</a></li>
                        <li><a href="#">بانیان و موسسین</a></li>
                         <li><a href="#">معرفی پرسنل</a></li>
                        <li><a href="#">معرفی مدرسین</a></li>
                        <li><a href="#">پایه های تحصیلی</a></li>
                        <li><a href="#">شهرستان لنگرود</a></li>
                    </ul>
                    <div class="clear">
                    </div>
                </li>-->
                <li><a href="LogOff.php">خروج</a></li>
            </ul>
        </div>
        <div class="Content">

            <?php /*
              if ($_SESSION['UserType'] == "Teacher") {
              ?>

              <table  border="1" cellpadding="5" cellspacing="5"  class="ViewTable">
              <tr>
              <td>
              <?php echo $name . " " . $family; ?>
              </td>
              </tr>
              </table>
              <?php
              } elseif ($_SESSION['UserType'] == "Student") {
              ?>
              <table  border="1" cellpadding="5" cellspacing="5"  class="ViewTable">
              <tr>
              <td>
              <?php echo $name . " " . $family; ?>
              </td>
              <td>
              <?php echo $codemelli; ?>
              </td>
              </tr>
              </table>
              <?php
              } */
            ?>




