
/* *********** Task N 1  *********** */

CREATE DATABASE Task1;
USE Task1;

CREATE TABLE Employee(
    EmployeeId int NOT NULL AUTO_INCREMENT,
    salary int,
    PRIMARY KEY(EmployeeId)
);

insert into Employee(salary) VALUES (100);
insert into Employee(salary) VALUES (200);
insert into Employee(salary) VALUES (300);

select * from Employee;

select Max(salary) from Employee
    where salary < (select Max(salary) from Employee
);

DROP TABLE Employee;
DROP DATABASE Task1;


/* *********** Task N 2 *********** */

CREATE DATABASE Task2;
USE Task2;

CREATE TABLE Employee(
    EmployeeId int NOT NULL AUTO_INCREMENT,
    num varchar(10),
    PRIMARY KEY(EmployeeId)
);

insert into Employee(num) VALUES (1);
insert into Employee(num) VALUES (1);
insert into Employee(num) VALUES (1);
insert into Employee(num) VALUES (1);
insert into Employee(num) VALUES (2);
insert into Employee(num) VALUES (1);
insert into Employee(num) VALUES (1);

select * from Employee;

select num as ConsecutiveNums
from Employee group by  num
having COUNT(num) > 3;

DROP TABLE Employee;
DROP DATABASE Task2;



/* *********** Task N 3 *********** */

CREATE DATABASE Task3;
USE Task3;

CREATE TABLE Employee(
    EmployeeId int NOT NULL AUTO_INCREMENT,
    name varchar(30),
    salary int,
    departamentId int,
    primary key(EmployeeId)
);

CREATE TABLE Departament(
    DepartamentId int NOT NULL AUTO_INCREMENT,
    name varchar(10),
    primary key(DepartamentId)
);

describe Employee;
describe Departament;

insert into Departament(name) value('IT');
insert into Departament(name) value('Sales');

insert into Employee(name,salary,departamentId) values ('Joe', 70000,1);
insert into Employee(name,salary,departamentId) values ('Jim', 90000,1);
insert into Employee(name,salary,departamentId) values ('Henry', 80000,2);
insert into Employee(name,salary,departamentId) values ('Sam', 60000,2);
insert into Employee(name,salary,departamentId) values ('Max', 90000,1);

SELECT * FROM Employee;

SELECT Employee.name, Employee.salary, Departament.name
FROM Employee
INNER JOIN Departament
ON Employee.departamentId = Departament.departamentId
WHERE salary IN (SELECT MAX(salary) FROM  Employee GROUP BY departamentId);

DROP TABLE Employee;
DROP TABLE Departament;
DROP DATABASE Task3;