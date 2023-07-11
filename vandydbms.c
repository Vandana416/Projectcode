<?php
session_start();
error_reporting(0);
include('includes/config.php');
if($_SESSION['alogin']!=''){
$_SESSION['alogin']='';
}
if(isset($_POST['login']))
{
$username=$_POST['username'];
$password=md5($_POST['password']);
$sql ="SELECT UserName,Password FROM admin WHERE UserName=:username and
Password=:password";
$query= $dbh -> prepare($sql);
$query-> bindParam(':username', $username, PDO::PARAM_STR);
$query-> bindParam(':password', $password, PDO::PARAM_STR);
$query-> execute();
$results=$query->fetchAll(PDO::FETCH_OBJ);
if($query->rowCount() > 0)
{
$_SESSION['alogin']=$_POST['username'];
echo "<script type='text/javascript'> document.location ='admin/dashboard.php';
</script>";
} else{
echo "<script>alert('Invalid Details');</script>";
Online Library Management 2020-21
Sree Venkateshwara College Of Science & Management Studies Page 19
}
}
?>
<!DOCTYPE html>
<html xmlns="http://www.w3.org/1999/xhtml">
<head>
 <meta charset="utf-8" />
 <meta name="viewport" content="width=device-width, initial-scale=1, maximumscale=1" />
 <meta name="description" content="" />
 <meta name="author" content="" />
 <title>Online Library Management System</title>
 <!-- BOOTSTRAP CORE STYLE -->
 <link href="assets/css/bootstrap.css" rel="stylesheet" />
 <!-- FONT AWESOME STYLE -->
 <link href="assets/css/font-awesome.css" rel="stylesheet" />
 <!-- CUSTOM STYLE -->
 <link href="assets/css/style.css" rel="stylesheet" />
 <!-- GOOGLE FONT -->
 <link href='http://fonts.googleapis.com/css?family=Open+Sans' rel='stylesheet'
type='text/css' />
</head>
<body>
 <!------MENU SECTION START-->
<?php include('includes/header.php');?>
<!-- MENU SECTION END-->
<div class="content-wrapper">
<div class="container">
Online Library Management 2020-21
Sree Venkateshwara College Of Science & Management Studies Page 20
<div class="row pad-botm">
<div class="col-md-12">
<h4 class="header-line">ADMIN LOGIN FORM</h4>
</div>
</div>

<!--LOGIN PANEL START-->
<div class="row">
<div class="col-md-6 col-sm-6 col-xs-12 col-md-offset-3" >
<div class="panel panel-info">
<div class="panel-heading">
LOGIN FORM
</div>
<div class="panel-body">
<form role="form" method="post">
<div class="form-group">
<label>Enter Username</label>
<input class="form-control" type="text" name="username" autocomplete="off" required
/>
</div>
<div class="form-group">
<label>Password</label>
<input class="form-control" type="password" name="password" autocomplete="off"
required />
</div>
<button type="submit" name="login" class="btn btn-info">LOGIN </button>
</form>
</div>
Online Library Management 2020-21
Sree Venkateshwara College Of Science & Management Studies Page 21
</div>
</div>
</div>
<!---LOGIN PABNEL END-->

 </div>
 </div>
 <!-- CONTENT-WRAPPER SECTION END-->
<?php include('includes/footer.php');?>
 <!-- FOOTER SECTION END-->
 <script src="assets/js/jquery-1.10.2.js"></script>
 <!-- BOOTSTRAP SCRIPTS -->
 <script src="assets/js/bootstrap.js"></script>
 <!-- CUSTOM SCRIPTS -->
 <script src="assets/js/custom.js"></script>
