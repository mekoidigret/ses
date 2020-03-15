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
            'date', 
            'time'
        );

        public $upload_dir;

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

        public static function attach($file) {
            $self = new self();
            if(!$file || empty($file) || !is_array($file)) {
                $self->errors[] = 'No file was uploaded.';
                return $self;
            }
            else if($file['error'] != 0) {
                $self->errors[] = $self->upload_errors[$file['error']];
                return $self;
            }
            else if(file_exists($self->upload_dir.DS.$file['name'])) {
                $self->errors[] = 'File already exists.';
                return $self;
            }
            else {
                $self->_temp_path = $file['tmp_name'];
                $self->_name = basename($file['name']);
                $self->_type = $file['type'];
                $self->_size = $file['size'];
                $self->_user_id = $_SESSION['user_id'];
                $self->_date = date('Y-m-d');
                $self->_time = date('H:i:s');
                return $self;
            }
        }

        public function save() {
            if(file_exists($this->upload_dir.DS.$this->_name)) {
                $this->errors[] = 'File already exists.';
                return false;
            }
            else if($this->create()) {
                if (move_uploaded_file($this->_temp_path, $this->upload_dir)) {
                    $this->message = 'File uploaded successfully.';
                    return true;
                }
                else {
                    global $db;
                    $db->delete(self::TABLE_NAME, ['id' => $this->_id]);
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
            return $this->upload_dir.DS.$this->_name;
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
                return self($file[0]);
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