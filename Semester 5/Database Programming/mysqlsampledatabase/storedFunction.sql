USE classicmodels;

DELIMITER $$
CREATE FUNCTION CustomerLevel(credit DECIMAL(10,2))
RETURNS VARCHAR(20)
DETERMINISTIC
BEGIN
	DECLARE customerLevel VARCHAR(20);
    
    IF credit > 50000 THEN
		SET customerLevel = 'PLATINUM';
	ELSEIF (credit <= 50000 AND credit >= 10000) THEN 
		SET customerLevel = 'GOLD';
	ELSEIF credit < 10000 THEN 
		SET customerLevel = 'SILVER';
	END IF;
		RETURN (customerLevel);

END $$
DELIMITER ;

SELECT customerName, CustomerLevel(creditLimit)
FROM customers
ORDER BY customerName;

DELIMITER $$
CREATE FUNCTION CountOrdersByCustomer(custNo INT)
RETURNS INT 
DETERMINISTIC
BEGIN
	DECLARE totalOrders INT DEFAULT 0;
    SELECT COUNT(*)
    INTO totalOrders
    FROM orders
    WHERE customerNumber = custNo;
    
    RETURN (totalOrders);

END $$
DELIMITER ;

SELECT CountOrdersByCustomer(103) AS total_orders_for_103;

SELECT customerNumber, customerName, CountOrdersByCustomer(customerNumber) AS total_orders
FROM customers
ORDER BY total_orders DESC;

DELIMITER $$

CREATE FUNCTION CountOrdersByCustomer(custNo INT) 
RETURNS INT
DETERMINISTIC
BEGIN
    -- Requirement 2: Declare local variable
    DECLARE totalOrders INT;

    -- Requirement 3.1 & 3.2: Count orders and store in variable
    SELECT COUNT(*) 
    INTO totalOrders
    FROM orders
    WHERE customerNumber = custNo;

    -- Requirement 3.3: Return the result
    RETURN totalOrders;
END$$

DELIMITER ;