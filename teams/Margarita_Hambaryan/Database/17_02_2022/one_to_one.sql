CREATE database db;

CREATE table db.people (
person_ID int NOT NULL UNIQUE, 
name varchar(51) NOT NULL, 
surname varchar(51) NOT NULL, 
PRIMARY KEY(person_ID)
);

CREATE table db.instagram_accounts(account_ID int NOT NULL UNIQUE, 
account varchar(51) NOT NULL UNIQUE, 
person_ID int NOT NULL UNIQUE, 
FOREIGN KEY(person_ID) REFERENCES db.people(person_ID)
);

INSERT into db.people values 
(0, "Poghos", "Poghosyan"),
(1, "Petros", "Petrosyan"), 
(2, "Martiros", "Martirosyan"),
(3, "Gevorg", "Gevorgyan"),
(4, "Sahak", "Sahakyan");


INSERT into db.instagram_accounts values
(17, "poghos_poghosyan", 0),
(21, "sahak_sahakyan", 4),
(25, "gevorg_gevorgyan", 3),
(40, "martiros_martirosyan", 2),
(47, "petros_petrosyan", 1);

SELECT * from db.people;
SELECT * from db.instagram_accounts;

DROP table db.instagram_accounts;
DROP table db.people;
DROP database db;

