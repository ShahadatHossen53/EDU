<?php include '../header.php';?>
    <div class="main-bg">



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

    $email = $_POST["email"];
    $password = $_POST["password"];

    $sql = "SELECT email, pass FROM admin_list WHERE email='$email'";
    $result = mysqli_query($conn, $sql);
    if (mysqli_num_rows($result) > 0) {

        $row = $result->fetch_assoc();
        $mainPassword = $row['pass'];
        $inserted_password = sha1($password);
        if($mainPassword == $inserted_password){
            echo "<h1 class='index-text text-center'>Welcome, you successfully log in!!!</h1>";
            //echo "<script> location.replace('home.php') </script>";
            echo "<script> location.replace('dashbord.php') </script>";
            // echo "<a href='home.php' class='btn btn-success form-control'>Goto Home</a>";
        }
        else{
            echo "<h1 class='index-text text-center'>Wrong Password!</h1>";
        }



        
    }
    else {
    echo "Sorry, this account not found!!!";
    }
    mysqli_close($conn);
    
    ?>
    
</div>
<?php include '../footer.php';?>

