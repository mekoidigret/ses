<?php
	require '../config/initialize.inc';

	$session->check(Admin::LEVEL);

	if(isset($_POST) && !empty($_POST)) {
		header('Content-type: application/json');
		$sql = 'INSERT INTO analytics (full_name, gender, status, school, year) '
			. 'VALUES (?,?,?,?,?)';
		$result = $db->prepare($sql);
		try {
			$result->execute([
				$_POST['full_name'],
				$_POST['gender'],
				$_POST['status'],
				$_POST['school'],
				$_POST['year']
			]);
			echo json_encode([
				'status' => true,
				'message' => 'Student added successfully.'
			]);
			exit;
		}
		catch(PDOException $e) {
			echo json_encode([
				'status' => false,
				'message' => $e->getMessage()
			]);
			exit;
		}
	}

	require '../templates/admin.add_student.inc';
?>