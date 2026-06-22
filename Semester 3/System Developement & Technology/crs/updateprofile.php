<?php
include('crs_session.php');
if (!session_id()) {
    session_start();
}
include 'db_connect.php';

if ($_SERVER["REQUEST_METHOD"] == "POST") {
    $u_sno = $_SESSION['funame'];
    $u_email = $_POST['u_email'];
    $u_contact = $_POST['u_contact'];
    $u_state = $_POST['u_state'];

    $query = "UPDATE tb_user SET u_email = ?, u_contact = ?, u_state = ? WHERE u_sno = ?";
    $stmt = $con->prepare($query);
    
    if ($stmt) {
        $stmt->bind_param("ssss", $u_email, $u_contact, $u_state, $u_sno);
        
        if ($stmt->execute()) {
            $_SESSION['message'] = "Profile updated successfully";
        } else {
            $_SESSION['message'] = "Error updating profile: " . $stmt->error;
        }
        
        $stmt->close();
    } else {
        $_SESSION['message'] = "Error preparing statement: " . $con->error;
    }

    // Redirect back to the profile page
    header("Location: profilestudent.php");
    exit();
}
