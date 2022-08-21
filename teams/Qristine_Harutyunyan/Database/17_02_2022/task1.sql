
create database Rel;


# One to one

create table Rel.Person(PersonId int NOT NULL UNIQUE,
                        PersonName varchar(20),
						PersonSurname varchar(25),
						CONSTRAINT PK_Person PRIMARY KEY (PersonID));


create table Rel.Address(PersonId int,
                         Country varchar(20),
						 Region varchar(30),
						 City varchar(20),
						 Street varchar(40),
                         CONSTRAINT FK_Person FOREIGN KEY (PersonID) references Rel.Person (PersonID)); 



insert into Rel.Person values (1, "Person1", "Surname1"),
                              (2, "Person2", "Surname2"),
							  (3, "Person3", "Surname3"),
							  (4, "Person4", "Surname4");

insert into Rel.Address values (1, "Armenia", "Yerevan", "Yerevan", "Avan 3/4"),
                               (2, "Armenia", "Lori", "Vanadzor", "street 12/5"),
							   (3, "Armenia", "Lori", "Stepanavan", "street 102"),
							   (4, "Armenia", "Kotayq", "Abovyan", "street 98");


select * from Rel.Person;
select * from Rel.Address;



# One to many

# Use table person from one to one
create table Rel.Relation(PersonId int,
                          RelName varchar(50),
                          CONSTRAINT FK_Person_Rel FOREIGN KEY (PersonID) references Rel.Person (PersonID));


insert into Rel.Relation values (1, "Married"),
                                (2, "Single"),
								(3, "in ralation"),
								(4, "single");



select * from Rel.Person;
select * from Rel.Relation;	



create table Rel.Profation(ProfId int not null Unique,
                          ProfName varchar(20),
						  CONSTRAINT PK_Prof PRIMARY KEY (ProfID));



insert into  Rel.Profation values(1, "Software engeenare"),
                                 (2, "Acountent"),
			        			   (3, "Singer"),
								   (4, "Dancer"),
								   (5, "Actor");

create table Rel.Person_Prof(PersonID int,
                             ProfID int,
							 CONSTRAINT FK_Person_Prof FOREIGN KEY (PersonID) references Rel.Person (PersonID),
							 CONSTRAINT FK_Prof_Per FOREIGN KEY (ProfID) references Rel.Profation (ProfID));


insert into Rel.Person_Prof values (1, 1),
                                   (1, 2),
								   (2, 3),
								   (2, 4),
								   (2, 5),
								   (3, 1),
								   (4, 2);


select * from Rel.Person;
select * from Rel.Profation;
select * from Rel.Person_Prof;								   
