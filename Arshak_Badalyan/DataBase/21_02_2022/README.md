## Project-name
	Tasks SQL query


## Project-description
	1.TASK 1 : Write an SQL query to report the second highest salary from the Employee table.
	2.TASK 2 : Write an SQL query to find all numbers that appear at least three times consecutively.
	3.TASK 3 : Write an SQL query to find employees who have the highest salary in each of the departments.


## Code source
	https://www.w3schools.com/sql/sql_join.asp
	https://www.techonthenet.com/mysql/


## Description
	For running project,go to folder and  need to open terminal,write down `pwd` and copy of your current path, than write on terminal `sudo mysql` than `source path/filename.sql`and run running project.


## Usage:
	From build dir, write on terminal\n
		1.`cd task dir/`,\n
		2.`pwd`
		3.`sudo mysql`
		4.`source path/filename.sql`


## OUTPUT:
	Task 1:

	+------------+--------+
	| EmployeeId | salary |
	+------------+--------+
	|          1 |    100 |
	|          2 |    200 |
	|          3 |    300 |
	+------------+--------+

	+-------------+
	| Max(salary) |
	+-------------+
	|         200 |
	+-------------+
###########################################################################
	Task 2:

	+------------+------+
	| EmployeeId | num  |
	+------------+------+
	|          1 | 1    |
	|          2 | 1    |
	|          3 | 1    |
	|          4 | 1    |
	|          5 | 2    |
	|          6 | 1    |
	|          7 | 1    |
	+------------+------+

	+-----------------+
	| ConsecutiveNums |
	+-----------------+
	| 1               |
	+-----------------+

###########################################################################
	Task 3:

	+---------------+-------------+------+-----+---------+----------------+
	| Field         | Type        | Null | Key | Default | Extra          |
	+---------------+-------------+------+-----+---------+----------------+
	| EmployeeId    | int         | NO   | PRI | NULL    | auto_increment |
	| name          | varchar(30) | YES  |     | NULL    |                |
	| salary        | int         | YES  |     | NULL    |                |
	| departamentId | int         | YES  |     | NULL    |                |
	+---------------+-------------+------+-----+---------+----------------+

	+---------------+-------------+------+-----+---------+----------------+
	| Field         | Type        | Null | Key | Default | Extra          |
	+---------------+-------------+------+-----+---------+----------------+
	| DepartamentId | int         | NO   | PRI | NULL    | auto_increment |
	| name          | varchar(10) | YES  |     | NULL    |                |
	+---------------+-------------+------+-----+---------+----------------+

	+------------+-------+--------+---------------+
	| EmployeeId | name  | salary | departamentId |
	+------------+-------+--------+---------------+
	|          1 | Joe   |  70000 |             1 |
	|          2 | Jim   |  90000 |             1 |
	|          3 | Henry |  80000 |             2 |
	|          4 | Sam   |  60000 |             2 |
	|          5 | Max   |  90000 |             1 |
	+------------+-------+--------+---------------+

	+-------+--------+-------+
	| name  | salary | name  |
	+-------+--------+-------+
	| Jim   |  90000 | IT    |
	| Henry |  80000 | Sales |
	| Max   |  90000 | IT    |
	+-------+--------+-------+

## Contents
	Thanks for reading :)