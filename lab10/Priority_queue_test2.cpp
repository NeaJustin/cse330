//Justin Pulido
//March 19th, 2018
//Priority_queue_test1.cpp
//The program is using the priority_queue.h to catch any errors within the template file
//it uses the push function as well as the top and pop functions within the .h file. 
//The program pushes numbers onto a queue and then it pops them off in order. Having
//assert lines to make sure it is doing what it needs to do properly. It will then create
//a second queue to test it further. If everything is pushed onto the queue and popped off
//correctly, it passes all the tests. 
//100% Complete
//O(n)

#include <iostream>
#include <cassert>

#include "priority_queue.h"

using namespace std;

int main()
{
    Priority_queue<int> pq;

    assert(pq.size() == 0);
    assert(pq.empty());

    pq.push(10);
    assert(pq.top() == 10);
    
    pq.push(20);
    assert(pq.top() == 20);
    
    pq.push(30);
    assert(pq.top() == 30);
    
    pq.push(40);
    assert(pq.top() == 40);
    
    pq.push(50);
    assert(pq.top() == 50);
    
    pq.push(5);
    assert(pq.top() == 50);
    
    pq.pop();
    assert(pq.top() == 40);
    
    pq.pop();
    assert(pq.top() == 30);
        
    pq.pop();
    assert(pq.top() == 20);

    pq.pop();
    assert(pq.top() == 10);
    
    pq.pop();
    assert(pq.top() == 5);
    
    pq.pop();
    assert(pq.size() == 0);

    Priority_queue<int> pq2;
    pq2.push(30);
    pq2.push(11);
    pq2.push(7);
    pq2.pop();
    assert(pq2.top() == 11);
    pq2.pop();
    assert(pq2.top() == 7);
    pq2.pop();
    assert(pq2.empty());

    cout << "All tests passed." << endl << endl;

    return 0;
}

