-- Customers table
create database online_shop;
create table online_shop.Customers (customer_id int not null primary key, customer_name varchar(20), surname varchar(30), email varchar(50), phone_number varchar(20), address varchar(50));
insert into online_shop.Customers values(1, 'Jonie', 'Deep', 'jonie.d@gmail.com', '9992393494', 'California Groove st. house 1');
insert into online_shop.Customers values(2, 'Eddy', 'Broke', 'eddy.b@gmail.com', '999239343', 'Virginia Sanders st. house 55');
insert into online_shop.Customers values(3, 'Sendy', 'Barr', 'sendy.b@gmail.com', '993469343', 'Delever Addington st. house 5');
insert into online_shop.Customers values(4, 'Sarah', 'Coner', 'sara.c@gmail.com', '983569443', 'Texas Werner st. house 23');
insert into online_shop.Customers values(5, 'Sherlock', 'Holmes', 'sher.lock@gmail.com', '983549413', 'London Baker st. house 221');

-- Status table
create table online_shop.Status(status_id int not null primary key, status varchar(30));
insert into online_shop.Status values (0, 'Not shipped');
insert into online_shop.Status values (1, 'Shipped');
insert into online_shop.Status values (2, 'On the way');

-- Orders table
create table online_shop.Orders (order_id int not null primary key, order_no int not null, date_from datetime, date_to datetime,customer_id int not null,foreign key (customer_id) references online_shop.Customers(customer_id), status_id int not null, foreign key(status_id) references online_shop.Status(status_id));
insert into online_shop.Orders values(10,1,'2022-02-10','2022-02-15',1,0);
insert into online_shop.Orders values(11,2,'2022-02-9','2022-02-15',2,1);
insert into online_shop.Orders values(12,3,'2022-02-20','2022-02-28',2,1);
insert into online_shop.Orders values(13,4,'2022-02-20','2022-02-28',4,2);
insert into online_shop.Orders values(14,5,'2022-02-14','2022-03-1',4,2);
-- Suppliers table
create table online_shop.Suppliers (supplier_id int not null primary key,supplier_name varchar(30));
insert into online_shop.Suppliers values(10000,'Adidas');
insert into online_shop.Suppliers values(10001,'Zara');
insert into online_shop.Suppliers values(10002,'Gucci');
insert into online_shop.Suppliers values(10003,'Nike');
insert into online_shop.Suppliers values(10004,'Prada');
-- Goods table
create table online_shop.Goods (good_id int not null primary key, good_code int not null, good_name varchar(50), cost int,count int ,supplier_id int not null,foreign key (supplier_id) references online_shop.Suppliers(supplier_id));
insert into online_shop.Goods values(1000,131245, 'Hoop 2.0',70,10,10002);
insert into online_shop.Goods values(1001,231324, 'T-shirt',25,12,10001);
insert into online_shop.Goods values(1002,166547, 'sweat',140,20,210004);
insert into online_shop.Goods values(1003,853469, 'glasses',100,12,10004);
insert into online_shop.Goods (good_id,good_code,good_name,cost,supplier_id) values(1004,154238, 'hat', '23$',10003);
-- Orderlines table
create table online_shop.Orderlines (orderline_id int not null primary key, count int,order_id int, foreign key (order_id) references online_shop.Orders(order_id), good_id int default null, foreign key (good_id) references online_shop.Goods(good_id));
insert into online_shop.Orderlines values(100,2,13,1001);
insert into online_shop.Orderlines values(101,1,13,1000);
insert into online_shop.Orderlines values(102,3,14,1002);
insert into online_shop.Orderlines values(103,2,13,1001);
insert into online_shop.Orderlines (orderline_id, order_id) values(104,10);
-- Add order-good table
create table online_shop.order_good (order_good_id int not null primary key, good_id int not null,foreign key (good_id) references online_shop.Goods(good_id),order_id int not null,foreign key (order_id) references online_shop.Orders(order_id));
insert into online_shop.order_good values(100000,1000,11);
insert into online_shop.order_good values(100001,1000,12);
insert into online_shop.order_good values(100002,1001,11);
insert into online_shop.order_good values(100003,1001,12);
insert into online_shop.order_good values(100004,1004,13);
insert into online_shop.order_good values(100005,1002,13);
insert into online_shop.order_good values(100006,1003,10);
insert into online_shop.order_good values(100007,1002,11);
insert into online_shop.order_good values(100008,1004,12);
insert into online_shop.order_good values(100009,1000,10);

-- Query 1
select customer_name, good_name from online_shop.Customers
join online_shop.Orders  on Customers.customer_id = Orders.customer_id
Join online_shop.Orderlines on Orders.order_id = Orderlines.order_id
join online_shop.Goods on Orderlines.good_id = Goods.good_id
where Customers.customer_id = 4;

-- Query 2
select order_id, date_from from online_shop.Orders where order_id = 10;

-- Query 3
select Count(status_id) from online_shop.Orders where status_id = 2;

-- Query 4
select good_name, (Goods.count - Orderlines.count) as goods_count from online_shop.Goods
join online_shop.Orderlines on Goods.good_id = Orderlines.good_id;

-- Query 5
select supplier_name, good_name from online_shop.Suppliers
join online_shop.Goods on Suppliers.supplier_id = Goods.supplier_id;


-- Query 6
select Orders.order_id, Sum(Goods.cost * Orderlines.count) as total from online_shop.Orders
join online_shop.Orderlines on Orders.order_id = Orderlines.order_id
join online_shop.Goods on Orderlines.good_id = Goods.good_id
where Orders.order_id = 13 or Orders.order_id = 14 group by Orders.order_id;

drop database online_shop;