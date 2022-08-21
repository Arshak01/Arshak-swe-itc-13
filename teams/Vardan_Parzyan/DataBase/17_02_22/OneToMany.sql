Create database OneToMany;

Create table OneToMany.Teacher(
Teacher_ID int NOT null auto_increment,
Teacher_Name varchar(30),
primary key(Teacher_ID)
);

Create table OneToMany.Cources(
Cource_ID int NOT NULL,
CourceName varchar(30),
Teacher_ID int NOT null,
CONSTRAINT FOREIGN KEY (Teacher_ID) REFERENCES OneToMany.Teacher(Teacher_ID)
);

insert into OneToMany.Teacher(Teacher_Name)
values('Vardan Parzyan');
insert into OneToMany.Teacher(Teacher_Name)
values('Petros Petrosyan');

insert into OneToMany.Cources(Cource_ID,CourceName,Teacher_ID)
values(1,'Biology',1);
insert into OneToMany.Cources(Cource_ID,CourceName,Teacher_ID)
values(2,'Math',2);
insert into OneToMany.Cources(Cource_ID,CourceName,Teacher_ID)
values(3,'History',1);

describe OneToMany.Teacher;
describe OneToMany.Cources;
select * from OneToMany.Teacher;
select * from OneToMany.Cources;
drop database OneToMany;
