create database t3;

use t3;

create table Department(id int unique not null, name varchar(30), primary key(id));

create table Employee(id int unique not null, name varchar(30), salary int, departamentId int, primary key(id), foreign key(departamentId) references Department(id));

insert into Department values(1, 'IT'), (2, 'Sales');

insert into Employee values
    (1, 'Joe', 70000, 1),
    (2, 'Jim', 90000, 1),
    (3, 'Henry', 80000, 2),
    (4, 'Sam', 60000, 2),
    (5, 'Max', 90000, 1);

select Department.name as 'Department', Employee.name as 'Employee', Employee.salary as 'Salary'
from Employee inner join Department on Employee.departamentid = Department.id
where Employee.salary in (select max(Salary) from Employee group by departamentId);

drop databasae t3;
