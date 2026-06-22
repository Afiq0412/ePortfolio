<?php
include 'headerstudent.php';
include 'db_connect.php';

if (isset($_GET['course_id'])) {
    $course_id = $_GET['course_id'];
}

if ($course_id > 0) {
    $sql = "SELECT * FROM tb_course
        LEFT JOIN tb_user ON tb_course.c_lec = tb_user.u_sno
        LEFT JOIN tb_registration ON tb_registration.r_course = tb_course.c_code
        WHERE c_code = '$course_id'";

    $result = mysqli_query($con, $sql);
    if (!$result) {
        die("Query failed: " . mysqli_error($con));
    }
    $row = mysqli_fetch_assoc($result);
?>

    <div class="content">
        <div class="container py-5">
            <div class="row mb-4">
                <div class="col-12">
                    <h2 class="text-primary">Course Details</h2>
                </div>
            </div>

            <div class="card shadow">
                <div class="card-header bg-primary text-white">
                    <h3 class="card-title mb-0">Course Information</h3>
                </div>
                <div class="card-body">
                    <div class="row">
                        <div class="col-md-6">
                            <ul class="list-group list-group-flush">
                                <li class="list-group-item"><strong>Course Code:</strong> <?php echo $row['c_code']; ?></li>
                                <li class="list-group-item"><strong>Course Name:</strong> <?php echo $row['c_name']; ?></li>
                                <li class="list-group-item"><strong>Course Credit (Hour):</strong> <?php echo $row['c_credit']; ?></li>
                                <li class="list-group-item"><strong>Semester:</strong> <?php echo $row['c_sem']; ?></li>
                                <li class="list-group-item"><strong>Lecturer In Charge:</strong> <?php echo $row['u_name']; ?></li>
                            </ul>
                        </div>
                        <div class="col-md-6">
                            <h4>Enrolled Students</h4>
                            <?php
                            $student = "SELECT tb_user.u_sno, tb_user.u_name 
                                FROM tb_registration 
                                JOIN tb_user ON tb_registration.r_student = tb_user.u_sno 
                                WHERE tb_registration.r_course = '$course_id'";
                            $result = mysqli_query($con, $student);
                            if (mysqli_num_rows($result) > 0) {
                                echo "<ul class='list-group'>";
                                while ($student = mysqli_fetch_assoc($result)) {
                                    echo "<li class='list-group-item d-flex justify-content-between align-items-center'>";
                                    echo "{$student['u_sno']} - {$student['u_name']}";
                                    echo "<a href='studentdetail.php?course_id={$course_id}&student_id={$student['u_sno']}' class='btn btn-sm btn-primary'>Details</a>";
                                    echo "</li>";
                                }
                                echo "</ul>";
                            } else {
                                echo "<p>No students enrolled in this course yet.</p>";
                            }
                            ?>
                        </div>
                    </div><br><br><br>
                    <a href='viewassigncourse.php' class='btn btn btn-secondary mb-4'><i class="fas fa-arrow-left mr-2"></i> Back to Assign Course List</a>
                </div>
            </div>


        <?php
    } else {
        echo "<div class='container py-5'><div class='alert alert-danger' role='alert'><i class='fas fa-exclamation-triangle mr-2'></i>Invalid Course Code.</div></div>";
    }
        ?>
        <script>
            function confirmCancel() {
                return confirm("Are you sure you want to cancel this course? This action cannot be undone.");
            }
        </script>
        </body>

        </html>

        <?php include 'footer.php'; ?>