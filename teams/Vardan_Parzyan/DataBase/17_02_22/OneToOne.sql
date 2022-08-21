Create database OneToOne;

Create table OneToOne.Student (
Student_ID int NOT null auto_increment,
FirstName varchar(20),
LastName varchar(20),
primary key(Student_ID)
);

Create table OneToOne.ContactInfo(
Contact_ID int not null auto_increment,
PhoneNum varchar(20),
Country varchar(20),
City varchar(20),
primary key(Contact_ID),
FK_Student_id int unique,
CONSTRAINT FK_Student_ID FOREIGN KEY (FK_Student_ID)
REFERENCES OneToOne.Student(Student_ID)
);

insert into OneToOne.Student(FirstName,LastName) values ('Vardan','Parzyan');
insert into OneToOne.Student(FirstName,LastName) values ('Poghos','Poghosyan');

insert into OneToOne.ContactInfo(FK_Student_id,PhoneNum,Country,City) values(FK_Student_id,'096272262','Armenia','Vanadzor');
insert into OneToOne.ContactInfo(FK_Student_id,PhoneNum,Country,City) values(FK_Student_id,'123456789','Armenia','Ddmashen');

describe OneToOne.Student;
describe OneToOne.ContactInfo;
select * from OneToOne.Student;
select * from OneToOne.ContactInfo;
drop database OneToOne;



