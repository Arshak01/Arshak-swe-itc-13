create database task3;

use task3;

create table temp(
id int not null auto_increment,
name varchar(30),
salary int,
departament_id int,
primary key(id));

create table departament(
id int not null auto_increment,
name varchar(10),
primary key(id));

describe temp;

insert into departament(name) value('IT');
insert into departament(name) value('Sales');

insert into temp(name,salary,departament_id) values ('Joe', 70000,1);
insert into temp(name,salary,departament_id) values ('Jim', 90000,1);
insert into temp(name,salary,departament_id) values ('Henry', 80000,2);
insert into temp(name,salary,departament_id) values ('Sam', 60000,2);
insert into temp(name,salary,departament_id) values ('Max', 90000,1);

select * from temp;

SELECT temp.name, temp.salary, departament.name
FROM temp
INNER JOIN departament 
ON temp.departament_id = departament.id
WHERE Salary IN (SELECT MAX(Salary) FROM  temp GROUP BY departament_id);

drop database task3;