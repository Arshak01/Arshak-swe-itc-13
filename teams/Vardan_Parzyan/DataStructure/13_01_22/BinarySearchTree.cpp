#include <iostream>

class Node {
public:

    int data;
    Node* left;
    Node* right;
};
class BinarySearchTree {
public:
    int data;
    Node* tLeft;
    Node* tRight;
    Node* tRoot;

    BinarySearchTree(){
        int data;
        tRoot = nullptr;
        tLeft = nullptr;
        tRight = nullptr;
    }

    Node* insertOrigin(Node* tmp, int data) {
        if (tmp==nullptr) {
            tmp = new Node;
            tmp->data = data;
            tmp->left = nullptr;
            tmp->right=nullptr;
        }
        else if (data < tmp->data) {
            tmp->left = insertOrigin(tmp->left, data);
        }
        else if (data > tmp->data) {
            tmp->right = insertOrigin(tmp->right, data);
        } else {
            std::cout << "This number is already here " << std::endl;
        }
        
        return tmp;
    }


    void insert(int data) {
        tRoot = insertOrigin(tRoot, data);
    }

    void print(Node* tmp) {
        if(tmp == NULL)
            return;
        print(tmp->left);
        std::cout << "\t";
        std::cout << tmp->data ;
        print(tmp->right);
        
        
    }

    void display() {
        print(tRoot);
        std::cout << std::endl;
    }


    
};

int main(){
    BinarySearchTree tree;
    tree.insert(10);
    tree.insert(15);
    tree.insert(20);
    tree.insert(5);
    tree.insert(6);
    tree.insert(3);
    tree.insert(25);
    tree.insert(30);
    tree.insert(2);
    tree.insert(1);
    tree.display();

    
    
    
    return 0;
}
