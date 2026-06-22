<?php
include('crs_session.php');
if(!session_id())
{
  session_start();
}

include 'db_connect.php';
$uic = $_SESSION['funame'];
$fcourse = $_POST['fcourse'];

$sql_get_semester = "SELECT c_sem FROM tb_course WHERE c_code = '$fcourse'";
$result = mysqli_query($con, $sql_get_semester);
$row = mysqli_fetch_assoc($result);
$course_semester = $row['c_sem'];

$sql = "INSERT INTO tb_registration (r_student, r_course, r_sem, r_status)
        VALUES ('$uic', '$fcourse', '$course_semester', '1')";

//Execute SQL
$reg = mysqli_query($con, $sql);

// Close Connection
mysqli_close($con);

// Confirmation registration successful or fail (task for project)

if($reg)
{
	echo '<script>alert("Register Successfully")
	window.location.replace("courseview.php")
	</script>';
}
else
{
	echo '<script>alert("Register Unsuccessfully. Please Try Again!")
	window.location.replace("courseregister.php")
	</script>';
}

?>