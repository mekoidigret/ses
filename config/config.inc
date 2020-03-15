<?php
	defined('DS') 			? null : define('DS', DIRECTORY_SEPARATOR);
	defined('DEVELOPMENT') 	? null : define('DEVELOPMENT', '1999');
	defined('PRODUCTION') 	? null : define('PRODUCTION', '2020');
	defined('KEY') 			? null : define('KEY', 'FoW451kurO5O1uViY48ebIwEVAd3ti');

	$config = array(
		'db' => array(
			'dsn' => '',
			'host' => 'localhost',
			'username' => 'ses',
			'password' => KEY,
			'dbname' => 'ses',
			'driver' => ''
		),
		'title' => array(
			'abbv' => 'SES',
			'full' => 'Student Enrollment System'
		),
		'authors' => array(
			'John Michael Manlupig'
		),
		'environment' => DEVELOPMENT
	);

	date_default_timezone_set('Asia/Manila');
?>