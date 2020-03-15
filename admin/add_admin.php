<?php
	require '../config/initialize.inc';

	$session->check(Admin::LEVEL);

	if(isset($_POST) && !empty($_POST)) {
		$admin = new Admin($_POST);
		echo json_encode(array(
			'status' => $admin->save(),
			'message' => $admin->message
		));
		exit;
	}

	require '../templates/admin.add_admin.inc';
?>