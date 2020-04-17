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
		$data['enrolled'][$year] = $db->query($sql)->rowCount();
		// --------------------------------------------------------------
		$sql = 'SELECT * FROM analytics '
			. 'WHERE year = '.$year.' '
			. 'AND status = '.$db->quote('Enrolled').' '
			. 'AND gender = '.$db->quote('Male');
		$data['male']['enrolled'][$year] = $db->query($sql)->rowCount();
		// --------------------------------------------------------------
		$sql = 'SELECT * FROM analytics '
			. 'WHERE year = '.$year.' '
			. 'AND status = '.$db->quote('Enrolled').' '
			. 'AND gender = '.$db->quote('Female');
		$data['female']['enrolled'][$year] = $db->query($sql)->rowCount();
		// --------------------------------------------------------------
		$sql = 'SELECT * FROM analytics '
			. 'WHERE year = '.$year.' '
			. 'AND status = '.$db->quote('Dropped');
		$data['dropped'][$year] = $db->query($sql)->rowCount();
		// --------------------------------------------------------------
		$sql = 'SELECT * FROM analytics '
			. 'WHERE year = '.$year.' '
			. 'AND status = '.$db->quote('Dropped').' '
			. 'AND gender = '.$db->quote('Male');
		$data['male']['dropped'][$year] = $db->query($sql)->rowCount();
		// --------------------------------------------------------------
		$sql = 'SELECT * FROM analytics '
			. 'WHERE year = '.$year.' '
			. 'AND status = '.$db->quote('Dropped').' '
			. 'AND gender = '.$db->quote('Female');
		$data['female']['dropped'][$year] = $db->query($sql)->rowCount();
		// --------------------------------------------------------------
	}
	
	header('Content-type: application/json');
	echo json_encode($data);
	exit;
?>