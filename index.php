<?php
	require 'config/initialize.inc';

	if(isset($_POST) && !empty($_POST) && ajax()) {
		$user = new User($_POST);
		if($user->authenticate()) {
			$session->message($user->message, 'success');
			$session->login($user);
			switch($user->access_level_id) {
				case Admin::LEVEL:
					$location = 'admin/dashboard.php';
					break;
				case Student::LEVEL:
					$location = 'student/dashboard.php';
					break;
			}
			echo json_encode(array(
				'status' => true,
				'location' => $location
			));
			exit;
		}
		else {
			echo json_encode(array(
				'status' => false,
				'message' => $user->message
			));
			exit;
		}
	}

	$header = new Header(array(
		'title' => 'Welcome',
		'scripts' => array(
			'index'
		)
	));

	require 'templates/header.inc';
	require 'templates/index.inc';
	require 'templates/footer.inc';
?>