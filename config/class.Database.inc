<?php
	class Database {
		private $_connection = null;
		private static $_instance = null;
		private static $_username;
		private static $_password;
		private static $_dbname;
		private static $_host;

		public function __construct() {
			global $config;
			self::$_username = $config['db']['username'];
			self::$_password = $config['db']['password'];
			self::$_dbname	 = $config['db']['dbname'];
			self::$_host 	 = $config['db']['host'];
			
			try {
				$this->_connection = new PDO('mysql:host='.self::$_host.';dbname='.self::$_dbname, self::$_username, self::$_password);
				$this->_connection->setAttribute(PDO::ATTR_ERRMODE, PDO::ERRMODE_EXCEPTION);
				$this->_connection->setAttribute(PDO::ATTR_EMULATE_PREPARES, 0);
			}
			catch(PDOException $e) {
				die($e->getMessage());
			}
		}

		public static function getInstance() {
				if(!self::$_instance) {
					self::$_instance = new self();
				}
				return self::$_instance;
		}

		public function query($sql) {
			return $this->_connection->query($sql);
		}

		public function prepare($sql) {
			return $this->_connection->prepare($sql);
		}

		public function quote($string) {
			return $this->_connection->quote($string);
		}

		public function insert($tb, $params = array()) {
			$data = array();
			$sql  = "INSERT INTO " . $tb . " (";
			foreach($params as $key => $value) {
				$sql .= $key . ",";
				$data[] = $value;
			}
			$sql  = substr($sql, 0, -1);
			$sql .= ") VALUES (";
			foreach($data as $entry) {
				$sql .= "?,";
			}
			$sql  = substr($sql, 0, -1);
			$sql .= ");";

			$res = $this->prepare($sql);
			try {
				$res->execute($data);
				return true;
			}
			catch (PDOException $e) {
				die($e->getMessage());
				return false;
			}
		}

		public function update($tb, $params = array(), $ids = array()) {
			$data = array();

			$sql  = "UPDATE " . $tb . " SET ";
			foreach($params as $key => $value) {
				$sql .= $key . " = ?,";
				$data[] = $value;
			}
			$sql  = substr($sql, 0, -1);
			if(!empty($ids)) {
				$sql .= " WHERE ";
				$multi_id = false;
				foreach($ids as $key => $value) {
					if ($multi_id) {
						$sql .= "AND " . $key . " = ? ";
						$data[] = $value;
					}
					else {
						$sql .= $key . " = ? ";
						$data[] = $value;
						$multi_id = true;
					}
				}
			}
			$res = $this->prepare($sql);
			try {
				$res->execute($data);
				return true;
			}
			catch (PDOException $e) {
				die($e->getMessage());
				return false;
			}
		}

		public function delete($tb, $ids = array()) {
			$sql  = "DELETE FROM " . $tb . " WHERE ";
			$multi_id = false;
			foreach($ids as $key => $value) {
				if ($multi_id) {
					$sql .= "AND " . $key . "=? ";
					$data[] = $value;
				}
				else {
					$sql .= $key . "=? ";
					$data[] = $value;
					$multi_id = true;
				}
			}
			$res = $this->prepare($sql);
			try {
				$res->execute($data);
				return true;
			}
			catch (PDOException $e) {
				die($e->getMessage());
				return false;
			}
		}

		public function search($tb, $params = array(), $option="") {
			$sql  = "SELECT * FROM " . $tb;
			if(!empty($params)) {
				$multi = false;
				$sql .= " WHERE ";
				foreach ($params as $key => $value) {
					if($multi) {
						$sql .= "AND " . $key . "=";
						$sql .= gettype($value) == 'string' ? $this->quote($value) : $value;
						$sql .= " ";
					}
					else {
						$sql .= $key . "=";
						$sql .= gettype($value) == 'string' ? $this->quote($value) : $value;
						$sql .= " ";
						$multi = true;
					}
				}
			}

			$result = $this->query($sql);
			if($option == "fetch") {
				if($result->rowCount() > 0) {
					$data_array = array();
					while($row = $result->fetch(PDO::FETCH_ASSOC)) {
						$data_array[] = $row;
					}
					return $data_array;
				}
				else {
					return null;
				}
			}
			else if ($option == "object") {
				if($result->rowCount() > 0) {
					$data_array = array();
					while($row = $result->fetch(PDO::FETCH_OBJ)) {
						$data_array[] = $row;
					}
					return $data_array;
				}
				else {
					return null;
				}
			}
		}

		public function count($table_name, $parameters) {
			global $db;
			$sql = 'SELECT * FROM '.$table_name.' '	
				. 'WHERE ';
			$multi = false;
			foreach ($params as $key => $value) {
				if($multi) {
					$sql .= "AND " . $key . "=";
					$sql .= gettype($value) == 'string' ? $this->quote($value) : $value;
					$sql .= " ";
				}
				else {
					$sql .= $key . "=";
					$sql .= gettype($value) == 'string' ? $this->quote($value) : $value;
					$sql .= " ";
					$multi = true;
				}
			}
			return $db->query($sql)->rowCount();
		}

		public function getLastInsertID() {
			return $this->_connection->lastInsertId();
		}
	}
?>
