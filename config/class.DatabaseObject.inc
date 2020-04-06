<?php
	/**
	 * Handler class for implementing common
	 * sql functions.
	 */
	abstract class DatabaseObject {

		public function __construct($data = array()) {
			foreach($data as $property => $value) {
				if(property_exists($this, $property)) {
					$this->$property = $value;
				}
			}
			return $this;
		}
		
		public static function findBy($param, $value) {
			global $db;
			$self = get_called_class();
			$sql = 'SELECT * FROM '.static::TABLE_NAME.' '
				.'WHERE '.$param.' = '.$db->quote($value);
			$result = $db->query($sql);
			if($result->rowCount() > 0) {
				return new $self($result->fetch(PDO::FETCH_ASSOC));
			}
			else {
				return null;
			}
		}

		public static function findBySQL($sql = '') {
			global $db;
			$self = get_called_class();
			$result = $db->query($sql);
			if($result->rowCount() > 0) {
				return new $self($result->fetch(PDO::FETCH_ASSOC));
			}
			else {
				return null;
			}
		}

		public static function findAllBySQL($sql = '') {
			global $db;
			$self = get_called_class();
			$result = $db->query($sql);
			if($result->rowCount() > 0) {
				$object_array = array();
				while($row = $result->fetch(PDO::FETCH_ASSOC)) {
					$object_array[] = new $self($row);
				}
				return $object_array;
			}
			else {
				return null;
			}
		}

		public static function countAll() {
			global $db;
			$sql = 'SELECT * FROM '.static::TABLE_NAME;
			return $db->query($sql)->rowCount();
		}
	}