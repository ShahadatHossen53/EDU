<?php include 'header.php'; ?>
        <div class="main-bg">
            <div class="row p-5">
                <div class="col-lg-7 m-auto">
                    <h1 class="text-center text-white index-text">Create your account for free!</h1>
                </div>
                <div class="col-lg-5 " >
                    <div class="contact-form">
                        <form action="signupValidation.php" class="my-form" method="POST">
                            <div class="form-group">
                                <div class="row">
                                    <div class="col-6">
                                        <label for="fname">First Name</label>
                                        <input type="text" name="fname" class="form-control" required>
                                    </div>
                                    <div class="col-6">
                                        <label for="lname">Last Name</label>
                                        <input type="text" name="lname" class="form-control" required>
                                    </div>
                                </div>
                            </div>
                            <div class="form-group">
                                <label for="email">Your Email Address</label>
                                <input type="email" name="email" class="form-control" required>
                            </div>


                            <div class="form-group">
                                <label for="password">Password</label>
                                <input type="password" name="password" class="form-control" required>
                            </div>
                            <div class="form-group">
                                <label for="password">Confirm Password</label>
                                <input type="password" name="cpassword" class="form-control" required>
                            </div>

                            <div class="row text-center mb-2">
                                <div class="col-md-6">
                                    <div class="form-check">
                                        <input class="form-check-input" type="radio" name="gender" id="gender" value="Male" required>
                                        <label class="form-check-label" for="gender">
                                          Male
                                        </label>
                                      </div>
                                </div>
                                <div class="col-md-6">
                                    <div class="form-check">
                                        <input class="form-check-input" type="radio" name="gender" id="gender" value="Female" required>
                                        <label class="form-check-label" for="gender">
                                          Female
                                        </label>
                                      </div>
                                </div>
                            </div>
                            <div class="form-group">
                                <input type="submit" value="Sign Up" class="btn btn-success form-control">
                                
                            </div>
                            <div class="text-center py-3">
                                <p>Already have an account? <a href="index.html" class="text-center btn btn-primary log-in" >Log in</a></p>
                            </div>
                        </form>
                    </div>
                </div>
            </div>
            <div class="row">
                <div class="col-6 my-block"><h1>Hello</h1></div>
                <div class="col-6 my-block"><h1>Hello</h1></div>
                <div class="col-6 my-block"><h1>Hello</h1></div>
                <div class="col-6 my-block"><h1>Hello</h1></div>
            </div>
        </div>

<?php include 'footer.php'; ?>