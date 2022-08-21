# Binary search implementation application

## To build and execute the application you need to run the following commands from ".../Narek_Hovhannisyan/ds/13_01_2022" directory
---

```bash
mkdir build && cd build
cmake .. . && make && ./main
```

> the executable file is ".../build/main"

the application has following methods

* insert(int data) – The function that adds a node to a tree.
* delete(int data) - The function that removes a node from a tree.
* print() -  Use level order tree traversal method to print

> print methods working example, we have a tree

                          5
                        /   \
                       4    11
                     /     /  \
                    1     7    20
                        /  \
                       6    9
print method will print 

```
5 4 1 - -
-
11 7 6 - -
9 - -
20 - -
```
> "-" means null child

Fill free to use them. Thanks
