<?php
	require '../config/initialize.inc';
	
	$session->check(Admin::LEVEL);

	$sql = 'SELECT * FROM '.Student::TABLE_NAME.' '
		. 'WHERE id NOT IN ('.$_SESSION['user_id'].') '
		. 'AND access_level_id = '.Student::LEVEL;
	$students = Student::findAllBySQL($sql);
	require '../templates/admin.applicants.inc';
?>