CREATE DATABASE company;
USE company;
CREATE TABLE Department (
	deptNo INT(5) PRIMARY KEY,
    deptName VARCHAR (20),
    address VARCHAR (30),
    city VARCHAR (15)
);
CREATE TABLE Employee (
	empID INT PRIMARY KEY,
    fName VARCHAR (10) NOT NULL,
	lName VARCHAR (20) NOT NULL,
    deptNo INT,
	FOREIGN KEY (deptNO) REFERENCES Department (deptNO)
);
    