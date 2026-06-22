CREATE DATABASE school;
USE school;
CREATE TABLE Students (
	studentID VARCHAR (10) PRIMARY KEY,
    fName VARCHAR (20) NOT NULL,
    lName VARCHAR (20) NOT NULL
);
CREATE TABLE Course (
	courseID VARCHAR (8) PRIMARY KEY,
    courseName VARCHAR (30) NOT NULL,
    studentID VARCHAR (10),
    FOREIGN KEY (studentID) REFERENCES Students (studentID)
);