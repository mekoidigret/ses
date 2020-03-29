<?php
	class Session {

		public $user_id;
		public $user_access_level_id;
		public $user_username;
		private static $_instance = null;

		private static $_keys = array(
			'user_id',
			'user_access_level_id',
			'user_username'
		);

		public function __construct() {
			session_start();
			foreach(self::$_keys as $property) {
				if(isset($_SESSION[$property])) {
					$this->$property = $_SESSION[$property];
				}
			}
			return $this;
		}

		public static function getInstance() {
			if(!self::$_instance) {
				self::$_instance = new self();
			}
			return self::$_instance;
		}

		public function message($msg='', $mode='info') {
			if(!empty($msg)) {
				// Set
				$_SESSION['message']  = '<div id="message-pane" class="rounded alert alert-'.$mode.'">';
				$_SESSION['message'] .= $msg;
				$_SESSION['message'] .= '</div>';
				unset($msg);
			}
			else {
				if(isset($_SESSION['message'])) {
					// Get
					$message  = '<div class="toast fade show" role="alert" aria-live="assertive" id="message-toast" aria-atomic="true">';
						$message .= '<div class="toast-header">';
							$message .= '<strong class="mr-auto">Message</strong>';
							$message .= '<small>Just now</small>';
							$message .= '<button class="ml-2 mb-1 close" aria-label="Close" type="button" data-target="#message-toast" data-dismiss="toast">';
								$message .= '<span aria-hidden="true">×</span>';
							$message .= '</button>';
						$message .= '</div>';
						$message .= '<div class="toast-body">';
							$message .= $_SESSION['message'];
						$message .= '</div>';
					$message .= '</div>';
					unset($_SESSION['message']);
					return $message;
				}
				else {
					return '<div id="message-pane"></div>';
				}
			}
		}

		public function login($user) {
			foreach($user as $key => $value) {
				$key = 'user_'.$key;
				$this->$key = $value;
				$_SESSION[$key] = $value;
			}
		}

		public function logout() {
			foreach($_SESSION as $key => $value) {
				unset($_SESSION[$key]);
				$this->$key = null;
				unset($this->$key);
			}
		}

		public function check($level) {
			if(!isset($_SESSION['user_id'])) {
				if(ajax()) {
					exit;
				}
				else {
					$this->message('Please login first.', 'warning');
					redirect('../index.php');
				}
			}
			else if($_SESSION['user_access_level_id'] != $level) {
				$this->logout();
				if(ajax()) {
					exit;
				}
				else {
					redirect('../index.php');
				}
			}
		}
	}
?>