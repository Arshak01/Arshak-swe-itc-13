# Homework from 17_02_2022

I've created 3 mysql relationships.

* one_to_one
* one_to_many
* many_to_many

To use my program you should:

* run ```sudo mysql``` command in the current directory. 

* Next run ```source <program name>```

Remember that you should not have any of my programs databases' names used to run my programs.

## One to one

#### Here i've implemented a simple people-phone number database.

People
```
+----+-------+
| ID | name  |
+----+-------+
|  1 | Jack  |
|  2 | Vacho |
|  3 | May   |
+----+-------+
```
##
Phone number
```
+---------+-----------+-------+
| phoneID | num       | FK_ID |
+---------+-----------+-------+
|       1 | 012123123 |     1 |
|       2 | 012321321 |     2 |
|       3 | 012321654 |     3 |
+---------+-----------+-------+
```


## One to many

#### This one is a list of football club and some of it's previous or current players.

Football club
```
+---------+-------------+
| club_ID | name        |
+---------+-------------+
|       1 | Barcelona   |
|       2 | MU          |
|       3 | Real Madrid |
+---------+-------------+
```
##
Football player
```
+-----------+-------------------+---------+
| player_ID | name              | club_ID |
+-----------+-------------------+---------+
|         1 | Lioniel Messi     |       1 |
|         2 | Xavi              |       1 |
|         3 | Iniesta           |       1 |
|         4 | Wayne Rooney      |       2 |
|         5 | De Gea            |       2 |
|         6 | Van Persie        |       2 |
|         7 | Cristiano Ronaldo |       3 |
|         8 | Benzema           |       3 |
|         9 | Marcelo           |       3 |
+-----------+-------------------+---------+
```

## Many to many

#### This one is a list of soldiers and the guns they have.

Soldiers
```
+------------+--------------+
| soldier_ID | soldier_name |
+------------+--------------+
|          1 | Ivanov       |
|          2 | Babkin       |
|          3 | Borisyuk     |
+------------+--------------+
```
##
Guns
```
+--------+----------+
| gun_ID | gun_name |
+--------+----------+
|      1 | AK-74    |
|      2 | PK       |
|      3 | RPG-7    |
+--------+----------+
```
##
Soldier and their Guns list
```
+-------+------------+--------+
| SG_ID | soldier_ID | gun_ID |
+-------+------------+--------+
|     1 |          1 |      1 |
|     2 |          1 |      3 |
|     3 |          2 |      1 |
|     4 |          2 |      2 |
|     5 |          3 |      2 |
|     6 |          3 |      3 |
+-------+------------+--------+
```
