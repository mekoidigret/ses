<?php
	require '../config/initialize.inc';
	
	$session->check(Admin::LEVEL);

	$page = isset($_GET['page']) ? (int)$_GET['page'] : 1;
	$page = $page > 0 ? $page : 1;
	$per_page = 30;
	$total_count = $db->query('SELECT * FROM analytics')->rowCount();

	$pagination = new Pagination($page, $per_page, $total_count);

	$count = $pagination->offset() + 1;

	$sql = 'SELECT * FROM analytics '
		. 'ORDER BY year DESC '
		. 'LIMIT '.$pagination->per_page.' '
		. 'OFFSET '.$pagination->offset().' ';

	$result = $db->query($sql);
	$students = array();

	if($result->rowCount() > 0) {
		while($row = $result->fetch(PDO::FETCH_ASSOC)) {
			$students[] = (object)$row;
		}
	}
	else {
		$students = null;
	}

	require '../templates/admin.students.inc';
?>