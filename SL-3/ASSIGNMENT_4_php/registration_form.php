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
			  padding: 20px;
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
		    width: 100%;
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

		input[type=submit]
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

		input[type=submit]:hover
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

	$name =  $email = $team = $mobile = $country = $year = $temp = $url = "" ;

	$placeholder_name="Your Name...";

	$nameErr = $teamErr = $emailErr =  $mobileErr =  $countryErr = $yearErr = $urlErr = "";

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

	  	if (!empty($_POST["url"]))
	  	{
	  		$url = test_input($_POST["url"]);
	  		if (! (filter_var($url, FILTER_VALIDATE_URL)) )
	  		{
				$urlErr = "Please enter a valid url 	" ;
			}
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
			<p><b>Registration for Football Club Fan Battle(FFCB)  </b> </p>
			<br>

			<p><h3>Description : </h3>
			<h4>A debate will be held amongst fans of all clubs, to decide the ultimate football club</h4><br>

			<div class="container">
				<h3> Name </h3>
				<input type="text" id="fname" name="name" placeholder="Your name..">
				<span style="color:red;" class="error"><?php echo $nameErr;?></span><br>

				<h3> Email </h3>
				<input type="text" id="mail" name="email" placeholder="abcd@email.com">
				<span style="color:red;" class="error"><?php echo $emailErr;?></span><br>

				<h3> Mobile Number </h3>
				<input type="text" id="no" name="mobile" placeholder="1234567890">
				<span style="color:red;" class="error"><?php echo $mobileErr;?></span><br>

				<h3> Favourite Club </h3>
				<input type="text" id="no" name="team" placeholder="Football FC">
				<span style="color:red;" class="error"><?php echo $teamErr;?></span><br>

				<h3> Country </h3>
				<input type="text" id="no" name="country" placeholder="cleeverland">
				<span style="color:red;" class="error"><?php echo $countryErr;?></span><br>

				<h3> Blog </h3>
				<h5>Enter URL of your blog(if any)</h5>
				<input type="text" id="no" name="url" placeholder="https://www.abcd.com">
				<span style="color:red;" class="error"><?php echo $urlErr;?></span><br>


				<h3> XP in football </h3>
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
			<br><h4>Kindly Refresh the form to reset</h4>
				</center>

			</div>
		</form>
</body>

</html>
