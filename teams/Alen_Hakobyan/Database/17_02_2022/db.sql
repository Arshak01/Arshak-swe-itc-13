create database ITC;

create table ITC.Country(
	CountryID int not null auto_increment,
	Name varchar(20),
	primary key (CountryID)
);

create table ITC.Capital(
	CapitalID int not null auto_increment,
	Name varchar(20),
	FK_CountryID int unique,
	primary key(CapitalID),
	foreign key(FK_CountryID) references Country(CountryID)
);

insert into ITC.Country values
	(1,"Armenia"),
	(2,"USA"),
	(3,"Russia"),
	(4,"Georgia"),
	(5,"Italy");

select * from ITC.Country;

insert into ITC.Capital values
	(1,"Rome",5),
	(2,"Moscow",3),
	(3,"Erevan",1),
	(4,"Washington",2),
	(5,"Tbilisi",4);

select * from ITC.Capital;

create table ITC.Region(
	RegionID int not null auto_increment,
	Name varchar(20),
	primary key(RegionID)
);

create table ITC.City(
	CityID int not null auto_increment,
	Name varchar(20),
	FK_RegionID int,
	primary key(CityID),
	foreign key(FK_RegionID) references Region(RegionID)
);

insert into ITC.Region values
	(1,"Gegharkunik"),
	(2,"Tavush"),
	(3,"Shirak"),
	(4,"Lori"),
	(5,"Kotayk"),
	(6,"Ararat");

select * from ITC.Region;

insert into ITC.City values
	(1,"Vanadzor",4),
	(2,"Spitak",4),
	(3,"Dilijan",2),
	(4,"Ijevan",2),
	(5,"Gyumri",3),
	(6,"Abovyan",5),
	(7,"Artik",3),
	(8,"Artashat",6),
	(9,"Gavar",1),
	(10,"Ararat",6),
	(11,"Hrazdan",5);

select * from ITC.City;

create table ITC.Hotel(
	HotelID int not null auto_increment,
	Name varchar(20),
	primary key(HotelID)
);

create table ITC.Room(
	RoomID int not null auto_increment,
	Number varchar(20),
	primary key(RoomID)
);

create table ITC.Hotel_room(
	Hotel_roomID int not null auto_increment,
	primary key(Hotel_roomID),
	FK_HotelID int,
	FK_RoomID int,
	foreign key(FK_HotelID) references Hotel(HotelID),
	foreign key(FK_RoomID) references Room(RoomID)
);

insert into ITC.Hotel values
	(1,"Lori"),
	(2,"Metropol"),
	(3,"Shirak"),
	(4,"Bellagio"),
	(5,"Cascade");

select * from ITC.Hotel;

insert into ITC.Room values
	(1,"Num 1"),
(2,"Num 2"),
(3,"Num 3"),
	(4,"Num 4"),
	(5,"Num 5"),
	(6,"Num 6"),
	(7,"Num 7"),
	(8,"Num 8"),
	(9,"Num 9"),
	(10,"Num 10");

select * from ITC.Room;

insert into ITC.Hotel_room values
	(1,2,1),
	(2,1,2),
	(3,1,3),
	(4,1,4),
	(5,1,5),
	(6,1,6),
	(7,1,7),
	(8,1,8),
	(9,1,9),
	(10,1,10),
	(11,1,1),
	(12,2,2),
	(13,2,3),
	(14,2,4),
	(15,2,5),
	(16,2,6),
	(17,2,7),
	(18,2,8),
	(19,2,9),
	(20,2,10),
	(21,3,1),
	(22,3,2),
	(23,3,3),
	(24,3,4),
	(25,3,5),
	(26,3,6),
	(27,3,7),
	(28,3,8),
	(29,3,9),
	(30,3,10),
	(31,4,1),
	(32,4,2),
	(33,4,3),
	(34,4,4),
	(35,4,5),
	(36,4,6),
	(37,4,7),
	(38,4,8),
	(39,4,9),
	(40,4,10),
	(41,5,1),
	(42,5,2),
	(43,5,3),
	(44,5,4),
	(45,5,5),
	(46,5,6),
	(47,5,7),
	(48,5,8),
	(49,5,9),
	(50,5,10);

select * from ITC.Hotel_room;

drop database ITC;
