<?php
include('crs_session.php');
if (!session_id()) {
    session_start();
}
include 'headerstudent.php';
include 'db_connect.php';

$u_sno = $_SESSION['funame'];

// Fetch student data from the database
$query = "SELECT * FROM tb_user WHERE u_sno = ?";
$stmt = $con->prepare($query);
$stmt->bind_param("s", $u_sno);
$stmt->execute();
$result = $stmt->get_result();
$student = $result->fetch_assoc();
?>

<div class="container mt-4">
    <div class="row justify-content-center">
        <div class="col-md-8">
            <div class="card shadow">
                <div class="card-header bg-primary text-white">
                    <h3 class="card-title mb-0">Student Profile</h3>
                </div>
                <div class="card-body">
                    <div class="text-center mb-4">
                        <h1 class="mt-2"><?php echo htmlspecialchars($student['u_name']); ?></h1>
                        <p class="text-muted">Student Number: <?php echo htmlspecialchars($student['u_sno']); ?></p>
                    </div>
                    <form action="updateprofile.php" method="POST">
                        <div class="mb-3">
                            <label for="u_email" class="form-label"><i class="fas fa-envelope me-2"></i>Email Address:</label>
                            <input type="email" class="form-control" id="u_email" name="u_email" value="<?php echo htmlspecialchars($student['u_email']); ?>" required>
                        </div>
                        <div class="mb-3">
                            <label for="u_pass" class="form-label"><i class="fas fa-lock me-2"></i>Password:</label>
                            <div class="input-group">
                                <input type="password" class="form-control" id="u_pass" name="u_pass" autocomplete="off" value="<?php echo htmlspecialchars($student['u_pwd']); ?>">
                                <button class="btn btn-outline-secondary" type="button" id="togglePassword">
                                    <i class="fas fa-eye"></i>
                                </button>
                            </div>
                        </div>
                        <div class="mb-3">
                            <label for="u_contact" class="form-label"><i class="fas fa-phone me-2"></i>Contact Number:</label>
                            <input type="text" class="form-control" id="u_contact" name="u_contact" value="<?php echo htmlspecialchars($student['u_contact']); ?>">
                        </div>
                        <div>
                            <div class="mb-3">
                                <label for="u_state" class="form-label"><i class="fas fa-map-marker-alt me-2"></i>State:</label>
                                <select class="form-select" id="u_state" name="u_state" required>
                                    <?php
                                    $states = [
                                        'Johor',
                                        'Kedah',
                                        'Kelantan',
                                        'Melaka',
                                        'Negeri Sembilan',
                                        'Pahang',
                                        'Pulau Pinang',
                                        'Perak',
                                        'Perlis',
                                        'Selangor',
                                        'Terengganu',
                                        'Sabah',
                                        'Sarawak',
                                        'WP Kuala Lumpur',
                                        'WP Labuan',
                                        'WP Putrajaya'
                                    ];
                                    foreach ($states as $state) {
                                        $selected = ($student['u_state'] == $state) ? 'selected' : '';
                                        echo "<option value=\"$state\" $selected>$state</option>";
                                    }
                                    ?>
                                </select>
                            </div>
                            <div class="mb-3">
                                <label for="u_reg" class="form-label"><i class="fas fa-calendar-alt me-2"></i>Registration Date:</label>
                                <input type="text" class="form-control" id="u_reg" name="u_reg" value="<?php echo htmlspecialchars($student['u_reg']); ?>" readonly>
                            </div>
                            <div class="text-center">
                                <button type="submit" class="btn btn-primary"><i class="fas fa-save me-2"></i>Update Profile</button>
                            </div>
                    </form>
                </div>
            </div>
        </div>
    </div>
</div>
<script>
    document.getElementById('togglePassword').addEventListener('click', function(e) {
        const password = document.getElementById('u_pass');
        const type = password.getAttribute('type') === 'password' ? 'text' : 'password';
        password.setAttribute('type', type);
        this.querySelector('i').classList.toggle('fa-eye');
        this.querySelector('i').classList.toggle('fa-eye-slash');
    });
</script>

<?php include 'footer.php'; ?>