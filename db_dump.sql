-- --------------------------------------------------------
-- Host:                         127.0.0.1
-- Server version:               10.3.15-MariaDB - mariadb.org binary distribution
-- Server OS:                    Win64
-- HeidiSQL Version:             10.3.0.5771
-- --------------------------------------------------------

/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET NAMES utf8 */;
/*!50503 SET NAMES utf8mb4 */;
/*!40014 SET @OLD_FOREIGN_KEY_CHECKS=@@FOREIGN_KEY_CHECKS, FOREIGN_KEY_CHECKS=0 */;
/*!40101 SET @OLD_SQL_MODE=@@SQL_MODE, SQL_MODE='NO_AUTO_VALUE_ON_ZERO' */;


-- Dumping database structure for ses
DROP DATABASE IF EXISTS `ses`;
CREATE DATABASE IF NOT EXISTS `ses` /*!40100 DEFAULT CHARACTER SET utf8 */;
USE `ses`;

-- Dumping structure for table ses.access_levels
DROP TABLE IF EXISTS `access_levels`;
CREATE TABLE IF NOT EXISTS `access_levels` (
  `id` int(10) unsigned NOT NULL AUTO_INCREMENT,
  `type` varchar(50) NOT NULL,
  PRIMARY KEY (`id`)
) ENGINE=InnoDB AUTO_INCREMENT=3 DEFAULT CHARSET=utf8;

-- Dumping data for table ses.access_levels: ~2 rows (approximately)
/*!40000 ALTER TABLE `access_levels` DISABLE KEYS */;
INSERT INTO `access_levels` (`id`, `type`) VALUES
	(1, 'Student'),
	(2, 'Administrator');
/*!40000 ALTER TABLE `access_levels` ENABLE KEYS */;

