# Online shop database

The sql script to create online shop data base with given conditions.


### Executing program

* How to run the program
* Step-by-step bullets
* Get the path to file and copy it
```
realpath online_shop.sql
```
* Connect to MySQL database server
```
sudo mysql
```
* Run the script
```
source /paste/the/path/here
```

## Authors

Contributors names and contact info

ex. Ananyan Tigran  
ex. [github](https://github.com/AnanyanTigran)

## Version History

* 0.1 
    * Initial Release

## Build With

* Mysql
* vim
* VSCode

1.Customers ordered goods
+---------------+-----------+
| customer_name | good_name |
+---------------+-----------+
| Sarah         | Hoop 2.0  |
| Sarah         | T-shirt   |
| Sarah         | T-shirt   |
+---------------+-----------+

2.When did send the specific order 
+----------+---------------------+
| order_id | date_from           |
+----------+---------------------+
|       10 | 2022-02-10 00:00:00 |
+----------+---------------------+

3.How much open orders are there in the sistem 
+------------------+
| Count(status_id) |
+------------------+
|                2 |
+------------------+

4.How mach goods are there in the warehouse
+-----------+-------------+
| good_name | goods_count |
+-----------+-------------+
| Hoop 2.0  |           9 |
| T-shirt   |          10 |
| T-shirt   |          10 |
+-----------+-------------+

5.Wich supplier is  producing the specific good
+---------------+-----------+
| supplier_name | good_name |
+---------------+-----------+
| Gucci         | Hoop 2.0  |
| Zara          | T-shirt   |
| Prada         | glasses   |
+---------------+-----------+

The total price of the order
+----------+-------+
| order_id | total |
+----------+-------+
|       13 |   170 |
+----------+-------+