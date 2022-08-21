#include "BinarySearchTree.hpp"
#include <iostream>

BinarySearchTree::BinarySearchTree(){
    this->root = nullptr;
}

bool BinarySearchTree::insert(int data) {
    Node* newNode = new Node(data);
    Node* ptr = this->root;

    if (this->root == nullptr) {
        this->root = newNode;
        return true;
    }

    while (true) {
        if (ptr->data == data) {
            return false;
        }


        if (newNode->data < ptr->data) {
            if (ptr->left == nullptr) {
                ptr->left = newNode;
                return true;
            } else {
                ptr = ptr->left;
            }
        } else {
            if (ptr->right == nullptr) {
                ptr->right = newNode;
                return true;
            } else {
                ptr = ptr->right;
            }
        }
    }
}

bool BinarySearchTree::del(int data) {
    //case then the tree is empty
    if (!this->root) {
        return false;
    }

    // declaring needed data
    Node* ptr = this->root;
    Node* parent = nullptr;
    std::string side;

    // direct the pointer to needed data node, and define its parent,
    // or if there is no such data containing node, return false
    while (true) {
        if (ptr->data == data) {
            break;
        } else if (data < ptr->data) {
            parent = ptr;
            ptr = ptr->left;
            if (ptr == nullptr) return false;
        } else {
            parent = ptr;
            ptr = ptr->right;
            if (ptr == nullptr) return false;
        }
    }

    //case 1: the node is leaf, that is it has no children
    if (!ptr->left && !ptr->right) {
        if (parent->left == ptr) {
            parent->left = nullptr;
            
        } else {
            parent->right = nullptr;
        }
        delete ptr;
        return true;
    }

    //case 2: the node has only child
    if (ptr->left == nullptr && ptr->right != nullptr 
        || ptr->left != nullptr && ptr->right == nullptr) {
        if (parent->left == ptr) {
            if (ptr->left != nullptr) {
                parent->left = ptr->left;
            } else {
                parent->left = ptr->right;
            }
            parent->left = ptr->left;
            delete ptr;
            return true;
        } else {
            if (ptr->left != nullptr) {
                parent->right = ptr->left;
            } else {
                parent->right = ptr->right;
            }
        }
        delete ptr;
        return true;
    }

    // case 3: the node has 2 children

    if (data > this->root->data) {
        side = "right";
    } else {
        side = "left";
    } 

    if (side == "right") {
        Node* maxForRightSide = ptr->left;
        Node* maxesParent = ptr;
        
        // handle that case when the deleting element's left is a leaf 
        if (maxForRightSide->right == nullptr) {
            ptr->data = maxForRightSide->data;
            ptr->left = nullptr;
            delete maxForRightSide;
            return true;
        }

        // find max for left side relative to deleting node
        // and define its parent
        while (maxForRightSide->right != nullptr) {
            maxesParent = maxForRightSide;
            maxForRightSide = maxForRightSide->right;
        }

        ptr->data = maxForRightSide->data;
        maxesParent->right = nullptr;
        delete maxForRightSide;
        return true;
    } else {
        Node* minForLeftSide = ptr->right;
        Node* minsParent = ptr;

        //handle that case when the deleting element's right is a leaf
        if (minForLeftSide->left == nullptr) {
            ptr->data = minForLeftSide->data;
            ptr->right = nullptr;
            delete minForLeftSide;
            return true;
        }
        
        // find min for right side relative to deleting node
        // and define its parent
        while (minForLeftSide->left != nullptr) {
            minsParent = minForLeftSide;
            minForLeftSide = minForLeftSide->left;
        }

        ptr->data = minForLeftSide->data;
        minsParent->left = nullptr;
        delete minForLeftSide;
        return true;
    }


    return false;
}

void BinarySearchTree::printPreparation(Node* ptr) {
    if (!ptr) {
        std::cout << " - ";
        return;
    }

    std::cout << ptr->data << " ";

    printPreparation(ptr->left);
    printPreparation(ptr->right);
    std::cout << std::endl;
}

void BinarySearchTree::print() {
    printPreparation(this->root);
}