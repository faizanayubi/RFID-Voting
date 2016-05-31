<?php

include 'db.php';

$sql = "SELECT id FROM rfids";
$result = $conn->query($sql);
?>
<!DOCTYPE html>
<html>
<head>
	<title>RFID based voting system</title>
</head>
<body>
	<h1>Welcome to Online voting portal</h1>
	<table align="center" border="1">
		<tr>
			<td>Region</td>
			<td>Vote Count</td>
		</tr>
		<tr>
			<td>North Delhi</td>
			<td><?php echo $result->num_rows;?></td>
		</tr>
	</table>
</body>
</html>
<?php
if ($result->num_rows > 0) {
    // output data of each row
    while($row = $result->fetch_assoc()) {
        //echo "id: " . $row["id"]. "<br>";
    }
} else {
    //echo "0 results";
}
$conn->close();
?>