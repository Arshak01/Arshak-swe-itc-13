
/*CREAT ONE TO ONE RELATIONSHIP*/

CREATE DATABASE OneToOne;
USE OneToOne;

CREATE TABLE Passport(
    PassportId int NOT NULL AUTO_INCREMENT,
    serialNumber int UNIQUE,
    PRIMARY KEY(PassportId)
);

CREATE TABLE Person(
    PersonId int NOT NULL AUTO_INCREMENT,
    name varchar(20),
    lastname varchar(20),
    FK_PassportId int UNIQUE,
    PRIMARY KEY(PersonId),
    FOREIGN KEY(FK_PassportId) REFERENCES Passport(PassportId)
);


INSERT into Passport(serialNumber) VALUES (156565);
INSERT into Passport(serialNumber) VALUES (156565);
INSERT into Person (name,lastname,FK_PassportId) VALUES ('Sargis', 'Hambaryan',1);
INSERT into Person (name,lastname,FK_PassportId) VALUES ('Arshak', 'Badalyan',2);

SELECT * FROM Person;
SELECT * FROM Passport;

DROP TABLE Person;
DROP TABLE Passport;

DROP DATABASE OneToOne;




/*CREAT ONE TO MANY RELATIONSHIP*/

CREATE DATABASE OneToMany;
USE OneToMany;

CREATE TABLE Teacher(
    TeacherId int NOT NULL AUTO_INCREMENT,
    tName varchar(20),
    tLastName varchar(20),
    PRIMARY KEY(TeacherId)

);

CREATE TABLE Student(
    StudentId int NOT NULL AUTO_INCREMENT,
    sName varchar(20),
    sLastName varchar(20),
    FK_TecherId int,
    PRIMARY KEY(StudentId),
    FOREIGN KEY (FK_TecherId) REFERENCES Teacher(TeacherId)

);

INSERT into Teacher(tName, tLastName) VALUES ('Dianna', 'Lalayan');
INSERT into Teacher(tName, tLastName) VALUES ('Mery', 'Grigoryan');
INSERT into Teacher(tName, tLastName) VALUES ('Sima', 'Davtyan');

INSERT into Student(sName, sLastName,FK_TecherId) VALUES ('Arman','Esayan',1);
INSERT into Student(sName, sLastName,FK_TecherId) VALUES ('Nana','Grigoryan',1);
INSERT into Student(sName, sLastName,FK_TecherId) VALUES ('Anna','Mirzoyan',2);
INSERT into Student(sName, sLastName,FK_TecherId) VALUES ('Kolya','Madacyan',1);
INSERT into Student(sName, sLastName,FK_TecherId) VALUES ('Filya','Teryan',2);

SELECT * FROM Teacher;
SELECT * FROM Student;

DROP TABLE Teacher;
DROP TABLE Student;

DROP DATABASE OneToMany;




/*CREAT MANY TO MANY RELATIONSHIP*/

CREATE DATABASE ManyToMany;
USE ManyToMany;

CREATE TABLE Employee(
    EmployeeId int NOT NULL AUTO_INCREMENT,
    name varchar(20),
    lastName varchar(20),
    PRIMARY KEY (EmployeeId)
);

CREATE TABLE Profession(
    ProfessionId int NOT NULL AUTO_INCREMENT,
    professionName varchar(40),
    PRIMARY KEY (ProfessionId)
);

CREATE TABLE Employee_Profession(
    Employee_Profession int NOT NULL AUTO_INCREMENT,
    FK_EmployeeId int,
    FK_ProfessionId int,
    PRIMARY KEY(Employee_Profession),
    FOREIGN KEY (FK_EmployeeId) REFERENCES Employee(EmployeeId),
    FOREIGN KEY (FK_ProfessionId) REFERENCES Profession(ProfessionId)
);

INSERT into Employee(name,lastName) VALUES ('Anna','Eranosyan');
INSERT into Employee(name,lastName) VALUES ('Tomma','Asatryan');
INSERT into Employee(name,lastName) VALUES ('Gor','Dallaqyan');
INSERT into Employee(name,lastName) VALUES ('Anna','Boryan');
INSERT into Employee(name,lastName) VALUES ('Gohar','Mirzoyan');
INSERT into Employee(name,lastName) VALUES ('Lilia','Surgsyan');

INSERT into Profession(professionName) VALUES ('Accountant');
INSERT into Profession(professionName) VALUES ('Baker');
INSERT into Profession(professionName) VALUES ('Cleaner');
INSERT into Profession(professionName) VALUES ('Pilot');
INSERT into Profession(professionName) VALUES ('Politician');
INSERT into Profession(professionName) VALUES ('Model');

INSERT into Employee_Profession(FK_EmployeeId, FK_ProfessionId) VALUES (1,2);
INSERT into Employee_Profession(FK_EmployeeId, FK_ProfessionId) VALUES (4,2);
INSERT into Employee_Profession(FK_EmployeeId, FK_ProfessionId) VALUES (1,5);
INSERT into Employee_Profession(FK_EmployeeId, FK_ProfessionId) VALUES (3,1);
INSERT into Employee_Profession(FK_EmployeeId, FK_ProfessionId) VALUES (5,4);
INSERT into Employee_Profession(FK_EmployeeId, FK_ProfessionId) VALUES (4,5);
INSERT into Employee_Profession(FK_EmployeeId, FK_ProfessionId) VALUES (2,1);

SELECT * FROM Employee;
SELECT * FROM Profession;
SELECT * FROM Employee_Profession;

DROP TABLE Employee_Profession;
DROP TABLE Employee;
DROP TABLE Profession;

DROP DATABASE ManyToMany;
