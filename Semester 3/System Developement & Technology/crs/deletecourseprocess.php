<?php
include 'headeradmin.php';
include 'db_connect.php';

if(isset($_GET['course_id'])){
    $course_id = $_GET['course_id'];

    $sql = "DELETE FROM tb_course WHERE c_code = '$course_id'";
    $result = mysqli_query($con, $sql);

    if($result){
        echo "<script>alert('Course deleted successfully.')
        window.location.replace('deletecourse.php')
        </script>";
    } else {
        echo "<script>alert('Failed to delete course.')
        window.location.replace('deletecourse.php')
        </script>";
    }
}
?>