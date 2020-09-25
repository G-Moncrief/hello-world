<?php
session_start();
include_once 'connection.php';
?>

<!DOCTYPE html>
<html>
  <head>
    <meta charset="utf-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Games | Bottomless Backlog</title>
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
    <div class="user-main-search">
      <form class="nav-wrapper" action="searchresults.php" method="post">
        <div>
          <input type="text" name="searchfor" placeholder="Title or publisher">
        </div>
        <div>
          <button type="select" class="button-loginreg" name="gamesearch">Search</button>
        </div>
      </form>
      <form class="nav-wrapper" action="addgame.php">
        <button type="select" class="button-loginreg" name="addbook">Add</button>
      </form>
    </div>
    <div class="nav-wrapper">
      <table class="table-mobile">
        <tr>
          <th>Title</th>
          <th>System</th>
          <th>Change<br>Status</th>
        </tr>
        <?php
        $sql = "SELECT * FROM `games` WHERE uid='{$_SESSION['u_un']}' ORDER BY status ";
        $result = mysqli_query($connection, $sql);

        while ($row = mysqli_fetch_array($result)) {
           ?>
           <tr>
             <td><?php echo $row['title']?></td>
             <td><?php echo $row['system']?></td>
             <td>
               <form class="" action="_changegamestatus.php" method="post">
                 <input type="hidden" name="gameid" value="<?php echo $row['gameid']?>">
                 <select  name="newstatus" onchange="this.form.submit()">
                   <option disabled selected value>Change Status</option>
                   <option value="2">Shelved</option>
                   <option value="1">Playing</option>
                   <option value="3">Finished</option>
                   <option value="0">Remove</option>
                 </select>
               </form>
             </td>
           </tr>
           <?php
           }
           ?>
      </table>
      <table class="table-desktop">
        <tr>
          <th>Title</th>
          <th>System</th>
          <th>Publisher</th>
          <th>Genre</th>
          <th>Length</th>
          <th>Current<br>Status</th>
          <th> </th>
        </tr>
        <?php
        $sql = "SELECT * FROM `games` WHERE uid='{$_SESSION['u_un']}' ORDER BY status ";
        $result = mysqli_query($connection, $sql);

        while ($row = mysqli_fetch_array($result)) {
           ?>
           <tr>
             <td id="<?php echo $row['gameid']?>"><?php echo $row['title']?></td>
             <td><?php echo $row['system']?></td>
             <td><?php echo $row['publisher']?></td>
             <td><?php echo $row['genre']?></td>
             <td><?php echo $row['length']?></td>
             <td>
               <?php
               if ($row['status']==1) {
                 echo "Playing";
               } elseif ($row['status']==2) {
                 echo "Shelved";
               } else {
                 echo "Finished";
               }
             ?>
            </td>
             <td>
               <form class="" action="_changegamestatus.php" method="post">
                 <input type="hidden" name="gameid" value="<?php echo $row['gameid']?>">
                 <select  name="newstatus" onchange="this.form.submit()">
                   <option disabled selected value>Change Status</option>
                   <option value="2">Shelved</option>
                   <option value="1">Playing</option>
                   <option value="3">Finished</option>
                   <option value="0">Remove</option>
                 </select>
               </form>

             </td>
           </tr>
           <?php
           }
           ?>
      </table>
    </div>
  </body>
</html>
