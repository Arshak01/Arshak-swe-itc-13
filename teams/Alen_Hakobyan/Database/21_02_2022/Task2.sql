create database Num;

create table Num.Temp(
	TempID int NOT NULL AUTO_INCREMENT,
	Num int,
	PRIMARY KEY (TempID)
);

insert into Num.Temp(Num) values
	(1),
	(1),
	(1),
	(2),
	(1),
	(2),
	(2);

select * from Num.Temp;

select Num as ConsecutiveNums from Num.Temp
	GROUP BY Num HAVING COUNT(Num) > 3;

drop database Num;
