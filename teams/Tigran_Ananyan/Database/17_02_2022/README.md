# Connection examples

The sql script to show one to one, one to more and more to more connections in database.


### Executing program

* How to run the program
* Step-by-step bullets
* Get the path to file and copy it
```
realpath examples.sql
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

Database Drivers

Lable
+----+---------------+
| id | name          |
+----+---------------+
|  1 | Mersedes Benz |
|  2 | BMW           |
|  3 | Tesla         |
|  4 | Audi          |
|  5 | Toyota        |
+----+---------------+
5 rows in set (0.00 sec)

License
+----+-------------+-------+
| id | code        | class |
+----+-------------+-------+
|  1 | AA123456789 | C     |
|  2 | AA124476729 | A     |
|  3 | AB124472728 | B     |
|  4 | AA125473721 | C     |
|  5 | BA325413731 | B     |
+----+-------------+-------+
5 rows in set (0.00 sec)

Person
+----+----------+---------+------------+
| id | name     | surname | license_id |
+----+----------+---------+------------+
|  1 | John     | Bronks  |          2 |
|  2 | James    | Camaron |          4 |
|  3 | Gordon   | Ramsey  |          1 |
|  4 | Fernando | Torres  |          3 |
|  5 | Ornello  | Mutti   |          5 |
+----+----------+---------+------------+
5 rows in set (0.01 sec)

Car
+----+---------------+-----------+----------+
| id | name          | type      | brand_id |
+----+---------------+-----------+----------+
|  1 | maybach       | sedan     |        1 |
|  2 | model x       | crossover |        3 |
|  3 | camry         | sedan     |        5 |
|  4 | gwagen        | crossover |        1 |
|  5 | model s plaid | sedan     |        3 |
+----+---------------+-----------+----------+
5 rows in set (0.00 sec)

Person_car
+----+---------------+-----------+--------+
| id | owner_license | person_id | car_id |
+----+---------------+-----------+--------+
|  1 | AA234256      |         1 |      3 |
|  2 | AB331236      |         4 |      3 |
|  3 | AA131132      |         4 |      2 |
|  4 | AA735032      |         1 |      4 |
|  5 | AA7310334     |         2 |      2 |
|  6 | AB7640330     |         5 |      1 |
|  7 | AB724550      |         3 |      5 |
|  8 | BB722323      |         2 |      3 |
+----+---------------+-----------+--------+
8 rows in set (0.00 sec)

