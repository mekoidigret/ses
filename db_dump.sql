-- --------------------------------------------------------
-- Host:                         127.0.0.1
-- Server version:               10.3.15-MariaDB - mariadb.org binary distribution
-- Server OS:                    Win64
-- HeidiSQL Version:             10.2.0.5599
-- --------------------------------------------------------

/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET NAMES utf8 */;
/*!50503 SET NAMES utf8mb4 */;
/*!40014 SET @OLD_FOREIGN_KEY_CHECKS=@@FOREIGN_KEY_CHECKS, FOREIGN_KEY_CHECKS=0 */;
/*!40101 SET @OLD_SQL_MODE=@@SQL_MODE, SQL_MODE='NO_AUTO_VALUE_ON_ZERO' */;

DROP DATABASE IF EXISTS `ses`;
CREATE DATABASE IF NOT EXISTS `ses` /*!40100 DEFAULT CHARACTER SET utf8 */;
USE `ses`;

-- Dumping database structure for ses


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

-- Dumping data for table ses.addresses: ~1 rows (approximately)
/*!40000 ALTER TABLE `addresses` DISABLE KEYS */;
INSERT INTO `addresses` (`user_id`, `street`, `brgy`, `municipality`, `city`) VALUES
	(1, '', 'Lico-an', 'Barotac Nuevo', 'Iloilo');
/*!40000 ALTER TABLE `addresses` ENABLE KEYS */;

-- Dumping structure for table ses.details
DROP TABLE IF EXISTS `details`;
CREATE TABLE IF NOT EXISTS `details` (
  `user_id` int(11) unsigned NOT NULL,
  `first_name` varchar(255) NOT NULL,
  `last_name` varchar(255) NOT NULL,
  `gender` varchar(6) NOT NULL,
  `age` varchar(3) NOT NULL,
  PRIMARY KEY (`user_id`),
  CONSTRAINT `FK_user_details_users` FOREIGN KEY (`user_id`) REFERENCES `users` (`id`) ON DELETE NO ACTION ON UPDATE NO ACTION
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

-- Dumping data for table ses.details: ~1 rows (approximately)
/*!40000 ALTER TABLE `details` DISABLE KEYS */;
INSERT INTO `details` (`user_id`, `first_name`, `last_name`, `gender`, `age`) VALUES
	(1, 'John Michael', 'Manlupig', 'Male', '20');
/*!40000 ALTER TABLE `details` ENABLE KEYS */;

-- Dumping structure for table ses.files
DROP TABLE IF EXISTS `files`;
CREATE TABLE IF NOT EXISTS `files` (
  `id` int(11) unsigned NOT NULL AUTO_INCREMENT,
  `user_id` int(11) unsigned NOT NULL,
  `name` varchar(255) NOT NULL,
  `size` int(11) NOT NULL,
  `type` varchar(50) NOT NULL,
  `date` date NOT NULL,
  `time` time NOT NULL,
  PRIMARY KEY (`id`),
  KEY `FK_files_users` (`user_id`),
  CONSTRAINT `FK_files_users` FOREIGN KEY (`user_id`) REFERENCES `users` (`id`) ON DELETE NO ACTION ON UPDATE NO ACTION
) ENGINE=InnoDB AUTO_INCREMENT=5 DEFAULT CHARSET=utf8;

-- Dumping data for table ses.files: ~0 rows (approximately)
/*!40000 ALTER TABLE `files` DISABLE KEYS */;
/*!40000 ALTER TABLE `files` ENABLE KEYS */;

-- Dumping structure for table ses.users
DROP TABLE IF EXISTS `users`;
CREATE TABLE IF NOT EXISTS `users` (
  `id` int(10) unsigned NOT NULL AUTO_INCREMENT,
  `access_level_id` int(10) unsigned NOT NULL,
  `username` varchar(255) NOT NULL,
  `password` varchar(255) NOT NULL,
  PRIMARY KEY (`id`),
  UNIQUE KEY `username` (`username`),
  KEY `FK_users_access_levels` (`access_level_id`),
  CONSTRAINT `FK_users_access_levels` FOREIGN KEY (`access_level_id`) REFERENCES `access_levels` (`id`) ON DELETE NO ACTION ON UPDATE NO ACTION
) ENGINE=InnoDB AUTO_INCREMENT=3 DEFAULT CHARSET=utf8;

-- Dumping data for table ses.users: ~3 rows (approximately)
/*!40000 ALTER TABLE `users` DISABLE KEYS */;
INSERT INTO `users` (`id`, `access_level_id`, `username`, `password`) VALUES
	(1, 2, 'mekkyinblack', '$2y$10$25sdXcIs94Nah/n/YRlY0.Diij5A.8ptuNrx2yTA84lcUUjEFPJHW'),
	(2, 2, 'admin', '$2y$10$j1Mjg8aeQNfoXkTHMC07IOiLTLf6BGDQBv.6ZCYM2PFJuC//kEHZa');
/*!40000 ALTER TABLE `users` ENABLE KEYS */;

/*!40101 SET SQL_MODE=IFNULL(@OLD_SQL_MODE, '') */;
/*!40014 SET FOREIGN_KEY_CHECKS=IF(@OLD_FOREIGN_KEY_CHECKS IS NULL, 1, @OLD_FOREIGN_KEY_CHECKS) */;
/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
