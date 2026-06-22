use company;

CREATE TABLE members (
	member_id INT AUTO_INCREMENT,
    name VARCHAR (100),
    PRIMARY KEY (member_id)
);

CREATE TABLE committees (
	committeer_id INT AUTO_INCREMENT,
    name VARCHAR (100),
    PRIMARY KEY (committeer_id)
);

INSERT INTO members (name)
VALUES ('John'), ('Jane'), ('Mary'), ('David'), ('Amelia');

INSERT INTO committees (name)
VALUES ('John'), ('Mary'), ('Amelia'), ('Joe');

#simplejoin -> old style
SELECT members.name, committees.name
FROM members, committees
WHERE members.name = committees.name;

#natural join
SELECT name
FROM members
NATURAL JOIN committees;

#innerjoin...on
SELECT m.name
FROM members m
INNER JOIN committees c
ON m.name = c.name;

#join...on
SELECT m.name
FROM members m
JOIN committees c
ON m.name = c.name;

#left outerjoin (Table A(left): members, B(right): committees)
SELECT m.name AS Member, c.name AS Committee
FROM members m
LEFT OUTER JOIN committees c
ON m.name = c.name;

#right outerjoin (Table A(left): members, B(right): committees)
SELECT m.name AS Member, c.name AS Committee
FROM members m
RIGHT OUTER JOIN committees c
ON m.name = c.name;