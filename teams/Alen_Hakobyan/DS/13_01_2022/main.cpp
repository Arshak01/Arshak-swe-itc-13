#include <iostream>
#include "binary_tree.h"

int main() {
	BinaryTree bt;
	bt.insert(20);
	bt.insert(30);
	bt.insert(40);
	bt.insert(80);
	bt.insert(10);
	bt.insert(90);
	bt.insert(70);
	bt.print();
	std::cout << "After delete (90).";
	bt.remove(90);
	bt.print();
	std::cout << "After delete (30).";
	bt.remove(30);
	bt.print();

	return 0;
}
