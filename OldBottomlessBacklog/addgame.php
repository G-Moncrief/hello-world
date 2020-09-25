<?php
session_start();
?>

<!DOCTYPE html>
<html>
  <head>
    <meta charset="utf-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Add Game | Bottomless Backlog</title>
    <link rel="stylesheet" href="style.css">
  </head>

  <body>

    <nav class="mainnav">
      <div class="bb-logo-main">
        <p>Bottomless<br>Backlog</p>
      </div>
      <a href="usermain.php"><img class="mainnav-img" src="images/home.jpg" alt=""></a>
      <a href="games.php"><img class="mainnav-img" src="images/controller.jpg" alt=""></a>
      <a href="library.php"><img class="mainnav-img" src="images/book.jpg" alt=""></a>
      <a href="shows.php"><img class="mainnav-img" src="images/remote.jpg" alt=""></a>
    </nav>

    <section class="user-main">
      <div>
        <br>
        <br>
        <h2>Add Game</h2>
      </div>
    </section>

    <div class="user-main-search">
      <form class="nav-wrapper" action="_addgamehandler.php" method="post">
        <div>
          <input type="text" name="title" placeholder="Title"  required>
        </div>
        <div>
          <input type="text" name="system" placeholder="System"  required>
        </div>
        <div>
          <input type="text" name="publisher" placeholder="Publisher"  required>
        </div>
        <div>
          <input type="text" name="genre" placeholder="Genre"  required>
        </div>
        <div>
          <input type="text" name="length" placeholder="Length(hours)"  required>
        </div>
        <div>
          <button type="select" class="button-loginreg" name="addgame">Add</button>
        </div>
      </form>
    </div>

  </body>
</html>
