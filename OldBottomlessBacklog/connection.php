<?php
$connection = mysqli_connect('localhost:3306','gmonc_admin','DBAdmin');
if(!connection){
	die("Database Connection Failed" . mysqli_error($connection));
}
$select_db=mysqli_select_db($connection,'gmonc_bbacklog');
if(!select_db){
	die("Database Selection Failed" . mysqli_error($connection));
}
?>
