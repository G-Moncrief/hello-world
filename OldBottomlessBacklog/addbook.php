<?php
session_start();
?>

<!DOCTYPE html>
<html>
  <head>
    <meta charset="utf-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Add Book | Bottomless Backlog</title>
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
        <h2>Add Book</h2>
      </div>
    </section>

    <div class="user-main-search">
      <form class="nav-wrapper" action="_addbookhandler.php" method="post">
        <div>
          <input type="text" name="title" placeholder="Title" required>
        </div>
        <div>
          <input type="text" name="author" placeholder="Author" required>
        </div>
        <div>
          <input type="text" name="genre" placeholder="Genre" required>
        </div>
        <div>
          <input type="text" name="pages" placeholder="Pages" required>
        </div>
        <div>
          <button type="select" class="button-loginreg" name="addbook">Add</button>
        </div>
      </form>
    </div>

  </body>
</html>
