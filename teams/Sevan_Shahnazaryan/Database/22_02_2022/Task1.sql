create database t3;

use t3;

create table Employee(id int not null unique auto_increment, salary int, primary key(id));

insert into Employee values (1, 100), (2, 200), (3, 300);

delimiter //
create procedure second_highest()
    begin select max(Employee.salary) as SecondHighestSalary
    from Employee
    where salary not in
    (select max(salary) from Employee);
    end; //

delimiter ;

call second_highest();
drop database t3;
