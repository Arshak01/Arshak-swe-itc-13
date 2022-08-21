#include <iostream>
#include "BinSearchTree.hpp"

int main() {
	BinSearchTree bst;
	bst.insert(12);
	bst.insert(34);
	bst.insert(56);
	bst.insert(78);
	bst.insert(90);
	bst.print();
	std::cout << "Deliting value {34}.";
	bst.remove(34);
	bst.print();
	std::cout << "Deliting value (12).";
	bst.remove(12);
	bst.print();

	return 0;
	return 0;
}
