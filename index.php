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
	<h1>Welcome to Online voting system</h1>
	<p></p>
</body>
</html>
<?php
if ($result->num_rows > 0) {
    // output data of each row
    while($row = $result->fetch_assoc()) {
        echo "id: " . $row["id"]. "<br>";
    }
} else {
    echo "0 results";
}
$conn->close();
?>