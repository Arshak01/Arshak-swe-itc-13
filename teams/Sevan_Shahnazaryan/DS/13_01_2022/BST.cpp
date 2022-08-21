#include <iostream>
#include "BST.hpp"

BST::BST() {
	this->root = NULL;
	this->level = 0;
}

Node* BST::getRoot() const {
	return this->root;
}

void BST::setRoot(Node *root) {
	this->root = root;
}

int BST::getLevel() const {
	return this->level;
}

void BST::setLevel(int level) {
	this->level = level;
}

//To avoid code repeating
Node* BST::search(int data, Node *ptr, int lvl) {
	if(this->root == NULL) {
		return NULL;
	} else if(ptr->getNum() < data) {
		this->level = (lvl + 1 > this->level) ? lvl + 1 : this->level;
		return(ptr->getRight() == NULL) ? ptr : search(data, ptr->getRight(), ++lvl);
	} else if(ptr->getNum() == data) {
		return ptr;
	} else {
		this->level = (lvl + 1 > this->level) ? lvl + 1 : this->level;
		return(ptr->getLeft() == NULL) ? ptr : search(data, ptr->getLeft(), ++lvl);
	}
}

void BST::insert(int data) {
	Node *tmp = search(data, this->root);
	if(tmp == NULL) {
		this->root = new Node(data, NULL, NULL);
		this->level++;
	} else if(tmp->getNum() == data) {
		std::cout << "CThe data(" << data
		<< ")already exists in binary tree" << std::endl;
	} else if(tmp->getNum() < data) {
		tmp->setRight(new Node(data, NULL, NULL));
	} else {
		tmp->setLeft(new Node(data, NULL, NULL));
	}
}

/*
   Failed attempt for remove
   void BST::remove(int data, Node *ptr) {
	if(ptr == NULL) {
		if(this->root == NULL) { //Alternative to remove(int data, Node *ptr = this->ptr)
			std::cout << "Error: The BST is empty. No elements to delete" << std::endl;
			return;
		} else {
			remove(data, this->root);
		}
		return;
	} else if(ptr->getNum() < data) {
		if(ptr->getRight() != NULL) {
			remove(data, ptr->getRight());
		} else {
			std::cout << "No such data (" << data << ')' << std::endl;
		}
	} else if(ptr->getNum() > data) {
		if(ptr->getLeft() != NULL) {
			remove(data, ptr->getLeft())
		} else {
			std::cout << "No such data (" << data << ')' << std::endl;
		}
	} else if(ptr->getNum() == data) {
		if(ptr->getLeft() == NULL && ptr->getRight() == NULL) {
			delete ptr;
		} else if(ptr->getLeft() == NULL && ptr->getRight() != NULL) {
			ptr = ptr->getRight;
		}
	}
}*/

void BST::printCL(Node *ptr, int lvl) {
	if(ptr == NULL) {
		return;
	} else if(lvl == 0) {
		std::cout << ptr->getNum() << ' ';
	} else if(lvl > 0) {
		printCL(ptr->getRight(), lvl - 1);
		printCL(ptr->getLeft(), lvl - 1);
	}
}

void BST::print() {
	for(int i = 0; i <= this->level; ++i) {
		printCL(this->root, i);
	}
	std::cout << std::endl;
}
