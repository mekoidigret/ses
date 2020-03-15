<?php
	require '../config/initialize.inc';

	$session->check(Admin::LEVEL);

	if(isset($_POST) && !empty($_POST)) {
        $file = new File();
        $file->upload_dir = 'assets/files/images/pps';
        $_POST['user_id'] = $_SESSION['user_id'];
        $detail = new Detail($_POST);
        $address = new Address($_POST);
        $detail->save();
        $address->save();
        $file = $file->attach($_FILES['file_upload']);
        if($file->save()) {
            $session->message('Settings saved successfully.', 'success');
            $location = 'dashboard.php';   
        }
        else {
            $message = '';

            foreach($file->errors as $error) {
                $message .= $error.'<br />';
            }
            $session->message($message, 'danger');
            $location = 'settings.php';
        }
        redirect($location);
    }

	$header = new Header(array(
		'title' => 'Settings'
	));

	require '../templates/header.inc';
	require '../templates/admin.settings.inc';
	require '../templates/footer.inc';
?>