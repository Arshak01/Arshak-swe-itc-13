create database task1;

create table task1.Employee(
id int not null auto_increment,
salary int,
primary key(id));

insert into task1.Employee(salary) value(100);
insert into task1.Employee(salary) value(200);
insert into task1.Employee(salary) value(300);

select * from task1.Employee;

select salary as SecondHighestSalary from(
Select Salary from task1.Employee 
order by salary desc limit 2) 
as something order by salary limit 1;

drop database task1;
