create database task2;

create table task2.temp(
id int not null auto_increment,
num int,
primary key(id));

insert into task2.temp(num) value (1);
insert into task2.temp(num) value (1);
insert into task2.temp(num) value (1);
insert into task2.temp(num) value (2);
insert into task2.temp(num) value (1);
insert into task2.temp(num) value (2);
insert into task2.temp(num) value (2);

select * from task2.temp;
select num as ConsecutiveNums from task2.temp group by  num having COUNT(num) > 3;

drop database task2;