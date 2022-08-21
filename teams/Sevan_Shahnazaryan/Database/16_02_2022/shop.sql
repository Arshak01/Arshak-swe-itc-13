create database shop;

use shop;

create table Customers(CustomerID int unique not null, name varchar(25), primary key(CustomerID));

create table Orders(OrderID int unique not null, CustomerID int not null, date varchar(50), address varchar(50), status varchar(20), foreign key(CustomerID) references Customers(CustomerID));

create table Supplier(SupplierID int unique not null, name varchar(25), address varchar(50), primary key(SupplierID));

create table Goods(GoodID int unique not null, name varchar(20), SupplierID int, price int, count int, primary key(GoodID), foreign key(SupplierID) references Supplier(SupplierID));

create table OrderLines(OrderLinesID int unique not null, OrderID int, GoodID int, count int,
foreign key(OrderID) references Orders(OrderID), foreign key(GoodID) references Goods(GoodID));

insert into Customers values(1, 'Jack'), (2, 'Dan'), (3, 'Rob');

insert into Orders values
    (101, 1, '01_01_2022 00:00', 'Shirakaci 1', 'Delivered'),
    (102, 1, '02_01_2022 15:34', 'Shinararneri 12', 'Delivered'),
    (103, 2, '03_01_2022 17:00', 'Shirakaci 1', 'On the way'),
    (104, 3, '03_01_2022 17:05', 'Hambardzumyan 5', 'On the way');

insert into Supplier values
    (201, 'Tashir Pizza', 'Tigran Mets 12'),
    (202, 'KFC', 'Tigran Mets 41'),
    (203, 'Asteri', 'Grigor Lusavorich 40');

insert into Goods values
    (301, 'Shaurma', 201, 1100, 50),
    (302, 'Shaurma', 203, 1200, 75),
    (303, 'Nuggets', 202, 750, 100),
    (304, 'Nuggets', 203, 650, 250);

insert into OrderLines values
    (401, 101, 301, 5),
    (402, 101, 303, 4),
    (403, 102, 301, 10),
    (404, 103, 301, 2),
    (405, 103, 302, 2),
    (406, 103, 303, 2),
    (407, 103, 304, 2),
    (408, 104, 303, 15),
    (409, 104, 301, 10);

delimiter //
create procedure supplier_good(IN SupID int)
begin
select Goods.SupplierID, Goods.GoodID, Goods.name from Goods
where SupplierID = SupID;
end;//

create procedure price_counter(IN OrdID int )
begin
select sum(Goods.price * OrderLines.count) from OrderLines
join Goods on Goods.GoodID = OrderLines.GoodID
where OrderLines.OrderID = OrdID;
end;//
delimiter ;

select * from Customers;
select * from Orders;
select * from Supplier;
select * from Goods;
select * from OrderLines;

select c.name as "Customer name", g.name as "Good name", ol.count
from Customers c inner join Orders o on c.customerID = o.customerID
inner join OrderLines ol on o.orderID = ol.orderID
inner join Goods g on g.goodID = ol.goodID;

select Orders.OrderID, Orders.Date from Orders;

select count(status) from Orders where status = 'On the way';

select sum(Goods.count) from Goods;

call supplier_good(203);

call price_counter(103);

drop database shop
