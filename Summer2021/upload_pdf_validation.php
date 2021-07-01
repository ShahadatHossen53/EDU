<?php include 'header.php';?>
<?php include 'navbar.php';?>
<div class="main-bg ">
    <div class="row blur-bg " >

        <?php 


            if(isset($_POST['author'])){
                $author_name = $_POST['author'];
                echo "auther name is ". $author_name;
            }
            else{
                echo "author name not set<br>";
                $author_name = "";
            }

            if(isset($_POST['details'])){
                $details = $_POST['details'];
                echo "details is :". $details;
            }
            else{
                echo "details not set<br>";
                $details = "";
            }

            if(isset($_POST['category'])){
                $category = $_POST['category'];
            }
            else{
                echo "custom category set<br>";
                $category = $_POST['custom_category'];
            }


				$file_up = $_FILES['file'];
                $book_name = $_POST['book_name'];
                $edition = $_POST['book_edition'];
                
                
                
                $version = $_POST['version'];
               
                $file_location = '';
                $same_book = false;

                echo "Book name = $book_name <br>";
                echo "Author = $author_name <br>";
                echo "details = $details <br>";
                echo "version = $version <br>";
                echo "category = $category <br>";


                $servername = "localhost";
                $username = "Shahadat";
                $password = "12345";
                $dbname = "e_library";


                foreach($file_up['name'] as $position => $file_up_name){
					$ext = pathinfo($file_up_name, PATHINFO_EXTENSION);
					$file_up_tmp_name = $file_up['tmp_name'][$position];
					$up_name = $file_up_name;
                    $file_location = "Files/PDF/".$up_name;
                    break;
				}
                


                // Create connection
                $conn = new mysqli($servername, $username, $password, $dbname);
                // Check connection
                if (!$conn) {
                    die("Connection failed: " . mysqli_connect_error());
                }
                else{
                    

                    $sql = "SELECT Book_name, Category, book_edition FROM books_list WHERE Book_name='$book_name'";
                    $result = $conn->query($sql);
                    
                    if ($result->num_rows > 0) {

                        
                        echo "The same book already present in an database. <br> Please choose another book(pdf).";
                        $same_book = true;
                        

                        
                    }
                    else {
                        if(!$same_book){
                            $is_uploaded = false;
                            foreach($file_up['name'] as $position => $file_up_name){
                                $ext = pathinfo($file_up_name, PATHINFO_EXTENSION);
                                $file_up_tmp_name = $file_up['tmp_name'][$position];
                                
                                $up_name = $file_up_name;
                                
                                if($ext == 'pdf' || $ext == 'PDF' || $ext == 'Pdf'){
                                    $move = move_uploaded_file($file_up_tmp_name, "Files/PDF/".$up_name);
                                    
                                    $sql = "INSERT INTO books_list (Book_name, Authors_name, Category, book_details, book_version, file_location, book_edition, approved)
                                    VALUES ('$book_name', '$author_name', '$category', '$details', '$version', '$file_location','$edition' , '0')";
                                    if (mysqli_query($conn, $sql)) {
                                        echo "Congratulation! Your your pdf uploded successfully<br>";
                                        echo "You see the pdf after admin approve your post. Thank you<br>";

                                        $last_id = mysqli_insert_id($conn);
                                        echo $last_id;

                                        $sql = "INSERT INTO new_posts (book_id, approved)
                                                VALUES ('$last_id', '0')";
                                        
                                        
                                        if(mysqli_query($conn, $sql)){
                                            echo "New post added<br>";
                                        }
                                        else{
                                            echo "Failed to add new post<br>";
                                        }



                                        $is_uploaded = true;


                                    } else {
                                        echo "Something is error. Please try again<br>";
                                        echo "Error: " . $sql . "<br>" . mysqli_error($conn);
                                    }
                                }
                                else{
                                    echo "Your selected file is not a PDF file!<br>You can upload only PDF file";
                                }
                                break;
                            }
                            if($is_uploaded){
                                echo "<h2 class='text-success' >$up_name upload successful</h2>";
                            }
                            else{
                                echo "<h2 class='text-warning' >$up_name upload Failed</h2>";
                            }
                        }
                        
                        
                    }
                    
                }
                mysqli_close($conn);



                
                ?>
    </div>
</div>



<?php include 'footer.php';?>