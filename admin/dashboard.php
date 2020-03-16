<?php
	require '../config/initialize.inc';

	$session->check(Admin::LEVEL);

	$header = new Header(array(
		'title' => 'Dashboard',
		'scripts' => array(
			'admin.dashboard'
		)
	));

	$detail = Detail::findBySQL('SELECT * FROM '.Detail::TABLE_NAME.' WHERE user_id = '.$_SESSION['user_id']);
	if($detail) {
		$photo = File::findByID($detail->photo_id);
	}

	require '../templates/header.inc';
	require '../templates/admin.dashboard.inc';
	require '../templates/footer.inc';
?>