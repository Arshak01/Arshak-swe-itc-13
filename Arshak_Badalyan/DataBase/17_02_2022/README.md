## Project-name
	RELATIONSHIP


## Project-description
	1.ONE TO ONE   - RELATIONSHIP
	2.ONE TO MANY  - RELATIONSHIP
	3.MANY TO MANY - RELATIONSHIP
	4.mysql tests - HACKERRANK  web page


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
	OneToOne

	+----------+--------+----------+---------------+
	| PersonId | name   | lastname | FK_PassportId |
	+----------+--------+----------+---------------+
	|        1 | Arshak | Badalyan |             1 |
	+----------+--------+----------+---------------+

	+------------+--------------+
	| PassportId | serialNumber |
	+------------+--------------+
	|          1 |       156565 |
	+------------+--------------+

	OneToMany
	
	+-----------+--------+-----------+
	| TeacherId | tName  | tLastName |
	+-----------+--------+-----------+
	|         1 | Dianna | Lalayan   |
	|         2 | Mery   | Grigoryan |
	|         3 | Sima   | Davtyan   |
	+-----------+--------+-----------+

	+-----------+-------+-----------+-------------+
	| StudentId | sName | sLastName | FK_TecherId |
	+-----------+-------+-----------+-------------+
	|         1 | Arman | Esayan    |           1 |
	|         2 | Nana  | Grigoryan |           1 |
	|         3 | Anna  | Mirzoyan  |           2 |
	|         4 | Kolya | Madacyan  |           1 |
	|         5 | Filya | Teryan    |           2 |
	+-----------+-------+-----------+-------------+

	ManyToMany

	+------------+-------+-----------+
	| EmployeeId | name  | lastName  |
	+------------+-------+-----------+
	|          1 | Anna  | Eranosyan |
	|          2 | Tomma | Asatryan  |
	|          3 | Gor   | Dallaqyan |
	|          4 | Anna  | Boryan    |
	|          5 | Gohar | Mirzoyan  |
	|          6 | Lilia | Surgsyan  |
	+------------+-------+-----------+

	+--------------+----------------+
	| ProfessionId | professionName |
	+--------------+----------------+
	|            1 | Accountant     |
	|            2 | Baker          |
	|            3 | Cleaner        |
	|            4 | Pilot          |
	|            5 | Politician     |
	|            6 | Model          |
	+--------------+----------------+

	+---------------------+---------------+-----------------+
	| Employee_Profession | FK_EmployeeId | FK_ProfessionId |
	+---------------------+---------------+-----------------+
	|                   1 |             1 |               2 |
	|                   2 |             4 |               2 |
	|                   3 |             1 |               5 |
	|                   4 |             3 |               1 |
	|                   5 |             5 |               4 |
	|                   6 |             4 |               5 |
	|                   7 |             2 |               1 |
	+---------------------+---------------+-----------------+


## Contents
Thanks for reading :)
