<?php
    $servername = "localhost";
    $username = "Shahadat";
    $password = "12345";
    $dbname = "e_library";

    // Create connection
    $conn = new mysqli($servername, $username, $password, $dbname);
    // Check connection
    if (!$conn) {
        die("Connection failed: " . mysqli_connect_error());
    }

   // sql to create table
    $sql = "CREATE TABLE new_posts (
    id INT(6) UNSIGNED AUTO_INCREMENT PRIMARY KEY,
    book_id INT(6) UNSIGNED,
    approved int(2)
    )";
    
  //  // sql to create table
  //   $sql = "CREATE TABLE books_list (
  //   id INT(6) UNSIGNED AUTO_INCREMENT PRIMARY KEY,
  //   Book_name VARCHAR(80) NOT NULL,
  //   Authors_Name VARCHAR(100) NOT NULL,
  //   Category VARCHAR(50),
  //   book_details text(200),
  //   book_version  VARCHAR(10),
  //   file_location VARCHAR(50),
  //   book_edition VARCHAR(10),
  //   approved int(2)
  //   )";
    
    if (mysqli_query($conn, $sql)) {
      echo "Table MyGuests created successfully";
    } else {
      echo "Error creating table: " . mysqli_error($conn);
    }
    
    mysqli_close($conn);


?>