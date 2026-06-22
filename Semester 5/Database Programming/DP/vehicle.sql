use company;

CREATE TABLE Vehicle (
		vehicleID INT PRIMARY KEY,
        year YEAR,
        make VARCHAR(40)
);
#add new columns model color notes
ALTER TABLE Vehicle
	ADD column model varchar(50),
    ADD column color varchar(30),
    ADD column note text;
    
#modify column model varchar (50) change to 20
ALTER TABLE Vehicle
	MODIFY COLUMN model varchar(20);
    
ALTER TABLE Vehicle
	CHANGE COLUMN note vehicleCondition TEXT;
    
#Table Structure
describe Vehicle;

#insert multiple rows
INSERT INTO Vehicle (vehicleID, year, make, model, color, vehicleCondition)
VALUES
(101, 2019, 'Honda', 'Civic', 'White', 'Fair'),
(102, 2025, 'Perodua', 'Myvi', 'Silver', 'Good'),
(103, 2015, 'Toyota', 'Hilux', 'Black', 'Fair'),
(104, 2015, 'Toyota', 'Vios', 'Red', 'Good');

#update, change the color and vehicleCondition
UPDATE Vehicle
SET color = 'Maroon', vehicleCondition = 'Very Good'
WHERE vehicleID = 104;

#change condition year is less than 2019 require
UPDATE Vehicle
SET vehicleCondition = 'Requires Service'
WHERE year < 2019;

SELECT * FROM Vehicle
ORDER BY make;

SELECT * FROM Vehicle
ORDER BY year DESC, make ASC;








#logical operator
#AND
SELECT * FROM Vehicle
WHERE year > 2019 AND color = 'white';

#OR
SELECT vehicleID, make, model, year
FROM vehicle
WHERE make = 'Toyota' OR make = 'Perodua';

SELECT vehicleID, make, model, vehicleCondition
FROM Vehicle
WHERE NOT (vehicleCondition = 'Fair');

#range, between .... and .....

SELECT vehicleID, make, year
FROM Vehicle
WHERE year BETWEEN 2019 AND 2025;

#null
SELECT vehicleID, vehicleCondition
FROM Vehicle
WHERE vehicleCondition IS NULL;

#distinct remove duplicates
SELECT DISTINCT make FROM Vehicle
ORDER BY make;