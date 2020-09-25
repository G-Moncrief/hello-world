<?php
ob_start();

session_start();

if  (isset($_POST['regsubmit'])){
  include_once 'connection.php';

  $username = mysqli_real_escape_string($connection,$_POST['username']);
  $email = mysqli_real_escape_string($connection,$_POST['email']);
  $password = mysqli_real_escape_string($connection,$_POST['password']);

  //error handling

  if (!filter_var($email, FILTER_VALIDATE_EMAIL)){
    header("Location: register.html?register=email");
    exit();
  } else {
    $sql = "SELECT * FROM login WHERE login_username='$username'";
    $result = mysqli_query($connection, $sql);
    $resultCheck = mysqli_num_rows($result);

    if ($resultCheck > 0) {
      header("Location: register.html?register=usernametaken");
      exit();
    } else {
      //pwd hash
      $hashedPwd = password_hash($password, PASSWORD_DEFAULT);

      	$sql = "INSERT INTO `login`(`username`, `email`, `password`) VALUES ('$username','$email','$hashedPwd')";
        $result = mysqli_query($connection, $sql);
      }
      if($result){
        $_SESSION['u_un']=$_POST['username'];
        $_SESSION['u_email']=$_POST['email'];
        $_SESSION['u_priv']=4;
        header("Location: redirect.php");
        exit();
      }
    }

} else {
  header("Location: register.php");
  exit();
}
ob_end_flush();
