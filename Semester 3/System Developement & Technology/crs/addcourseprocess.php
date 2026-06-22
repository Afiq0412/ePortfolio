<?php
include 'db_connect.php';
session_start();

if ($_SERVER["REQUEST_METHOD"] == "POST") {
    $c_code = $_POST['c_code'];
    $c_sem = $_POST['c_sem'];
    $c_name = $_POST['c_name'];
    $c_credit = $_POST['c_credit'];
    $c_maxstudent = $_POST['c_maxstudent'];
    $c_lec = $_POST['c_lec'];

    $check_query = "SELECT * FROM tb_course WHERE c_code = '$c_code'";
    $check_result = mysqli_query($con, $check_query);

    if (mysqli_num_rows($check_result) > 0) {
        $update_query = "UPDATE tb_course SET 
                         c_sem = '$c_sem', 
                         c_name = '$c_name', 
                         c_credit = '$c_credit', 
                         c_maxstudent = '$c_maxstudent', 
                         c_lec = '$c_lec' 
                         WHERE c_code = '$c_code'";
        
        if (mysqli_query($con, $update_query)) {
            $_SESSION['message'] = "Course updated successfully.";
            $_SESSION['message_type'] = "success";
        } else {
            $_SESSION['message'] = "Error updating course: " . mysqli_error($con);
            $_SESSION['message_type'] = "danger";
        }
    } else {
        $insert_query = "INSERT INTO tb_course (c_code, c_sem, c_name, c_credit, c_maxstudent, c_lec) 
                         VALUES ('$c_code', '$c_sem', '$c_name', '$c_credit', '$c_maxstudent', '$c_lec')";
        
        if (mysqli_query($con, $insert_query)) {
            $_SESSION['message'] = "Course added successfully.";
            $_SESSION['message_type'] = "success";
        } else {
            $_SESSION['message'] = "Error adding course: " . mysqli_error($con);
            $_SESSION['message_type'] = "danger";
        }
    }

    // Redirect back to addcourse.php
    header("Location: addcourse.php");
    exit();
} else {
    // If accessed directly without POST data, redirect to addcourse.php
    header("Location: addcourse.php");
    exit();
}
?>
