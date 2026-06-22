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
