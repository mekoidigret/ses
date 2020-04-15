<?php
	require 'config/initialize.inc';
	
	if(isset($_POST) && !empty($_POST)) {
		$student = new Student($_POST);
		if($student->save()) {
			$session->message($student->message, 'success');
			$data = array(
				'id' => $student->id,
				'access_level_id' => $student->access_level_id,
				'username' => $student->username,
			);
			$session->login($data);
			$location = 'student/dashboard.php';
			echo json_encode(array(
				'status' => true,
				'location' => $location
			));
			exit;
		}
		else {
			echo json_encode(array(
				'status' => false,
				'message' => $student->message
			));
			exit;
		}
	}

	$header = new Header(array(
		'title' => 'Register',
		'scripts' => array(
			'register'
		)
	));

	require 'templates/header.inc';
	require 'templates/register.inc';
	require 'templates/footer.inc';
?>