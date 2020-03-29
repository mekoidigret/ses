<?php
	require '../config/initialize.inc';

	$session->check(Student::LEVEL);

	$sql = 'SELECT * FROM '.Request::TABLE_NAME.' '
		. 'WHERE user_id = '.$_SESSION['user_id'];
	$request = Request::findBySQL($sql);
	if($request) {
		$date = new DateTime($request->date);
		$request_year = new DateTime($date->format('Y'));
		$current_year = new DateTime(date('Y'));
		if($request_year >= $current_year) {
			$session->message('You have already sent a request this year. Please request one next year.', 'warning');
			redirect('dashboard.php');
		}
	}
	$sql = 'INSERT INTO '.Request::TABLE_NAME.' '
		. '(id, date, user_id, passed) '
		. 'VALUES (?,?,?,?)';
	$id = Request::generateExamID();
	$data = array(
		$id,
		date('Y-m-d'),
		$_SESSION['user_id'],
		0
	);
	$result = $db->prepare($sql);
	try {
		$result->execute($data);
		$session->message('Request sent successfully please copy your exam ID.', 'success');
		$_SESSION['exam_id'] = base64_encode($id);
		redirect('dashboard.php');
	}
	catch(PDOException $exception) {
		$session->message($exception->getMessage(), 'danger');
		redirect('dashboard.php');
	}
?>