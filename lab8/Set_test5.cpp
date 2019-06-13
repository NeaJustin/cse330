/*****************************************************************************************
* Justin Pulido
* Set_test5.cpp
* Test the implementation of the Set.h file and if there is an error
* it will catch the problem. 
* tests the begin and end functions of the set and is then testing the erase function 
  using iterators in the program. If we find a number that we enter, it will delete it 
  from the tree and make the necessary adjustments to change it. We will continously do it 
  until the user pressed CTRL + D.
* Big O(n) where n is the size of the problem
* 100% COMPLTE
*****************************************************************************************/

#include <iostream>

#include "Set.h"

using namespace std;

int main()
{
    Set<int> tree;
    Set<int>::iterator i;
    int n;

    tree.insert(100);
    tree.insert(50);
    tree.insert(110);
    tree.insert(40);
    tree.insert(75);
    tree.insert(30);
    tree.insert(60);
    tree.insert(80);
    tree.insert(55);
    tree.insert(90);
    tree.insert(59);
    tree.insert(57);
    tree.insert(56);
    tree.insert(58);

    tree.printTree();
    cout << "Iterate Over and Print Elements\n";
    for (i = tree.begin(); i != tree.end(); i++)
        cout << *i << " ";
    cout << endl;

    //Set<int> copy(tree); // save a copy
    cin >> n;
    while (n >= 0) {
        i = tree.find(n);
        tree.erase(i);
        //tree.erase(n); // test the other erase()

        tree.printTree();
        cout << "Iterate Over and Print Elements\n";
        for (i = tree.begin(); i != tree.end(); i++)
            cout << *i << " ";
        cout << endl;

        //tree = copy; // restore original tree
        cin >> n;
    }
	return 0;
}

