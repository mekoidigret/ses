<?php
	require '../config/initialize.inc';

	$session->check(Admin::LEVEL);

	$header = new Header(array(
		'title' => 'Dashboard',
		'scripts' => array(
			'admin.dashboard'
		)
	));

	$detail = Detail::findBy('user_id', $_SESSION['user_id']);
	$photo = null;
	if($detail) {
		$photo = File::findByID($detail->photo_id);
	}

	require '../templates/header.inc';
	require '../templates/admin.dashboard.inc';
	require '../templates/footer.inc';
?>