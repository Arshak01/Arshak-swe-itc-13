CREATE database Shop;
USE Shop;

CREATE TABLE Goods(
	goodsId int NOT NULL AUTO_INCREMENT,
	goodsName varchar(20),
	unitPrice float,
	measurment varchar(5),
	PRIMARY KEY (goodsId)
);

CREATE TABLE Customers(
    	customersId int NOT NULL AUTO_INCREMENT,
	name varchar(40),
	phone varchar(40),
	address varchar(40),
	PRIMARY KEY (customersId)
);

CREATE TABLE Orders(
	ordersId int NOT NULL AUTO_INCREMENT,
	orderNumber int,
  	customersId int,
   	orderDate datetime,
   	statusWay varchar(10),
	totalAmount float,
	PRIMARY KEY (ordersId)
);

CREATE TABLE  Suppliers(
   	suppliersId int NOT NULL AUTO_INCREMENT,
   	companyName varchar(40),
   	phone varchar(20),
   	PRIMARY KEY (suppliersId)
);

CREATE TABLE OrderLines(
	orderLinesId int NOT NULL AUTO_INCREMENT,
	ordersId int,
	goodsId int,
   	customersId int,
	PRIMARY KEY (orderLinesId),
	FOREIGN KEY (customersId) REFERENCES Customers(customersId),
   	FOREIGN KEY (ordersId) REFERENCES Orders(ordersId)
);

CREATE TABLE Warehouse(
   	warehouseId int NOT NULL AUTO_INCREMENT,
   	warehouseName varchar(40),
   	suppliersId int,
   	PRIMARY KEY (warehouseId),
   	FOREIGN KEY (suppliersId) REFERENCES Suppliers(suppliersId)
);

CREATE TABLE WarehouseProducts(
   	warehouseProductsId int NOT NULL AUTO_INCREMENT,
   	warehouseId int,
   	goodsId int,
    	suppliersId int,
    	count int,
    	PRIMARY KEY (WarehouseProductsId),
    	FOREIGN KEY (suppliersId) REFERENCES Suppliers(suppliersId),
    	FOREIGN KEY (goodsId) REFERENCES Goods(goodsId)
);


INSERT INTO Customers (name,phone,address) VALUES ('Arshak','+37455887799','Bazum');
INSERT INTO Customers (name,phone,address) VALUES ('Arman', '+37455447799','Taron4');
INSERT INTO Customers (name,phone,address) VALUES ('Karen','+37455347517','Taron2');

INSERT INTO Suppliers(companyName,phone) VALUES ('Gandzak','+374 93 461335');
INSERT INTO Suppliers(companyName,phone) VALUES ('Smile','+374 44 242131');
INSERT INTO Suppliers(companyName,phone) VALUES ('LevelUp','+374 77 182510');

INSERT INTO Goods(goodsName,unitPrice,measurment) VALUES ('Apple',2500,'g');
INSERT INTO Goods(goodsName,unitPrice,measurment) VALUES ('Orange',4,'kg');
INSERT INTO Goods(goodsName,unitPrice,measurment) VALUES ('Strawberry',850,'g');

INSERT INTO Orders(orderNumber, customersId, orderDate, statusWay, totalAmount) VALUES(4, 3, CURRENT_TIMESTAMP(), 'waiting',5);
INSERT INTO Orders(orderNumber, customersId, orderDate, statusWay, totalAmount) VALUES(5, 2, CURRENT_TIMESTAMP(), 'send',3);
INSERT INTO Orders(orderNumber, customersId, orderDate, statusWay, totalAmount) VALUES(3, 1, CURRENT_TIMESTAMP(), 'waiting',10);

INSERT INTO OrderLines(ordersId, goodsId) VALUES (3,1);
INSERT INTO OrderLines(ordersId, goodsId) VALUES (2,3);
INSERT INTO OrderLines(ordersId, goodsId) VALUES (1,3);

INSERT INTO Warehouse(warehouseName, suppliersId) VALUES ('Gandzak_Pahest', 2);

INSERT INTO WarehouseProducts(warehouseId, goodsId, count) VALUES (1, 3, 4);


SELECT * FROM Customers;
SELECT * FROM Orders;
SELECT * FROM Suppliers;
SELECT * FROM Goods;
SELECT * FROM OrderLines;
SELECT * FROM Warehouse;
SELECT * FROM WarehouseProducts;


--  1. question
select OrdersId, date from Orders;

-- 2.question
SELECT * FROM Orders
WHERE orderDate = CURRENT_TIMESTAMP();

-- 3.question
select Count(statusWay) from Orders
where statusWay <> 'send';

-- 5.question
SELECT * FROM Warehouse
WHERE warehouseId = 1;


DROP TABLE OrderLines;
DROP TABLE Orders;
DROP TABLE Warehouse;
DROP TABLE WarehouseProducts;
DROP TABLE Goods;
DROP TABLE Suppliers;
DROP TABLE Customers;

DROP DATABASE Shop;
