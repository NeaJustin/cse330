/********************************************************
 - Justin Pulido
 - Sum.cpp
 - January 9th, 2018
********************************************************/

#include <iostream>

using namespace std;

int main()
{
    int i, n = 10, total = 0;
    
    for (i = 1; i <= n; i++) { 
	    total += i; // line 11
    }

    cout << "1 + 2 + ... + " << n << " = " << total << endl; // line 13

    return 0;
}

