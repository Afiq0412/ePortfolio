CREATE DATABASE hostel_mgmt_adibafiq;
use hostel_mgmt_adibafiq;

CREATE TABLE room_types (
	type_id INT PRIMARY KEY,
    type_name VARCHAR(10),
    rent DECIMAL(10,2),
    deposit DECIMAL(10,2),
    capacity INT
);

CREATE TABLE rooms (
	room_id VARCHAR(5) PRIMARY KEY,
    type_id INT,
    room_no VARCHAR(10),
    floor_no INT,
    is_occupied BOOLEAN,
    FOREIGN KEY (type_id) REFERENCES room_types(type_id)
);

CREATE TABLE students (
	student_id VARCHAR(10) PRIMARY KEY,
    room_id VARCHAR(5),
    fname VARCHAR(30) NOT NULL,
    lname VARCHAR(30) NOT NULL,
    status VARCHAR(20),
    checkin_date DATE,
    FOREIGN KEY (room_id) REFERENCES rooms(room_id)
);

CREATE TABLE maintenance (
	maint_id INT PRIMARY KEY,
    room_id VARCHAR(5),
    issue_desc TEXT,
    severity VARCHAR(15),
    status VARCHAR(10),
    reported_on DATE,
    resolved_on DATE,
    FOREIGN KEY (room_id) REFERENCES rooms(room_id)
);

CREATE TABLE payments (
	payment_id INT PRIMARY KEY,
    student_id VARCHAR(10),
    amount DECIMAL(10,2),
    paid_on DATE,
    method VARCHAR(10),
    note TEXT,
    FOREIGN KEY (student_id) REFERENCES students(student_id)
);

ALTER TABLE students
	ADD COLUMN email VARCHAR(30) UNIQUE;
    
CREATE TABLE test_table (
	test_id INT PRIMARY KEY
);

DROP TABLE test_table;

# Data Insertion (DML)
INSERT INTO room_types (type_id, type_name, rent, deposit, capacity) 
VALUES
(1, 'Single', 550.00, 250.00, 1),
(2, 'Double', 450.00, 150.00, 2),
(3, 'Family', 750.00, 350.00, 4),
(4, 'Premium', 950.00, 450.00, 2),
(5, 'Single', 530.00, 200.00, 1),
(6, 'Double', 420.00, 120.00, 2),
(7, 'Family', 820.00, 300.00, 5),
(8, 'Premium', 980.00, 500.00, 2),
(9, 'Single', 580.00, 220.00, 1),
(10, 'Double', 460.00, 180.00, 2);

INSERT INTO rooms (room_id, room_no, floor_no, is_occupied, type_id) 
VALUES
('R001','A101', 1, TRUE, 1),
('R002','A102', 1, TRUE, 2),
('R003','A103', 1, FALSE, 3),
('R004','B201', 2, TRUE, 4),
('R005','B202', 2, FALSE, 5),
('R006','B203', 3, TRUE, 6),
('R007','C301', 3, TRUE, 7),
('R008','C302', 4, FALSE, 8),
('R009','C303', 4, TRUE, 9),
('R010','C304', 4, FALSE, 10);

INSERT INTO students (student_id, room_id, fname, lname, status, checkin_date, email) 
VALUES
('A001', 'R001', 'Aiman', 'Rahman', 'ACTIVE', '2025-01-10', 'aiman@gmail.com'),
('A002', 'R002', 'Bella', 'Tan', 'ACTIVE', '2025-02-12', 'bella@gmail.com'),
('A003', 'R004', 'Chong', 'Wei', 'ACTIVE', '2025-03-05', 'chong@gmail.com'),
('A004', 'R006', 'Dina', 'Ahmad', 'ACTIVE', '2025-04-20', 'dina@gmail.com'),
('A005', 'R007', 'Eddy', 'Low', 'ACTIVE', '2025-05-25', 'eddy@gmail.com'),
('A006', NULL, 'Farah', 'Ali', 'NON_ACTIVE', NULL, 'farah@gmail.com'),
('A007', NULL, 'Goh', 'Chin', 'NON_ACTIVE', NULL, 'goh@gmail.com'),
('A008', NULL, 'Hana', 'Zulkifli', 'NON_ACTIVE', NULL, 'hana@gmail.com'),
('A009', 'R009', 'Ivan', 'Lim', 'ACTIVE', '2025-06-10', 'ivan@gmail.com'),
('A010', 'R010', 'Julia', 'Teo', 'ACTIVE', '2025-06-15', 'julia@gmail.com');

SELECT * FROM students;

INSERT INTO maintenance (maint_id, room_id, issue_desc, severity, status, reported_on, resolved_on) 
VALUES
(1, 'R001', 'Aircond not cooling', 'HIGH', 'RESOLVED', '2025-01-05', '2025-01-07'),
(2, 'R002', 'Broken desk', 'LOW', 'RESOLVED', '2025-01-10', '2025-01-12'),
(3, 'R003', 'Water leak', 'MEDIUM', 'OPEN', '2025-02-03', NULL),
(4, 'R004', 'Power socket malfunction', 'MEDIUM', 'RESOLVED', '2025-02-08', '2025-02-09'),
(5, 'R005', 'Window crack', 'LOW', 'OPEN', '2025-03-02', NULL),
(6, 'R006', 'Internet not working', 'HIGH', 'OPEN', '2025-03-15', NULL),
(7, 'R007', 'Light bulb flickering', 'LOW', 'RESOLVED', '2025-04-05', '2025-04-30'),
(8, 'R008', 'Door hinge broken', 'MEDIUM', 'OPEN', '2025-05-11', NULL),
(9, 'R009', 'Aircond noise', 'LOW', 'RESOLVED', '2025-05-20', '2025-06-11'),
(10, 'R010', 'Floor tiles loose', 'MEDIUM', 'OPEN', '2025-06-01', NULL),
(11, 'R003', 'Ceiling paint peeling', 'LOW', 'OPEN', '2025-06-20', NULL),
(12, 'R005', 'Desk drawer stuck', 'LOW', 'RESOLVED', '2025-06-18', '2025-06-19'),
(13, 'R002', 'Aircond water dripping', 'MEDIUM', 'OPEN', '2025-07-01', NULL),
(14, 'R008', 'Broken curtain rail', 'LOW', 'RESOLVED', '2025-07-03', '2025-07-04'),
(15, 'R010', 'Shower pressure low', 'MEDIUM', 'OPEN', '2025-07-05', NULL);

