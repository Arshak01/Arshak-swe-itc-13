create database Shop;
use Shop;
create table Customers(
Customer_ID int not null AUTO_INCREMENT,
Customer_Name varchar(50),
Phone varchar(20),
Addres varchar(50),
CONSTRAINT Pk_Customer Primary Key (Customer_ID));

create table Orders(
Order_ID int not null AUTO_INCREMENT,
OrderDate DATETIME,
Customer_ID int,
Status_ID int,
CONSTRAINT Pk_Order Primary Key (Order_ID),
CONSTRAINT FK_ORDER_Cust Foreign Key (Customer_ID) REFERENCES Customers (Customer_ID),
CONSTRAINT FK_ORDER_Status Foreign Key (Status_ID) REFERENCES Status (Status_ID));

create table Suppliers(
Supp_ID int not null AUTO_INCREMENT,
SuppName varchar (50),
CONSTRAINT Pk_Sup Primary Key (Supp_ID));

create table Goods(
Good_ID int not null AUTO_INCREMENT,
GoodsName varchar(50),
GoodsUnit varchar(20),
GoodsPrice int,
GoodsQuantity int,
Supp_Id int,
CONSTRAINT FK_Goods_Sup Foreign Key (Supp_ID) REFERENCES Suppliers (Supp_ID),
CONSTRAINT Pk_Good Primary Key (Good_ID));

create table Orderlines(
Order_ID int,
Good_ID int,
GoodQuantity int,
OrderLine int not null,
CONSTRAINT FK_ORDER_OrderLine Foreign Key (Order_ID) REFERENCES Orders (Order_ID),
CONSTRAINT FK_ORDER_Goods Foreign Key (Good_ID) REFERENCES Goods (Good_ID));


insert into Customers values (1, "Cust1", "1111", "Earth, Armenia");
insert into Customers values (2, "Cust2", "2222", "Mars, Object 77");

insert into Orders values (1, "2222-01-22", 1, 1);
insert into Orders values (2, "2222-02-22", 2, 1);
insert into Orders values (3, "2222-03-22", 3, 2);

insert into Suppliers values (1, "Supp1");
insert into Suppliers values (2, "Supp2");

insert into Goods values (1, "Good1", "piece", 100, 10, 1);
insert into Goods values (2, "Good2", "piece", 200, 9, 1);
insert into Goods values (3, "Good3", "piece", 300, 8, 2);

insert into Orderlines values (1, 1, 1, 1);
insert into Orderlines values (1, 2, 1, 2);
insert into Orderlines values (2, 1, 1, 3);							  

select CustomerName, GoodsName
from Customers
join Orders  on Customers.Customer_ID = Orders.Customer_ID
join Orderlines on Orders.Order_ID = Orderlines.Order_ID
join Goods on Orderlines.GoodId = Goods.Good_ID
where Customers.Customer_ID = 1;


-- select Order_ID, OrderDate
-- from Shop.Orders
-- where Order_ID = 1;

-- select GoodsName, (GoodsQuantity - Orderlines.GoodQuantity) as Result
-- from Goods
-- join Orderlines on Goods.Good_ID = Orderlines.Good_ID;

-- select GoodsName, SupName
-- from Goods
-- join Suppliers on Goods.Supp_Id = Suppliers.Supp_Id
-- where GoodsName = 1;
