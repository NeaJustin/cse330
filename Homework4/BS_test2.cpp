//BS_test2.cpp

#include <iostream>
#include "BinarySearch.h"

using namespace std;

int main()
{
	BinarySearch<int> tree;

	tree.insert(20);
	tree.insert(10);
	tree.insert(32);
/*
	tree.insert(85);
	tree.insert(23);
	tree.insert(1);
	tree.insert(5);
	tree.insert(12);
	tree.insert(16);
	tree.insert(22);
	tree.insert(90);
	tree.insert(87);
*/
	cout << "the number of nodes: " << tree.node() << endl;
	cout << "the number of leaves: " << tree.leaf() << endl;
	cout << "the number of full nodes: " << tree.count() << endl;
	cout << "Is the tree a BST?: 0 for no, 1 for yes: " << tree.Btree() << endl;

	return 0;
}
