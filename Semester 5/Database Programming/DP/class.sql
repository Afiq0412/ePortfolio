use company;

CREATE TABLE addresses (
	address_id 	SMALLINT NOT NULL AUTO_INCREMENT,
    street 		VARCHAR(50) NOT NULL,
    city 		VARCHAR(30) NOT NULL,
    PRIMARY KEY (address_id)
);

CREATE TABLE stores (
	store_id 	TINYINT NOT NULL AUTO_INCREMENT,
    store_name 	VARCHAR(30) NOT NULL,
    address_id 	SMALLINT UNSIGNED NOT NULL,
    PRIMARY KEY (store_id)
);

CREATE TABLE customer (
    customer_id	SMALLINT UNSIGNED NOT NULL AUTO_INCREMENT,
    store_id 	TINYINT NOT NULL,
    first_name 	VARCHAR(45) NOT NULL,
    last_name 	VARCHAR(45) NOT NULL,
    email 		VARCHAR(50) DEFAULT NULL,
    address_id 	SMALLINT UNSIGNED NOT NULL,
    active 		BOOLEAN NOT NULL DEFAULT TRUE,
    create_date DATETIME NOT NULL,
    last_update TIMESTAMP DEFAULT CURRENT_TIMESTAMP
				ON UPDATE CURRENT_TIMESTAMP,
    PRIMARY KEY (customer_id)
);
ALTER TABLE addresses
	MODIFY address_id SMALLINT UNSIGNED;

ALTER TABLE stores
	ADD CONSTRAINT fk_store_address
    FOREIGN KEY (address_id) REFERENCES addresses(address_id)
    ON DELETE RESTRICT
    ON UPDATE CASCADE;
    
ALTER TABLE customer
	ADD CONSTRAINT fk_customer_store
    FOREIGN KEY (store_id) REFERENCES stores(store_id)
	ON DELETE RESTRICT
    ON UPDATE CASCADE;
    
ALTER TABLE customer
	ADD CONSTRAINT fk_customer_address
    FOREIGN KEY (address_id) REFERENCES addresses(address_id)
	ON DELETE RESTRICT
    ON UPDATE CASCADE;
