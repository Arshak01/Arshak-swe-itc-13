## Project-name
	Vector

## Project-description
	Create the Vector which contain these functions.
		Vector();
		Vector(int size);
		Vector(int size, int value);
		void push(int data);
		void pop();
		void insert(int index, int data);
		void deleteAtIndex(int index);
		int operator [] (int index);
		void print();
		int size();
		int capacity();
		bool empty();
		~Vector();
		
## Code source 
. https://cmake.org/runningcmake/
. https://cmake.org/cmake/help/latest/guide/tutorial/index.html

## Description
For running project, need to go build directory,if there is not PLEASE make dir and go there. Write down on terminal : `cmake .. .`  and after that `cmake --build .`  commands generate build files, after all write name of executable file name `./vector.out` on terminal for running program.

## Usage:
From build dir, write on terminal
	1.`cmake .. .`
	2.`cmake --build .`
	3.`./vector.out`

## Contents
Thanks for reading :)
