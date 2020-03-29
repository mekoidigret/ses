<?php
	require '../config/initialize.inc';
	
	$session->check(Admin::LEVEL);

	$sql = 'SELECT * FROM '.Admin::TABLE_NAME.' '
		. 'WHERE id NOT IN ('.$_SESSION['user_id'].') '
		. 'AND access_level_id = '.Admin::LEVEL;
	$admins = Admin::findAllBySQL($sql);
	require '../templates/admin.admins.inc';
?>