<?php
	require '../config/initialize.inc';
	
	$session->check(Admin::LEVEL);

	$id = isset($_GET['id']) ? (int)$_GET['id'] : null;

	if(!$id) {
		exit;
	}

	$admin = Admin::findBy('id', $id);
	if(!$admin) {
		exit;
	}
	else {
		echo json_encode(array(
			'status' => $db->delete(Admin::TABLE_NAME, array('id' => $admin->id)),
			'message' => 'Admin '.htmlentities($admin->username).' deleted successfully.'
		));
		exit;
	}
?>