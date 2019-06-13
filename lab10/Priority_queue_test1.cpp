//Justin Pulido
//March 19th, 2018
//Priority_queue_test1.cpp
//The program is using the priority_queue.h to catch any errors within the template file
//it uses the push function as well as the top and pop functions within the .h file. 
//The program pushes numbers onto a queue and then orders them from increasing to decreasing
//order. and it will pop off each one after it is printed. 
//100% Complete
//O(n)

#include <iostream>

#include "priority_queue.h"

using namespace std;

int main()
{
    Priority_queue<int> p, q, pq;

    int x;
    while (cin >> x) {
        p.push(x);
	}

    pq = q = p;

    while (!pq.empty()) {
        cout << pq.top() << " ";
        pq.pop();
    }
    cout << endl;

	return 0;
}

