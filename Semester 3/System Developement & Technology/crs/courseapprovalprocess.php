<?php
include('crs_session.php');
if (!session_id()) {
  session_start();
}
include 'headeradmin.php';
include 'db_connect.php';
if (isset($_GET['id'])) {
  $tid = $_GET['id'];
}

// Retrieve all registered course
$sql = "SELECT * FROM tb_registration
        LEFT JOIN tb_course ON tb_registration.r_course = tb_course.c_code
        LEFT JOIN tb_status ON tb_registration.r_status = tb_status.s_id
        LEFT JOIN tb_user ON tb_registration.r_student = tb_user.u_sno
        WHERE r_tid = '$tid'";

$result = mysqli_query($con, $sql);
$row = mysqli_fetch_array($result);

?>

<div class="container mt-5">
  <div class="card shadow">
    <div class="card-header bg-primary text-white">
      <h4 class="mb-0">Course Approval Process</h4>
    </div>
    <div class="card-body">
      <div class="row">
        <div class="col-md-6">
          <h5 class="card-title">Student Information</h5>
          <ul class="list-group list-group-flush">
            <li class="list-group-item"><strong>Transaction ID:</strong> <?php echo $row['r_tid']; ?></li>
            <li class="list-group-item"><strong>Semester:</strong> <?php echo $row['r_sem']; ?></li>
            <li class="list-group-item"><strong>Student ID:</strong> <?php echo $row['u_sno']; ?></li>
            <li class="list-group-item"><strong>Student Name:</strong> <?php echo $row['u_name']; ?></li>
          </ul>
        </div>
        <div class="col-md-6">
          <h5 class="card-title">Course Information</h5>
          <ul class="list-group list-group-flush">
            <li class="list-group-item"><strong>Course Code:</strong> <?php echo $row['r_course']; ?></li>
            <li class="list-group-item"><strong>Course Name:</strong> <?php echo $row['c_name']; ?></li>
            <li class="list-group-item"><strong>Current Status:</strong> <span class="badge badge-info"><?php echo $row['s_desc']; ?></span></li>
          </ul>
        </div>
      </div>
      <div class="row mt-4">
        <div class="col-12">
          <h5 class="card-title">Approval Action</h5>
          <form method="POST" action="approvalupdate.php">
            <input type="hidden" name="tid" value="<?php echo $row['r_tid']; ?>">
            <div class="btn-group" role="group">
              <button type="submit" name="action" value="approve" class="btn btn-success">
                <i class="fas fa-check-circle"></i> Approve
              </button>
              <button type="submit" name="action" value="reject" class="btn btn-danger">
                <i class="fas fa-times-circle"></i> Reject
              </button>
            </div>
          </form>
        </div>
      </div>
    </div>
    <div class="card-footer">
      <a href="courseapproval.php" class="btn btn-secondary">
        <i class="fas fa-arrow-left"></i> Back to Course Approval List
      </a>
    </div>
  </div>
</div>

<?php include 'footer.php'; ?>
