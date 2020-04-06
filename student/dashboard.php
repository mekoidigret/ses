<?php
	require '../config/initialize.inc';
	$session->check(Student::LEVEL);

	$header = new Header(array(
		'title' => 'Dashboard',
		'scripts' => array(
			'student.dashboard'
		)
	));
	$sql = 'SELECT * FROM '.Detail::TABLE_NAME.' WHERE user_id = '.$_SESSION['user_id'];
	$detail = Detail::findBySQL($sql);
	$photo = null;
	if($detail) {
		$photo = File::findByID($detail->photo_id);
	}

	require '../templates/header.inc';
	require '../templates/student.dashboard.inc';
	require '../templates/footer.inc';
?>