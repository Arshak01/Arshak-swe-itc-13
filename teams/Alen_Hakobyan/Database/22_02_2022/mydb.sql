create database itc;

create table itc.Person(
	PID int not null,
	Email varchar(20),
	PRIMARY KEY(PID)
);

insert into itc.Person values
	(1,'a@b.com'),
	(2,'c@b.com'),
	(3,'a@b.com'),
	(4,'d@b.com'),
	(5,'c@b.com');

select * from itc.Person;

select Email from itc.Person
	group by Email
	having count(Email) > 1;

create table itc.World(
	Name varchar(20) not null,
	Continent varchar(20),
	Area int,
	Population int,
	gdp bigint,
	PRIMARY KEY(Name)
);

insert into itc.World values
	('Afghanistan','Asia',652230,25500100 ,20343000000),
	('Albania','Europe',28748,2831741,12960000000),
	('Algeria','Africa',2381741,37100000 ,1886810000000),
	('Andorra','Europe',468,78115,3712000000),
	('Angola','Africa',1246700,20609294,100990000000);

select * from itc.World;

select Name, Population, Area from itc.World
	where Population > 25000000 or area > 3000000;

create table itc.Courses(
	Student varchar(20) not null,
	Class varchar(20) not null,
	PRIMARY KEY(Student,Class)
);

insert into itc.Courses values
	('A','Math'),
	('B','English'),
	('C','Math'),
	('D','Biology'),
	('E','Math'),
	('F','Computer'),
	('G','Math'),
	('H','Math'),
	('I','Math');

select * from itc.Courses;

select Class from itc.Courses
	group by Class
	having count(Class) >= 5;

create table itc.Stadium(
	Id int,
	Visit_date date UNIQUE,
	People int,
	PRIMARY KEY(Visit_date)
);

insert into itc.Stadium values 
	(1,'2017-01-01',10),
	(2,'2017-01-02',109),
	(3,'2017-01-03',150),
	(4,'2017-01-04',99),
	(5,'2017-01-05',145),
	(6,'2017-01-06',1455),
	(7,'2017-01-07',199),
	(8,'2017-01-08',188);

select * from itc.Stadium;

select distinct s1.* from itc.Stadium s1, itc.Stadium s2, itc.Stadium s3
	where s1.people >= 100
	and s2.people >= 100
	and s3.people >= 100
	and ((s1.id = s2.id -1 and s1.id = s3.id - 2)
	or (s1.id = s2.id + 1 and s1.id = s3.id -1)
	or (s1.id = s2.id + 2 and s1.id = s3.id +1 ))
	order by s1.id;

drop database itc;
