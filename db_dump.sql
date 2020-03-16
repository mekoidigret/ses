DROP DATABASE IF EXISTS `ses`;
CREATE DATABASE IF NOT EXISTS `ses`;
USE `ses`;
DROP TABLE IF EXISTS `access_levels`;
CREATE TABLE IF NOT EXISTS `access_levels` (
  `id` int(10) unsigned NOT NULL AUTO_INCREMENT,
  `type` varchar(50) NOT NULL,
  PRIMARY KEY (`id`)
);
INSERT INTO `access_levels` (`id`, `type`) VALUES
	(1, 'Student'),
	(2, 'Administrator');

DROP TABLE IF EXISTS `addresses`;
CREATE TABLE IF NOT EXISTS `addresses` (
  `user_id` int(10) unsigned NOT NULL,
  `street` varchar(150) NOT NULL,
  `brgy` varchar(150) NOT NULL,
  `municipality` varchar(150) NOT NULL,
  `city` varchar(150) NOT NULL,
  PRIMARY KEY (`user_id`),
  CONSTRAINT `FK_user_addresses_users` FOREIGN KEY (`user_id`) REFERENCES `users` (`id`) ON DELETE NO ACTION ON UPDATE NO ACTION
);
INSERT INTO `addresses` (`user_id`, `street`, `brgy`, `municipality`, `city`) VALUES
	(1, '', 'Lico-an', 'Barotac Nuevo', 'Iloilo');

DROP TABLE IF EXISTS `details`;
CREATE TABLE IF NOT EXISTS `details` (
  `user_id` int(11) unsigned NOT NULL,
  `first_name` varchar(255) NOT NULL,
  `last_name` varchar(255) NOT NULL,
  `gender` varchar(6) NOT NULL,
  `age` varchar(3) NOT NULL,
  PRIMARY KEY (`user_id`),
  CONSTRAINT `FK_user_details_users` FOREIGN KEY (`user_id`) REFERENCES `users` (`id`) ON DELETE NO ACTION ON UPDATE NO ACTION
);
INSERT INTO `details` (`user_id`, `first_name`, `last_name`, `gender`, `age`) VALUES
	(1, 'John Michael', 'Manlupig', 'Male', '20');
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
);
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
);
INSERT INTO `users` (`id`, `access_level_id`, `username`, `password`) VALUES
	(1, 2, 'mekkyinblack', '$2y$10$25sdXcIs94Nah/n/YRlY0.Diij5A.8ptuNrx2yTA84lcUUjEFPJHW'),
	(2, 2, 'admin', '$2y$10$j1Mjg8aeQNfoXkTHMC07IOiLTLf6BGDQBv.6ZCYM2PFJuC//kEHZa');