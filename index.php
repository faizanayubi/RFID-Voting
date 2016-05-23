<?php

include 'db.php';

$sql = "SELECT id FROM rfids";
$result = $conn->query($sql);

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