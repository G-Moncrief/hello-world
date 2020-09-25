<?php

session_start();
include_once 'connection.php';
print_r($_POST);
print_r($_SESSION);
ob_start();

$gameid = mysqli_real_escape_string($connection,$_POST['gameid']);
$newstatus = mysqli_real_escape_string($connection,$_POST['newstatus']);

if ($_POST['newstatus']==0){
  $sql = "DELETE FROM `games` WHERE gameid='$gameid'";
  $result = mysqli_query($connection, $sql);
  if($result){
    header("Location: games.php");
    exit();
  }

} else {
  $sql = "UPDATE games SET status='$newstatus' WHERE gameid='$gameid'";
  $result = mysqli_query($connection, $sql);
  if($result){
    header('Location: games.php#'.$gameid);
    exit();
  }
}
