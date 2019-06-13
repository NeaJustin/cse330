/***************************************************************************
*Justin Pulido
*BS_test1.cpp
*March 14th, 2018
*the task is asking the user to create a Binary Tree without the search 
 functions within the program. Which results in an unsuccessful tree being
 created. 
*The program creates the tree using an insert function, finds the number 
 of full nodes within the program, finds the number of leaves and the 
 number of numbers within the tree itself. After it determines whether or not
 it is a binary tree based on the given input. 
*O(n) const time
*100% Complete, having trouble with the binary tree output deciding whether 
 it is a tree or not a Binary tree.  
*****************************************************************************/
#include <iostream>
#include "BinarySearch.h"

using namespace std;

int main()
{
	BinarySearch<int> tree;

	tree.insert(7);
	tree.insert(10);
	tree.insert(20);
	tree.insert(89);
	tree.insert(5);
	tree.insert(2);
	tree.insert(8);
	tree.insert(12);
	tree.insert(16);
	tree.insert(22);

	cout << "the number of nodes: " << tree.node() << endl;
	cout << "the number of leaves: " << tree.leaf() << endl;
	cout << "the number of full nodes: " << tree.count() << endl;
	cout << "Is the tree a BST?: 0 for no, 1 for yes: " << tree.Btree() << endl;

	return 0;
}

