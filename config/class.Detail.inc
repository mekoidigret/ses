<?php
	class Detail extends DatabaseObject {
		public $user_id;
		public $first_name;
		public $last_name;
		public $gender;
		public $age;
		public $school = null;
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
				$old_detail = self::findBySQL('SELECT * FROM '.self::TABLE_NAME.' WHERE user_id = '.$_SESSION['user_id']);
				$data = array(
					'first_name' => $this->first_name,
					'last_name' => $this->last_name,
					'gender' => $this->gender,
					'age' => $this->age,
					'school' => $this->school,
					'photo_id' => $this->photo_id
				);
				if($db->update(self::TABLE_NAME, $data, array('user_id' => $this->user_id))) {
					$file = File::findByID($old_detail->photo_id);
					return $file->destroy();
				}
			}
		}
	}