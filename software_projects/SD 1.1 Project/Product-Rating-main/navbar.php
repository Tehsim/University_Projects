

<style>
a:hover {
  background-color: #ADD8E6;
}
</style>



<nav class="navbar navbar-expand-lg navbar-light bg-light">
  <button class="navbar-toggler" type="button" data-toggle="collapse" data-target="#navbarTogglerDemo03" aria-controls="navbarTogglerDemo03" aria-expanded="false" aria-label="Toggle navigation">
    <span class="navbar-toggler-icon"></span>
  </button>
  <a class="navbar-brand" href="index.php">Home</a>

  <div class="collapse navbar-collapse" id="navbarTogglerDemo03">
    <ul class="navbar-nav mr-auto mt-2 mt-lg-0">

      <?php
      $userName = '';
      $show = '';
      $register_nav_show = 'hidden';
      if(!empty($_SESSION['userid']) && $_SESSION['userid']) {
      	$userName =  $_SESSION['username'];
        $register_nav_show = 'hidden';
      } else {
      	$show = 'hidden';
        $register_nav_show = '';
      }
      ?>

 

      <li class="nav-item">
        <a class="nav-link" href="contact.php" style="color:black">Contact Us <span class="sr-only">(current)</span></a>
        
      </li>
    </ul>


    <div id="loggedPanel" class="<?php echo $show; ?>">
      <span id="loggedUser" class="logged-user"><?php echo $userName; ?></span>
      <a href="action.php?action=logout">Logout</a>
    </div>

    <ul class="navbar-nav pull-right <?php echo $register_nav_show; ?>">
      <li class="nav-item">
        <a class="nav-link" href="register.php" style="color:black">Registration</a>
      </li>
    </ul>
  </div>
</nav>
