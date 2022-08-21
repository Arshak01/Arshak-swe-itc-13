#include <iostream>
#include "./node.hpp"

Node::Node(){
	this->data;
	this->left = NULL;
	this->right = NULL;
}

Node::Node(int data){
	this->data = data;
	this->left = NULL;
	this->right = NULL;
}
