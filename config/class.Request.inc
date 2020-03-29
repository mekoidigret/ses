<?php
	class Request extends DatabaseObject {

		public $id = null;
		public $date;
		public $user_id;
		public $passed = false;
		public $user_data = null;

		const TABLE_NAME = 'requests';

		public function __construct($data = array()) {
			parent::__construct($data);
			$this->passed = (bool)$this->passed;
			global $db;
			$detail = Detail::findBySQL('SELECT * FROM '.Detail::TABLE_NAME.' WHERE user_id = '.$this->user_id);
			$address = Address::findBySQL('SELECT * FROM '.Address::TABLE_NAME.' WHERE user_id = '.$this->user_id);
			if(!$detail || !$address) {
				throw new Exception("Student must have details and an address.", 1);
			}
			$this->user_data = new stdClass();
			$this->user_data->detail = $detail;
			$this->user_data->address = $address;
			return $this;
		}

		public static function generateExamID() {
			global $db;
			$id = self::_generateBytes();
			$sql = 'SELECT * FROM '.self::TABLE_NAME.' '
				.'WHERE id = '.$db->quote($id);
			if($db->query($sql)->rowCount() == 0) {
				return $id;
			}
			else {
				self::generateExamID();
			}
		}

		private static function _generateBytes() {
			return date('Y').'-'.generateID(2,2).'-'.generateID(2,2).'-'.generateID(2,2);
		}
	}