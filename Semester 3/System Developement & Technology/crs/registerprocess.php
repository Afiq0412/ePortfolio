<?php
// Connect to DB
include('db_connect.php');

// Retrieve data from form
$funame = $_POST['funame'];
$fpwd = $_POST['fpwd'];
$femail = $_POST['femail'];
$fname = $_POST['fname'];
$fcontact = $_POST['fcontact'];
$fstate = $_POST['fstate'];

// Hash the password
$hashed_password = password_hash($fpwd, PASSWORD_DEFAULT);

// Prepare SQL statement
$sql = "INSERT INTO tb_user (u_sno, u_pwd, u_email, u_name, u_contact, u_state, u_reg, u_utype) 
        VALUES (?, ?, ?, ?, ?, ?, CURRENT_TIMESTAMP(), '2')";

// Prepare and bind
$stmt = $con->prepare($sql);
$stmt->bind_param("ssssss", $funame, $hashed_password, $femail, $fname, $fcontact, $fstate);

// Execute the statement
$reg = $stmt->execute();

// Close statement and connection
$stmt->close();
mysqli_close($con);

// Confirmation registration successful or fail (task for project)
if($reg)
{
    echo '<script>alert("Register Successfully")
    window.location.replace("login.php")
    </script>';
}
else
{
    echo '<script>alert("Register Unsuccessfully. Please Try Again!")
    window.location.replace("register.php")
    </script>';
}
?>
