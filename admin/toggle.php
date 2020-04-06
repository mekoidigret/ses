<?php
	require '../config/initialize.inc';

	$session->check(Admin::LEVEL);

	$id = isset($_GET['id']) ? base64_decode($_GET['id']) : redirect('dashboard.php');

	$request = Request::findBy('id', $id);

	if(!$request) {
		redirect('dashboard.php');
	}

	$sql = 'UPDATE '.Request::TABLE_NAME.' SET '
		. 'passed = 1 '
		. 'WHERE id = '.$db->quote($request->id);
	try {
		$db->query($sql);
		$message = 'Exam ID \''.$request->id.'\' passed successfully.';
		$session->message($message, 'success');
		redirect('dashboard.php');
	}
	catch(PDOException $e) {
		$session->message($e->getMessage(), 'danger');
		redirect('dashboard.php');
	}

?>