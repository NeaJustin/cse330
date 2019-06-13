/****************************************************************************************
*Justin Pulido
*Queue_test1.cpp
*February 21, 2018
*The program is testing the Queue.h file implementations and seeing if they are all 
 functioning properly.
*It solves the problem by using the constructor and deconstructor from Vector.h class 
 and uses it for the Stack.h. We then use those constructors in the main program to
 be able to execute the program successfully.
*100% Complete 
*Big O(n) where it is the size problem. 
****************************************************************************************/

#include <iostream>

#include "../lab4/Vector.h"
#include "Queue.h"

using namespace std;

int main()
{
	Queue<int> s; // uses List as the default container
	s.push(5);
	s.push(6);
	cout << s.front() << endl;
	
	Queue<double, Vector> v; // uses the Vector as the container
	v.push(1.5);
	v.push(2.3);
	v.pop();
	cout << v.front() << endl << endl;

	return 0;
}
