<?php
session_start();
include_once 'connection.php';

 ?>

 <!DOCTYPE html>
 <html>
   <head>
     <meta charset="utf-8">
     <meta name="viewport" content="width=device-width, initial-scale=1.0">
     <title>Search Results | Bottomless Backlog</title>
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

     <div class="nav-wrapper">
       <table class="table-mobile">
         <?php
         if (isset($_POST['booksearch'])){
           $setval="0";
           $sql = "SELECT DISTINCT title, author, genre, pages FROM `library` WHERE title LIKE '%{$_POST['searchfor']}%' OR author LIKE '%{$_POST['searchfor']}%' ";
           $result = mysqli_query($connection, $sql);
         }

         elseif (isset($_POST['gamesearch'])){
           $setval="1";
           $sql = "SELECT DISTINCT title, system, publisher, length, genre FROM `games` WHERE title LIKE '%{$_POST['searchfor']}%' OR publisher LIKE '%{$_POST['searchfor']}%'";
           $result = mysqli_query($connection, $sql);

         }

         elseif (isset($_POST['showsearch'])){
           $setval="2";
           $sql = "SELECT DISTINCT title, network, genre, length, episodes  FROM `shows` WHERE title LIKE '%{$_POST['searchfor']}%' ";
           $result = mysqli_query($connection, $sql);
         }

         while ($row = mysqli_fetch_array($result)) {
   ?>
   <tr>
     <td id="<?php echo $row[0]?>"><?php echo $row['title']?></td>
     <td><?php echo $row[1]?></td>
     <td>
       <form class="" action="_adder.php" method="post">
         <input type="hidden" name="type" value="<?php echo $setval?>">
         <input type="hidden" name="value0" value="<?php echo $row[0]?>">
         <input type="hidden" name="value1" value="<?php echo $row[1]?>">
         <input type="hidden" name="value2" value="<?php echo $row[2]?>">
         <input type="hidden" name="value3" value="<?php echo $row[3]?>">
         <input type="hidden" name="value4" value="<?php echo $row[4]?>">
         <input type="hidden" name="value5" value="<?php echo $row[5]?>">
         <input type="hidden" name="value6" value="<?php echo $row[6]?>">
         <input type="hidden" name="value7" value="<?php echo $row[7]?>">
         <button class="button-loginreg" type="submit" name="addtodb">ADD</button>
       </form>
     </td>
   </tr>
 <?php } ?>

       </table>
       <table class="table-desktop">
         <?php
         if (isset($_POST['booksearch'])){
           $setval="0";
           $sql = "SELECT DISTINCT title, author, genre, pages FROM `library` WHERE title LIKE '%{$_POST['searchfor']}%' OR author LIKE '%{$_POST['searchfor']}%' ";
           $result = mysqli_query($connection, $sql);
         }

         elseif (isset($_POST['gamesearch'])){
           $setval="1";
           $sql = "SELECT DISTINCT title, system, publisher, length, genre FROM `games` WHERE title LIKE '%{$_POST['searchfor']}%' OR publisher LIKE '%{$_POST['searchfor']}%'";
           $result = mysqli_query($connection, $sql);

         }

         elseif (isset($_POST['showsearch'])){
           $setval="2";
           $sql = "SELECT DISTINCT title, network, genre, length, episodes  FROM `shows` WHERE title LIKE '%{$_POST['searchfor']}%' ";
           $result = mysqli_query($connection, $sql);
         }

         while ($row = mysqli_fetch_array($result)) {
   ?>
   <tr>
     <td id="<?php echo $row[0]?>"><?php echo $row['title']?></td>
     <td><?php echo $row[1]?></td>
     <td><?php echo $row[2]?></td>
     <td><?php echo $row[4]?></td>
     <td><?php echo $row[5]?></td>
     <td><?php echo $row[6]?></td>
     <td><?php echo $row[7]?></td>
     <td>
       <form class="" action="_adder.php" method="post">
         <input type="hidden" name="type" value="<?php echo $setval?>">
         <input type="hidden" name="value0" value="<?php echo $row[0]?>">
         <input type="hidden" name="value1" value="<?php echo $row[1]?>">
         <input type="hidden" name="value2" value="<?php echo $row[2]?>">
         <input type="hidden" name="value3" value="<?php echo $row[3]?>">
         <input type="hidden" name="value4" value="<?php echo $row[4]?>">
         <input type="hidden" name="value5" value="<?php echo $row[5]?>">
         <input type="hidden" name="value6" value="<?php echo $row[6]?>">
         <input type="hidden" name="value7" value="<?php echo $row[7]?>">
         <button class="button-loginreg" type="submit" name="addtodb">ADD</button>
       </form>
     </td>
   </tr>
 <?php } ?>
       </table>
     </div>
   </body>
 </html>
