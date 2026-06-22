<?php include 'header_main.php'; ?>
<div class="container"><br><br><br>

  <h4>Please Fill In The Login</h4>
  <form method="POST" action="loginprocess.php">
    <fieldset>
      <div>
        <label for="exampleInputEmail1" class="form-label mt-4">Please Enter Your Staff or Student Number</label>
        <input type="text" name="funame" class="form-control" id="exampleInputEmail1" aria-describedby="emailHelp" placeholder="Enter your staff or student ID" required>
      </div>
      <div>
        <label for="exampleInputPassword1" class="form-label mt-4">Password</label>
        <div class="input-group">
          <input type="password" name="fpwd" class="form-control" id="exampleInputPassword1" placeholder="Enter your password" autocomplete="off" required>
          <span class="input-group-text" onclick="togglePassword()">
            <i class="fas fa-eye" id="togglePassword"></i>
          </span>
          
        </div>
      </div>

    </fieldset>
    <br><button type="submit" class="btn btn-primary">Login</button><br><br><br><br>
    </fieldset>
  </form>

  <script>
    function togglePassword() {
      var passwordInput = document.getElementById("exampleInputPassword1");
      var toggleIcon = document.getElementById("togglePassword");

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
  </script>

  </body>
  <?php include 'footer.php'; ?>