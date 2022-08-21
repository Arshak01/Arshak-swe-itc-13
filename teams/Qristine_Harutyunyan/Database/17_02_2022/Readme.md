## Create database Shop

## Description

# There are folowing tables

  1. Person
  2. Address

  3. Person
  4. Relation

  5. Person
  6. Profation


# There are folowing relations
 
  1. Person.PersonID - Address.PersonID (one to one)
     Usually One to one relations are Id number and Id's owner` person or something.
    
     mysql> source task1.sql
+----------+------------+---------------+
| PersonId | PersonName | PersonSurname |
+----------+------------+---------------+
|        1 | Person1    | Surname1      |
|        2 | Person2    | Surname2      |
|        3 | Person3    | Surname3      |
|        4 | Person4    | Surname4      |
+----------+------------+---------------+
4 rows in set (0.00 sec)

+----------+---------+---------+------------+-------------+
| PersonId | Country | Region  | City       | Street      |
+----------+---------+---------+------------+-------------+
|        1 | Armenia | Yerevan | Yerevan    | Avan 3/4    |
|        2 | Armenia | Lori    | Vanadzor   | street 12/5 |
|        3 | Armenia | Lori    | Stepanavan | street 102  |
|        4 | Armenia | Kotayq  | Abovyan    | street 98   |
+----------+---------+---------+------------+-------------+  

   2. PersonID and ReationName (one to many)
      It also will be if Relation have ID and in Person table we add RelationID;
	  Usually one to many is few enum list, and our one element can choose only one.
	  Person can be in one of this ralations.

mysql> source task1.sql
+----------+------------+---------------+
| PersonId | PersonName | PersonSurname |
+----------+------------+---------------+
|        1 | Person1    | Surname1      |
|        2 | Person2    | Surname2      |
|        3 | Person3    | Surname3      |
|        4 | Person4    | Surname4      |
+----------+------------+---------------+
4 rows in set (0.00 sec)

+----------+-------------+
| PersonId | RelName     |
+----------+-------------+
|        1 | Married     |
|        2 | Single      |
|        3 | in ralation |
|        4 | single      |
+----------+-------------+
4 rows in set (0.00 sec)	

   3.  Profation and Person (many to many)
       There are many people In one profetion and one person can have many profations.

+----------+------------+---------------+
| PersonId | PersonName | PersonSurname |
+----------+------------+---------------+
|        1 | Person1    | Surname1      |
|        2 | Person2    | Surname2      |
|        3 | Person3    | Surname3      |
|        4 | Person4    | Surname4      |
+----------+------------+---------------+
4 rows in set (0.00 sec)

+--------+--------------------+
| ProfId | ProfName           |
+--------+--------------------+
|      1 | Software engeenare |
|      2 | Acountent          |
|      3 | Singer             |
|      4 | Dancer             |
|      5 | Actor              |
+--------+--------------------+
5 rows in set (0.00 sec)

+----------+--------+
| PersonID | ProfID |
+----------+--------+
|        1 |      1 |
|        1 |      2 |
|        2 |      3 |
|        2 |      4 |
|        2 |      5 |
|        3 |      1 |
|        4 |      2 |
+----------+--------+

## Usage
```MySql
cd ../swe-itc-13-homeworks/Qristine_Harutyunyan/Database/17_02_2022
sudo mysql
source task1.sql
```
