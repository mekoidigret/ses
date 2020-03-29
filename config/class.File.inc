<?php
    class File {
        public $_id;
        public $_name;
        public $_type;
        public $_size;
        public $_user_id;
        public $_date;
        public $_time;
        public $_temp_path;

        const F_NEW = 1;
        const F_OLD = 2;
        const TABLE_NAME = 'files';

        protected static $db_fields = array(
            'name',
            'type', 
            'size', 
            'user_id',
            'upload_dir',
            'date', 
            'time'
        );

        public $_upload_dir;

        protected $upload_errors = array(
			UPLOAD_ERR_OK => "No errors.",
			UPLOAD_ERR_INI_SIZE => "File is larger than the maximum upload file size.",
			UPLOAD_ERR_FORM_SIZE => "File is larger than the maximum upload file size.",
			UPLOAD_ERR_PARTIAL => "Only part of the file has been uploaded.",
			UPLOAD_ERR_NO_FILE => "No file.",
			UPLOAD_ERR_NO_TMP_DIR => "No temporary directory.",
			UPLOAD_ERR_CANT_WRITE => "Unable to upload.",
			UPLOAD_ERR_EXTENSION => "Please upload the correct file extension."
        );

        public $errors = array();
        public $message;

        public function __construct($data = array()) {
            foreach($data as $property => $value) {
                $property = '_'.$property;
                if(property_exists($this, $property)) {
                    $this->$property = $value;
                }
            }
            return $this;
        }

        public function attach($file) {
            if(!$file || empty($file) || !is_array($file)) {
                $this->errors[] = 'No file was uploaded.';
                return $this;
            }
            else if($file['error'] != 0) {
                $this->errors[] = $this->upload_errors[$file['error']];
                return $this;
            }
            else if(file_exists($this->_upload_dir.DS.$file['name'])) {
                $this->errors[] = 'File already exists.';
                return $this;
            }
            else {
                $this->_temp_path = $file['tmp_name'];
                $this->_name = basename($file['name']);
                $this->_type = $file['type'];
                $this->_size = $file['size'];
                $this->_user_id = $_SESSION['user_id'];
                $this->_date = date('Y-m-d');
                $this->_time = date('H:i:s');
                return $this;
            }
        }

        public function save() {
            if(file_exists($this->_upload_dir.DS.$this->_name)) {
                $this->errors[] = 'File already exists.';
                return false;
            }
            else if($this->create()) {
                if (move_uploaded_file($this->_temp_path, $this->getPath())) {
                    $this->message = 'File uploaded successfully.';
                    return true;
                }
                else {
                    global $db;
                    $db->delete(self::TABLE_NAME, array('id' => $this->_id));
                    $this->errors[] = 'Unable to upload file.';
                    return false;
                }
            }
            else {
                $this->errors[] = 'Database error.';
                return false;
            }
        }

        protected function attributes() {
            $attributes = array();
            foreach(self::$db_fields as $field) {
                $property = '_'.$field;
                if(property_exists($this, $property)) {
                    $attributes[$field] = $this->$property;
                }
            }
            return $attributes;
        }

        private function create() {
            global $db;
            if($db->insert(self::TABLE_NAME, $this->attributes())) {
                $this->_id = $db->getLastInsertID();
                return true;
            }
            else {
                return false;
            }
        }

        public static function findAll() {
            global $db;
            $sql  = 'SELECT * FROM '.self::TABLE_NAME.' ';
            $sql .= 'WHERE user_id = ' . $_SESSION['user_id'] .' ';
            $sql .= 'ORDER BY type';
            $result = $db->query($sql);
            if($result->rowCount() > 0) {
                $object_array = array();
                while($row = $result->fetch(PDO::FETCH_ASSOC)) {
                    $object_array[] = new self($row);
                }
                return $object_array;
            }
            else {
                return null;
            }
        }

        public function getSizeAsText() {
			if($this->_size < 1024) {
				return "{$this->_size} bytes";
			} elseif($this->size < 1048576) {
				$size_kb = round($this->_size/1024);
				return "{$size_kb} KB";
			} else {
				$size_mb = round($this->_size/1048576, 1);
				return "{$size_mb} MB";
			}
        }
        
        public function getPath() {
            return $this->_upload_dir.DS.$this->_name;
        }

        public function getDateUploaded() {
            $date = date_create($this->_date);
            $date = date_format($date, 'F d, Y');
            $time = date_create($this->_time);
            $time = date_format($time, 'g:i A');
            return $date.' '.$time;
        }

        public static function findByID($id) {
            global $db;
            $file = $db->search(self::TABLE_NAME, array('id' => $id), 'fetch');
            if($file) {
                return new self($file[0]);
            }
            else {
                return null;
            }
        }

        public function destroy() {
            if($this->delete()) {
                return unlink($this->getPath()) ? true : false;
            }
            else {
                return false;
            }
        }

        private function delete() {
            global $db;
            return $db->delete(self::TABLE_NAME, array('id' => $this->_id));
        }

        public function download() {
            if(file_exists($this->getPath())) {
                header('Content-Description: File Transfer');
                header('Content-Type: '.$this->_type);
                header('Content-Disposition: attachment; filename="'.basename($this->_name).'"');
                header('Expires: 0');
                header('Pragma: public');
                header('Content-Length: '.filesize($this->getPath()));
                readfile($this->getPath());
                return true;
            }
            return false;
        }
    }
?>