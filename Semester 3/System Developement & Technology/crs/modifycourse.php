<?php
include 'headerstudent.php';
include 'db_connect.php';

if (isset($_GET['course_id'])) {
    $course_id = $_GET['course_id'];
}

if ($course_id > 0) {
    $sql = "SELECT * FROM tb_course
        LEFT JOIN tb_user ON tb_course.c_lec = tb_user.u_sno
        WHERE c_code = '$course_id'";

    $result = mysqli_query($con, $sql);
    if (!$result) {
        die("Query failed: " . mysqli_error($con));
    }
    $row = mysqli_fetch_array($result);
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
                                <li class="list-group-item"><strong>Lecturer In Charge:</strong> <?php echo $row['u_name']; ?></li>
                            </ul>
                        </div>
                        <div class="col-md-6">
                            <div class="card h-100">
                                <div class="card-body d-flex flex-column justify-content-center align-items-center">
                                    <h4 class="text-center mb-4">Course Actions</h4>
                                    <form action='cancelcourse.php' method='POST' onsubmit="return confirmCancel()">
                                        <input type='hidden' name='course_id' value='<?php echo $row['c_code']; ?>'>
                                        <input type='hidden' name='user_id' value='<?php echo $uid; ?>'>
                                        <button type='submit' class='btn btn-danger btn-lg'>
                                            Cancel Course <i class="fas fa-trash-alt mr-4"></i>
                                        </button>
                                    </form>
                                </div>
                            </div>
                        </div>
                    </div><br><br><br>
                    <a href='courseview.php' class='btn btn btn-secondary mb-4'><i class="fas fa-arrow-left mr-2"></i> Back to Course List</a>
                </div>
            </div>
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