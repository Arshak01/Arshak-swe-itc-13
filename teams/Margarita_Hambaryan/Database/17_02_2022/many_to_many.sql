CREATE database db;

CREATE table db.people(
person_ID int NOT NULL UNIQUE, 
name VARCHAR(50) NOT NULL, 
PRIMARY KEY(person_ID)
);

CREATE table db.actors(
actor_ID int NOT NULL UNIQUE, 
name VARCHAR(50) NOT NULL, 
PRIMARY KEY(actor_ID)
);

CREATE table db.fav_actors(
person_ID int NOT NULL, 
actor_ID int NOT NULL, 
FOREIGN KEY(person_ID) REFERENCES people(person_ID),
FOREIGN KEY(actor_ID) REFERENCES actors(actor_ID), 
UNIQUE(person_ID, actor_ID)
);

INSERT into db.people values
(0, "Poghos"),
(1, "Petros"),
(2, "Tadeos");

INSERT into db.actors values 
(17, "LeonardoDICaprio"), 
(18, "WillSmith"), 
(45, "MorganFreeman"), 
(33, "AngelinaJolie"), 
(56, "AdrianoChelentano");

INSERT INTO db.fav_actors values
(1, 17),
(1, 56),
(1, 33),
(2, 45), 
(2, 18), 
(0, 17), 
(0, 18), 
(2, 17);

SELECT * from db.people;
SELECT * from db.actors;
SELECT * from db.fav_actors;

DROP table db.fav_actors;
DROP table db.actors;
DROP table db.people;

DROP database db;

