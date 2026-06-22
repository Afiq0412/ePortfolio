<?php
include('crs_session.php');
if (!session_id()) {
    session_start();
}
include 'headerlec.php';
include 'db_connect.php';

// Get user ID
$uic = $_SESSION['funame'];

// Retrieve all registered courses
$sql = "SELECT * FROM tb_course
        LEFT JOIN tb_user ON tb_course.c_lec = tb_user.u_sno
        WHERE u_utype = 1";

$result = mysqli_query($con, $sql);

if (!$result) {
    die("Query failed: " . mysqli_error($con));
}

// Array of semesters
$semesters = array('2023/2024-1', '2023/2024-2', '2024/2025-1', '2024/2025-2');

// Store course data by semester
$course_data = [];
while ($row = mysqli_fetch_array($result)) {
    $course_data[$row['c_sem']][] = $row;
}

// Loop through each semester
foreach ($semesters as $semester) {
    echo "<div class='container mt-4'>";
    echo "<h4 class='semester-header'>Semester: $semester</h4>";
    echo "<div class='table-responsive'>";
    echo "<table class='table table-striped table-hover table-bordered text-center'>";
    echo "<thead class='thead-dark'>
            <tr>
                <th scope='col'>Course</th>
                <th scope='col'>Course Name</th>
                <th scope='col'>Credit Hour</th>
                <th scope='col'>Lecturer</th>
                <th scope='col'>Details</th>
            </tr>
          </thead>";
    echo "<tbody>";

    if (!empty($course_data[$semester])) {
        foreach ($course_data[$semester] as $row) {
            echo "<tr>";
            echo "<td>" . htmlspecialchars($row['c_code']) . "</td>";
            echo "<td>" . htmlspecialchars($row['c_name']) . "</td>";
            echo "<td>" . htmlspecialchars($row['c_credit']) . "</td>";
            echo "<td>" . htmlspecialchars($row['u_name']) . "</td>";
            echo "<td><a href='coursedetail.php?course_id=" . htmlspecialchars($row['c_code']) . "' class='btn btn-success'>Detail</a></td>";
            echo "</tr>";
        }
    } else {
        echo "<tr><td colspan='5' class='text-muted'>No courses available for this semester.</td></tr>";
    }

    echo "</tbody></table></div></div><br><br>";
}
?>

<style>
    .semester-header {
        background-color: #f8f9fa;
        color: rgb(49, 53, 57);
        padding: 10px 15px;
        margin-top: 30px;
        margin-bottom: 20px;
        border-left: 5px solid #007bff;
        font-weight: bold;
        font-size: 1.2em;
        box-shadow: 0 2px 5px rgba(0, 0, 0, 0.1);
        border-radius: 0 5px 5px 0;
    }

    .table {
        box-shadow: 0 2px 5px rgba(0, 0, 0, 0.1);
    }

    .table thead {
        background-color: #343a40;
        color: white;
    }

    .table-bordered {
        border: 1px solid #dee2e6;
    }

    .btn-sm {
        font-size: 0.875rem;
        padding: 0.25rem 0.5rem;
    }

    .table td,
    .table th {
        vertical-align: middle;
    }
</style>

<?php include 'footer.php'; ?>