CREATE database db;

CREATE table db.parents
(parent_ID int NOT NULL UNIQUE, 
mother_name varchar(50) NOT NULL, 
father_name varchar(50) NOT NULL, 
PRIMARY KEY(parent_ID));

CREATE table db.kids
(kid_ID int NOT NULL UNIQUE, 
kid_name varchar(50) NOT NULL, 
parent_ID int NOT NULL, 
FOREIGN KEY(parent_ID) REFERENCES db.parents(parent_ID));

INSERT into db.parents values 
(0, "Poghosuhi", "Poghos"),
(1, "Petrosuhi", "Petros"), 
(2, "Armen", "Armenuhi");

INSERT INTO db.kids values 
(17, "Philipos", 1),
(18, "Serob", 1), 
(20, "Hakobos", 1), 
(21, "Pharandzem", 2),
(24, "Smbat", 0),
(26, "Ararat", 0),
(30, "Varduhi", 0),
(45, "Karine", 2),
(46, "Satine", 2),
(49, "Qvazimodo", 2);

SELECT * from db.parents;
SELECT * from db.kids;

DROP table db.kids;
DROP table db.parents;
DROP database db;

