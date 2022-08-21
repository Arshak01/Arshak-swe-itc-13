create database t3;

use t3;

create table Employee(id int unique not null, num varchar(50), primary key(id));

insert into Employee values
    (1, 1),
    (2, 1),
    (3, 1),
    (4, 2),
    (5, 1),
    (6, 2),
    (7, 2);

select num as ConsecutiveNums from Employee group by num having count(num) > 3;

drop database t3;
