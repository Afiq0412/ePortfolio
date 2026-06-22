-- phpMyAdmin SQL Dump
-- version 5.2.1
-- https://www.phpmyadmin.net/
--
-- Host: 127.0.0.1
-- Generation Time: Jan 31, 2025 at 02:05 PM
-- Server version: 10.4.32-MariaDB
-- PHP Version: 8.2.12

SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
START TRANSACTION;
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8mb4 */;

--
-- Database: `db_crs`
--

-- --------------------------------------------------------

--
-- Table structure for table `tb_course`
--

CREATE TABLE `tb_course` (
  `c_code` varchar(10) NOT NULL,
  `c_sem` varchar(15) NOT NULL,
  `c_name` varchar(50) NOT NULL,
  `c_credit` int(11) NOT NULL,
  `c_maxstudent` int(11) NOT NULL,
  `c_lec` varchar(10) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;

--
-- Dumping data for table `tb_course`
--

INSERT INTO `tb_course` (`c_code`, `c_sem`, `c_name`, `c_credit`, `c_maxstudent`, `c_lec`) VALUES
('SECJ1033', '2023/2024-1', 'Programming Technique I', 3, 45, 'L003'),
('SECJ3014', '2024/2025-2', 'Object Oriented Programming', 4, 50, 'L002'),
('SECP2523', '2024/2025-1', 'Database', 3, 50, 'L004'),
('SECP3723', '2024/2025-2', 'System Development Technology', 3, 45, 'L001'),
('SECR1213', '2024/2025-1', 'Network Communication', 3, 40, 'L002');

-- --------------------------------------------------------

--
-- Table structure for table `tb_registration`
--

CREATE TABLE `tb_registration` (
  `r_tid` int(11) NOT NULL COMMENT 'This is transaction ID',
  `r_student` varchar(10) NOT NULL,
  `r_course` varchar(10) NOT NULL,
  `r_sem` varchar(11) NOT NULL,
  `r_status` int(11) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;

--
-- Dumping data for table `tb_registration`
--

INSERT INTO `tb_registration` (`r_tid`, `r_student`, `r_course`, `r_sem`, `r_status`) VALUES
(12, 'S001', 'SECP3723', '2024/2025-2', 2),
(15, 'S011', 'SECR1213', '2024/2025-1', 2),
(17, 'S001', 'SECP2523', '2024/2025-1', 1),
(18, 'S001', 'SECJ1033', '2023/2024-1', 1),
(19, 'S011', 'SECJ1033', '2023/2024-1', 1);

-- --------------------------------------------------------

--
-- Table structure for table `tb_status`
--

CREATE TABLE `tb_status` (
  `s_id` int(11) NOT NULL,
  `s_desc` varchar(20) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;

--
-- Dumping data for table `tb_status`
--

INSERT INTO `tb_status` (`s_id`, `s_desc`) VALUES
(1, 'Received'),
(2, 'Approved'),
(3, 'Rejected');

-- --------------------------------------------------------

--
-- Table structure for table `tb_user`
--

CREATE TABLE `tb_user` (
  `u_sno` varchar(10) NOT NULL,
  `u_pwd` varchar(255) NOT NULL,
  `u_email` varchar(30) NOT NULL,
  `u_name` varchar(50) NOT NULL,
  `u_contact` varchar(12) NOT NULL,
  `u_state` varchar(20) NOT NULL,
  `u_reg` timestamp NULL DEFAULT NULL,
  `u_utype` int(11) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;

--
-- Dumping data for table `tb_user`
--

INSERT INTO `tb_user` (`u_sno`, `u_pwd`, `u_email`, `u_name`, `u_contact`, `u_state`, `u_reg`, `u_utype`) VALUES
('A001', '$2y$10$tBp8WP8Mps7snfJOwkUkDuKeVScrdkDpAhqBGnShSFrJxniOWMr1G', 'mirul@gmail.com', 'Amirul Hasan', '0179072912', 'Pulau Pinang', '2025-01-30 19:17:24', 3),
('L001', '$2y$10$/dUliwYO/kdvOdBK7HDFDO2ioOlIJ2Prc3AUgHKS49krKqJGoTzDC', 'aina@gmail.com', 'Aina Abdul', '01911111111', 'Johor', '2023-01-31 16:00:00', 1),
('L002', '$2y$10$Hl37/tfxbAkPIZuslmyn4u1sQvgZ4gCTezkJn6x/VOvwOICJQ.3K.', 'faz@gmail.com', 'Fazura Abdul', '0172222222', 'Kelantan', '2023-09-30 16:00:00', 1),
('L003', '$2y$10$ZazAunAVyKFgZun9x02M7uTcypSUCrPPd6npTZfjaInHgDRaPbYSa', 'ahamd@gmail.com', 'Ahmad Kasim', '0192342351', 'Kelantan', '2025-01-28 07:49:30', 1),
('L004', '$2y$10$P217lsNehHy0R9jSltbRF.rYDIAFWjMDs0mvmzPZjy9zjZNM67fpS', 'nur@gmail.com', 'Nur Fatimah', '012932355', 'Wilayah Persekutuan ', '2025-01-28 07:49:30', 1),
('S001', '$2y$10$rO1tvvAJm.wqi6KDrUopH.EXO1jjvZQvzF3LLywkwKWlTYAi4NgBK', 'fat@gmail.com', 'Fatah Abdul', '0113971310', 'Melaka', '2024-01-31 16:00:00', 2),
('S002', '$2y$10$NEibLheyJa.jy3vDTXcRse7vPeiF3dPP7oGhlPW.bdQdchxNE4p6m', 'kam@gmail.com', 'Kamarul Abdul', '0124444444', 'Sarawak', '2024-09-30 16:00:00', 2),
('S011', '$2y$10$MZLdVl32d8PZyooM7CCPSuyytwFdJLCF/xpJBLPovNpHNZGrI/AIy', 'afiq@gmail.com', 'Afiq Danial', '0194312944', 'Johor', '2024-11-19 15:14:44', 2);

-- --------------------------------------------------------

--
-- Table structure for table `tb_utype`
--

CREATE TABLE `tb_utype` (
  `t_id` int(11) NOT NULL,
  `t_decs` varchar(20) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;

--
-- Dumping data for table `tb_utype`
--

INSERT INTO `tb_utype` (`t_id`, `t_decs`) VALUES
(1, 'Lecturer'),
(2, 'Student'),
(3, 'Admin');

--
-- Indexes for dumped tables
--

--
-- Indexes for table `tb_course`
--
ALTER TABLE `tb_course`
  ADD PRIMARY KEY (`c_code`),
  ADD KEY `c_lec` (`c_lec`);

--
-- Indexes for table `tb_registration`
--
ALTER TABLE `tb_registration`
  ADD PRIMARY KEY (`r_tid`),
  ADD KEY `r_student` (`r_student`),
  ADD KEY `r_course` (`r_course`),
  ADD KEY `r_status` (`r_status`) USING BTREE;

--
-- Indexes for table `tb_status`
--
ALTER TABLE `tb_status`
  ADD PRIMARY KEY (`s_id`);

--
-- Indexes for table `tb_user`
--
ALTER TABLE `tb_user`
  ADD PRIMARY KEY (`u_sno`),
  ADD KEY `u_type` (`u_utype`);

--
-- Indexes for table `tb_utype`
--
ALTER TABLE `tb_utype`
  ADD PRIMARY KEY (`t_id`);

--
-- AUTO_INCREMENT for dumped tables
--

--
-- AUTO_INCREMENT for table `tb_registration`
--
ALTER TABLE `tb_registration`
  MODIFY `r_tid` int(11) NOT NULL AUTO_INCREMENT COMMENT 'This is transaction ID', AUTO_INCREMENT=20;

--
-- Constraints for dumped tables
--

--
-- Constraints for table `tb_course`
--
ALTER TABLE `tb_course`
  ADD CONSTRAINT `tb_course_ibfk_1` FOREIGN KEY (`c_lec`) REFERENCES `tb_user` (`u_sno`);

--
-- Constraints for table `tb_registration`
--
ALTER TABLE `tb_registration`
  ADD CONSTRAINT `tb_registration_ibfk_1` FOREIGN KEY (`r_student`) REFERENCES `tb_user` (`u_sno`),
  ADD CONSTRAINT `tb_registration_ibfk_2` FOREIGN KEY (`r_course`) REFERENCES `tb_course` (`c_code`) ON DELETE CASCADE,
  ADD CONSTRAINT `tb_registration_ibfk_3` FOREIGN KEY (`r_status`) REFERENCES `tb_status` (`s_id`);

--
-- Constraints for table `tb_user`
--
ALTER TABLE `tb_user`
  ADD CONSTRAINT `tb_user_ibfk_1` FOREIGN KEY (`u_utype`) REFERENCES `tb_utype` (`t_id`);
COMMIT;

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
