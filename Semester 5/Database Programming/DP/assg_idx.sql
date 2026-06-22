CREATE DATABASE index_lab;
USE index_lab;

CREATE TABLE employee(
	emp_id INT AUTO_INCREMENT PRIMARY KEY,
	emp_name VARCHAR(50), 
    department VARCHAR(30), 
    salary DECIMAL(10,2), 
    join_date DATE
); 

INSERT INTO employee (emp_name, department, salary, join_date) 
VALUES
('Aiman Hakim', 'IT', 2500.00, '2021-02-15'),
('Siti Noraini', 'Finance', 7200.00, '2020-08-10'),
('Farhan Rosli', 'HR', 2900.00, '2022-01-12'),
('Nadia Karim', 'Marketing', 8000.00, '2023-03-19'),
('Daniel Wong', 'Sales', 5100.00, '2020-11-25'),
('Nur Alia', 'IT', 7600.00, '2022-09-05'),
('Hafiz Rahman', 'Finance', 2600.00, '2019-07-01'),
('Melissa Tan', 'Operations', 4900.00, '2021-06-17'),
('Azlan Musa', 'IT', 7500.00, '2023-02-10'),
('Intan Zulaikha', 'HR', 2700.00, '2021-10-22'),
('Shahrul Nizam', 'Sales', 8200.00, '2020-12-14'),
('Carmen Lee', 'Finance', 9000.00, '2018-05-09'),
('Arif Faiz', 'Operations', 2100.00, '2022-07-23'),
('Nabila Rosman', 'IT', 8800.00, '2023-08-03'),
('Syafiq Izzuddin', 'Marketing', 2300.00, '2021-09-18'),
('Wei Jun', 'Finance', 7900.00, '2019-03-12'),
('Amirah Bakar', 'Operations', 2400.00, '2020-04-28'),
('Irfan Hadi', 'IT', 8700.00, '2023-06-11'),
('Zainab Omar', 'Sales', 7300.00, '2021-12-06'),
('Hassan Ali', 'HR', 2800.00, '2020-10-30');

SELECT * FROM employee;

set profiling = 1;

CREATE INDEX idx_salary ON employee(salary);

SELECT * FROM employee WHERE salary BETWEEN 3000 AND 7000;

show profiles;

DROP INDEX idx_salary ON employee;

CREATE INDEX idx_join_date ON employee(join_date);

SELECT * FROM employee WHERE join_date BETWEEN '2022-01-01' AND '2025-01-01';

DROP INDEX idx_join_date ON employee;

DROP TABLE employee;

SHOW INDEX FROM employee FROM index_lab;