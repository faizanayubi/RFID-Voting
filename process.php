<?php

include 'db.php';

$card = $_GET['card'];
if (isset($card)) {
	$timestamp = strftime("%Y-%m-%d %H:%M:%S", time());

	$sql = "INSERT INTO rfids (card, created) VALUES ('{$card}', '{$timestamp}')";

	if ($conn->query($sql) === TRUE) {
	    echo "New record created successfully";
	} else {
	    echo "Error: " . $sql . "<br>" . $conn->error;
	}
}

$conn->close();

?>