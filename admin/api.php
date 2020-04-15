<?php

	require '../config/initialize.inc';

	$data = array();

	// JS -> data.enrolled.year['2015']
	// JS -> data.dropped.year['2015']

	for($i = 15; $i <= 20; $i++) {
		$year = '20'.$i;
		$sql = 'SELECT * FROM analytics '
			. 'WHERE year = '.$year.' '
			. 'AND status = '.$db->quote('Enrolled');
		$result = $db->query($sql);
		$data['enrolled'][$year] = $result->rowCount();
	}

	for($i = 15; $i <= 20; $i++) {
		$year = '20'.$i;
		$sql = 'SELECT * FROM analytics '
			. 'WHERE year = '.$year.' '
			. 'AND status = '.$db->quote('Dropped');
		$result = $db->query($sql);
		$data['dropped'][$year] = $result->rowCount();
	}

	// for($i = 15; $i <= 20; $i++) {
	// 	$year = '20'.$i;
	// 	$sql = 'SELECT * FROM analytics '
	// 		. 'WHERE year = '.$year.' '
	// 		. 'AND status = '.$db->quote('Applicant');
	// 	$result = $db->query($sql);
	// 	$data['applicant'][$year] = $result->rowCount();
	// }
	
	header('Content-type: application/json');
	echo json_encode($data);
?>