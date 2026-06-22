<?php
// Set DB parameter
$servername = "localhost";
$username = "root";
$password = "";
$dbname = "db_crs";


// Connect DB
$con = mysqli_connect($servername, $username, $password, $dbname);

// Connection Check (continue as individual project)

if(!$con)
{
	die("Connection failed: " . mysqli_connect_error());
}

?>

