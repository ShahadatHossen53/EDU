<!-- 
<form action="" method="POST"> 


<table>
    <tr>
    
        <td>input</td>
        <td><select id="inputState" class="form-control" name="category" required oninput="myFunction()">
                <option selected disabled value="">Select Categroy</option>
                <option value="1">Category 1</option>
                <option value="2">Category 2</option>
                <option value="3">Category 3</option>
                <option value="4">Category 4</option>
                <option value="5">Category 5</option>
                <option value="6">Category 6</option>
                <option value="7">Category 7</option>
                <option value="custom" >Create Category</option>
            </select></td>
    </tr>
    <tr><td>Enter name</td>
    <td><input type="text" name="details"  id="custom_category" ></td>
   </tr>
   <tr>
    <td><input type="submit" name="details" id="inputAddress" value="Submit" ></td>
   </tr>
    
</table>
<p id='demo'></p>

</form>


<script>
function myFunction(event) {

    var x = document.getElementById("inputState").value;
    if(x=='custom'){
        document.getElementById("custom_category").setAttribute('required', 'true');
    }
    else{
        document.getElementById("custom_category").removeAttribute('required');
    }
}
</script> -->
<!-- <form action="" method="POST"> 
<table>
    <tr>
    
        <td>input</td>
        <td><select id="inputState" class="form-control" name="category" ">
                <option selected disabled value="">Select Categroy</option>
                <option value="1">Category 1</option>
                <option value="2">Category 2</option>
                <option value="3">Category 3</option>
                <option value="4">Category 4</option>
                <option value="5">Category 5</option>
                <option value="6">Category 6</option>
                <option value="7">Category 7</option>
            </select></td>
    </tr>
    <tr><td>Enter name</td>
    <td><input type="text" name="details"  id="custom_category" ></td>
   </tr>
   <tr>
    <td><input type="submit" name="submit" id="inputAddress" value="Submit" ></td>
   </tr>
    
</table>

</form>


<?php
//  $servername = "localhost";
//  $username = "Shahadat";
//  $password = "12345";
//  $dbname = "e_library";

//  $conn = new mysqli($servername, $username, $password, $dbname);

//   if(isset($_POST['submit'])){
//     $name = $_POST['category'];
//     $details = $_POST['details'];

//     echo "category = $name<br>";
//     echo "details = $details<br>";

//     if($conn){
//       $sql = "INSERT INTO new_posts (book_id, approved)
//       VALUES ('1', '0')";
//       if(mysqli_query($conn, $sql)){
//           echo "new post added<br>";
//       }
//       else{
//           echo "New post not added<br>";
//       }
//     }
//     else{
//       echo "Database not connected<br>";
//     }


    
//   }

?> -->
<form action="" method="post">
    <button name="btn1">Button 1</button>
    <button name="btn2">Button 2</button>
    <button name="btn3">Button 3</button>
    <button name="btn4">Button 4</button>
</form>
<?php 

    if(isset($_POST['btn1'])){
        echo "Button 1 clicked<br>";
    }

    if(isset($_POST['btn2'])){
        echo "Button 2 clicked<br>";
    }

    if(isset($_POST['btn3'])){
        echo "Button 3 clicked<br>";
    }

    if(isset($_POST['btn4'])){
        echo "Button 4 clicked<br>";
    }

?>


