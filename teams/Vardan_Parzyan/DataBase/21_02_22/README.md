## Project-name
	HOMEWORK

## Project-description
There must be some important description (oO)


## Code source
	https://www.w3schools.com/sql/default.asp


## Usage:
1. Open terminal
2. Use command "sudo mysql -p " and enter the password
3. Use command mysql> source file_path/name to run it. 

## OUTPUT:
TASK 1.

This is our table that we have created. 
+----+--------+
| id | salary |
+----+--------+
|  1 |    100 |
|  2 |    200 |
|  3 |    300 |
+----+--------+

This is the answer of tasks question
+---------------------+
| SecondHighestSalary |
+---------------------+
|                 200 |
+---------------------+


TAKS 2.

This is our table that we have created. 
+----+------+
| id | num  |
+----+------+
|  1 |    1 |
|  2 |    1 |
|  3 |    1 |
|  4 |    2 |
|  5 |    1 |
|  6 |    2 |
|  7 |    2 |
+----+------+

This is the answer of tasks question
+-----------------+
| ConsecutiveNums |
+-----------------+
|               1 |
+-----------------+

TASK 3.

This is our tables that we have created. 
+----+-------+--------+----------------+
| id | name  | salary | departament_id |
+----+-------+--------+----------------+
|  1 | Joe   |  70000 |              1 |
|  2 | Jim   |  90000 |              1 |
|  3 | Henry |  80000 |              2 |
|  4 | Sam   |  60000 |              2 |
|  5 | Max   |  90000 |              1 |
+----+-------+--------+----------------+
+----+-------+
| id | name  |
+----+-------+
|  1 | IT    |
|  2 | Sales |
+----+-------+

After 'inner join' out table is like -
+-------+--------+-------+
| name  | salary | name  |
+-------+--------+-------+
| Joe   |  70000 | IT    |
| Jim   |  90000 | IT    |
| Henry |  80000 | Sales |
| Sam   |  60000 | Sales |
| Max   |  90000 | IT    |
+-------+--------+-------+

This is the answer of tasks question
+-------+--------+-------+
| name  | salary | name  |
+-------+--------+-------+
| Jim   |  90000 | IT    |
| Henry |  80000 | Sales |
| Max   |  90000 | IT    |
+-------+--------+-------+





