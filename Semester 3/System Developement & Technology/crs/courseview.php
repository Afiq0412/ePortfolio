<?php
session_start();
include 'headerstudent.php';
include 'db_connect.php';
// Get user ID
$uic = $_SESSION['funame'];

// Retrieve all registered course
$sql = "SELECT * FROM tb_registration
        LEFT JOIN tb_course ON tb_registration.r_course = tb_course.c_code
        LEFT JOIN tb_status ON tb_registration.r_status = tb_status.s_id
        WHERE r_student = '$uic'
        ORDER BY r_sem";

$result = mysqli_query($con, $sql);

if (!$result) {
  die("Query failed: " . mysqli_error($con));
}

// Array of semesters
$semesters = array('2023/2024-1', '2023/2024-2', '2024/2025-1', '2024/2025-2');

// Loop through each semester
foreach ($semesters as $semester) {
  echo "<div class='container'><br>";
  echo "<h4>Semester: $semester</h4>";
  echo "<table class='table table-striped table-hover'>";
  echo "<thead>
            <tr>
                <th scope='col'>Transaction ID</th>
                <th scope='col'>Course</th>
                <th scope='col'>Course Name</th>
                <th scope='col'>Status</th>
                <th scope='col'>Modify</th>
            </tr>
          </thead>";
  echo "<tbody>";

  // Reset the pointer to the beginning of the result set
  mysqli_data_seek($result, 0);

  // Loop through the results
  while ($row = mysqli_fetch_array($result)) {
    if ($row['r_sem'] == $semester) {
      echo "<tr>";
      echo "<td>" . $row['r_tid'] . "</td>";
      echo "<td>" . $row['r_course'] . "</td>";
      echo "<td>" . $row['c_name'] . "</td>";
      echo "<td>" . $row['s_desc'] . "</td>";
      if ($row['r_status'] == 1) {
        echo "<td><a href='modifycourse.php?course_id=" . $row['r_course'] . "' class='btn btn-success'>Modify</a></td>";
      } else {
        echo "<td><button class='btn btn-secondary' disabled>Modify</button></td>";
      }
      echo "</tr>";
    }
  }

  echo "</tbody></table></div><br><br><br>";
}
?>
</tbody>
</table>
<style>
    h4 {
        background-color: #f8f9fa;
        color: #007bff;
        padding: 10px 15px;
        margin-top: 30px;
        margin-bottom: 20px;
        border-left: 5px solid #007bff;
        font-weight: bold;
        font-size: 1.2em;
        box-shadow: 0 2px 5px rgba(0,0,0,0.1);
        border-radius: 0 5px 5px 0;
    }
</style>
</body>
<?php include 'footer.php'; ?>
</body>