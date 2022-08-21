create database Max;

create table Max.Temp(
	TempID int NOT NULL AUTO_INCREMENT,
	Name varchar(30),
	Salary int,
	DepartamentID int,
	PRIMARY KEY (TempID)
);

create table Max.Departament(
	DepartmentID int NOT NULL AUTO_INCREMENT,
	Name varchar(30),
	PRIMARY KEY (DepartmentID)
);

insert into Max.Departament(Name) values
	('IT'),
	('Sales');

insert into Max.Temp(Name, Salary, DepartamentID) values 
	('Joe', 70000,1),
	('Jim', 90000,1),
	('Henry', 80000,2),
	('Sam', 60000,2),
	('Max', 90000,1);

select * from Max.Temp;

select Temp.Name, Temp.Salary, Departament.Name from Max.Temp 
	JOIN Max.Departament ON Temp.DepartamentID = Departament.DepartmentID
	where Salary IN (select MAX(Salary) FROM Max.Temp GROUP BY Temp.DepartamentID);

drop database Max;
