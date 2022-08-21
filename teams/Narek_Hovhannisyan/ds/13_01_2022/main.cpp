#include <iostream>
#include "BinarySearchTree.hpp"

int main() {
    BinarySearchTree tree;
    std::cout << std::boolalpha << tree.del(11) << std::endl;
    std::cout << std::boolalpha << tree.insert(5) << std::endl;
    std::cout << std::boolalpha << tree.insert(5) << std::endl;

    tree.insert(3);
    tree.insert(11);
    tree.insert(1);
    tree.insert(7);
    tree.insert(20);
    tree.insert(6);
    tree.insert(9);
    tree.insert(17);
    tree.insert(4);
    std::cout << std::endl;

    tree.print();
/*
                5
              /   \
             3     11
            / \    /  \
           1   4  7    20
                 / \   / 
                6   9 17 
*/

    tree.del(11); // delete an element from right side
    tree.del(3);  // delete an element from left side, its right is a leaf
    tree.del(20); // delete an 1 child element
 
    tree.print();

    return 0;
}