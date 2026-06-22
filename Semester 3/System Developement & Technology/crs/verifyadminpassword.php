<?php
session_start();
include 'db_connect.php';

$response = ['success' => false, 'message' => ''];

if ($_SERVER['REQUEST_METHOD'] === 'POST' && isset($_POST['password']) && isset($_POST['course_id'])) {
    $password = $_POST['password'];
    $course_id = $_POST['course_id'];
    $admin_id = $_SESSION['funame'];

    // First, verify if the user is an admin and get their hashed password
    $admin_check_sql = "SELECT u_utype, u_pwd FROM tb_user WHERE u_sno = ?";
    $admin_check_stmt = $con->prepare($admin_check_sql);
    $admin_check_stmt->bind_param("s", $admin_id);
    $admin_check_stmt->execute();
    $admin_result = $admin_check_stmt->get_result();

    if ($admin_result->num_rows > 0) {
        $user_data = $admin_result->fetch_assoc();
        if ($user_data['u_utype'] === 3) { // Assuming 3 is the admin user type
            // Verify the password
            if (password_verify($password, $user_data['u_pwd'])) {
                // Password is correct, now check if the course exists
                $course_check_sql = "SELECT * FROM tb_course WHERE c_code = ?";
                $course_check_stmt = $con->prepare($course_check_sql);
                $course_check_stmt->bind_param("s", $course_id);
                $course_check_stmt->execute();
                $course_result = $course_check_stmt->get_result();

                if ($course_result->num_rows > 0) {
                    $response['success'] = true;
                    $response['message'] = 'Verification successful';
                } else {
                    $response['message'] = 'Course not found';
                }

                $course_check_stmt->close();
            } else {
                $response['message'] = 'Incorrect password';
            }
        } else {
            $response['message'] = 'User is not an admin';
        }
    } else {
        $response['message'] = 'User not found';
    }

    $admin_check_stmt->close();
} else {
    $response['message'] = 'Invalid request';
}

echo json_encode($response);
