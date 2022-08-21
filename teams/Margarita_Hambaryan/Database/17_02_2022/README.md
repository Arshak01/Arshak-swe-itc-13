#Hi all,
####Today I've created examples for showing the relationships between one-to-one(example1) one-o-many(example2) and many_to_many(example3).

##These are the results:

**Example1:**

*db.people*
+------------+----------------------+-----------+
| account_ID | account              | person_ID |
+------------+----------------------+-----------+
|         17 | poghos_poghosyan     |         0 |
|         21 | sahak_sahakyan       |         4 |
|         25 | gevorg_gevorgyan     |         3 |
|         40 | martiros_martirosyan |         2 |
|         47 | petros_petrosyan     |         1 |
+------------+----------------------+-----------+

*db.instagram_accounts*
+-----------+----------+-------------+
| person_ID | name     | surname     |
+-----------+----------+-------------+
|         0 | Poghos   | Poghosyan   |
|         1 | Petros   | Petrosyan   |
|         2 | Martiros | Martirosyan |
|         3 | Gevorg   | Gevorgyan   |
|         4 | Sahak    | Sahakyan    |
+-----------+----------+-------------+

-----------------------------------------------

**Example2:**

*db.parents*
+-----------+-------------+-------------+
| parent_ID | mother_name | father_name |
+-----------+-------------+-------------+
|         0 | Poghosuhi   | Poghos      |
|         1 | Petrosuhi   | Petros      |
|         2 | Armen       | Armenuhi    |
+-----------+-------------+-------------+

*db.kids*
+--------+------------+-----------+
| kid_ID | kid_name   | parent_ID |
+--------+------------+-----------+
|     17 | Philipos   |         1 |
|     18 | Serob      |         1 |
|     20 | Hakobos    |         1 |
|     21 | Pharandzem |         2 |
|     24 | Smbat      |         0 |
|     26 | Ararat     |         0 |
|     30 | Varduhi    |         0 |
|     45 | Karine     |         2 |
|     46 | Satine     |         2 |
|     49 | Qvazimodo  |         2 |
+--------+------------+-----------+


----------------------------------------------

**Example3:**

*db.people*
+-----------+--------+
| person_ID | name   |
+-----------+--------+
|         0 | Poghos |
|         1 | Petros |
|         2 | Tadeos |
+-----------+--------+

*db.actors*
+----------+-------------------+
| actor_ID | name              |
+----------+-------------------+
|       17 | LeonardoDICaprio  |
|       18 | WillSmith         |
|       33 | AngelinaJolie     |
|       45 | MorganFreeman     |
|       56 | AdrianoChelentano |
+----------+-------------------+

*db.fav_actors*
+-----------+----------+
| person_ID | actor_ID |
+-----------+----------+
|         0 |       17 |
|         1 |       17 |
|         2 |       17 |
|         0 |       18 |
|         2 |       18 |
|         1 |       33 |
|         2 |       45 |
|         1 |       56 |
+-----------+----------+


Thanks,
Margarita Hambaryan


