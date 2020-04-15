-- phpMyAdmin SQL Dump
-- version 4.9.0.1
-- https://www.phpmyadmin.net/
--
-- Host: 127.0.0.1
-- Generation Time: Apr 15, 2020 at 03:59 AM
-- Server version: 10.3.15-MariaDB
-- PHP Version: 7.3.6

SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
SET AUTOCOMMIT = 0;
START TRANSACTION;
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8mb4 */;

--
-- Database: `ses`
--

-- --------------------------------------------------------

--
-- Table structure for table `access_levels`
--

CREATE TABLE `access_levels` (
  `id` int(10) UNSIGNED NOT NULL,
  `type` varchar(50) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

--
-- Dumping data for table `access_levels`
--

INSERT INTO `access_levels` (`id`, `type`) VALUES
(1, 'Student'),
(2, 'Administrator');

-- --------------------------------------------------------

--
-- Table structure for table `addresses`
--

CREATE TABLE `addresses` (
  `user_id` int(10) UNSIGNED NOT NULL,
  `street` varchar(150) NOT NULL,
  `brgy` varchar(150) NOT NULL,
  `municipality` varchar(150) NOT NULL,
  `city` varchar(150) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

--
-- Dumping data for table `addresses`
--

INSERT INTO `addresses` (`user_id`, `street`, `brgy`, `municipality`, `city`) VALUES
(2, 'Sta. Cruz', 'Lico-an', 'Barotac Nuevo', 'Iloilo'),
(8, 'Sta. Cruz', 'Lico-an', 'Barotac Nuevo', 'Iloilo');

-- --------------------------------------------------------

--
-- Table structure for table `analytics`
--

CREATE TABLE `analytics` (
  `id` int(10) UNSIGNED NOT NULL,
  `full_name` varchar(100) NOT NULL,
  `gender` varchar(6) NOT NULL,
  `status` varchar(20) NOT NULL,
  `school` varchar(20) NOT NULL,
  `year` year(4) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

--
-- Dumping data for table `analytics`
--

INSERT INTO `analytics` (`id`, `full_name`, `gender`, `status`, `school`, `year`) VALUES
(1, 'John Michael Manlupig', 'Male', 'Enrolled', 'ISCOF', 2015),
(2, 'John Michael Manlupig', 'Male', 'Enrolled', 'ISCOF', 2015),
(3, 'Noriel Sazon', 'Male', 'Enrolled', 'ISCOF', 2015),
(4, 'Jane Doe', 'Female', 'Dropped', 'ISCOF', 2017);

-- --------------------------------------------------------

--
-- Table structure for table `details`
--

CREATE TABLE `details` (
  `user_id` int(11) UNSIGNED NOT NULL,
  `first_name` varchar(255) NOT NULL,
  `last_name` varchar(255) NOT NULL,
  `gender` varchar(6) NOT NULL,
  `age` varchar(3) NOT NULL,
  `school` varchar(255) DEFAULT NULL,
  `photo_id` int(10) UNSIGNED NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

--
-- Dumping data for table `details`
--

INSERT INTO `details` (`user_id`, `first_name`, `last_name`, `gender`, `age`, `school`, `photo_id`) VALUES
(2, 'John Michael', 'Manlupig', 'Male', '21', NULL, 18),
(8, 'John Michael', 'Manlupig', 'Male', '21', 'Iloilo State College of Fisheries', 19);

-- --------------------------------------------------------

--
-- Table structure for table `files`
--

CREATE TABLE `files` (
  `id` int(11) UNSIGNED NOT NULL,
  `user_id` int(11) UNSIGNED NOT NULL,
  `name` varchar(255) NOT NULL,
  `size` int(11) NOT NULL,
  `type` varchar(50) NOT NULL,
  `upload_dir` varchar(255) NOT NULL,
  `date` date NOT NULL,
  `time` time NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

--
-- Dumping data for table `files`
--

INSERT INTO `files` (`id`, `user_id`, `name`, `size`, `type`, `upload_dir`, `date`, `time`) VALUES
(18, 2, '36276951_1912975805392180_2582493943081992192_n.jpg', 8678, 'image/jpeg', '..\\assets\\files\\images\\pps', '2020-03-21', '14:10:21'),
(19, 8, 'Resume.jpg', 9148928, 'image/jpeg', '..\\assets\\files\\images\\pps', '2020-03-25', '22:28:16');

-- --------------------------------------------------------

--
-- Table structure for table `requests`
--

CREATE TABLE `requests` (
  `id` varchar(19) NOT NULL,
  `date` date NOT NULL,
  `user_id` int(10) UNSIGNED NOT NULL,
  `passed` tinyint(1) UNSIGNED NOT NULL DEFAULT 0
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

--
-- Dumping data for table `requests`
--

INSERT INTO `requests` (`id`, `date`, `user_id`, `passed`) VALUES
('2020-98bf-6a6e-68df', '2020-03-29', 8, 1),
('2020-d311-bbd7-2dda', '2020-04-06', 9, 0);

-- --------------------------------------------------------

--
-- Table structure for table `users`
--

CREATE TABLE `users` (
  `id` int(10) UNSIGNED NOT NULL,
  `access_level_id` int(10) UNSIGNED NOT NULL,
  `username` varchar(255) NOT NULL,
  `password` varchar(255) NOT NULL,
  `created` timestamp NOT NULL DEFAULT current_timestamp(),
  `modified` timestamp NOT NULL DEFAULT current_timestamp() ON UPDATE current_timestamp(),
  `status` varchar(50) NOT NULL DEFAULT 'Applicant'
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

--
-- Dumping data for table `users`
--

INSERT INTO `users` (`id`, `access_level_id`, `username`, `password`, `created`, `modified`, `status`) VALUES
(1, 2, 'mekkyinblack', '$2y$10$25sdXcIs94Nah/n/YRlY0.Diij5A.8ptuNrx2yTA84lcUUjEFPJHW', '2020-04-14 11:12:43', '2020-04-14 11:12:56', 'Applicant'),
(2, 2, 'admin', '$2y$10$j1Mjg8aeQNfoXkTHMC07IOiLTLf6BGDQBv.6ZCYM2PFJuC//kEHZa', '2020-04-14 11:12:43', '2020-04-14 11:12:56', 'Applicant'),
(8, 1, 'student', '$2y$10$pf7Nc3Tf7fDNT11J/gbi0.6nxfLGbynImWoLHfGK7zopGT1YSQzmO', '2020-04-14 11:12:43', '2020-04-14 11:24:34', 'Enrolled'),
(9, 1, 'mekoi', '$2y$10$VLl9onOnd/j41RzXkshPEOxK5munSFUo8qlG5XUuChLDV.gzATpeG', '2020-04-14 11:12:43', '2020-04-14 11:12:56', 'Applicant');

--
-- Indexes for dumped tables
--

--
-- Indexes for table `access_levels`
--
ALTER TABLE `access_levels`
  ADD PRIMARY KEY (`id`);

--
-- Indexes for table `addresses`
--
ALTER TABLE `addresses`
  ADD PRIMARY KEY (`user_id`);

--
-- Indexes for table `analytics`
--
ALTER TABLE `analytics`
  ADD PRIMARY KEY (`id`);

--
-- Indexes for table `details`
--
ALTER TABLE `details`
  ADD PRIMARY KEY (`user_id`),
  ADD UNIQUE KEY `FK_details_files` (`photo_id`);

--
-- Indexes for table `files`
--
ALTER TABLE `files`
  ADD PRIMARY KEY (`id`),
  ADD KEY `FK_files_users` (`user_id`);

--
-- Indexes for table `requests`
--
ALTER TABLE `requests`
  ADD PRIMARY KEY (`id`),
  ADD KEY `FK_requests_users` (`user_id`);

--
-- Indexes for table `users`
--
ALTER TABLE `users`
  ADD PRIMARY KEY (`id`),
  ADD UNIQUE KEY `username` (`username`),
  ADD KEY `FK_users_access_levels` (`access_level_id`);

--
-- AUTO_INCREMENT for dumped tables
--

--
-- AUTO_INCREMENT for table `access_levels`
--
ALTER TABLE `access_levels`
  MODIFY `id` int(10) UNSIGNED NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=3;

--
-- AUTO_INCREMENT for table `analytics`
--
ALTER TABLE `analytics`
  MODIFY `id` int(10) UNSIGNED NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=5;

--
-- AUTO_INCREMENT for table `files`
--
ALTER TABLE `files`
  MODIFY `id` int(11) UNSIGNED NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=20;

--
-- AUTO_INCREMENT for table `users`
--
ALTER TABLE `users`
  MODIFY `id` int(10) UNSIGNED NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=10;

--
-- Constraints for dumped tables
--

--
-- Constraints for table `addresses`
--
ALTER TABLE `addresses`
  ADD CONSTRAINT `FK_user_addresses_users` FOREIGN KEY (`user_id`) REFERENCES `users` (`id`) ON DELETE NO ACTION ON UPDATE NO ACTION;

--
-- Constraints for table `details`
--
ALTER TABLE `details`
  ADD CONSTRAINT `FK_details_files` FOREIGN KEY (`photo_id`) REFERENCES `files` (`id`) ON DELETE NO ACTION ON UPDATE NO ACTION,
  ADD CONSTRAINT `FK_user_details_users` FOREIGN KEY (`user_id`) REFERENCES `users` (`id`) ON DELETE NO ACTION ON UPDATE NO ACTION;

--
-- Constraints for table `files`
--
ALTER TABLE `files`
  ADD CONSTRAINT `FK_files_users` FOREIGN KEY (`user_id`) REFERENCES `users` (`id`) ON DELETE NO ACTION ON UPDATE NO ACTION;

--
-- Constraints for table `requests`
--
ALTER TABLE `requests`
  ADD CONSTRAINT `FK_requests_users` FOREIGN KEY (`user_id`) REFERENCES `users` (`id`) ON DELETE NO ACTION ON UPDATE NO ACTION;

--
-- Constraints for table `users`
--
ALTER TABLE `users`
  ADD CONSTRAINT `FK_users_access_levels` FOREIGN KEY (`access_level_id`) REFERENCES `access_levels` (`id`) ON DELETE NO ACTION ON UPDATE NO ACTION;
COMMIT;

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