-- Dumping structure for table ses.addresses
DROP TABLE IF EXISTS `addresses`;
CREATE TABLE IF NOT EXISTS `addresses` (
  `user_id` int(10) unsigned NOT NULL,
  `street` varchar(150) NOT NULL,
  `brgy` varchar(150) NOT NULL,
  `municipality` varchar(150) NOT NULL,
  `city` varchar(150) NOT NULL,
  PRIMARY KEY (`user_id`),
  CONSTRAINT `FK_user_addresses_users` FOREIGN KEY (`user_id`) REFERENCES `users` (`id`) ON DELETE NO ACTION ON UPDATE NO ACTION
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

-- Dumping data for table ses.addresses: ~0 rows (approximately)
/*!40000 ALTER TABLE `addresses` DISABLE KEYS */;
INSERT INTO `addresses` (`user_id`, `street`, `brgy`, `municipality`, `city`) VALUES
	(2, 'Sta. Cruz', 'Lico-an', 'Barotac Nuevo', 'Iloilo'),
	(8, 'Sta. Cruz', 'Lico-an', 'Barotac Nuevo', 'Iloilo');
/*!40000 ALTER TABLE `addresses` ENABLE KEYS */;

-- Dumping structure for table ses.analytics
DROP TABLE IF EXISTS `analytics`;
CREATE TABLE IF NOT EXISTS `analytics` (
  `id` int(10) unsigned NOT NULL AUTO_INCREMENT,
  `full_name` varchar(100) NOT NULL,
  `gender` varchar(6) NOT NULL,
  `status` varchar(20) NOT NULL,
  `school` varchar(20) NOT NULL,
  `year` year(4) NOT NULL,
  PRIMARY KEY (`id`)
) ENGINE=InnoDB AUTO_INCREMENT=5 DEFAULT CHARSET=latin1;

-- Dumping data for table ses.analytics: ~0 rows (approximately)
/*!40000 ALTER TABLE `analytics` DISABLE KEYS */;
INSERT INTO `analytics` (`id`, `full_name`, `gender`, `status`, `school`, `year`) VALUES
	(1, 'John Michael Manlupig', 'Male', 'Enrolled', 'ISCOF', '2015'),
	(2, 'John Michael Manlupig', 'Male', 'Enrolled', 'ISCOF', '2015'),
	(3, 'Noriel Sazon', 'Male', 'Enrolled', 'ISCOF', '2015'),
	(4, 'Jane Doe', 'Female', 'Dropped', 'ISCOF', '2017');
/*!40000 ALTER TABLE `analytics` ENABLE KEYS */;

-- Dumping structure for table ses.details
DROP TABLE IF EXISTS `details`;
CREATE TABLE IF NOT EXISTS `details` (
  `user_id` int(11) unsigned NOT NULL,
  `first_name` varchar(255) NOT NULL,
  `last_name` varchar(255) NOT NULL,
  `gender` varchar(6) NOT NULL,
  `age` varchar(3) NOT NULL,
  `school` varchar(255) DEFAULT NULL,
  `photo_id` int(10) unsigned NOT NULL,
  PRIMARY KEY (`user_id`),
  UNIQUE KEY `FK_details_files` (`photo_id`),
  CONSTRAINT `FK_details_files` FOREIGN KEY (`photo_id`) REFERENCES `files` (`id`) ON DELETE NO ACTION ON UPDATE NO ACTION,
  CONSTRAINT `FK_user_details_users` FOREIGN KEY (`user_id`) REFERENCES `users` (`id`) ON DELETE NO ACTION ON UPDATE NO ACTION
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

-- Dumping data for table ses.details: ~2 rows (approximately)
/*!40000 ALTER TABLE `details` DISABLE KEYS */;
INSERT INTO `details` (`user_id`, `first_name`, `last_name`, `gender`, `age`, `school`, `photo_id`) VALUES
	(2, 'John Michael', 'Manlupig', 'Male', '21', NULL, 18),
	(8, 'John Michael', 'Manlupig', 'Male', '21', 'Iloilo State College of Fisheries', 19);
/*!40000 ALTER TABLE `details` ENABLE KEYS */;

-- Dumping structure for table ses.files
DROP TABLE IF EXISTS `files`;
CREATE TABLE IF NOT EXISTS `files` (
  `id` int(11) unsigned NOT NULL AUTO_INCREMENT,
  `user_id` int(11) unsigned NOT NULL,
  `name` varchar(255) NOT NULL,
  `size` int(11) NOT NULL,
  `type` varchar(50) NOT NULL,
  `upload_dir` varchar(255) NOT NULL,
  `date` date NOT NULL,
  `time` time NOT NULL,
  PRIMARY KEY (`id`),
  KEY `FK_files_users` (`user_id`),
  CONSTRAINT `FK_files_users` FOREIGN KEY (`user_id`) REFERENCES `users` (`id`) ON DELETE NO ACTION ON UPDATE NO ACTION
) ENGINE=InnoDB AUTO_INCREMENT=20 DEFAULT CHARSET=utf8;

-- Dumping data for table ses.files: ~1 rows (approximately)
/*!40000 ALTER TABLE `files` DISABLE KEYS */;
INSERT INTO `files` (`id`, `user_id`, `name`, `size`, `type`, `upload_dir`, `date`, `time`) VALUES
	(18, 2, '36276951_1912975805392180_2582493943081992192_n.jpg', 8678, 'image/jpeg', '..\\assets\\files\\images\\pps', '2020-03-21', '14:10:21'),
	(19, 8, 'Resume.jpg', 9148928, 'image/jpeg', '..\\assets\\files\\images\\pps', '2020-03-25', '22:28:16');
/*!40000 ALTER TABLE `files` ENABLE KEYS */;

-- Dumping structure for table ses.requests
DROP TABLE IF EXISTS `requests`;
CREATE TABLE IF NOT EXISTS `requests` (
  `id` varchar(19) NOT NULL,
  `date` date NOT NULL,
  `user_id` int(10) unsigned NOT NULL,
  `passed` tinyint(1) unsigned NOT NULL DEFAULT 0,
  PRIMARY KEY (`id`),
  KEY `FK_requests_users` (`user_id`),
  CONSTRAINT `FK_requests_users` FOREIGN KEY (`user_id`) REFERENCES `users` (`id`) ON DELETE NO ACTION ON UPDATE NO ACTION
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

-- Dumping data for table ses.requests: ~1 rows (approximately)
/*!40000 ALTER TABLE `requests` DISABLE KEYS */;
INSERT INTO `requests` (`id`, `date`, `user_id`, `passed`) VALUES
	('2020-98bf-6a6e-68df', '2020-03-29', 8, 1),
	('2020-d311-bbd7-2dda', '2020-04-06', 9, 0);
/*!40000 ALTER TABLE `requests` ENABLE KEYS */;

-- Dumping structure for table ses.users
DROP TABLE IF EXISTS `users`;
CREATE TABLE IF NOT EXISTS `users` (
  `id` int(10) unsigned NOT NULL AUTO_INCREMENT,
  `access_level_id` int(10) unsigned NOT NULL,
  `username` varchar(255) NOT NULL,
  `password` varchar(255) NOT NULL,
  `created` timestamp NOT NULL DEFAULT current_timestamp(),
  `modified` timestamp NOT NULL DEFAULT current_timestamp() ON UPDATE current_timestamp(),
  `status` varchar(50) NOT NULL DEFAULT 'Applicant',
  PRIMARY KEY (`id`),
  UNIQUE KEY `username` (`username`),
  KEY `FK_users_access_levels` (`access_level_id`),
  CONSTRAINT `FK_users_access_levels` FOREIGN KEY (`access_level_id`) REFERENCES `access_levels` (`id`) ON DELETE NO ACTION ON UPDATE NO ACTION
) ENGINE=InnoDB AUTO_INCREMENT=10 DEFAULT CHARSET=utf8;

-- Dumping data for table ses.users: ~3 rows (approximately)
/*!40000 ALTER TABLE `users` DISABLE KEYS */;
INSERT INTO `users` (`id`, `access_level_id`, `username`, `password`, `created`, `modified`, `status`) VALUES
	(1, 2, 'mekkyinblack', '$2y$10$25sdXcIs94Nah/n/YRlY0.Diij5A.8ptuNrx2yTA84lcUUjEFPJHW', '2020-04-14 19:12:43', '2020-04-14 19:12:56', 'Applicant'),
	(2, 2, 'admin', '$2y$10$j1Mjg8aeQNfoXkTHMC07IOiLTLf6BGDQBv.6ZCYM2PFJuC//kEHZa', '2020-04-14 19:12:43', '2020-04-14 19:12:56', 'Applicant'),
	(8, 1, 'student', '$2y$10$pf7Nc3Tf7fDNT11J/gbi0.6nxfLGbynImWoLHfGK7zopGT1YSQzmO', '2020-04-14 19:12:43', '2020-04-14 19:24:34', 'Enrolled'),
	(9, 1, 'mekoi', '$2y$10$VLl9onOnd/j41RzXkshPEOxK5munSFUo8qlG5XUuChLDV.gzATpeG', '2020-04-14 19:12:43', '2020-04-14 19:12:56', 'Applicant');
/*!40000 ALTER TABLE `users` ENABLE KEYS */;

/*!40101 SET SQL_MODE=IFNULL(@OLD_SQL_MODE, '') */;
/*!40014 SET FOREIGN_KEY_CHECKS=IF(@OLD_FOREIGN_KEY_CHECKS IS NULL, 1, @OLD_FOREIGN_KEY_CHECKS) */;
/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
