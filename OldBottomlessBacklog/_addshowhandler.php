<?php
session_start();
print_r($_POST);
print_r($_SESSION);

ob_start();

if  (isset($_POST['addshow'])){
  session_start();
  include_once 'connection.php';

  $title = mysqli_real_escape_string($connection,$_POST['title']);
  $network = mysqli_real_escape_string($connection,$_POST['network']);
  $genre = mysqli_real_escape_string($connection,$_POST['genre']);
  $episodes = mysqli_real_escape_string($connection,$_POST['episodes']);
  $length = mysqli_real_escape_string($connection,$_POST['length']);

  $sql = "INSERT INTO `shows`(`uid`, `title`, `network`, `genre`, `episodes`, `length`) VALUES ('{$_SESSION['u_un']}','$title','$network', '$genre', '$episodes','$length')";
  $result = mysqli_query($connection, $sql);
  if($result){
    header("Location: addshow.php");
    exit();
  }
} else {
  header("Location: addshow.php?error");
  exit();
}

ob_end_flush();
