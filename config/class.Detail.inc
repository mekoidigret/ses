<?php
	class Detail extends DatabaseObject {
		public $user_id;
		public $first_name;
		public $last_name;
		public $gender;
		public $age;
		public $photo_id;

		const TABLE_NAME = 'details';

		public function getName() {
			return htmlentities($this->last_name.', '.$this->first_name);
		}

		public function save() {
			global $db;
			if($db->query('SELECT * FROM '.self::TABLE_NAME.' WHERE user_id = '.$this->user_id)->rowCount() == 0) {
				return $db->insert(self::TABLE_NAME, $this);
			}
			else {
				$data = array(
					'first_name' => $this->first_name,
					'last_name' => $this->last_name,
					'gender' => $this->gender,
					'age' => $this->age
				);
				return $db->update(self::TABLE_NAME, $data, array('user_id' => $this->user_id));
			}
		}
	}