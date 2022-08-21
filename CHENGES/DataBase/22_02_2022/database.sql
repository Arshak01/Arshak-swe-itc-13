
CREATE DATABASE Task1;
USE Task1;

CREATE TABLE Cinema(
    CinemaId int NOT NULL AUTO_INCREMENT,
    movie varchar(100),
    description varchar(400),
    rating float,
    PRIMARY KEY (CinemaId)
);

INSERT into Cinema(movie,description,rating) VALUES ('War','great 3D',8.9);
INSERT into Cinema(movie,description,rating) VALUES ('Science','fiction',8.5);
INSERT into Cinema(movie,description,rating) VALUES ('irish','boring',6.2);
INSERT into Cinema(movie,description,rating) VALUES ('Ice song','Fantacy',8.6);
INSERT into Cinema(movie,description,rating) VALUES ('House card','Interesting',9.1);

SELECT * FROM Cinema;

SELECT * FROM Cinema
WHERE CinemaId%2!=0 and description <> 'boring'
ORDER BY CinemaId desc;

DROP TABLE Cinema;
DROP DATABASE Task1;


--##################


CREATE DATABASE Task2;
USE Task2;

CREATE TABLE Person(
    PersonId int NOT NULL AUTO_INCREMENT,
    lastName varchar(50),
    firstName varchar(50),
    PRIMARY KEY (PersonId)
);

CREATE TABLE Address(
    AddressId int NOT NULL AUTO_INCREMENT,
    FK_PersonId int,
    city varchar(30),
    state varchar(30),
    PRIMARY KEY (AddressId),
    FOREIGN KEY (FK_PersonId) REFERENCES Person(PersonId)
);


INSERT into Person(lastName,firstName) VALUES ('Wang','Allen');
INSERT into Person(lastName,firstName) VALUES ('Alice','Bob');

INSERT into Address(FK_PersonId,city,state) VALUES (2,'New York City','New York');
INSERT into Address(FK_PersonId,city,state) VALUES (2,'Los Angles','California');

SELECT * FROM Person;
SELECT * FROM Address;

SELECT firstName, lastName, city, state from  Person LEFT JOIN Address
on Person.PersonId = Address.FK_PersonId;

DROP TABLE Address;
DROP TABLE Person;
DROP DATABASE Task2;


--#########################


CREATE DATABASE Task3;
USE Task3;

CREATE TABLE Person(
    PersonId int NOT NULL AUTO_INCREMENT,
    email varchar(500),
    PRIMARY KEY (PersonId)
);

INSERT into Person(email) VALUES ('a@b.com');
INSERT into Person(email) VALUES ('a@c.com');
INSERT into Person(email) VALUES ('a@b.com');

SELECT * FROM Person;

SELECT email from Person
group by email
having count(email) > 1;

DROP TABLE Person;
DROP DATABASE Task3;


--###########################


CREATE DATABASE Task4;
USE Task4;

CREATE TABLE Department(
    DepartmentId int NOT NULL AUTO_INCREMENT,
    name varchar(30),
    PRIMARY KEY (DepartmentId)
);

CREATE TABLE Employee(
    EmployeeId int NOT NULL AUTO_INCREMENT,
    name varchar(20),
    salary int,
    FK_departmentId int,
    PRIMARY KEY(EmployeeId),
    FOREIGN KEY(FK_departmentId) REFERENCES Department(DepartmentId)
);

INSERT into Department(name) VALUES ('IT');
INSERT into Department(name) VALUES ('Sales');

INSERT into Employee(name,salary,FK_departmentId) VALUES ('Joe',70000,1);
INSERT into Employee(name,salary,FK_departmentId) VALUES ('Jim',90000,2);
INSERT into Employee(name,salary,FK_departmentId) VALUES ('Henry',80000,1);
INSERT into Employee(name,salary,FK_departmentId) VALUES ('Sam',60000,2);
INSERT into Employee(name,salary,FK_departmentId) VALUES ('Max',90000,2);
INSERT into Employee(name,salary,FK_departmentId) VALUES ('Ray',100000,1);

SELECT * FROM Department;
SELECT * FROM Employee;

SELECT FK_departmentId, max(salary) FROM Employee
GROUP BY FK_departmentId;

DROP TABLE Employee;
DROP TABLE Department;
DROP DATABASE Task4;


--##########################


CREATE DATABASE Task5;
USE Task5;

CREATE TABLE Seat(
    SeatId int NOT NULL AUTO_INCREMENT,
    name varchar(30),
    PRIMARY KEY (SeatId)
);

INSERT into Seat(name) VALUES ('Jim');
INSERT into Seat(name) VALUES ('Henry');
INSERT into Seat(name) VALUES ('Sam');
INSERT into Seat(name) VALUES ('Max');
INSERT into Seat(name) VALUES ('Ray');
INSERT into Seat(name) VALUES ('Joe');

SELECT * FROM Seat;

SELECT SeatId, name FROM Seat

ORDER BY SeatId DESC;

DROP TABLE Seat;
DROP DATABASE Task5;