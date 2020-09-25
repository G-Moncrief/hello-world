<?php
ob_start();

session_start();
if (isset($_POST['loginsubmit'])) {
  include 'connection.php';

    $username = mysqli_real_escape_string($connection,$_POST['username']);
    $password = mysqli_real_escape_string($connection,$_POST['password']);

    $sql = "SELECT * FROM `login` WHERE username='$username'";
    $result = mysqli_query($connection, $sql);
    $resultCheck = mysqli_num_rows($result);
    if ($resultCheck < 1) {
      header("Location: index.html?login=invalidun");
      exit();
    } else {
      if($row = mysqli_fetch_assoc($result)) {
        $hashedPwdCheck = password_verify($password, $row['password']);

        if ($hashedPwdCheck == false) {
          header("Location: index.html?login=invalidpw");
          exit();
        } elseif ($hashedPwdCheck == true) {
          $_SESSION['u_un']=$row['username'];
          $_SESSION['u_email']=$row['email'];
          $_SESSION['u_priv']=$row['priv'];
          header("Location: redirect.php");
          exit();
        }
      }
    }


} else {
  header("Location: index.html?login=error");
  exit();
}
ob_end_flush();
