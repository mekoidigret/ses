<?php
	/**
	 * The standard User class for handling
	 * all users regardless of their access levels.
	 */
	class User extends DatabaseObject {
		public $id;
		public $access_level_id;
		public $username;
		protected $password;

		public $message;

		const TABLE_NAME = 'users';

		public function authenticate() {
			$user = self::findBy('username', $this->username);
			if($user) {
				if(password_verify($this->password, $user->password)) {
					foreach($user as $property => $value) {
						$this->$property = $value;
					}
					$this->message = 'User authenticated successfully.';
					return true;
				}
				else {
					$this->message = 'Wrong password.';
					return false;
				}
			}
			else {
				$this->message = 'Username does not exist.';
				return false;
			}
		}

		public function __get($property) {
			return $this->$property;
		}

		public function save() {
			return !$this->id ? $this->create() : $this->update();
		}

		public function create() {
			global $db;
			$user = self::findBySQL('SELECT * FROM '.self::TABLE_NAME.' WHERE username = '.$db->quote($this->username));
			if(!$user) {
				$data = array(
					'username' => $db->quote($this->username),
					'access_level_id' => static::LEVEL,
					'password' => $db->quote(password_hash($this->password, PASSWORD_BCRYPT)),
					'status' => $this->status
				);
				$sql = 'INSERT INTO '.self::TABLE_NAME.' ('
					. join(' , ', array_keys($data)).') '
					. 'VALUES ('
					. join(' , ', array_values($data)).');';
				try {
					$db->query($sql);
					$this->id = $db->getLastInsertID();
					$this->message = 'User added successfully.';
					return true;
				}
				catch(PDOException $e) {
					$this->message = $e->getMessage();
					return false;
				}
			}
			else {
				$this->message = 'Username already taken.';
				return false;
			}
		}
	}