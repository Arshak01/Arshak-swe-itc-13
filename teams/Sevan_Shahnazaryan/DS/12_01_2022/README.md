***Welcome to my List implementation with iterators***

My program consists of 8 files:

	● CmakeLists.txt(Minimum required version 3.10)
	● Task1_List.cpp (main function is here)
	● Node.cpp, Node.hpp (Node class)
	● Iterator.cpp, Iterator.hpp (Iterator class)
	● List.cpp, List.hpp (List class)

I have made the following functions.

	● In List class
	◦ Default constructor - Constructs an empty container, with no elements.
    ◦ Copy constructor - Constructs a container with a copy of each of the elements in x, in the same order.
	◦ void pushBack(int data) – Adds a new element at the end of the list
	◦ void pushFront(int data) – Adds a new element at the beginning of the list
	◦ void popBack() - Removes the last element in the list container
	◦ void popFront() - Removes the first element in the list container
	◦ void insert(int position, int data) – Insert new element in the given position
	◦ void remove(int data) – Removes the first encountered element which contains given data
	◦ print() - Print the list

	● In Iterator class.
		◦iterator begin() - Returns an iterator pointing to the first element in the list.
		◦ iterator end() - Returns an iterator referring to the past-the-end element in the list (Does not really work)
		container.
		◦iterator& operator++() - Prefix ++ overload
		◦iterator& operator++(int) -  Postfix ++ overload
		◦iterator& operator--() - Prefix – overload
		◦iterator& operator--(int) -  Postfix -- overload
		◦iterator& operator!=(iterator &obj) -  bool no equal != overload


***To use the program***

Write the following commads in terminal from the current directery

	◦mkdir build
	◦cd build
	◦cmake .. .
	◦make
	◦./List

Hope you enjoy my programs (^_^)

© Sevan Shahnazaryan. Future(hopefully) Developer in Instigate Mobile. 2022. All rights reserved.
