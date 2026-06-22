<?php
include 'crs_session.php';
if (!session_id()) {
    session_start();
}
include 'headerlec.php';
include "db_connect.php";

$uid = $_SESSION['funame'];

if (!isset($_SESSION['funame'])) {
    header("Location: login.php");
    exit();
}

$sql = "SELECT * FROM tb_user WHERE u_sno = '$uid'";
$result = mysqli_query($con, $sql);
$row = mysqli_fetch_assoc($result);
$fname = $row['u_name'];
?>

<div class="container mt-5">
    <h2>Welcome, <?php echo $fname; ?></h2>
    <div class="row mt-4">
        <div class="col-md-4">
            <div class="card">
                <div class="card-body">
                    <h5 class="card-title">View The Assigned Courses</h5>
                    <p class="card-text">View student enrolled courses and course materials.</p>
                    <a href="viewassigncourse.php" class="btn btn-primary">Go to Courses</a>
                </div>
            </div>
        </div>
    </div>
</div>
<?php include 'footer.php'; ?>
