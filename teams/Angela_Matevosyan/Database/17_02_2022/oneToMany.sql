create database 1ton;
create table 1ton.Person(
    RersonId int not null,
    Name varchar(20),
    primary key(PersonId)
);
create table 1ton.Phone(
    PhoneId int not null,
    Numbers int not null,
    FK_PersonId int,
    primary key(PhoneId),
    foreign key(FK_PersonId) references Person(PersonId)
);
insert into 1ton.Person values
    (1,"Name1"),
    (2,"Name2"),
    (3,"Name3"),
    (4,"Name4"),
    (5,"Name5");
select * from 1ton.Person;
insert into 1ton.Phone values
    (1, 099632, 3),
    (2, 096654, 2),
    (3, 077251, 2),
    (4, 096224, 4),
    (5, 045225, 5),
    (6, 094511, 3),
    (7, 055163, 5),
    (8, 095362, 4),
select * from 1ton.Phone;
