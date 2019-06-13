/**************************************************************************************
* Justin Pulido
* BST_test12.cpp
* Test the implementation of the BinarySearchTree.h file and if there is an error
* it will catch the problem. 
* Big O(n) where n is the size of the problem
* 100% COMPLTE
**************************************************************************************/

#include <iostream>

#include "BinarySearchTree.h"

using namespace std;

int main()
{
    BinarySearchTree<int> tree;

    tree.insert(6);
    tree.insert(8);
    tree.insert(2);
    tree.insert(1);
    tree.insert(5);
    tree.insert(3);
    tree.insert(4);
    tree.printTree();

    cout << "Min = " << tree.findMin() << endl;
    cout << "Max = " << tree.findMax() << endl;

    cout << "Remove 2\n";
    tree.remove(2);
    tree.printTree();

    cout << "Contains 2? " << tree.contains(2) << endl;
    cout << "Contains 4? " << tree.contains(4) << endl;

    cout << "Copy Constructor\n";
    tree.remove(6);
    BinarySearchTree<int> copy(tree);
    cout << "Remove 6\n";
    //tree.remove(6);
    copy.printTree();

    cout << "Inorder Traversal\n";
    copy.inorder();
    cout << endl;

    cout << "Clear Tree\n";
    copy.makeEmpty();
    copy.printTree();
	
	return 0;
}
