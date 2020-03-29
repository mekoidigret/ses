<?php
	require '../config/initialize.inc';

	$session->check(Student::LEVEL);

	if(isset($_POST) && !empty($_POST)) {
        switch($_FILES['file_upload']['type']) {
            case 'image/jpeg':
                break;
            case 'image/jpg':
                break;
            case 'image/png':
                break;
            default:
                $session->message('Please upload an image.', 'warning');
                redirect('settings.php');
                break;
        }
        $file = new File();
        $file->_upload_dir = '..'.DS.'assets'.DS.'files'.DS.'images'.DS.'pps';
        $_POST['user_id'] = $_SESSION['user_id'];
        $file->attach($_FILES['file_upload']);
        if(empty($file->errors) && $file->save()) {
            $_POST['photo_id'] = $file->_id;
            $detail = new Detail($_POST);
            $address = new Address($_POST);
            $address->save();
            $detail->save();
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
    $detail = Detail::findBySQL('SELECT * FROM '.Detail::TABLE_NAME.' WHERE user_id = '.$_SESSION['user_id']);
    $address = Address::findBySQL('SELECT * FROM '.Address::TABLE_NAME.' WHERE user_id = '.$_SESSION['user_id']);
    $photo = null;
    if($detail) {
        $photo = File::findByID($detail->photo_id);
    }
	require '../templates/header.inc';
	require '../templates/student.settings.inc';
	require '../templates/footer.inc';
?>