<?php
include 'headeradmin.php';
include 'db_connect.php';

$uid = $_SESSION['funame'];

$sql = "SELECT tb_course.*, tb_user.u_name 
        FROM tb_course
        LEFT JOIN tb_user ON tb_course.c_lec = tb_user.u_sno";

$result = mysqli_query($con, $sql);
if (!$result) {
    die("Query failed: " . mysqli_error($con));
}
?>

<div class="container py-5">
    <div class="row mb-4">
        <div class="col-12">
            <h2 class="text-primary">Course Details</h2>
        </div>
    </div>

    <div class="table-responsive">
        <table class="table table-striped table-hover table-bordered">
            <thead class="table-light">
                <tr>
                    <th scope="col">Course Code</th>
                    <th scope="col">Course Name</th>
                    <th scope="col">Semester</th>
                    <th scope="col">Credit Hours</th>
                    <th scope="col">Maximum Student</th>
                    <th scope="col">Lecturer</th>
                    <th scope="col">Operation</th>
                </tr>
            </thead>
            <tbody>
                <?php
                while ($row = mysqli_fetch_assoc($result)) {
                    echo "<tr>";
                    echo "<td>" . htmlspecialchars($row['c_code']) . "</td>";
                    echo "<td>" . htmlspecialchars($row['c_name']) . "</td>";
                    echo "<td>" . htmlspecialchars($row['c_sem']) . "</td>";
                    echo "<td>" . htmlspecialchars($row['c_credit']) . "</td>";
                    echo "<td>" . htmlspecialchars($row['c_maxstudent']) . "</td>";
                    echo "<td>" . htmlspecialchars($row['c_lec']) . " - " . htmlspecialchars($row['u_name']) . "</td>";
                    echo "<td>";
                    echo "<a href='deletecourseprocess.php?course_id=" . urlencode($row['c_code']) . "' class='btn btn-outline-danger btn-sm' onclick='return confirmDelete()'><i class='fas fa-trash'></i> Delete</a>";
                    echo "</td>";
                    echo "</tr>";
                }
                ?>
            </tbody>
        </table>
    </div>
</div>

<script>
    function confirmDelete() {
        return confirm("Are you sure you want to delete this course?");
    }
</script>
</body>

</html>

<?php include 'footer.php'; ?>