</script>
</body>
</html>
User Signup
ca<?php
session_start();
include('includes/config.php');
error_reporting(0);
if(isset($_POST['signup']))
{

Online Library Management 2020-21
Sree Venkateshwara College Of Science & Management Studies Page 22
//Code for student ID
$count_my_page = ("studentid.txt");
$hits = file($count_my_page);
$hits[0] ++;
$fp = fopen($count_my_page , "w");
fputs($fp , "$hits[0]");
fclose($fp);
$StudentId= $hits[0];
$fname=$_POST['fullanme'];
$mobileno=$_POST['mobileno'];
$email=$_POST['email'];
$password=md5($_POST['password']);
$status=1;
$sql="INSERT INTO
tblstudents(StudentId,FullName,MobileNumber,EmailId,Password,Status)
VALUES(:StudentId,:fname,:mobileno,:email,:password,:status)";
$query = $dbh->prepare($sql);
$query->bindParam(':StudentId',$StudentId,PDO::PARAM_STR);
$query->bindParam(':fname',$fname,PDO::PARAM_STR);
$query->bindParam(':mobileno',$mobileno,PDO::PARAM_STR);
$query->bindParam(':email',$email,PDO::PARAM_STR);
$query->bindParam(':password',$password,PDO::PARAM_STR);
$query->bindParam(':status',$status,PDO::PARAM_STR);
$query->execute();
$lastInsertId = $dbh->lastInsertId();
if($lastInsertId)
{
echo '<script>alert("Your Registration successfull and your student id is
"+"'.$StudentId.'")</script>';
}
Online Library Management 2020-21
Sree Venkateshwara College Of Science & Management Studies Page 23
else
{
echo "<script>alert('Something went wrong. Please try again');</script>";
}
}
?>
<!DOCTYPE html>
<html xmlns="http://www.w3.org/1999/xhtml">
<head>
 <meta charset="utf-8" />
 <meta name="viewport" content="width=device-width, initial-scale=1, maximumscale=1" />
 <meta name="description" content="" />
 <meta name="author" content="" />
 <!--[if IE]>
 <meta http-equiv="X-UA-Compatible" content="IE=edge,chrome=1">
 <![endif]-->
 <title>Online Library Management System | Student Signup</title>
 <!-- BOOTSTRAP CORE STYLE -->
 <link href="assets/css/bootstrap.css" rel="stylesheet" />
 <!-- FONT AWESOME STYLE -->
 <link href="assets/css/font-awesome.css" rel="stylesheet" />
 <!-- CUSTOM STYLE -->
 <link href="assets/css/style.css" rel="stylesheet" />
 <!-- GOOGLE FONT -->
 <link href='http://fonts.googleapis.com/css?family=Open+Sans' rel='stylesheet'
type='text/css' />
<script type="text/javascript">
Online Library Management 2020-21
Sree Venkateshwara College Of Science & Management Studies Page 24
function valid()
{
if(document.signup.password.value!= document.signup.confirmpassword.value)
{
alert("Password and Confirm Password Field do not match !!");
document.signup.confirmpassword.focus();
return false;
}
return true;
}
</script>
<script>
function checkAvailability() {
$("#loaderIcon").show();
jQuery.ajax({
url: "check_availability.php",
data:'emailid='+$("#emailid").val(),
type: "POST",
success:function(data){
$("#user-availability-status").html(data);
$("#loaderIcon").hide();
},
error:function (){}
});
}
</script>
</head>
<body>
 <!------MENU SECTION START-->
Online Library Management 2020-21
Sree Venkateshwara College Of Science & Management Studies Page 25
<?php include('includes/header.php');?>
<!-- MENU SECTION END-->
 <div class="content-wrapper">
 <div class="container">
 <div class="row pad-botm">
 <div class="col-md-12">
 <h4 class="header-line">User Signup</h4>

 </div>
 </div>
 <div class="row">

<div class="col-md-9 col-md-offset-1">
 <div class="panel panel-danger">
 <div class="panel-heading">
 SINGUP FORM
 </div>
 <div class="panel-body">
 <form name="signup" method="post" onSubmit="return valid();">
<div class="form-group">
<label>Enter Full Name</label>
<input class="form-control" type="text" name="fullanme" autocomplete="off" required
/>
</div>
<div class="form-group">
<label>Mobile Number :</label>
Online Library Management 2020-21
Sree Venkateshwara College Of Science & Management Studies Page 26
<input class="form-control" type="text" name="mobileno" maxlength="10"
autocomplete="off" required />
</div>

<div class="form-group">
<label>Enter Email</label>
<input class="form-control" type="email" name="email" id="emailid"
onBlur="checkAvailability()" autocomplete="off" required />
 <span id="user-availability-status" style="font-size:12px;"></span>
</div>
<div class="form-group">
<label>Enter Password</label>
<input class="form-control" type="password" name="password" autocomplete="off"
required />
</div>
<div class="form-group">
<label>Confirm Password </label>
<input class="form-control" type="password" name="confirmpassword"
autocomplete="off" required />
</div>
<button type="submit" name="signup" class="btn btn-danger" id="submit">Register
Now </button>
 </form>
 </div>
 </div>
 </div>
 </div>
Online Library Management 2020-21
Sree Venkateshwara College Of Science & Management Studies Page 27
 </div>
 </div>
 <!-- CONTENT-WRAPPER SECTION END-->
 <?php include('includes/footer.php');?>
 <script src="assets/js/jquery-1.10.2.js"></script>
 <!-- BOOTSTRAP SCRIPTS -->
 <script src="assets/js/bootstrap.js"></script>
 <!-- CUSTOM SCRIPTS -->
 <script src="assets/js/custom.js"></script>
</body>
</html>
User Login
<?php
session_start();
error_reporting(0);
include('includes/config.php');
if($_SESSION['login']!=''){
$_SESSION['login']='';
}
if(isset($_POST['login']))
{
$email=$_POST['emailid'];
$password=md5($_POST['password']);
$sql ="SELECT EmailId,Password,StudentId,Status FROM tblstudents WHERE
EmailId=:email and Password=:password";
$query= $dbh -> prepare($sql);
$query-> bindParam(':email', $email, PDO::PARAM_STR);
$query-> bindParam(':password', $