<?php

$hostname = "localhost";
$username = "root";
$password = "";
$database = "sensor_db";

$conn = mysqli_connect($hostname, $username, $password, $database);


if (!$conn)
{
    die("connection failed: " . mysqli_connect_error());
}

echo "Database connection is successful\n";

$t = $_POST["temperature"];
$h = $_POST["humidity"];


$statement = "INSERT INTO dht11 (temperature, humidity) VALUES (".$t.", ".$h.")";

if (mysqli_query($conn, $statement))
{
    echo "success";
}
else echo "failed " . $statement . "<br>" . mysqli_error($conn);

?>