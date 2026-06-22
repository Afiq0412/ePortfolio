<?php
include ('crs_session.php');
if(!session_id())
{
  session_start();
}
include 'db_connect.php';

if ($_SERVER['REQUEST_METHOD'] === 'POST') {
    $tid = $_POST['tid'];
    $action = $_POST['action'];

    if ($action === 'approve') {
        $status = 2;
    } elseif ($action === 'reject') {
        $status = 3;
    } else {
        // Invalid action
        header('Location:  courseapproval.php?id=' . $tid);
        exit();
    }

    $sql = "UPDATE tb_registration SET r_status = $status WHERE r_tid = '$tid'";
    $result = mysqli_query($con, $sql);

    if ($result) {
        echo "<script>alert('Approved successfully.')
        window.location.replace(' courseapproval.php?id=' . $tid')
        </script>";
    } else {
        // Error
        echo "Error updating record: " . mysqli_error($con);
    }
} else {
    // Invalid request method
    header('Location: index.php');
}
?>
