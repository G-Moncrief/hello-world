<?php
ob_start();

session_start();
include_once 'connection.php';

$sql = "SELECT * FROM `library` WHERE uid='{$_SESSION['u_un']}'";
$result = mysqli_query($connection, $sql);

while ($row = mysqli_fetch_array($result)) {

}


/*
how to implement the dropdowns that modify specific elements:

echo the id into the onclick function of the dropdown and then run a script that modifies the status


<?php
    $connect = mysql_connect("localhost","root", "root");
    if (!$connect) {
        die(mysql_error());
    }
    mysql_select_db("apploymentdevs");
    $results = mysql_query("SELECT * FROM demo LIMIT 10");
    while($row = mysql_fetch_array($results)) {
    ?>
        <tr>
            <td><?php echo $row['Id']?></td>
            <td><?php echo $row['Name']?></td>
        </tr>

    <?php
    }
    ?>
    <td>
      <select  onchange="">
        <option disabled selected value>Change Status</option>
        <option value=>Shelved</option>
        <option value=>Reading</option>
        <option value=>Finished</option>
      </select>
    </td>

*/

 ?>
