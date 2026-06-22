use company;

ALTER TABLE Employee
	ADD COLUMN salary DOUBLE,
    ADD COLUMN managerID INT (5),
    ADD CONSTRAINT fk_managerID
		FOREIGN KEY (managerID) REFERENCES Manager(managerID);
    
    
CREATE TABLE Manager (
	managerID INT (5) PRIMARY KEY,
    managerName VARCHAR(30),
    position VARCHAR(20),
    deptNo INT,
    salary DOUBLE,
    FOREIGN KEY (deptNo) REFERENCES Department(deptNo) 
);

INSERT INTO Department (deptNo, deptName, address, city)
VALUES
(1001, 'Financial', 'Taman Cahaya', 'Purnama'),
(1002, 'Supplier', 'Jalan Anggur', 'Permata'),
(1003, 'Human Resources', 'Laman Bahagia', 'Tropika');

SELECT * FROM Department;

INSERT INTO Manager (managerID, managerName, position, deptNo, salary)
VALUES
(1010, 'Alif', 'Executive', 1001, 20000.0),
(1020, 'Iman', 'CEO', 1002, 50000.0),
(1030, 'Ali', 'President', 1003, 42000.0);

SELECT * FROM Manager;

INSERT INTO Employee (empID, fName, lName, deptNo, salary, managerID)
VALUES
(110, 'Kasim', 'Ahmad', 1001, 1500.0, 1010),
(111, 'Man', 'Kacip', 1003, 1800.0, 1020);

INSERT INTO Employee (empID, fName, lName, deptNo, salary, managerID)
VALUES
(112, 'Leman', 'Ahmad', 1001, 1700.0, 1010);

SELECT * FROM Employee;

SELECT empID, salary
FROM employee
WHERE deptNo= (
SELECT deptNo
FROM department
WHERE
deptName = 'Financial');

SELECT e.empID, e.fName, e.lName, d.deptName
FROM employee e
JOIN department d ON e.deptNo = d.deptNo;

SELECT empID, fName, lName, deptName
FROM employee
NATURAL JOIN department;

SELECT empID, fName, lName, deptName
FROM employee
JOIN department USING (deptNo);

SELECT e.empID, e.fName, e.salary , d.city
FROM employee e
JOIN department d ON d.deptNo = e.deptNo
WHERE d.city = 'Purnama'
AND e.salary >= 1000;


SELECT e.empID, e.fName, e.lName, m.empID, m.fName, m.lName
FROM employee e
JOIN employee m ON e.managerID = m.empID;

SELECT e.managerID, m.fName, m.lName
FROM employee e
JOIN employee m ON e.managerID = m.empID;