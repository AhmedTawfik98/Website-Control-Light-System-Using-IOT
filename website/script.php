<?php

if (isset($_GET['status']))
{
	$myfile = fopen("status.txt","w");
	if ($_GET['status'] == 'on')
	{
		fwrite($myfile,'1');
		header ("location: on.html");
	}
	elseif($_GET['status'] == 'off')
	{
		fwrite($myfile,'0');
		header ("location: off.html");
	}
	fclose($myfile);
}



?>