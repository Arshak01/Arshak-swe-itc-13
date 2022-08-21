create database one_to_many;

use one_to_many;

create table club(
	club_ID int not null,
	name varchar(15),
	primary key(club_ID)
);

create table player(
	player_ID int not null,
	name varchar(25),	
	club_ID int not null,
	primary key(player_ID),
	foreign key(club_ID) references club(club_ID)
);

insert into club values
	(1, 'Barcelona'),
	(2, 'MU'),
	(3, 'Real Madrid');

insert into player values
	(1, 'Lioniel Messi', 1),
	(2, 'Xavi', 1),
	(3, 'Iniesta', 1),
	(4, 'Wayne Rooney', 2),
	(5, 'De Gea', 2),
	(6, 'Van Persie', 2),
	(7, 'Cristiano Ronaldo', 3),
	(8, 'Benzema', 3),
	(9, 'Marcelo', 3);

select * from club;

select * from player;
