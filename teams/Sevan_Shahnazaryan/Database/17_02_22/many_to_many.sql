create database many_to_many;

use many_to_many;

create table soldier(soldier_ID int not null, soldier_name varchar(30), primary key(soldier_ID));

create table gun(gun_ID int not null, gun_name varchar(20), primary key(gun_ID));

create table soldier_gun(
	SG_ID int not null,
	soldier_ID int not null,
	gun_ID int not null,
	foreign key(soldier_ID) references soldier(soldier_ID),
	foreign key(gun_ID) references gun(gun_ID)
);

insert into soldier values
	(1, 'Ivanov'),
	(2, 'Babkin'),
	(3, 'Borisyuk');

insert into gun values (1, 'AK-74'), (2, 'PK'), (3, 'RPG-7');

insert into soldier_gun values
	(1, 1, 1),
	(2, 1, 3),
	(3, 2, 1),
	(4, 2, 2),
	(5, 3, 2),
	(6, 3, 3);

select * from soldier;

select * from gun;

select * from soldier_gun;
