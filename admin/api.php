<?php

	require '../config/initialize.inc';

	$data = array();

	// JS -> data.enrolled.year['2015']
	// JS -> data.dropped.year['2015']

	$sql = 'SELECT * FROM '.User::TABLE_NAME.' '
	. 'WHERE YEAR(modified) = 2020 '
	. 'AND status = '.$db->quote('Enrolled');
	$result = $db->query($sql);
	$data['enrolled']['2020'] = $result->rowCount();

	$sql = 'SELECT * FROM '.User::TABLE_NAME.' '
	. 'WHERE YEAR(modified) = 2020 '
	. 'AND status = '.$db->quote('Dropped');
	$result = $db->query($sql);
	$data['dropped']['2020'] = $result->rowCount();

	$sql = 'SELECT * FROM '.User::TABLE_NAME.' '
	. 'WHERE YEAR(modified) = 2020 '
	. 'AND status = '.$db->quote('Applicant');
	$result = $db->query($sql);
	$data['applicant']['2020'] = $result->rowCount();

	for($i = 5; $i <= 9; $i++) {
		$year = '201'.$i;
		$sql = 'SELECT * FROM '.User::TABLE_NAME.' '
			. 'WHERE YEAR(modified) = '.$year.' '
			. 'AND status = '.$db->quote('Enrolled');
		$result = $db->query($sql);
		$data['enrolled'][$year] = $result->rowCount();
	}

	for($i = 5; $i <= 9; $i++) {
		$year = '201'.$i;
		$sql = 'SELECT * FROM '.User::TABLE_NAME.' '
			. 'WHERE YEAR(modified) = '.$year.' '
			. 'AND status = '.$db->quote('Dropped');
		$result = $db->query($sql);
		$data['dropped'][$year] = $result->rowCount();
	}

	for($i = 5; $i <= 9; $i++) {
		$year = '201'.$i;
		$sql = 'SELECT * FROM '.User::TABLE_NAME.' '
			. 'WHERE YEAR(modified) = '.$year.' '
			. 'AND status = '.$db->quote('Applicant');
		$result = $db->query($sql);
		$data['applicant'][$year] = $result->rowCount();
	}
	header('Content-type: application/json');
	echo json_encode($data);
?>