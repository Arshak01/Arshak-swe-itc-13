create database nton;
create table nton.Movies(
	MovieId int not null, 
	Name varchar(50), 
	primary key(MovieId)
);
create table nton.Actors(
	ActorId int not null,
	Name varchar(50), 
	primary key(ActorId)
);
create table nton.Junction(
	JunctionId int not null, 
	primary key(JunctionId),
       	FK_MovieId int,
       	FK_ActorId int,
       	foreign key(FK_MovieId) references Movies(MovieId),
       	foreign key(FK_ActorId) references Actors(ActorId)
);
insert into nton.Movies values
	(1, "Harry Potter"),
	(2, "The Matrix"),
	(3, "John Wick"),
	(4, "Beauty and the Beast"),
	(5, "Pirates of the Caribbean"),
	(6, "Crimes of Grindelwald");
select * from nton.Movies;
insert into nton.Actors values
	(1, "Emma Watson"),
	(2, "Keanu Reeves"),
	(3, "Johnny Depp"),
	(4, "Daniel Radcliff");
select * from nton.Actors;
insert into nton.Junction values
	(1, 1, 1),
	(2, 1, 4),
	(3, 2, 2),
	(4, 4, 1),
	(5, 5, 3),
 	(6, 6, 3);
select * from nton.Junction;




