<?php
ob_start();
require_once('connection.php');
if(isset($_POST) & !empty($_POST)){
	$username = $_POST['username'];
	$email = $_POST['email'];
	$password = $_POST['password'];
	$sql = "INSERT INTO `login`(`username`, `email`, `password`) VALUES ('$username','$email','$password')";
	$result = mysqli_query($connection, $sql);
}
if($result){
	header("Location: https://www.google.com/");
	exit;
}
ob_end_flush();
?>
<!DOCTYPE html>
<html>
<head>
	<title>Login & Registration</title>


<style>
    h1{
        font-family: impact;
        font-size: 50px;
    }
	p{
		font-family: verdana;
		font-size: 20px;
		border: 5px;
		padding: 5ex;
	}
	
    input[type=text], select {
        width: 20%;
        padding: 12px 20px;
        margin: 8px 0;
        display: inline-block;
        border: 1px solid black;
        border-radius: 4px;
        box-sizing: border-box;
        float: center;
    }
	
	.button {
		text-decoration: none;
        width: 9.9%;
        background-color: grey;
        color: white;
        padding: 14px 20px;
        margin: 8px 0;
        border: none;
        border-radius: 4px;
        cursor: pointer;
        font-family: verdana;
		font-size: 15px;
    }
    
    input[type=submit]:hover {
        background-color: lightgray;
    }
	.center {
	    margin: auto;
	    width: 80%;
	}
</style>
</head>

<body>
	
	<img src="images/haul.jpg" style="float:left; padding: 50px 100px;"/>

    <p style=padding:50px;>
        <h1>Ready to take control of your media backlog?</h1><br>
		<form method ="POST">
			<input type="text" name="username" placeholder="Username" required><br>
			<input type="text" name="email" placeholder="Email Address" required><br>
			<input type="text" name="password" placeholder="Password" required><br>
			<button class="button" type="submit">Register</button>
			<a  href="login.php" class="button"> Already Registered? </a>
		</form>
    </p>
     

</body>


</html>