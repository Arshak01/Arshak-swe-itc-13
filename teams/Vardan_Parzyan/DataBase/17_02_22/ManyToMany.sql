Create database ManyToMany;

Create table ManyToMany.Student (
Student_ID int NOT null auto_increment,
FirstName varchar(20),
LastName varchar(20),
primary key(Student_ID)
);

Create table ManyToMany.Teacher(
Teacher_ID int NOT null auto_increment,
Teacher_Name varchar(30),
primary key(Teacher_ID)
);

Create table ManyToMany.Cources(
CourceName varchar(30),
Teacher_ID int NOT null,
Student_ID int Not null,
Primary key(CourceName),
CONSTRAINT Student_ID FOREIGN KEY (Student_ID)
REFERENCES ManyToMany.Student(Student_ID),
CONSTRAINT Teacher_ID FOREIGN KEY (Teacher_ID)
REFERENCES ManyToMany.Teacher(Teacher_ID)
);


insert into ManyToMany.Student(FirstName,LastName)
values('Vardan','Parzyan');
insert into ManyToMany.Student(FirstName,LastName)
values('Petros','Poghosyan');
insert into ManyToMany.Student(FirstName,LastName)
values('Poghos','Petrosyan');

insert into ManyToMany.Teacher(Teacher_ID, Teacher_Name)
values (001,'Elya');
insert into ManyToMany.Teacher(Teacher_ID, Teacher_Name)
values (002,'Nane');
insert into ManyToMany.Teacher(Teacher_ID, Teacher_Name)
values (003,'Martiros');

insert into ManyToMany.Cources(CourceName,Teacher_ID,Student_ID)
values('DataBase',001,1);
insert into ManyToMany.Cources(CourceName,Teacher_ID,Student_ID)
values('Algorithm',002,1);
insert into ManyToMany.Cources(CourceName,Teacher_ID,Student_ID)
values('DM Documentation',002,1);

insert into ManyToMany.Cources(CourceName,Teacher_ID,Student_ID)
values('Biology',003,2);
insert into ManyToMany.Cources(CourceName,Teacher_ID,Student_ID)
values('Math',003,2);
insert into ManyToMany.Cources(CourceName,Teacher_ID,Student_ID)
values('Constitution',003,3);

describe ManyToMany.Student;
describe ManyToMany.Teacher;
describe ManyToMany.Cources;
select * from ManyToMany.Student;
select * from ManyToMany.Teacher;
select * from ManyToMany.Cources;
drop database ManyToMany;





