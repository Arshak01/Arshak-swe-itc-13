CREATE DATABASE Shop;
USE Shop;

CREATE TABLE Customers(
    CustomersId int NOT NULL AUTO_INCREMENT,
    custName varchar(40),
    phone varchar(40),
    address varchar(40),
    PRIMARY KEY (CustomersId)
);

CREATE TABLE Suppliers(
    SuppliersId INT NOT NULL AUTO_INCREMENT,
    suppName varchar(20),
    phone varchar(30),
    address varchar(20),
    PRIMARY KEY(SuppliersId)
);

CREATE TABLE Orders(
    OrdersId INT NOT NULL AUTO_INCREMENT,
    date varchar(40),
    address varchar(80),
    status varchar(20),
    FK_Customers int,
    PRIMARY KEY(OrdersId),
    FOREIGN KEY(FK_Customers) REFERENCES Customers(CustomersId)
);

CREATE TABLE Goods(
    GoodsId INT NOT NULL AUTO_INCREMENT,
    goodsName varchar(20),
    unitPrice float,
    count int,
    measurment varchar(20),
    FK_Suppliers int,
    PRIMARY KEY(GoodsId),
    FOREIGN KEY(FK_Suppliers) REFERENCES Suppliers(SuppliersId)
);

CREATE TABLE OrderLines(
    OrderLinesId INT NOT NULL AUTO_INCREMENT,
    count int,
    FK_OrderId int,
    FK_GoodsId int,
    PRIMARY KEY(OrderLinesId),
    FOREIGN KEY(FK_OrderId) REFERENCES Orders(OrdersId),
    FOREIGN KEY(FK_GoodsId) REFERENCES Goods(GoodsId)
);


/*CUSTOMERS INSERT */
INSERT INTO Customers (custName,phone,address) VALUES ('Alex', '+37455419944','Bazum');
INSERT INTO Customers (custName,phone,address) VALUES ('Arshak','+37455887799','Taron4');
INSERT INTO Customers (custName,phone,address) VALUES ('Dianna','+37455815799','Taron1');

/* SUPPLIER INSERT */
INSERT INTO Suppliers(suppName,phone,address) VALUES ('Gandzak','+374 93 461335','Taron4');
INSERT INTO Suppliers(suppName,phone,address) VALUES ('Smile', '+374 44 242131','Tigran Mec');
INSERT INTO Suppliers(suppName,phone,address) VALUES ('LevelUp','+374 77 182510','Taron2');

/* PRODUCT INSERT */
INSERT INTO Goods(goodsName,unitPrice,count,measurment,FK_Suppliers) VALUES ('Apple',250,600,'kg',1);
INSERT INTO Goods(goodsName,unitPrice,count,measurment,FK_Suppliers) VALUES ('Orange',400,400,'kg',2);
INSERT INTO Goods(goodsName,unitPrice,count,measurment,FK_Suppliers) VALUES ('Strawberry',250,300,'kg',3);

/* ORDERS INSERT */
INSERT INTO Orders(date,address, status,FK_Customers) VALUES(CURRENT_TIMESTAMP(),'Taron4','waiting',2);
INSERT INTO Orders(date,address, status,FK_Customers) VALUES(CURRENT_TIMESTAMP(),'Taron1','send',1);
INSERT INTO Orders(date,address, status,FK_Customers) VALUES(CURRENT_TIMESTAMP(),'Bazum','waiting',3);


/* ORDER ITEM INSERT */
INSERT INTO OrderLines(count,FK_OrderId, FK_GoodsId) VALUES (1,3,1);
INSERT INTO OrderLines(count,FK_OrderId, FK_GoodsId) VALUES (2,2,1);
INSERT INTO OrderLines(count,FK_OrderId, FK_GoodsId) VALUES (3,1,3);


SELECT * FROM Customers;
SELECT * FROM Suppliers;
SELECT * FROM Goods;
SELECT * FROM Orders;
SELECT * FROM OrderLines;



select suppName, goodsName from Suppliers
	join Orders on Suppliers.SuppliersId = Orders.FK_Customers
	join OrderLines on Orders.OrdersId = OrderLines.FK_OrderId
	join Goods on OrderLines.FK_GoodsId = Goods.GoodsId
	where Suppliers.SuppliersId <> 0 ;

select OrdersId, date from Orders;

select Count(Status) from Orders
	where Status <> 'send';

select goodsName, (Goods.count - OrderLines.count) as Goods_count from Goods
	join OrderLines on Goods.GoodsId = OrderLines.FK_GoodsId;

select custName, goodsName from Customers
	join Orders on Customers.CustomersId = Orders.FK_Customers
	Join OrderLines on Orders.OrdersId = OrderLines.FK_OrderId
	join Goods on OrderLines.FK_GoodsId = Goods.GoodsId
	where Customers.CustomersId = 1 or Customers.CustomersId = 2 or Customers.CustomersId = 3;

select Orders.OrdersId, Sum(Goods.unitPrice * OrderLines.count) as Total_Price from Orders
	join OrderLines on Orders.OrdersId = OrderLines.FK_OrderId
	join Goods on OrderLines.FK_GoodsId = Goods.GoodsId
	where Orders.OrdersId = 1 or Orders.OrdersId = 2 or Orders.OrdersId = 3 group by Orders.OrdersId;


DROP TABLE OrderLines;
DROP TABLE Orders;
DROP TABLE Customers;
DROP TABLE Goods;
DROP TABLE Suppliers;

DROP DATABASE Shop;
