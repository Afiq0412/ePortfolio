<?php
include 'headeradmin.php';
include 'db_connect.php';

// Fetch lecturers for the dropdown
$sql = "SELECT u_sno, u_name FROM tb_user WHERE u_utype = 1";
$result = mysqli_query($con, $sql);

?>

<div class="container mt-5">
    <div class="row justify-content-center">
        <div class="col-md-8">
            <div class="card shadow">
                <div class="card-header bg-primary text-white">
                    <h3 class="mb-0">Add / Modify Course</h3>
                </div>
                <div class="card-body">
                    <form method="POST" action="addcourseprocess.php" id="courseForm">
                        <div class="row mb-3">
                            <div class="col-md-6">
                                <label for="c_code" class="form-label">Course Code</label>
                                <input type="text" class="form-control" id="c_code" name="c_code" required>
                            </div>
                            <div class="col-md-6">
                                <label for="c_sem" class="form-label">Semester</label>
                                <select class="form-select" id="c_sem" name="c_sem" required>
                                    <option value="">Select Semester</option>
                                    <option value="2023/2024-1">2023/2024-1</option>
                                    <option value="2023/2024-2">2023/2024-2</option>
                                    <option value="2024/2025-1">2024/2025-1</option>
                                    <option value="2024/2025-2">2024/2025-2</option>
                                </select>
                            </div>
                        </div>
                        <div class="mb-3">
                            <label for="c_name" class="form-label">Course Name</label>
                            <input type="text" class="form-control" id="c_name" name="c_name" required>
                        </div>
                        <div class="row mb-3">
                            <div class="col-md-6">
                                <label for="c_credit" class="form-label">Credit Hours</label>
                                <input type="number" class="form-control" id="c_credit" name="c_credit" required>
                            </div>
                            <div class="col-md-6">
                                <label for="c_maxstudent" class="form-label">Max Students</label>
                                <input type="number" class="form-control" id="c_maxstudent" name="c_maxstudent" required>
                            </div>
                        </div>
                        <div class="mb-3">
                            <label for="c_lec" class="form-label">Lecturer</label>
                            <select class="form-select" id="c_lec" name="c_lec" required>
                                <option value="">Select Lecturer</option>
                                <?php
                                while ($row = mysqli_fetch_assoc($result)) {
                                    echo "<option value='" . $row['u_sno'] . "'>" . $row['u_sno'] . " - " . $row['u_name'] . "</option>";
                                }
                                ?>
                            </select>
                        </div>
                        <div class="d-grid">
                            <button type="submit" class="btn btn-primary">Submit</button>
                        </div>
                        <div class="container py-5">
                            <?php
                            if (isset($_SESSION['message'])) {
                                $alertClass = ($_SESSION['message_type'] == 'success') ? 'alert-success' : 'alert-danger';
                                echo "<div class='alert {$alertClass} alert-dismissible fade show' role='alert'>";
                                echo $_SESSION['message'];
                                echo "<button type='button' class='btn-close' data-bs-dismiss='alert' aria-label='Close'></button>";
                                echo "</div>";

                                unset($_SESSION['message']);
                                unset($_SESSION['message_type']);
                            }
                            ?>
                        </div>
                    </form>
                </div>
            </div>
        </div>
    </div>
</div>

<script>
    document.getElementById('courseForm').addEventListener('submit', function(event) {
        event.preventDefault();
        // Perform client-side validation here
        if (validateForm()) {
            this.submit();
        }
    });

    function validateForm() {
        // Add your validation logic here
        return true; // Return false if validation fails
    }
</script>

<?php include 'footer.php'; ?>