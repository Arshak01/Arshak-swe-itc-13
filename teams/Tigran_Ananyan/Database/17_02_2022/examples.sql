-- Creating drivers database
create database drivers;
-- Brand's table
create table drivers.brand (id int not null primary key,name varchar(30));
insert into drivers.brand values(1,'Mersedes Benz');
insert into drivers.brand values(2,'BMW');
insert into drivers.brand values(3,'Tesla');
insert into drivers.brand values(4,'Audi');
insert into drivers.brand values(5,'Toyota');
-- Driver's license table
create table drivers.license (id int not null primary key,code varchar(30), class varchar(5));
insert into drivers.license values(1,'AA123456789','C');
insert into drivers.license values(2,'AA124476729','A');
insert into drivers.license values(3,'AB124472728','B');
insert into drivers.license values(4,'AA125473721','C');
insert into drivers.license values(5,'BA325413731','B');
-- Person table
create table drivers.person (id int not null primary key,name varchar(20),surname varchar(20),license_id int not null, foreign key (license_id) references drivers.license(id));
insert into drivers.person values(1, 'John','Bronks',2);
insert into drivers.person values(2, 'James','Camaron',4);
insert into drivers.person values(3, 'Gordon','Ramsey',1);
insert into drivers.person values(4, 'Fernando','Torres',3);
insert into drivers.person values(5, 'Ornello','Mutti',5);
-- Car table
create table drivers.car (id int not null primary key,name varchar(20),type varchar(20),brand_id int not null, foreign key (brand_id) references drivers.brand(id));
insert into drivers.car values(1, 'maybach','sedan',1);
insert into drivers.car values(2, 'model x','crossover',3);
insert into drivers.car values(3, 'camry','sedan',5);
insert into drivers.car values(4, 'gwagen','crossover',1);
insert into drivers.car values(5, 'model s plaid','sedan',3);
-- Person's car table
create table drivers.person_car (id int not null primary key,owner_license varchar(20),person_id int not null, foreign key (person_id) references drivers.person(id),car_id int not null, foreign key (car_id) references drivers.car(id));
insert into drivers.person_car values(1, 'AA234256',1,3);
insert into drivers.person_car values(2, 'AB331236',4,3);
insert into drivers.person_car values(3, 'AA131132',4,2);
insert into drivers.person_car values(4, 'AA735032',1,4);
insert into drivers.person_car values(5, 'AA7310334',2,2);
insert into drivers.person_car values(6, 'AB7640330',5,1);
insert into drivers.person_car values(7, 'AB724550',3,5);
insert into drivers.person_car values(8, 'BB722323',2,3);
--
-- Done, now we have drivers database where tables
-- car and brand connected with one to more connection, 
-- person and license connected with one to one connection,
-- car and person connected with more to more connection

select * from drivers.brand;
select * from drivers.license;
select * from drivers.person;
select * from drivers.car;
select * from drivers.person_car;