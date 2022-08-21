sudo mysql
###### Customers table
create database online_shop;
create table online_shop.Customers (id int not null primary key, name varchar(20), surname varchar(30), email varchar(50), phone_number varchar(20), address varchar(50),constraint cust_id_unique unique(id));
insert into online_shop.Customers values(1, 'Jonie', 'Deep', 'jonie.d@gmail.com', '9992393494', 'California Groove st. house 1');
insert into online_shop.Customers values(2, 'Eddy', 'Broke', 'eddy.b@gmail.com', '999239343', 'Virginia Sanders st. house 55');
insert into online_shop.Customers values(3, 'Sendy', 'Barr', 'sendy.b@gmail.com', '993469343', 'Delever Addington st. house 5');
insert into online_shop.Customers values(4, 'Sarah', 'Coner', 'sara.c@gmail.com', '983569443', 'Texas Werner st. house 23');
insert into online_shop.Customers values(5, 'Sherlock', 'Holmes', 'sher.lock@gmail.com', '983549413', 'London Baker st. house 221');
###### Orders table
create table online_shop.Orders (id int not null primary key, no int not null, date_from varchar(10), date_to varchar(10),customer_id int,constraint fk_order_id foreign key (customer_id) references online_shop.Customers(id));
insert into online_shop.Orders (id,no,date_from,date_to,customer_id) values(10,1,'10/02/2022','15/02/2022',1);
insert into online_shop.Orders (id,no,date_from,date_to,customer_id) values(11,2,'13/02/2022','18/02/2022',2);
insert into online_shop.Orders (id,no,date_from,date_to,customer_id) values(12,3,'11/02/2022','15/02/2022',2);
insert into online_shop.Orders (id,no,date_from,date_to,customer_id) values(13,4,'16/02/2022','21/02/2022',4);
insert into online_shop.Orders (id,no,date_from,date_to,customer_id) values(14,5,'15/02/2022','21/02/2022',4);
###### Orderlines table
create table online_shop.Orderlines (id int not null primary key,order_id int,constraint fk_orderlist_id foreign key (order_id) references online_shop.Orders(id));
insert into online_shop.Orderlines (id,order_id) values(100,13);
insert into online_shop.Orderlines (id,order_id) values(101,13);
insert into online_shop.Orderlines (id,order_id) values(102,14);
insert into online_shop.Orderlines (id,order_id) values(103,13);
insert into online_shop.Orderlines (id,order_id) values(104,10);
###### Suppliers table
create table online_shop.Suppliers (id int not null primary key,name varchar(30),constraint sup_id_unique unique(id));
insert into online_shop.Suppliers (id,name) values(10000,'Adidas');
insert into online_shop.Suppliers (id,name) values(10001,'Zara');
insert into online_shop.Suppliers (id,name) values(10002,'Gucci');
insert into online_shop.Suppliers (id,name) values(10003,'Nike');
insert into online_shop.Suppliers (id,name) values(10004,'Prada');
###### Goods table
create table online_shop.Goods (id int not null primary key, code int not null, name varchar(10), cost varchar(20),order_id int,constraint fk_order_good_id foreign key (order_id) references online_shop.Orders(id),suppliers_id int,constraint fk_sup_id foreign key (suppliers_id) references online_shop.Suppliers(id));
insert into online_shop.Goods values(1000,131245, 'Hoop 2.0', '70$',12,10003);
insert into online_shop.Goods values(1001,231324, 'T-shirt', '25$',11,10001);
insert into online_shop.Goods values(1002,166547, 'sweat', '140$',14,10003);
insert into online_shop.Goods values(1003,853469, 'glasses', '100$',14,10004);
insert into online_shop.Goods values(1004,154238, 'hat', '23$',10,10003);
###### Add foreign key good_id
alter table online_shop.Orders add good_id int;
alter table online_shop.Orders add constraint fk_good_id foreign key(good_id) references online_shop.Goods(id);
update online_shop.Orders set  good_id=1000 where id=10;
update online_shop.Orders set  good_id=1004 where id=11;
update online_shop.Orders set  good_id=1000 where id=12;
update online_shop.Orders set  good_id=1001 where id=13;
update online_shop.Orders set  good_id=1003 where id=14;




