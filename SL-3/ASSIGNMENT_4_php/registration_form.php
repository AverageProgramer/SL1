<!DOCTYPE html>
<html>
<head>
	
	<style>


		header
		{
			background-color: #cdcdf2;
    			color: #474544;
			  font-size: 32px;
			  font-weight: 700;
			  letter-spacing: 10px;
			  text-align: center;
			  padding: 10px;
			  text-transform: uppercase;

	    	}
	    	
	    button 
	     {
 			 overflow: visible;
		}	

		button, select 
		{
		  text-transform: none;
		}

		button, input, select, textarea 
		{
		  color: #5A5A5A;
		  font: inherit;
		  margin: 0;
		}

		input 
		{
		  line-height: normal;
		}

		textarea 
		{
		  overflow: auto;
		}
		
		form 
		{
			padding: 30px;
			margin: 50px 0;
			background-color: #F1F1F1;

		}

		input[type=text],select, textarea 
		{	
		    width: 50%;
		    padding: 12px;
		    border: 1px solid #ccc;
		    border-radius: 4px;
		    resize: vertical;
		}

		label 
		{
		    padding: 12px 12px 12px 0;
		    display: block;
		}		

		input[type=submit] , [type=reset] 
		{
		    width: 15%;
		    height: 5%;
		    background-color:  #cc00cc;
		    color: white;
		    padding: 14px 20px;
		    margin: 8px 0;
		    border: none;
		    border-radius: 4px;
		    cursor: pointer;
		    font-weight: 700;
		    letter-spacing: 10px;
		  	text-align: center;
		  padding: 20px;
		  text-transform: uppercase;
		}

		input[type=submit][type=reset]:hover 
		{
		    background-color:  #b300b3;
		}

		.container 
		{
		    border-radius: 5px;
		    background-color: #f2f2f2;
		    height: 150%;
		    padding: 20px;
		}
				
		.row:after 
		{
		    content: "";
		    display: table;
		    clear: both;
		}
		
		body
		{
			background-color: #a9a9f2;
		}
		
		table
		{
			border-spacing : 10px;
		}

	</style>
	<title>
		REGISTRATION FORM FOR Clash Wildcard
	</title>
</head>
<header>
	REGISTRATION FORM
</header>
<body>
	<?php
	// define variables and set to empty values
	
	$name =  $email = $team = $mobile = $country = $year = $temp = "" ;
	
	$placeholder_name="Your Name..."; 

	$nameErr = $teamErr = $emailErr =  $mobileErr =  $countryErr = $yearErr ="";
	
	if ($_SERVER["REQUEST_METHOD"] == "POST") 
	{
	  	if (empty($_POST["name"])) 
		{
	    		$nameErr = "Please enter your name .";
	  	}
		else 
		{
	    		$name = test_input($_POST["name"]);
	    		// check if name only contains letters and whitespace
	    		if (!preg_match("/^[a-zA-Z ]*$/",$name)) 
				{
	      			$nameErr = "Name must contain only letters and whitespaces."; 
	    		}
	    		else
	    		{
	    			$placeholder_name=$name;
	    		}
	  	}

		
	  
	  	if (empty($_POST["email"])) 
		{
	    		$emailErr = "Please enter your email.";
	  	} 
		else 
		{
	    		$email = test_input($_POST["email"]);
	    		// check if e-mail address is well-formed
	    		if (!filter_var($email, FILTER_VALIDATE_EMAIL)) 
				{
	     			$emailErr = "Invalid email format."; 
	    		}
	  	}
	  	
	    	if (empty($_POST["mobile"])) 
		{
	    		$mobileErr = "Please enter your Mobile no.";
	  	} 
		else 
		{
	    		$mobile = test_input($_POST["mobile"]);
	    		// check if mobile no. is well-formed
	    		if (!preg_match("/^[1-9]{1}[0-9]{9}$/",$mobile)) 
			{
	      			$mobileErr = "Invalid Mobile no."; 
	    		}
	  	}
	  	
	  	if (empty($_POST["team"]))
	  	{
	  		$teamErr = "Please enter your favourite team" ;
	  		$temp = "\n";
	  	}
	  	
	  	if (empty($_POST["country"]))
	  	{
	  		$countryErr = "Please enter your country name" ;
	  	}
	  	
	  	if (empty($_POST["year"]))
	  	{
	  		$yearErr = "Please Fill your Year of XP in football 	" ;
	  	}
	  	
	  	
	}
	function test_input($data) 
	{
	  $data = trim($data);
	  $data = stripslashes($data);
	  $data = htmlspecialchars($data);
	  return $data;
	}
	
?>


		<form name="registration"  action="<?php echo htmlspecialchars($_SERVER["PHP_SELF"]);?>" method="POST">
			<p><b>Registration for Football Club Fan Battle(FFCB)  </b>
			<br>	
			
			<p><h3>Description : </h3>
			<h4>A debate will be held amongst fans of all clubs, to decide the ultimate football club</h4>
								
			<div class="container">
				<h3> Name * :</h3>
				<input type="text" id="fname" name="name" placeholder="Your name.."
				value="<?php echo isset($_POST["name"]) ? $_POST["name"] : '';?>" >
				<span style="color:red;" class="error"><?php echo $nameErr;?></span><br>
				
				<h3> Email * :</h3>
				<input type="text" id="mail" name="email" placeholder="abcd@email.com"
				value="<?php echo isset($_POST["email"]) ? $_POST["email"] : '';?>" >
				<span style="color:red;" class="error"><?php echo $emailErr;?></span><br>
				
				<h3> Mobile Number * :</h3>
				<input type="text" id="no" name="mobile" placeholder="1234567890"
				value="<?php echo isset($_POST["mobile"]) ? $_POST["mobile"] : '';?>" >
				<span style="color:red;" class="error"><?php echo $mobileErr;?></span><br>
				
				<h3> Favourite Club * :</h3>
				<input type="text" id="no" name="team" placeholder="Football FC"
				value="<?php echo isset($_POST["team"]) ? $_POST["team"] : '';?>" >
				<span style="color:red;" class="error"><?php echo $teamErr;?></span><br>
				
				<h3> Country * :</h3>
				<input type="text" id="no" name="country" placeholder="cleeverland"
				value="<?php echo isset($_POST["country"]) ? $_POST["country"] : '';?>" >
				<span style="color:red;" class="error"><?php echo $countryErr;?></span><br>
				
				
				<h3> XP in football * :</h3>
				<label class="radio-inline">
	  			<input type="radio" name="year" value="1" id="4">1 &nbsp&nbsp&nbsp&nbsp
	  			<input type="radio" name="year" value="2" id="5">2 &nbsp&nbsp&nbsp&nbsp
	  			<input type="radio" name="year" value="3" id="6">3 &nbsp&nbsp&nbsp&nbsp
	  			<input type="radio" name="year" value="4" id="6">more than 3 &nbsp&nbsp&nbsp&nbsp
				<span style="color:red;" class="error"><?php echo $yearErr;?></span>
						
  			<br>
  			
  			<br>
  			<hr>
  			<br>
  			<b>Debate Details : </b><br>
  			<table><tr><td>Date : </td> <td>16/09/18 </td></tr>
  			<tr><td>Venue : </td><td>PICT </td><tr>
			</table>
  			<center>
  				 <input type="submit" name="Submit" value="Submit" >
  				 <input type="reset" name="Reset" value="reset" >
			<br>
				</center>
			
			</div>
		</form>
</body>

</html>
