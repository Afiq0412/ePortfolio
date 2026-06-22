<?php
include 'headeradmin.php';
include 'crs_session.php';
?>

<div class="container mt-5">
    <h2>Admin Dashboard</h2>
    <div class="row mt-4">
        <div class="col-md-4 mb-3">
            <div class="card">
                <div class="card-body">
                    <h5 class="card-title">Course Management</h5>
                    <p class="card-text">Manage students, lecturers, and admin accounts.</p>
                    <a href="courseapproval.php" class="btn btn-primary">Manage Users</a>
                </div>
            </div>
        </div>
        <div class="col-md-4 mb-3">
            <div class="card">
                <div class="card-body">
                    <h5 class="card-title">Course Management</h5>
                    <p class="card-text">Add or edit courses.</p>
                    <a href="addcourse.php" class="btn btn-primary">Manage Courses</a>
                </div>
            </div>
        </div>
        <div class="col-md-4 mb-3">
            <div class="card">
                <div class="card-body">
                    <h5 class="card-title">Delete Course</h5>
                    <p class="card-text">Delete course registrations.</p>
                    <a href="deletecourse.php" class="btn btn-primary">Manage Courses</a>
                </div>
            </div>
        </div>
    </div>
</div>

<?php include 'footer.php'; ?>
