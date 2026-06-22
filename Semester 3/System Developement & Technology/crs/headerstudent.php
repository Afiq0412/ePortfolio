<!DOCTYPE html>
<html lang="en">

<head>
  <title>Course Registration System</title>
  <meta charset="utf-8">
  <meta name="viewport" content="width=device-width, initial-scale=1">

  <!-- Bootstrap CSS -->
  <link href="https://cdn.jsdelivr.net/npm/bootstrap@5.3.0/dist/css/bootstrap.min.css" rel="stylesheet" integrity="sha384-9ndCyUaIbzAi2FUVXJi0CjmCapSmO7SnpJef0486qhLnuZ2cdeRhO02iuK6FUUVM" crossorigin="anonymous">

  <!-- Bootstrap Icons -->
  <link rel="stylesheet" href="https://cdn.jsdelivr.net/npm/bootstrap-icons@1.11.2/font/bootstrap-icons.min.css">

  <!-- Font Awesome -->
  <link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/6.4.0/css/all.min.css" integrity="sha512-iecdLmaskl7CVkqkXNQ/ZH/XLlvWZOJyj7Yy7tcenmpD1ypASozpmT/E0iPtmFIB46ZmdtAc9eNBvH0H/ZpiBw==" crossorigin="anonymous" referrerpolicy="no-referrer" />

  <!-- Custom CSS -->
  <style>
    .navbar-nav .nav-link.active {
      background-color: rgba(255, 255, 255, 0.1);
      border-radius: 0.25rem;
    }
  </style>
</head>

<body>
  <nav class="navbar navbar-expand-lg bg-dark" data-bs-theme="dark">
    <div class="container-fluid">
      <a class="navbar-brand">CRS Student</a>
      <button class="navbar-toggler" type="button" data-bs-toggle="collapse" data-bs-target="#navbarColor02" aria-controls="navbarColor02" aria-expanded="false" aria-label="Toggle navigation">
        <span class="navbar-toggler-icon"></span>
      </button>
      <div class="collapse navbar-collapse" id="navbarColor02">
        <ul class="navbar-nav me-auto">
          <li class="nav-item">
            <a class="nav-link" href="student.php">Home</a>
          </li>
          <li class="nav-item">
            <a class="nav-link" href="courseregister.php">Register Course</a>
          </li>
          <li class="nav-item">
            <a class="nav-link" href="courseview.php">View Your Courses</a>
          </li>
        </ul>
        <ul class="navbar-nav">
          <li class="nav-item dropdown">
            <a class="nav-link dropdown-toggle" href="#" id="navbarDropdown" role="button" data-bs-toggle="dropdown" aria-expanded="false">
              <i class="bi bi-gear-fill"></i> Settings
            </a>
            <ul class="dropdown-menu dropdown-menu-end" aria-labelledby="navbarDropdown">
            <li><a class="dropdown-item" href="profilestudent.php?u_sno=<?php echo $_SESSION['u_sno']; ?>">
              <i class="bi bi-person-circle"></i> Profile</a></li>
              <li>
                <hr class="dropdown-divider">
              </li>
              <li><a class="dropdown-item" href="logout.php"><i class="bi bi-box-arrow-right"></i> Logout</a></li>
            </ul>
          </li>
        </ul>
      </div>
    </div>
  </nav>

  <!-- Bootstrap JavaScript Bundle with Popper -->
  <script src="https://cdn.jsdelivr.net/npm/bootstrap@5.3.0/dist/js/bootstrap.bundle.min.js" integrity="sha384-geWF76RCwLtnZ8qwWowPQNguL3RmwHVBC9FhGdlKrxdiJJigb/j/68SIy3Te4Bkz" crossorigin="anonymous"></script>

  <script>
    document.addEventListener('DOMContentLoaded', function() {
      // Get the current page URL
      var currentPage = window.location.pathname.split('/').pop();

      // Get all nav links
      var navLinks = document.querySelectorAll('.navbar-nav .nav-link');

      // Loop through the links
      navLinks.forEach(function(link) {
        // If the link's href matches the current page, add the active class
        if (link.getAttribute('href') === currentPage) {
          link.classList.add('active');
        }

        // Add click event listener
        link.addEventListener('click', function() {
          // Remove active class from all links
          navLinks.forEach(function(innerLink) {
            innerLink.classList.remove('active');
          });
          // Add active class to clicked link
          this.classList.add('active');
        });
      });
    });
  </script>
</body>

</html>