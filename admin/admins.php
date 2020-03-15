<?php
	require '../config/initialize.inc';
	
	$session->check(Admin::LEVEL);

	$admins = Admin::findAllBySQL('SELECT * FROM '.Admin::TABLE_NAME.' WHERE id NOT IN ('.$_SESSION['user_id'].')');
	require '../templates/admin.admins.inc';
?>