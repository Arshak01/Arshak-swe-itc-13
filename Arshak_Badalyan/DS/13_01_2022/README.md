## Project-name
	Binary Search Tree

## Project-description
	Implement  Binary Search Tree which contain these functions.
		◦ Default constructor - Constructs an empty container, with no elements.
		◦ insert(int data) – The function that adds a node to a tree.
		◦ delete(int data) - The function that removes a node from a tree.
		◦ print() -  Use level order tree traversal method to print
		
	I add extra some function`
		bool empty(); - check tree empty or not.
		void isEmpty(); - delete tree element.
		void printOrders(); print all types of orders element. 
		void inOrder(Node* temp); - chenge tree to left->root->right
		void preOrder(Node* temp); - chenge tree to root->left->right
		void postOrder(Node* temp); - chenge tree to left->right->root
		void search(int); search value from tree , but this fun already not finished.
	 
        		
## Description
For running project, need to go build directory,if there is not PLEASE make dir and go there. Write down on terminal : `cmake .. .`  and after that `cmake --build .`  commands generate build files, after all write name of executable file name `./binarySearch.out` on terminal for running program.

## Usage:
From build dir, write on terminal
	1.`cmake .. .`
	2.`cmake --build .`
	3.`./binarySearch.out`

## Code source 
	https://www.geeksforgeeks.org/level-order-tree-traversal/ 


## Contents
Thanks for reading :)
