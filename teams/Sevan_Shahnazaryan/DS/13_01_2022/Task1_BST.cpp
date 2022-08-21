#include <iostream>
#include "BST.hpp"

int main() {
	BST tree;
	tree.insert(7);
	tree.insert(8);
	tree.insert(9);
	tree.insert(10);
	tree.insert(6);
	tree.insert(5);
	tree.insert(4);
	tree.insert(3);
	tree.insert(2);
	tree.insert(1);
	std::cout << "Height = " << tree.getLevel() << std::endl;
	std::cout << "root = " << tree.getRoot()->getNum() << std::endl;
	tree.print();
	return 0;
}