SELECT * FROM maintenance;

INSERT INTO payments (payment_id, amount, paid_on, method, note, student_id) 
VALUES
(1, 550.00, '2025-01-15', 'CASH', 'January rent', 'A001'),
(2, 450.00, '2025-02-20', 'FPX', 'February rent', 'A002'),
(3, 950.00, '2025-03-10', 'CARD', 'March rent', 'A003'),
(4, 980.00, '2025-04-15', 'FPX', 'April rent', 'A004'),
(5, 820.00, '2025-05-12', 'CARD', 'May rent', 'A005'),
(6, 530.00, '2025-02-10', 'CASH', 'Deposit for new room', 'A006'),
(7, 460.00, '2025-03-05', 'TNG', 'Partial rent', 'A007'),
(8, 820.00, '2025-05-15', 'FPX', 'Full rent', 'A008'),
(9, 750.00, '2025-06-05', 'CARD', 'June rent', 'A009'),
(10, 950.00, '2025-06-10', 'TNG', 'June rent', 'A010');

# UPDATE and DELETE Operation
UPDATE rooms
SET is_occupied = TRUE
WHERE room_id IN (
	SELECT room_id
    FROM students
    WHERE status = 'ACTIVE'
);

SET SQL_SAFE_UPDATES = 0;
DELETE FROM maintenance
WHERE status = 'RESOLVED' AND DATEDIFF(CURDATE(), reported_on) > 60;

# Data Retrieval and Filtering Queries
SELECT * 
FROM room_types
WHERE rent BETWEEN 400 AND 800;

SELECT *
FROM students
WHERE fname LIKE 'A%';

SELECT *
FROM payments
WHERE method IN ('FPX','CARD');

# Function and Expressions

SELECT method, SUM(amount) AS total_payments
FROM payments
GROUP BY method;

SELECT student_id, UPPER(CONCAT(fname, ' ', lname)) AS student_full_name, email
FROM students;

# Task 3 - Reporting and Aggregation

CREATE VIEW v_room_status AS
SELECT 
    r.room_no,
    rt.type_name,
    rt.rent,
    r.floor_no,
    rt.capacity,
    (
        SELECT COUNT(*)
        FROM students s
        WHERE s.room_id = r.room_id
          AND s.status = 'ACTIVE'
    ) AS n_occupants,
    (
        SELECT COUNT(*)
        FROM maintenance m
        WHERE m.room_id = r.room_id
          AND m.status = 'OPEN'
    ) AS pending_issues,

    CASE 
        WHEN (
            SELECT COUNT(*)
            FROM students s2
            WHERE s2.room_id = r.room_id
              AND s2.status = 'ACTIVE'
        ) = 0 
        THEN TRUE ELSE FALSE
    END AS is_vacant

FROM rooms r
JOIN room_types rt ON r.type_id = rt.type_id;

SELECT * FROM v_room_status;

# 1
SELECT rt.type_name, COUNT(s.student_id) AS total_students
FROM room_types rt
LEFT JOIN rooms r ON rt.type_id = r.type_id
LEFT JOIN students s ON r.room_id = s.room_id
GROUP BY rt.type_name;

# 2
SELECT 
    type_name,
    ROUND(AVG(rent), 2) AS avg_rent,
    ROUND(SUM(deposit), 2) AS total_deposit
FROM room_types
GROUP BY type_name;

# 3
SELECT 
	YEAR(paid_on) AS pay_year,
    MONTH(paid_on) AS pay_month,
    SUM(amount) AS total_amount
FROM payments
GROUP BY YEAR(paid_on), MONTH(paid_on)
ORDER BY pay_year, pay_month;

# 4
SELECT
	r.floor_no,
    COUNT(m.maint_id) AS open_issues
FROM maintenance m
JOIN rooms r ON r.room_id = m.room_id
WHERE m.status = 'OPEN'
GROUP BY r.floor_no
HAVING COUNT(m.maint_id) > 2;

SELECT 
    r.room_no,
    UPPER(CONCAT(s.fname, ' ', s.lname)) AS student_name,
    rt.type_name,
    ROUND(rt.rent, 2) AS rent_rounded,
    r.floor_no,
    rt.capacity,
    CASE
        WHEN rt.rent < 500 THEN 'LOW'
        WHEN rt.rent >= 500 AND rt.rent < 800 THEN 'MEDIUM'
        ELSE 'HIGH'
    END AS rent_category
FROM rooms r
JOIN room_types rt ON r.type_id = rt.type_id
JOIN students s ON s.room_id = r.room_id
ORDER BY r.room_no;

