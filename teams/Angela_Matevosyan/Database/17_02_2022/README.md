###Example1: ONE TO ONE RELATION
**Each user can have only one unique password. Th result is like this:**

mysql> select * from 1to1.Users;
+--------+-------+
| UserId | Name  |
+--------+-------+
|      1 | User1 |
|      2 | User2 |
|      3 | User3 |
|      4 | User4 |
|      5 | User5 |
+--------+-------+


mysql> select * from 1to1.Passwords;
+------------+----------+-----------+
| PasswordId | Password | FK_UserId |
+------------+----------+-----------+
|          1 | jfv35c   |         5 |
|          2 | njf23k   |         3 |
|          3 | ncj45l   |         2 |
|          4 | kmd85f   |         4 |
|          5 | bnj59s   |         1 |
+------------+----------+-----------+

###Example2: ONE TO MANY RELATION
**Each person can have more than one phone numbers, the result is like this:**

mysql> select * from 1ton.Person;
+----------+-------+
| PersonId | Name  |
+----------+-------+
|        1 | Name1 |
|        2 | Name2 |
|        3 | Name3 |
|        4 | Name4 |
|        5 | Name5 |
+----------+-------+


mysql> select * from 1ton.Phone;
+---------+---------+-------------+
| PhoneId | Numbers | FK_PersonId |
+---------+---------+-------------+
|       1 |   99632 |           3 |
|       2 |   96654 |           2 |
|       3 |  177251 |           2 |
|       4 |   96224 |           4 |
|       5 |   45225 |           5 |
|       6 |   94511 |           3 |
|       7 |   55163 |           5 |
|       8 |   95362 |           4 |
+---------+---------+-------------+

###Example 3: MANY TO MANY RELATION
**Many actors can play in many movies. The result is like this:**

mysql> select * from nton.Movies;
+---------+--------------------------+
| MovieId | Name                     |
+---------+--------------------------+
|       1 | Harry Potter             |
|       2 | The Matrix               |
|       3 | John Wick                |
|       4 | Beauty and the Beast     |
|       5 | Pirates of the Caribbean |
|       6 | Crimes of Grindelwald    |
+---------+--------------------------+

mysql> select * from nton.Actors;
+---------+-----------------+
| ActorId | Name            |
+---------+-----------------+
|       1 | Emma Watson     |
|       2 | Keanu Reeves    |
|       3 | Johnny Depp     |
|       4 | Daniel Radcliff |
+---------+-----------------+

mysql> select * from nton.Junction;
+------------+------------+------------+
| JunctionId | FK_MovieId | FK_ActorId |
+------------+------------+------------+
|          1 |          1 |          1 |
|          2 |          1 |          4 |
|          3 |          2 |          2 |
|          4 |          4 |          1 |
|          5 |          5 |          3 |
|          6 |          6 |          3 |
+------------+------------+------------+

