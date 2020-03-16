<?php
	class Address extends DatabaseObject {
		public $user_id;
		public $street;
		public $brgy;
		public $municipality;
		public $city;

		const TABLE_NAME = 'addresses';

		public function save() {
			global $db;
			if($db->query('SELECT * FROM '.self::TABLE_NAME.' WHERE user_id = '.$this->user_id)->rowCount() == 0) {
				return $db->insert(self::TABLE_NAME, $this);
			}
			else {
				$data = array(
					'street' => $this->street,
					'brgy' => $this->brgy,
					'municipality' => $this->municipality,
					'city' => $this->city
				);
				return $db->update(self::TABLE_NAME, $data, array('user_id' => $this->user_id));
			}
		}
	}