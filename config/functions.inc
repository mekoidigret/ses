<?php
	function redirect($location) {
		header('Location: '.$location);
		exit;
	}

	function __autoload($class_name) {
		require_once 'class.'.$class_name.'.inc';
	}

	function ajax() {
		return isset($_SERVER['HTTP_X_REQUESTED_WITH']) && $_SERVER['HTTP_X_REQUESTED_WITH'] == 'XMLHttpRequest';
	}

	function protocol() {
		$protocol='http';
		if (isset($_SERVER['HTTPS']) && strtoupper($_SERVER['HTTPS']) == 'ON') {
	  		$protocol='https';
		}
		return $protocol;
	}

	function url($location = '') {
		global $config;
		$environment = '';
		switch($config['environment']) {
			case DEVELOPMENT:
				$environment = '/'.strtolower($config['title']['abbv']).'/';
				break;
			case PRODUCTION:
				$environment = '/';
				break;
		}
		return sprintf(
			"%s://%s%s%s",
	    	protocol(),
	    	$_SERVER['SERVER_NAME'],
	    	$environment,
	    	$location
	  	);
	}

	function selfUrl() {
		return htmlentities($_SERVER['PHP_SELF']);
	}
?>