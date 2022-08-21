create database Emp;

create table Emp.Employee(
	EmployeeID int NOT NULL AUTO_INCREMENT,
	Salary int,
	PRIMARY KEY (EmployeeID)
);

insert into Emp.Employee(Salary) values     
	(100),
	(200),
	(300);

select * from Emp.Employee;

select Max(Salary) as SecondHighestSalary from Emp.Employee
	where Salary < (select Max(Salary) from Emp.Employee);

drop database Emp;
