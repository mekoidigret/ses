<?php
	require '../config/initialize.inc';

	$current_page = isset($_GET['page']) ? (int)$_GET['page'] : 1;
	$per_page = 7;
	$total_count = Request::countAll();

	$pagination = new Pagination($current_page, $per_page, $total_count);
	$sql = $pagination->generateSQL(Request::TABLE_NAME, array(
		'user_id' => $_SESSION['user_id']
	));
	
	$requests = Request::findAllBySQL($sql);

	require '../templates/student.requests.inc';
?>