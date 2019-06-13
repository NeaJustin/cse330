/**************************************************************************
*Justin Pulido
*Vector_test2.cpp
*Feb 6, 2018
*The main program tests the capacity, size, iterators, push_back, pop_back,
 begin, and end functions within the template files. 
*Big O(n) is the size of the problem
*100% Complete
**************************************************************************/
#include <iostream>
#include <string>
#include <cassert>

#include "Vector.h"
#include "/home/csusb.edu/005178247/cse330/lab3/String.h"

using namespace std;

int main()
{
    Vector<int> v;
    
    v.reserve(2);
    assert(v.capacity() == 2);

    Vector<string> v1(2);
    assert(v1.capacity() == 2);
    assert(v1.size() == 2);
    assert(v1[0] == "");
    assert(v1[1] == "");

    v1[0] = "hi";
    assert(v1[0] == "hi");

    Vector<int> v2(2, 7);
    assert(v2[1] == 7);

    Vector<int> v10(v2);
    assert(v10[1] == 7);

    Vector<string> v3(2, "hello");
    assert(v3.size() == 2);
    assert(v3.capacity() == 2);
    assert(v3[0] == "hello");
    assert(v3[1] == "hello");

    v3.resize(1);
    assert(v3.size() == 1);
    assert(v3[0] == "hello");

    Vector<string> v4 = v3;
    assert(v4.size() == 1);
    assert(v4[0] == v3[0]);
    v3[0] = "test";
    assert(v4[0] != v3[0]); //fails when assingment results in shallow copy
    assert(v4[0] == "hello");
    
    v3.pop_back();
    assert(v3.size() == 0);
    
    Vector<int> v5(7, 9);
    Vector<int>::iterator it = v5.begin();
    while(it !=  v5.end()) {
        assert(*it == 9);
        ++it;
    }

    Vector<int> v6;
    v6.push_back(100);
    assert(v6.size() == 1);
    assert(v6[0] == 100);
    v6.push_back(101);
    assert(v6.size() == 2);
    assert(v6[0] == 100);
    v6.push_back(101);

    cout << "SUCCESS" << endl;
    

    return 0;
}

