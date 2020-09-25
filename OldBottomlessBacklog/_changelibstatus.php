<?php

session_start();
include_once 'connection.php';
print_r($_POST);
print_r($_SESSION);
ob_start();

$libid = mysqli_real_escape_string($connection,$_POST['libid']);
$newstatus = mysqli_real_escape_string($connection,$_POST['newstatus']);

if ($_POST['newstatus']==0){
  $sql = "DELETE FROM `library` WHERE libid='$libid'";
  $result = mysqli_query($connection, $sql);
  if($result){
    header("Location: library.php");
    exit();
  }

} else {
  $sql = "UPDATE library SET status='$newstatus' WHERE libid='$libid'";
  $result = mysqli_query($connection, $sql);
  if($result){
    header('Location: library.php#'.$libid);
    exit();
  }
}
