<?php
	require '../config/initialize.inc';

	// API Code
	// ---------------------------------------------------------------------------------------
	/**
	 * 'Dummy Data Insertion Code'
	 * 
	 * NOTE: RUN THIS CODE ONLY ONCE. OR ELSE YOUR DATABASE WILL HAVE TOO MUCH DATA.
	 * Tanggalin mo to lahat pagkatapos nito insert.
	 * 
	 * Pwede mo din i-edit yung names ng mga schools, dagdagan or bawasan. 
	 * Mag aadjust automatic yung code.
	 * 
	 */
	$genders = ['Male', 'Female'];

	$schools = [
		'Iloilo State College of Fisheries',
		'University of the Philippines',
		'Central Philippine University',
		'University of San Agustin',
		'STI',
		'University of Iloilo',
		'Polytechnic University of the Philippines',
	];

	$statuses = ['Enrolled', 'Dropped'];

	for($i = 15; $i <= 20; $i++) {
		for($x = 0; $x <= 1000; $x++) {
			$full_name = bin2hex(random_bytes(ceil(13 / 2)));
			$gender = $genders[rand(0,1)];
			$school = $schools[rand(0,(count($schools) - 1))];
			$status = $statuses[rand(0,(count($statuses) - 1))];
			$year = '20'.$i;
			$result = $db->prepare('INSERT INTO analytics (full_name, gender, school, year, status) VALUES (?,?,?,?,?)');
			$result->execute([
				$full_name,
				$gender,
				$school,
				$year,
				$status
			]);
		}
	}
	exit;
	// ---------------------------------------------------------------------------------------
?>