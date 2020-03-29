<?php
	require '../config/initialize.inc';

	$sql = 'SELECT * FROM '.Request::TABLE_NAME.' '
		. 'WHERE user_id = '.$_SESSION['user_id'].' '
		. 'ORDER BY date DESC';
	$requests = Request::findAllBySQL($sql);

	require '../templates/student.requests.inc';
?>