## Project-name
	Tasks from WebPage


## Project-description
	1.Not Boring Movies
	2.Combine Two Tables
	3.Duplicate Emails
	4.Department Highest Salary
	5.Exchange Seats


## Code source
	https://leetcode.com/problemset/database/
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
	Task1:
		+----------+------------+-------------+--------+
		| CinemaId | movie      | description | rating |
		+----------+------------+-------------+--------+
		|        1 | War        | great 3D    |    8.9 |
		|        2 | Science    | fiction     |    8.5 |
		|        3 | irish      | boring      |    6.2 |
		|        4 | Ice song   | Fantacy     |    8.6 |
		|        5 | House card | Interesting |    9.1 |
		+----------+------------+-------------+--------+

		+----------+------------+-------------+--------+
		| CinemaId | movie      | description | rating |
		+----------+------------+-------------+--------+
		|        5 | House card | Interesting |    9.1 |
		|        1 | War        | great 3D    |    8.9 |
		+----------+------------+-------------+--------+

	Task2:
		+----------+----------+-----------+
		| PersonId | lastName | firstName |
		+----------+----------+-----------+
		|        1 | Wang     | Allen     |
		|        2 | Alice    | Bob       |
		+----------+----------+-----------+

		+-----------+-------------+---------------+------------+
		| AddressId | FK_PersonId | city          | state      |
		+-----------+-------------+---------------+------------+
		|         1 |           2 | New York City | New York   |
		|         2 |           2 | Los Angles    | California |
		+-----------+-------------+---------------+------------+

		+-----------+-------------+---------------+------------+
		| AddressId | FK_PersonId | city          | state      |
		+-----------+-------------+---------------+------------+
		|         1 |           2 | New York City | New York   |
		|         2 |           2 | Los Angles    | California |
		+-----------+-------------+---------------+------------+

	Task3:
		+----------+---------+
		| PersonId | email   |
		+----------+---------+
		|        1 | a@b.com |
		|        2 | a@c.com |
		|        3 | a@b.com |
		+----------+---------+

		+---------+
		| email   |
		+---------+
		| a@b.com |
		+---------+

	Task4:
		+--------------+-------+
		| DepartmentId | name  |
		+--------------+-------+
		|            1 | IT    |
		|            2 | Sales |
		+--------------+-------+

		+------------+-------+--------+-----------------+
		| EmployeeId | name  | salary | FK_departmentId |
		+------------+-------+--------+-----------------+
		|          1 | Joe   |  70000 |               1 |
		|          2 | Jim   |  90000 |               2 |
		|          3 | Henry |  80000 |               1 |
		|          4 | Sam   |  60000 |               2 |
		|          5 | Max   |  90000 |               2 |
		|          6 | Ray   | 100000 |               1 |
		+------------+-------+--------+-----------------+

		+-----------------+-------------+
		| FK_departmentId | max(salary) |
		+-----------------+-------------+
		|               1 |      100000 |
		|               2 |       90000 |
		+-----------------+-------------+

	Task5:
		+--------+-------+
		| SeatId | name  |
		+--------+-------+
		|      1 | Jim   |
		|      2 | Henry |
		|      3 | Sam   |
		|      4 | Max   |
		|      5 | Ray   |
		|      6 | Joe   |
		+--------+-------+

		+--------+-------+
		| SeatId | name  |
		+--------+-------+
		|      6 | Joe   |
		|      5 | Ray   |
		|      4 | Max   |
		|      3 | Sam   |
		|      2 | Henry |
		|      1 | Jim   |
		+--------+-------+


## Contents
Thanks for reading :)
