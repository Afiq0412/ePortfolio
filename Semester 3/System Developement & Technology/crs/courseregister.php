<?php
include('crs_session.php');
if (!session_id()) {
  session_start();
}
include 'headerstudent.php';
include "db_connect.php";
?>
<div class="container mt-5">
  <h4>Course Registration Form</h4>
  <div class="mb-4">
    <h5>Available Courses</h5>
    <table id="courseTable" class="table table-striped table-bordered">
      <thead>
        <tr>
          <th>Course Code</th>
          <th>Course Name</th>
          <th>Credit Hours</th>
          <th>Number of Student</th>
          <th>Lecturer</th>
          <th>Action</th>
        </tr>
      </thead>
      <tbody>
        <?php
          $sql = "SELECT c.*, u.u_name, 
          (SELECT COUNT(*) FROM tb_registration WHERE r_course = c.c_code) AS enrolled_students
          FROM tb_course c
          LEFT JOIN tb_user u ON c.c_lec = u.u_sno";
        $result = mysqli_query($con, $sql);
        while ($row = mysqli_fetch_assoc($result)) {
          echo "<tr>";
          echo "<td>" . $row['c_code'] . "</td>";
          echo "<td>" . $row['c_name'] . "</td>";
          echo "<td>" . $row['c_credit'] . "</td>";
          echo "<td>" . $row['enrolled_students'] . "/" . $row['c_maxstudent'] . "</td>";
          echo "<td>" . $row['u_name'] . "</td>";
          echo "<td><button class='btn btn-primary btn-sm select-course' data-code='" . $row['c_code'] . "' data-name='" . $row['c_name'] . "'>Select</button></td>";
          echo "</tr>";
        }
        ?>
      </tbody>
    </table>
  </div>
  <form method="POST" action="registercourseprocess.php">
    <div class="mb-3">
      <label for="selectedCourse" class="form-label">Selected Course</label>
      <input type="text" class="form-control" id="selectedCourseName" readonly>
      <input type="hidden" id="selectedCourseCode" name="fcourse" required>
    </div>
    <button type="submit" class="btn btn-primary">Register Course</button>
  </form><br><br><br>
</div>

<link rel="stylesheet" type="text/css" href="https://cdn.datatables.net/1.11.5/css/dataTables.bootstrap5.min.css">
<script type="text/javascript" src="https://code.jquery.com/jquery-3.6.0.min.js"></script>
<script type="text/javascript" src="https://cdn.datatables.net/1.11.5/js/jquery.dataTables.min.js"></script>
<script type="text/javascript" src="https://cdn.datatables.net/1.11.5/js/dataTables.bootstrap5.min.js"></script>

<script>
  $(document).ready(function() {
    $('#courseTable').DataTable();

    $('.select-course').click(function() {
      var courseCode = $(this).data('code');
      var courseName = $(this).data('name');
      $('#selectedCourseName').val(courseCode + ' - ' + courseName);
      $('#selectedCourseCode').val(courseCode);
    });
  });
</script>

<?php include 'footer.php'; ?>