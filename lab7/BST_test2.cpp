/******************************************************************************
 * Justin Pulido
 * BST_test2.cpp
 * The program also tests the BinarySearchTree.h as well as being able to 
 * implement a postorder and preorder function. 
 * It is done for posorder by going to the left, then right and then to the
 * node. Pre order is done by going to the node, then left and then right. 
 * Big O(n) is the size of the problem.
 * 100% COMPLETE
*****************************************************************************/

#include <iostream>

#include "BinarySearchTree.h"

using namespace std;

int main()
{
    BinarySearchTree<int> complete_tree;

    complete_tree.insert(20);
    complete_tree.insert(10);
    complete_tree.insert(30);
    complete_tree.insert(35);
    complete_tree.insert(25);
    complete_tree.insert(5);
    complete_tree.insert(15);
    complete_tree.printTree();

    cout << "Inorder Traversal" << endl;
    complete_tree.inorder();
    cout << endl;

    cout << "Postorder Traversal" << endl;
    complete_tree.postorder();
    cout << endl;

    cout << "Preorder Traversal" << endl;
    complete_tree.preorder();
    cout << endl;
    
    return 0;
}

