create database one_to_one;

use one_to_one;

create table people(
    ID int not null,
    ame varchar(20),
    primary key(ID)
);

create table phone(
    phoneID int not null,
    num varchar(9),
    FK_ID int not null,
    primary key(FK_ID),
    foreign key(FK_ID) references people(ID)
);

insert into people values
    (1, 'Jack'),
    (2, 'Vacho'),
    (3, 'May');

insert into phone values
    (1, '012123123', 1),
    (2, '012321321', 2),
    (3, '012321654', 3);

select * from people;

select * from phone;
