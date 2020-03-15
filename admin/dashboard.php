<?php
	require '../config/initialize.inc';

	$session->check(Admin::LEVEL);

	$header = new Header(array(
		'title' => 'Dashboard',
		'scripts' => array(
			'admin.dashboard'
		)
	));

	require '../templates/header.inc';
	require '../templates/admin.dashboard.inc';
	require '../templates/footer.inc';
?>