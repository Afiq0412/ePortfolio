<?php
include 'headerstudent.php';
include 'db_connect.php';

if (isset($_GET['student_id']) && isset($_GET['course_id'])) {
    $student_id = $_GET['student_id'];
    $course_id = $_GET['course_id'];
}

if ($student_id > 0) {
    $sql = "SELECT * FROM tb_user WHERE u_sno = '$student_id'";

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
                    <h3 class="card-title mb-0">Student Information</h3>
                </div>
                <div class="card-body">
                    <div class="row">
                        <div class="col-md-6">
                            <ul class="list-group list-group-flush">
                                <li class="list-group-item"><strong>Student Number:</strong> <?php echo $row['u_sno']; ?></li>
                                <li class="list-group-item"><strong>Name:</strong> <?php echo $row['u_name']; ?></li>
                                <li class="list-group-item"><strong>Email Address:</strong> <?php echo $row['u_email']; ?></li>
                                <li class="list-group-item"><strong>State Address:</strong> <?php echo $row['u_state']; ?></li>
                                <li class="list-group-item"><strong>Registration Time:</strong> <?php echo $row['u_reg']; ?></li>
                            </ul>
                        </div>
                    </div><br><br><br>
                    <a href='coursedetail.php?course_id=<?php echo $course_id?>' class='btn btn btn-secondary mb-4'><i class="fas fa-arrow-left mr-2"></i> Back</a>
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