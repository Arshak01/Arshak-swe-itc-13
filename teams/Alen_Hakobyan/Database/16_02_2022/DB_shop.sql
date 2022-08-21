create database ITC;

create table ITC.Customers(
	CustomersID int NOT NULL AUTO_INCREMENT,
	CustName varchar(20),
	PhoneNumber varchar(20),
	Address varchar(50),
	PRIMARY KEY (CustomersID)
);

create table ITC.Suppliers(
	SuppliersID int NOT NULL AUTO_INCREMENT,
	SuppName varchar(20),
	PRIMARY KEY (SuppliersID)
);

create table ITC.Status(
	StatusID int NOT NULL AUTO_INCREMENT,
	Status varchar(20),
	PRIMARY KEY (StatusID)
);

create table ITC.Goods(
	GoodsID int NOT NULL AUTO_INCREMENT,
	GoodsName varchar(20),
	Price int,
	Count int,
	PRIMARY KEY (GoodsID)
);

create table ITC.Orders(
	OrdersID int NOT NULL AUTO_INCREMENT,
	FK_CustomersID int,
	OrderDate DATETIME,
	FK_SuppliersID int,
	FK_StatusID int,
	PRIMARY KEY (OrdersID),
	FOREIGN KEY (FK_CustomersID) REFERENCES Customers(CustomersID) ON DELETE CASCADE,
	FOREIGN KEY (FK_SuppliersID) REFERENCES Suppliers(SuppliersID) ON DELETE CASCADE,
	FOREIGN KEY (FK_StatusID) REFERENCES Status(StatusID) ON DELETE CASCADE
);

create table ITC.Orderlines(
	OrderlinesID int NOT NULL AUTO_INCREMENT,
	FK_GoodsID int,
	Count int,
	FK_OrdersID int,
	PRIMARY KEY (OrderlinesID),
	FOREIGN KEY (FK_GoodsID) REFERENCES Goods(GoodsID) ON DELETE CASCADE,
	FOREIGN KEY (FK_OrdersID) REFERENCES Orders(OrdersID) ON DELETE CASCADE
);

insert into ITC.Customers values
	(1,"Name1",9911,"Vanadzor1"),
	(2,"Name2",9922,"Vanadzor2"),
	(3,"Name3",9933,"Vanadzor3"),
	(4,"Name4",9944,"Vanadzor4");

insert into ITC.Suppliers values
	(1,"Supp1"),
	(2,"Supp2"),
	(3,"Supp3");

insert into ITC.Status values
	(1,"Not Shipped yet"),
	(2,"Shipped"),
	(3,"Is Shipping");

insert into ITC.Goods values
	(1,"Good1",100,5),
	(2,"Good2",200,4),
	(3,"Good3",300,6),
	(4,"Good4",400,8);

insert into ITC.Orders values
	(1,1,"2022-02-21 21:33:33",1,3),
	(2,2,"2022-02-20 20:30:30",2,2),
	(3,4,"2022-02-21 21:40:40",3,1);

insert into ITC.Orderlines values
	(1,1,2,1),
	(2,3,4,2),
	(3,4,1,3);

select CustName, GoodsName from ITC.Customers
	join ITC.Orders on Customers.CustomersID = Orders.FK_CustomersID
	Join ITC.Orderlines on Orders.OrdersID = Orderlines.FK_OrdersID
	join ITC.Goods on Orderlines.FK_GoodsID = Goods.GoodsID
	where Customers.CustomersID = 1 or Customers.CustomersID = 2 or Customers.CustomersID = 3 or Customers.CustomersID = 4;

select OrdersID, OrderDate from ITC.Orders;

select Count(FK_StatusID) from ITC.Orders
	where FK_StatusID <> 2;

select GoodsName, (Goods.Count - Orderlines.Count) as Goods_Count from ITC.Goods
	join ITC.Orderlines on Goods.GoodsID = Orderlines.FK_GoodsID;

select SuppName, GoodsName from ITC.Suppliers
	join ITC.Orders on Suppliers.SuppliersID = Orders.FK_SuppliersID
	join ITC.Orderlines on Orders.OrdersID = Orderlines.FK_OrdersID
	join ITC.Goods on Orderlines.FK_GoodsID = Goods.GoodsID
	where Suppliers.SuppliersID <> 0 ;

select Orders.OrdersID, Sum(Goods.Price * Orderlines.Count) as Total_Price from ITC.Orders
	join ITC.Orderlines on Orders.OrdersID = Orderlines.FK_OrdersID
	join ITC.Goods on Orderlines.FK_GoodsID = Goods.GoodsID
	where Orders.OrdersID = 1 or Orders.OrdersID = 2 or Orders.OrdersID = 3 group by Orders.OrdersID;

drop database ITC;
