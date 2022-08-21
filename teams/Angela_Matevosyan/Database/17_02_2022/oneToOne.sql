create database 1to1;
create table 1to1.Users(
    UserId int not null,
    Name varchar(20),
    primary key (UserId)
);
create table 1to1.Passwords(
    PasswordId int not null,
    Password varchar(8),
    FK_UserId int unique,
    primary key(PasswordId),
    foreign key(FK_UserId) references Users(UserId)
);
insert into 1to1.Users values
    (1,"User1"),
    (2,"User2"),
    (3,"User3"),
    (4,"User4"),
    (5,"User5");
select * from 1to1.Users;
insert into 1to1.Passwords values
    (1,"jfv35c", 5),
    (2,"njf23k", 3),
    (3,"ncj45l", 2),
    (4,"kmd85f", 4),
    (5,"bnj59s", 1);
select * from 1to1.Passwords;
