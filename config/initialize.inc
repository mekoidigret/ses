<?php
	require_once 'config.inc';
	require_once 'functions.inc';
	
	DEFINED('SITE_ROOT') ? null : DEFINE('SITE_ROOT', url());

	 $database = Database::getInstance();
	 $db =& $database;
	 $session = Session::getInstance();
?>