<?php
session_start();
include_once 'connection.php';
print_r($_POST);
print_r($_SESSION);

if ($_POST['type']==0) {
  echo "adding a book";

  $title = mysqli_real_escape_string($connection,$_POST["value0"]);
  $author = mysqli_real_escape_string($connection,$_POST["value1"]);
  $genre = mysqli_real_escape_string($connection,$_POST["value2"]);
  $pages = mysqli_real_escape_string($connection,$_POST["value3"]);

  $sql = "INSERT INTO `library`(`uid`, `title`, `author`, `genre`, `pages`) VALUES ('{$_SESSION['u_un']}','$title','$author','$genre','$pages')";
  $result = mysqli_query($connection, $sql);
  if($result){
    header("Location: library.php");
    exit();
  }
}

elseif ($_POST['type']==1) {
  echo "adding a game";

  $title = mysqli_real_escape_string($connection,$_POST["value0"]);
  $system = mysqli_real_escape_string($connection,$_POST["value1"]);
  $publisher = mysqli_real_escape_string($connection,$_POST["value2"]);
  $genre = mysqli_real_escape_string($connection,$_POST["value4"]);
  $length = mysqli_real_escape_string($connection,$_POST["value3"]);

  $sql = "INSERT INTO `games`(`uid`, `title`, `system`, `publisher`, `genre`, `length`) VALUES ('{$_SESSION['u_un']}','$title','$system','$publisher','$genre','$length')";
  $result = mysqli_query($connection, $sql);
  if($result){
    header("Location: games.php");
    exit();
  }
}

elseif ($_POST['type']==2) {
  echo "adding a show";

  $title = mysqli_real_escape_string($connection,$_POST["value0"]);
  $network = mysqli_real_escape_string($connection,$_POST["value1"]);
  $genre = mysqli_real_escape_string($connection,$_POST["value2"]);
  $episodes = mysqli_real_escape_string($connection,$_POST["value4"]);
  $length = mysqli_real_escape_string($connection,$_POST["value3"]);

  $sql = "INSERT INTO `shows`(`uid`, `title`, `network`, `genre`, `episodes`, `length`) VALUES ('{$_SESSION['u_un']}','$title','$network', '$genre', '$episodes','$length')";
  $result = mysqli_query($connection, $sql);
  if($result){
    header("Location: shows.php");
    exit();
  }
}
