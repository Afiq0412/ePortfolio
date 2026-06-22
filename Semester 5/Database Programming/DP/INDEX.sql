SELECT * FROM company.employee;
#b-tree index on salary
CREATE INDEX idx_emp_salary
ON employee (salary);

#sql query select
SELECT *
FROM employee
WHERE salary BETWEEN 1000 AND 2000;

CREATE TABLE articles (
	article_id INT PRIMARY KEY,
    title VARCHAR (100),
    content TEXT
);

CREATE
FULLTEXT INDEX idx_content
ON articles (content);

SELECT *
FROM articles
WHERE MATCH (content)
AGAINST
('machine learning' IN NATURAL LANGUAGE MODE);