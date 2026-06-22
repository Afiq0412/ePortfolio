<?php
session_start();
include('db_connect.php');

$funame = $_POST['funame'];
$fpwd = $_POST['fpwd'];

$sql = "SELECT * FROM tb_user WHERE u_sno = ?";
$stmt = $con->prepare($sql);
$stmt->bind_param("s", $funame);
$stmt->execute();
$result = $stmt->get_result();

if ($result->num_rows == 1) {
    $row = $result->fetch_assoc();
    
    if (password_verify($fpwd, $row['u_pwd'])) {
        // Password is correct
        $_SESSION['u_sno'] = session_id();
        $_SESSION['funame'] = $funame;

        if ($row['u_utype'] == 1) {
            echo '<script>window.location.replace("lecturer.php")</script>';
        } elseif ($row['u_utype'] == 2) {
            echo '<script>window.location.replace("student.php")</script>';
        } elseif ($row['u_utype'] == 3) {
            echo '<script>window.location.replace("Admin.php")</script>';
        }
    } else {
        // Password is incorrect
        echo '<script>
        alert("Login Failed. Please Try Again")
        window.location.replace("login.php")
        </script>';
    }
} else {
    // User not found
    echo '<script>
    alert("Login Failed. Please Try Again")
    window.location.replace("login.php")
    </script>';
}

mysqli_close($con);
?>
