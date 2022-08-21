README file for the explanation of homework.

Task: Examples for One-to-One, One-to-Many, Many-to-Many.

FIRST: One to One:

+------------+-------------+------+-----+---------+----------------+
| Field      | Type        | Null | Key | Default | Extra          |
+------------+-------------+------+-----+---------+----------------+
| Student_ID | int         | NO   | PRI | NULL    | auto_increment |
| FirstName  | varchar(20) | YES  |     | NULL    |                |
| LastName   | varchar(20) | YES  |     | NULL    |                |
+------------+-------------+------+-----+---------+----------------+

+------------+-------------+------+-----+---------+----------------+
| Field      | Type        | Null | Key | Default | Extra          |
+------------+-------------+------+-----+---------+----------------+
| PhoneNum   | varchar(20) | YES  |     | NULL    |                |
| Country    | varchar(20) | YES  |     | NULL    |                |
| City       | varchar(20) | YES  |     | NULL    |                |
| Student_id | int         | NO   | MUL | NULL    | auto_increment |
+------------+-------------+------+-----+---------+----------------+

+------------+-----------+-----------+
| Student_ID | FirstName | LastName  |
+------------+-----------+-----------+
|          1 | Vardan    | Parzyan   |
|          2 | Poghos    | Poghosyan |
+------------+-----------+-----------+
+-----------+---------+----------+------------+
| PhoneNum  | Country | City     | Student_id |
+-----------+---------+----------+------------+
| 096272262 | Armenia | Vanadzor |          1 |
| 123456789 | Armenia | Ddmashen |          2 |
+-----------+---------+----------+------------+

SECOND: One To Many:

+--------------+-------------+------+-----+---------+-------+
| Field        | Type        | Null | Key | Default | Extra |
+--------------+-------------+------+-----+---------+-------+
| Teacher_ID   | int         | NO   | PRI | NULL    |       |
| Teacher_Name | varchar(30) | YES  |     | NULL    |       |
+--------------+-------------+------+-----+---------+-------+

+------------+-------------+------+-----+---------+-------+
| Field      | Type        | Null | Key | Default | Extra |
+------------+-------------+------+-----+---------+-------+
| Cource_ID  | int         | NO   |     | NULL    |       |
| CourceName | varchar(30) | YES  |     | NULL    |       |
| Teacher_ID | int         | NO   | MUL | NULL    |       |
+------------+-------------+------+-----+---------+-------+

+------------+------------------+
| Teacher_ID | Teacher_Name     |
+------------+------------------+
|          1 | Vardan Parzyan   |
|          2 | Petros Petrosyan |
+------------+------------------+

+-----------+------------+------------+
| Cource_ID | CourceName | Teacher_ID |
+-----------+------------+------------+
|         1 | Biology    |          1 |
|         2 | Math       |          2 |
|         3 | History    |          1 |
|         1 | Biology    |          1 |
|         2 | Math       |          2 |
|         3 | History    |          1 |
+-----------+------------+------------+

THIRD: Many To Many

+------------+-------------+------+-----+---------+----------------+
| Field      | Type        | Null | Key | Default | Extra          |
+------------+-------------+------+-----+---------+----------------+
| Student_ID | int         | NO   | PRI | NULL    | auto_increment |
| FirstName  | varchar(20) | YES  |     | NULL    |                |
| LastName   | varchar(20) | YES  |     | NULL    |                |
+------------+-------------+------+-----+---------+----------------+
+--------------+-------------+------+-----+---------+-------+
| Field        | Type        | Null | Key | Default | Extra |
+--------------+-------------+------+-----+---------+-------+
| Teacher_ID   | int         | NO   | PRI | NULL    |       |
| Teacher_Name | varchar(30) | YES  |     | NULL    |       |
+--------------+-------------+------+-----+---------+-------+
+------------+-------------+------+-----+---------+-------+
| Field      | Type        | Null | Key | Default | Extra |
+------------+-------------+------+-----+---------+-------+
| CourceName | varchar(30) | YES  |     | NULL    |       |
| Teacher_ID | int         | NO   | MUL | NULL    |       |
| Student_ID | int         | NO   | MUL | NULL    |       |
+------------+-------------+------+-----+---------+-------+
+------------+-----------+-----------+
| Student_ID | FirstName | LastName  |
+------------+-----------+-----------+
|          1 | Vardan    | Parzyan   |
|          2 | Petros    | Poghosyan |
|          3 | Poghos    | Petrosyan |
+------------+-----------+-----------+
+------------+--------------+
| Teacher_ID | Teacher_Name |
+------------+--------------+
|          1 | Elya         |
|          2 | Nane         |
|          3 | Martiros     |
+------------+--------------+
+------------------+------------+------------+
| CourceName       | Teacher_ID | Student_ID |
+------------------+------------+------------+
| DataBase         |          1 |          1 |
| Algorithm        |          2 |          1 |
| DM Documentation |          2 |          1 |
| Biology          |          3 |          2 |
| Math             |          3 |          2 |
| Constitution     |          3 |          3 |
+------------------+------------+------------+


       
