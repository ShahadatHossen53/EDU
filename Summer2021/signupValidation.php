
<?php include 'header.php';?>

<?php

    $servername = "localhost";
    $username = "Shahadat";
    $password = "12345";
    $dbname = "e_library";

    echo '<div class="main-bg">';
    // Create connection
    $conn = new mysqli($servername, $username, $password, $dbname);
    // Check connection
    if (!$conn) {
        die("Connection failed: " . mysqli_connect_error());
    }
    else{
        $email = $_POST["email"];

        $sql = "SELECT email FROM accounts WHERE email='$email'";
        $result = $conn->query($sql);
        echo "<h1 class='index-text text-center'>";
        if ($result->num_rows > 0) {
            
            echo "This email address already used in an another account. <br> Please choose another email address or";
            echo "<a href='index.html' class='text-center btn btn-primary log-in' >Log in</a> your account";

            
        }
        else {
            $password = $_POST["password"];
            $cpassword = $_POST["cpassword"];
            if($password != $cpassword){
                echo "Your password are not matched!! Please enter the same password to confirm password section";
            }
            else{
                $f_name = $_POST['fname'];
                $l_name = $_POST['lname'];
                $gender = $_POST['gender'];
                $password = sha1($password);
                $sql = "INSERT INTO accounts (firstname, lastname, email, pass, gender)
                        VALUES ('$f_name', '$l_name', '$email', '$password', '$gender')";
                if (mysqli_query($conn, $sql)) {
                    echo "Congratulation! Your account created successfully";
                    echo "<script> location.replace('home.php') </script>";

                  } else {
                    echo "Something is error. Please try again<br>";
                    echo "Error: " . $sql . "<br>" . mysqli_error($conn);
                  }
            }
        }
    }
    mysqli_close($conn);
    echo "</h1></div>";
    

    


?>
<?php include 'footer.php';?>

