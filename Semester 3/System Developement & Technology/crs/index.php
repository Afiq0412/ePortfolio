<?php include 'header_main.php'; ?>
<div class="container mt-5">
  <h1 class="mb-4">Course Management System</h1>
  <div class="row">
    <div class="col-md-4">
      <div class="card mb-4">
        <div class="card-body">
          <h5 class="card-title">Register</h5>
          <p class="card-text">Create a new account to access courses.</p>
          <a href="register.php" class="btn btn-primary">Register Now</a>
        </div>
      </div>
    </div>
    <div class="col-md-4">
      <div class="card mb-4">
        <div class="card-body">
          <h5 class="card-title">Login</h5>
          <p class="card-text">Access your account and enrolled courses.</p>
          <a href="login.php" class="btn btn-primary">Login</a>
        </div>
      </div>
    </div>
    <div class="col-md-4">
      <div class="card mb-4">
        <div class="card-body">
          <h5 class="card-title">My Profile</h5>
          <p class="card-text">Update your personal information and settings.</p>
          <a href="#" class="btn btn-primary">Edit Profile</a>
        </div>
      </div>
    </div>
    <div class="row">
      <div class="col-md-8">
        <div class="card">
          <div class="card-body">
            <h5 class="card-title">Announcements</h5>
            <ul class="list-group list-group-flush">
              <li class="list-group-item">New course "Introduction to AI" now available!</li>
              <li class="list-group-item">System maintenance scheduled for this weekend.</li>
              <li class="list-group-item">Don't forget to submit your assignments before the deadline.</li>
            </ul>
          </div>
        </div>
      </div>
      <div class="col-md-4">
        <div class="card">
          <div class="card-body">
            <h5 class="card-title">Quick Links</h5>
            <ul class="list-group list-group-flush">
              <li class="list-group-item"><a href="#">Academic Calendar</a></li>
              <li class="list-group-item"><a href="#">Student Resources</a></li>
              <li class="list-group-item"><a href="#">Help & Support</a></li>
            </ul>
          </div>
        </div>
      </div>
    </div>
  </div>

  <?php include 'footer.php'; ?>