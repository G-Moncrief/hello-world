<?php
session_start();
print_r($_POST);
print_r($_SESSION);

ob_start();

if  (isset($_POST['addgame'])){
  session_start();
  include_once 'connection.php';

  $title = mysqli_real_escape_string($connection,$_POST['title']);
  $system = mysqli_real_escape_string($connection,$_POST['system']);
  $publisher = mysqli_real_escape_string($connection,$_POST['publisher']);
  $genre = mysqli_real_escape_string($connection,$_POST['genre']);
  $length = mysqli_real_escape_string($connection,$_POST['length']);

  $sql = "INSERT INTO `games`(`uid`, `title`, `system`, `publisher`, `genre`, `length`) VALUES ('{$_SESSION['u_un']}','$title','$system','$publisher','$genre','$length')";
  $result = mysqli_query($connection, $sql);
  if($result){
    header("Location: addgame.php");
    exit();
  }
} else {
  header("Location: addgame.php?error");
  exit();
}

ob_end_flush();
