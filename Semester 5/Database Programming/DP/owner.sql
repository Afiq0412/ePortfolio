use company;

CREATE TABLE owner (
	ownerID INT PRIMARY KEY,
    firstName VARCHAR(30),
    lastName VARCHAR(30),
    city VARCHAR(30)
);

INSERT INTO owner (ownerID, firstName, lastName, city)
VALUES
(1001, 'Ahmad', 'Abu', 'Bandar Batu'),
(1002, 'Ali', 'Kasim', 'Taman Pelangi'),
(1003, 'Cik', 'Siti', 'Taman Budaya'),
(1004, 'Afiq', 'Danial', 'Bandar Pahat');

ALTER TABLE Vehicle
ADD COLUMN ownerID INT,
ADD CONSTRAINT fk_vehicle_owner
	FOREIGN KEY (ownerID) REFERENCES owner(ownerID);
    
UPDATE Vehicle SET ownerID = 1 WHERE vehicleID = 101;
UPDATE Vehicle SET ownerID = 2 WHERE vehicleID = 102;
UPDATE Vehicle SET ownerID = 3 WHERE vehicleID = 103;
UPDATE Vehicle SET ownerID = 4 WHERE vehicleID = 104;

SELECT ownerID, UPPER(firstName) AS FIRST,
LOWER(lastName) AS LAST
FROM owner;

SELECT ownerID,
	CONCAT (firstName, ' ', lastName) AS fullname
FROM owner;

SELECT vehicleID, make,
	SUBSTR(make, 1, 3) as make_prefix
FROM Vehicle;

/*
SELECT vehicleID, make, model, year,
	CASE
		WHEN year >= 2019 THEN 'A:NEW'
        WHEN year BETWEEN 2019 AND 2025 THEN 'B:RECENT'
        ELSE 'C:OLDER/OTHERS'
	END AS age
    FROM Vehicle
    ORDER BY year DESC;
*/   
SELECT vehicleID, make, year,
	CASE
    WHEN year>=2019 THEN 'New'
    WHEN year BETWEEN 2015 AND 2018 THEN 'Used'
    ELSE 'Old'
    END AS status_age
FROM Vehicle;