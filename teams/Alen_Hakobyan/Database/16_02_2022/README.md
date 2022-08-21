## Project-name
	MySQL

## Project-description
	Create a Shop Database.

## Links
- [MySQL](https://www.w3schools.com/sql/sql_alter.asp)


## Available Commands

Need to run sudo mysql and after that source (filename).


## Built With
- Visual Code
- MySQL


# List of products ordered by the customer.

+----------+-----------+
| CustName | GoodsName |
+----------+-----------+
| Name1    | Good1     |
| Name2    | Good3     |
| Name4    | Good4     |
+----------+-----------+

# Orders DateTime

+----------+---------------------+
| OrdersID | OrderDate           |
+----------+---------------------+
|        1 | 2022-02-21 21:33:33 |
|        2 | 2022-02-20 20:30:30 |
|        3 | 2022-02-21 21:40:40 |
+----------+---------------------+

# Status Count

+--------------------+
| Count(FK_StatusID) |
+--------------------+
|                  2 |
+--------------------+

# Count of Goods in stock.

+-----------+-------------+
| GoodsName | Goods_Count |
+-----------+-------------+
| Good1     |           3 |
| Good3     |           2 |
| Good4     |           7 |
+-----------+-------------+

# Which Suppliers provides the good.

+----------+-----------+
| SuppName | GoodsName |
+----------+-----------+
| Supp1    | Good1     |
| Supp2    | Good3     |
| Supp3    | Good4     |
+----------+-----------+

# Total Price of Order.

+----------+-------------+
| OrdersID | Total_Price |
+----------+-------------+
|        1 |         200 |
|        2 |        1200 |
|        3 |         400 |
+----------+-------------+

