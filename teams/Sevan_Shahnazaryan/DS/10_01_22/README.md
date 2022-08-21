***HI! Welcome to my homework for 10_01_2022***

**Task1_Vector.cpp**

To use this program you should compile it with g++ compiler, higher than 98 version and run the executable file.

I've implemented vector class based on dynamic arrays.

Made following functions

	● extender() to avoid code duplication. Extends vector 1/2 times bigger.

	● Default constructor, which creates a vector with no elements.

	● Parametrized constructor, to create with fixed size and fill it with any number.
	● Getters and setters for member variables, including size().
	● Push(), to add an element.
	● Pop(), to delete one.
	● Insert(), to insert in a specific insert.
		I made an algorithm which does not create a new every time insert is being called.
		Instead I just move elements to right till that specific index.
		So I save memory and time.
	● [] operator overloading function, that returns a specific index value/
	● ~(Vector) destructor, to delete the vector.


**Task2_Stack.cpp**

To use this program you should compile it with g++ compiler, higher than 98 version and run the executable file.

For this program I made 2 classes.
First one is Node, which contains the value and a pointer to previous node.
Second one is Stack, which consists of nodes.

It has the following fucntions.

	● Default constructor that give null and 0 values to head pointer and length.
	● Pop(), which changes the head to one element back and deletes previous head with temp variable.
	● Size(), returns the length of the Stack.
	● IsEmpty(), return true if it's empty, false if not.
	● Print(), prints the Stack without deleting it's elements.
	● Destructor, that deletes it's head.


**Task3_Queue.cpp**

To use this program you should compile it with g++ compiler, higher than 98 version and run the executable file.

Here I used the same code of Stack, but added tail pointer of Node that points the beginning of Queue

I've added these new functions:
	● PushBack(), which adds an element from the beginning.
	● PopFront(), which removes an element from the end and decrements length.
	● Some getter and setters, including size();
	● Other functions are mostly the same as Stack.

Hope you enjoy my programs (^_^)

© Sevan Shahnazaryan. Future(hopefully) Developer in Instigate Mobile.
2022. All rights reserved.
