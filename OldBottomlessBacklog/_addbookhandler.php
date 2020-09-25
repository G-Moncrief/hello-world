<?php
session_start();
print_r($_POST);
print_r($_SESSION);

ob_start();

if  (isset($_POST['addbook'])){
  session_start();
  include_once 'connection.php';

  $title = mysqli_real_escape_string($connection,$_POST['title']);
  $author = mysqli_real_escape_string($connection,$_POST['author']);
  $genre = mysqli_real_escape_string($connection,$_POST['genre']);
  $pages = mysqli_real_escape_string($connection,$_POST['pages']);

  $sql = "INSERT INTO `library`(`uid`, `title`, `author`, `genre`, `pages`) VALUES ('{$_SESSION['u_un']}','$title','$author','$genre','$pages')";
  $result = mysqli_query($connection, $sql);
  if($result){
    header("Location: addbook.php");
    exit();
  }
} else {
  header("Location: addbook.php?error");
  exit();
}

ob_end_flush();
