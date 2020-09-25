<?php
session_start();
include_once 'connection.php';
?>

<!DOCTYPE html>
<html>
  <head>
    <meta charset="utf-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Shows | Bottomless Backlog</title>
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
          <input type="text"  name="searchfor" placeholder="Title">
        </div>
        <div>
          <button type="select" class="button-loginreg" name="showsearch">Search</button>
        </div>
      </form>
      <form class="nav-wrapper" action="addshow.php">
        <button type="select" class="button-loginreg" name="addshow">Add</button>
      </form>
    </div>
    <div class="nav-wrapper">
      <table class="table-mobile">
        <tr>
          <th>Title</th>
          <th>Director<br>or<br>Network</th>
          <th>Status</th>
        </tr>
        <tr>
          <?php
          $sql = "SELECT * FROM `shows` WHERE uid='{$_SESSION['u_un']}' ORDER BY status ";
          $result = mysqli_query($connection, $sql);

          while ($row = mysqli_fetch_array($result)) {
             ?>
             <tr>
               <td><?php echo $row['title']?></td>
               <td><?php echo $row['network']?></td>
               <td>
                 <form class="" action="_changeshowstatus.php" method="post">
                   <input type="hidden" name="showid" value="<?php echo $row['showid']?>">
                   <select  name="newstatus" onchange="this.form.submit()">
                     <option disabled selected value>Change Status</option>
                     <option value="2">Shelved</option>
                     <option value="1">Watching</option>
                     <option value="3">Finished</option>
                     <option value="0">Remove</option>
                   </select>
                 </form>
               </td>
             </tr>
             <?php
             }
             ?>
        </tr>
      </table>
      <table class="table-desktop">
        <tr>
          <th>Title</th>
          <th>Director<br>or<br>Network</th>
          <th>Genre</th>
          <th>Episodes</th>
          <th>Runtime</th>
          <th>Current<br>Status</th>
        </tr>
        <?php
        $sql = "SELECT * FROM `shows` WHERE uid='{$_SESSION['u_un']}' ORDER BY status ";
        $result = mysqli_query($connection, $sql);

        while ($row = mysqli_fetch_array($result)) {
           ?>
           <tr>
             <td id="<?php echo $row['showid']?>"><?php echo $row['title']?></td>
             <td><?php echo $row['network']?></td>
             <td><?php echo $row['genre']?></td>
             <td><?php echo $row['episodes']?></td>
             <td><?php echo $row['length']?></td>
             <td>
               <?php
               if ($row['status']==1) {
                 echo "Watching";
               } elseif ($row['status']==2) {
                 echo "Shelved";
               } else {
                 echo "Finished";
               }
             ?>
            </td>
             <td>
               <form class="" action="_changeshowstatus.php" method="post">
                 <input type="hidden" name="showid" value="<?php echo $row['showid']?>">
                 <select  name="newstatus" onchange="this.form.submit()">
                   <option disabled selected value>Change Status</option>
                   <option value="2">Shelved</option>
                   <option value="1">Watching</option>
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
