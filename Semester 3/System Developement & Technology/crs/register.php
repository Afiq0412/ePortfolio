<?php include 'header_main.php'; ?>
<div class="container"><br><br><br>

  <h4>Please Fill All Following Details</h4>
  <form method="POST" action="registerprocess.php">
    <fieldset>
      <div>
        <label for="exampleInputEmail1" class="form-label mt-4">Please Enter Your Staff or Student Number</label>
        <input type="text" name="funame" class="form-control" id="exampleInputEmail1" aria-describedby="emailHelp" placeholder="Enter your staff or student ID" required>
      </div>
      <div>
        <label for="exampleInputPassword1" class="form-label mt-4">Create Your Password</label>
        <div class="input-group">
          <input type="password" name="fpwd" class="form-control" id="exampleInputPassword1" placeholder="Enter your password" autocomplete="off" required>
          <span class="input-group-text" onclick="togglePassword('exampleInputPassword1', 'togglePassword1')">
            <i class="fas fa-eye" id="togglePassword1"></i>
          </span>
        </div>
      </div>
      <div>
        <label for="exampleInputPassword2" class="form-label mt-4">Confirm Your Password</label>
        <div class="input-group">
          <input type="password" name="fpwd_confirm" class="form-control" id="exampleInputPassword2" placeholder="Confirm your password" autocomplete="off" required>
          <span class="input-group-text" onclick="togglePassword('exampleInputPassword2', 'togglePassword2')">
            <i class="fas fa-eye" id="togglePassword2"></i>
          </span>
        </div>
        <div id="passwordMismatch" class="text-danger" style="display: none;">Passwords do not match!</div>
      </div>
      <div>
        <label for="exampleInputEmail1" class="form-label mt-4">Enter Your Email Address</label>
        <input type="email" name="femail" class="form-control" id="exampleInputEmail1" aria-describedby="emailHelp" placeholder="Enter your email address" required>
      </div>
      <div>
        <label for="exampleInputEmail1" class="form-label mt-4">Enter Your Full Name</label>
        <input type="text" name="fname" class="form-control" id="exampleInputEmail1" aria-describedby="emailHelp" placeholder="Enter your full name" required>
      </div>
      <div>
        <label for="exampleInputEmail1" class="form-label mt-4">Enter Your Contact Number</label>
        <input type="text" name="fcontact" class="form-control" id="exampleInputEmail1" aria-describedby="emailHelp" placeholder="Enter your contact number" required>
      </div>
      <div>
        <label for="exampleSelect1" class="form-label mt-4">Select Your State</label>
        <select class="form-select" name="fstate" id="exampleSelect1" required>
          <option>Johor</option>
          <option>Kedah</option>
          <option>Kelantan</option>
          <option>Melaka</option>
          <option>Negeri Sembilan</option>
          <option>Pahang</option>
          <option>Pulau Pinang</option>
          <option>Perak</option>
          <option>Perlis</option>
          <option>Selangor</option>
          <option>Terengganu</option>
          <option>Sabah</option>
          <option>Sarawak</option>
          <option>WP Kuala Lumpur</option>
          <option>WP Labuan</option>
          <option>WP Putrajaya</option>
        </select>
      </div><br>

    </fieldset>
    <div class="row mt-4">
      <div class="col-md-2 d-flex justify-content-between">
        <button type="reset" class="btn btn-warning">Reset <i class="bi bi-arrow-counterclockwise"></i></button>
        <button type="submit" class="btn btn-primary">Submit <i class="bi bi-arrow-right"></i></button>
      </div>
    </div>
    <br><br><br><br>
  </form>

  <script>
    function togglePassword(inputId, iconId) {
      var passwordInput = document.getElementById(inputId);
      var toggleIcon = document.getElementById(iconId);

      if (passwordInput.type === "password") {
        passwordInput.type = "text";
        toggleIcon.classList.remove("fa-eye");
        toggleIcon.classList.add("fa-eye-slash");
      } else {
        passwordInput.type = "password";
        toggleIcon.classList.remove("fa-eye-slash");
        toggleIcon.classList.add("fa-eye");
      }
    }
    document.addEventListener('DOMContentLoaded', function() {
      var password = document.getElementById('exampleInputPassword1');
      var confirmPassword = document.getElementById('exampleInputPassword2');
      var mismatchMessage = document.getElementById('passwordMismatch');
      var submitButton = document.getElementById('submitButton');

      function checkPasswords() {
        if (password.value !== confirmPassword.value) {
          mismatchMessage.style.display = 'block';
          submitButton.disabled = true;
        } else {
          mismatchMessage.style.display = 'none';
          submitButton.disabled = false;
        }
      }

      password.addEventListener('input', checkPasswords);
      confirmPassword.addEventListener('input', checkPasswords);

      document.getElementById('registrationForm').addEventListener('submit', function(e) {
        if (password.value !== confirmPassword.value) {
          e.preventDefault();
          mismatchMessage.style.display = 'block';
        }
      });
    });
  </script>

  </body>
  <?php include 'footer.php'; ?>
  </body>