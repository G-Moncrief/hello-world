<?php
session_start();
include_once 'connection.php';
?>

<!DOCTYPE html>
<html>
  <head>
    <meta charset="utf-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Main | Bottomless Backlog</title>
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
      <div class="">
        <h2>
          <?php
            echo $_SESSION['u_un'];
           ?>
         </h2>
        <br>
        -THE-
        <br><br>
        FANTASTIC SCHOLAR
      </div>
    </section>

    <section class="user-main">
      <div >
        <img class="user-main-img" src="images/fantasy.jpg" alt="">
      </div>
      <div class="user-main">
          <table>
            <tr>
              <td>
                <?php
                $sql = "SELECT SUM(pages)AS pagesum FROM `library` WHERE uid='{$_SESSION['u_un']}'AND status='3'";
                $result = mysqli_query($connection, $sql);
                while ($row = mysqli_fetch_array($result)){echo $row['pagesum'];}
                ?>
              </td>
              <td>Pages Read</td>
            </tr>
            <tr>
              <td>
                <?php
                $sql = "SELECT SUM(length)AS playtime FROM `games` WHERE uid='{$_SESSION['u_un']}'AND status='3'";
                $result = mysqli_query($connection, $sql);
                while ($row = mysqli_fetch_array($result)){echo $row['playtime'];}
                ?>
              </td>
              <td>Hours Played</td>
            </tr>
            <tr>
              <td>
                <?php
                $sql = "SELECT SUM(episodes)AS episodes FROM `shows` WHERE uid='{$_SESSION['u_un']}'AND status='3'";
                $result = mysqli_query($connection, $sql);
                while ($row = mysqli_fetch_array($result)){echo $row['episodes'];}
                ?>
              </td>
              <td>Episodes Watched</td>
            </tr>
            <tr>
              <td>
                <?php
                $sql = "SELECT SUM(temp) AS total
                    FROM (SELECT count(libid) AS temp
                    FROM library
                    WHERE uid='JohnnyTest' AND status=3

                    UNION

                    SELECT count(gameid) AS temp
                    FROM games
                    WHERE uid='JohnnyTest' AND status=3

                    UNION

                    SELECT count(showid) AS temp
                    FROM shows
                    WHERE uid='JohnnyTest' AND status=3) AS temp";
                $result = mysqli_query($connection, $sql);
                while ($row = mysqli_fetch_array($result)){echo $row['total'];}
                ?>
              </td>
              <td>Total items finished</td>
            </tr>
            <tr>
              <td> </td>
              <td> </td>
            </tr>
            <tr>
              <td>Ranked</td>
              <td>###</td>
            </tr>
            <tr>
              <td>out of </td>
              <td>
                <?php
                $sql = "SELECT COUNT(*)AS usercount FROM `login`";
                $result = mysqli_query($connection, $sql);
                while ($row = mysqli_fetch_array($result)){echo $row['usercount'];}
                ?>
              </td>
            </tr>
          </table>
        </div>
    </section>

      <form class="login-fields" action="logout.php">
        <button name ="logout" class="button-logout" type="submit">Logout</button>
      </form>

  </body>
</html>
