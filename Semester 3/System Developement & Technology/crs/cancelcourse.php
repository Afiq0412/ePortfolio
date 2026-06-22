<?php
include 'db_connect.php';

if ($_SERVER['REQUEST_METHOD'] == 'POST') {
    $course_id = mysqli_real_escape_string($con, $_POST['course_id']);
    $uid = mysqli_real_escape_string($con, $_POST['user_id']);

    $sql = "DELETE FROM tb_registration 
            WHERE r_student = ? AND r_course = ? AND r_status = 1";
    
    $stmt = mysqli_prepare($con, $sql);
    mysqli_stmt_bind_param($stmt, "is", $uid, $course_id);
    
    if (mysqli_stmt_execute($stmt)) {
        $affected_rows = mysqli_stmt_affected_rows($stmt);
        if ($affected_rows > 0) {
            $_SESSION['message'] = "Course successfully cancelled.";
            header("Location: courseview.php");
        } else {
            $_SESSION['message'] = "No registration found to cancel.";
            header("Location: modifycourse.php");
        }
    } else {
        $_SESSION['message'] = "Error cancelling course: " . mysqli_error($con);
        header("Location: modifycourse.php");
    }
    
    mysqli_stmt_close($stmt);
    exit();
}
?>
