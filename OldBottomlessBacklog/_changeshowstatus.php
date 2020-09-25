<?php

session_start();
include_once 'connection.php';
print_r($_POST);
print_r($_SESSION);
ob_start();

$showid = mysqli_real_escape_string($connection,$_POST['showid']);
$newstatus = mysqli_real_escape_string($connection,$_POST['newstatus']);

if ($_POST['newstatus']==0){
  $sql = "DELETE FROM `shows` WHERE showid='$showid'";
  $result = mysqli_query($connection, $sql);
  if($result){
    header("Location: shows.php");
    exit();
  }

} else {
  $sql = "UPDATE shows SET status='$newstatus' WHERE showid='$showid'";
  $result = mysqli_query($connection, $sql);
  if($result){
    header('Location: shows.php#'.$showid);
    exit();
  }
}
