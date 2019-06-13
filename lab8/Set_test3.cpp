/**************************************************************************************
* Justin Pulido
* Set_test3.cpp
* Test the implementation of the Set.h file and if there is an error
* Tests the insert function of the tree, with checking size, and the count of it as
  well. also testing the copy function and the print, along with the clear function. 
* Big O(n) where n is the size of the problem
* 100% COMPLTE
**************************************************************************************/

#include <iostream>

#include "Set.h"

using namespace std;

int main()
{
    Set<int> tree;

    cout << "Size = " << tree.size() << endl;
    cout << "Empty? " << tree.empty() << endl;
    
    tree.insert(6);
    tree.insert(8);
    tree.insert(2);
    tree.insert(1);
    tree.insert(5);
    tree.insert(3);
    tree.insert(4);
    tree.insert(5); // duplicate ignored
    tree.printTree();

    cout << "Count 5 = " << tree.count(5) << endl;
    cout << "Size = " << tree.size() << endl;
    cout << "Empty? " << tree.empty() << endl;
    cout << "Erase 2\n";
    tree.erase(2);
    tree.printTree();

    cout << "Size = " << tree.size() << endl;
    cout << "Empty? " << tree.empty() << endl;
    cout << "Count 2 = " << tree.count(2) << endl;
    cout << "Erase 6\n";
    tree.erase(6);
    tree.printTree();

    cout << "Copy Constructor\n";
    Set<int> copy(tree);
    copy.printTree();
    
    cout << "Copy Size = " << copy.size() << endl;
    cout << "Clear Copy\n";
    copy.clear();
    cout << "Size = " << copy.size() << endl;
    cout << "Empty? " << copy.empty() << endl;
    
    return 0;
}

