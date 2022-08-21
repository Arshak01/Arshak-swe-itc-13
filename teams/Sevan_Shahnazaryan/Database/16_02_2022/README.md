# Homework from 16_02_2022

To use my program you should:

* run ```sudo mysql``` command in the current directory. 

* Next run ```source <program name>```

Remember that you should not have any of my programs databases' names used to run my programs.

## One to one

#### Here i've implemented a simple people-phone number database.

Customers
```
+------------+------+
| CustomerID | name |
+------------+------+
|          1 | Jack |
|          2 | Dan  |
|          3 | Rob  |
+------------+------+

```
##
Orders
```
+---------+------------+------------------+-----------------+------------+
| OrderID | CustomerID | date             | address         | status     |
+---------+------------+------------------+-----------------+------------+
|     101 |          1 | 01_01_2022 00:00 | Shirakaci 1     | Delivered  |
|     102 |          1 | 02_01_2022 15:34 | Shinararneri 12 | Delivered  |
|     103 |          2 | 03_01_2022 17:00 | Shirakaci 1     | On the way |
|     104 |          3 | 03_01_2022 17:05 | Hambardzumyan 5 | On the way |
+---------+------------+------------------+-----------------+------------+
```
##
Supplier
```
+------------+--------------+----------------------+
| SupplierID | name         | address              |
+------------+--------------+----------------------+
|        201 | Tashir Pizza | Tigran Mets 12       |
|        202 | KFC          | Tigran Mets 41       |
|        203 | Asteri       | Grigor Lusavorich 40 |
+------------+--------------+----------------------+
```
##
Goods
```
+--------+---------+------------+-------+-------+
| GoodID | name    | SupplierID | price | count |
+--------+---------+------------+-------+-------+
|    301 | Shaurma |        201 |  1100 |    50 |
|    302 | Shaurma |        203 |  1200 |    75 |
|    303 | Nuggets |        202 |   750 |   100 |
|    304 | Nuggets |        203 |   650 |   250 |
+--------+---------+------------+-------+-------+
```
##
OrderLines
```
+--------------+---------+--------+-------+
| OrderLinesID | OrderID | GoodID | count |
+--------------+---------+--------+-------+
|          401 |     101 |    301 |     5 |
|          402 |     101 |    303 |     4 |
|          403 |     102 |    301 |    10 |
|          404 |     103 |    301 |     2 |
|          405 |     103 |    302 |     2 |
|          406 |     103 |    303 |     2 |
|          407 |     103 |    304 |     2 |
|          408 |     104 |    303 |    15 |
|          409 |     104 |    301 |    10 |
+--------------+---------+--------+-------+
```



#### The result of my program you will see after running it.
