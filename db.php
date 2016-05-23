<?php
	$servername = "localhost";
	$username = "admin_rf";
	$password = "TCSSlG5enL";
	$dbname = "admin_rf";

	// Create connection
	$conn = new mysqli($servername, $username, $password, $dbname);
	// Check connection
	if ($conn->connect_error) {
	    die("Connection failed: " . $conn->connect_error);
	}
?>