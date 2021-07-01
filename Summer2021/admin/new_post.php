
     <?php
         $servername = "localhost";
         $username = "Shahadat";
         $password = "12345";
         $dbname = "e_library";
         // Create connection
         $conn = new mysqli($servername, $username, $password, $dbname);
         //Check connection
         if (!$conn) {
             die("Connection failed: " . mysqli_connect_error());
         }
         else{
            $sql = "SELECT id, book_id, approved FROM new_posts ";
            $result = mysqli_query($conn, $sql);
            echo "<div class='row blur-bg' style='margin-bottom: 18px;'>";
            if (mysqli_num_rows($result) > 0) {
                $book_counter = 1;
                while($row = $result->fetch_assoc()){
                    $book_id = $row['book_id'];
                    $sql = "SELECT * FROM books_list where id='$book_id'";
                    if($result_in = mysqli_query($conn, $sql)){
                        if($row_in = $result_in->fetch_assoc()){
                            $book_name = $row_in['Book_name'];
                            $Author_Names = $row_in['Authors_Name'];
                            $Category = $row_in['Category'];
                            $book_details = $row_in['book_details'];
                            $book_version = $row_in['book_version'];
                            $file_location = $row_in['file_location'];
                            $book_edition = $row_in['book_edition'];
                            $approved = $row_in['approved'];

                            echo '<div class="col-md-3 col-sm-6 ">';
                                echo '<div class="card bg-primary border border-success" >';
                                    echo '<img src="../img/book_1.jpg" class="card-img-top p-1 " style="height: 200px; width: auto;" alt="">';
                                    echo '<div class="card-body">';
                                        echo '<h5 class="card-title">'.$book_name.'</h5>';
                                        echo '<p class="card-text">'.$Author_Names.' '.$Category.' '.$book_version.' '. $book_edition.'</p>';
                                        echo '<a href="../'.$file_location.'" class="btn btn-success">Details</a>';
                                        echo '<a href="#" class="btn btn-warning ml-3">Approve</a>';
                                    echo'</div>
                                </div>
                            </div>';

                            if($book_counter %4==0){
                                echo "</div>";
                                echo "<div class='row blur-bg' style='margin-bottom: 18px;'>";
                            }
                        }
                        else{
                            echo "data fetch Failed!!!<br>";
                        }
                    }
                    else{
                        echo "query failed!!!!<br>";
                    }
                   $book_counter++;
                }
            }
            echo '</div>';
        }
    ?> 
<?php
    mysqli_close($conn);
?>


