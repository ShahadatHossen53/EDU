<?php include '../header.php';?>
<?php include 'Admin_navbar.php';?>

    <div class="main-bg">
        <div class="row blur-bg " >
            <div class="col-9">
                <div class="col-12 index-text text-center p-5 text-shadow" id="myDIV" >
                    <h1 >New Posts</h1>
                </div>
                <?php include 'new_post.php';?>
                
            </div>
            <div class="col-3">
                <h1 class="index-text animation-text" style='background: #e083f74b; '>Functions</h1>
                <?php include 'functions.php';?>
            </div>
            
        </div>
        
    </div>


<?php include '../footer.php';?>
