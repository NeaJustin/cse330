#ifndef PRIORITY_QUEUE_H
#define PRIORITY_QUEUE_H

//Justin Pulido
//March 19th, 2018
//Priority_queue.h
//contains the functions that are tested within the main program to check for any errors
//Contains the pop, push, and top functions for the main program to be executed
//100% Complete

#include <vector>

using namespace std;

template <class T>
class Priority_queue
{
private:
    vector<T> c;
public:
    bool empty() { return c.empty(); }
    unsigned int size() { return c.size(); }
    void push(const T & x);
    void push(T && x);
    void pop();
    T & top() { return c.front(); }
    const T & top() const { return c.front(); }
};

//start from the first part of the queue and pop off the first one and 
//go onto the next one. we will set the leftchild to 1 and rightchild
//to 2. Then check which one is bigger and swap them. 
//O(nlogn)
template <class T>
void Priority_queue<T>::pop()
{
    if(empty()) {
        return;
    }

    c[0] = c.back();
    c.pop_back();
    unsigned int n = 0;
    unsigned int LeftChild = 1;
    unsigned int RightChild = 2;
    
    while(LeftChild < c.size()) {   
        unsigned int biggest_child = LeftChild;
        if(RightChild < c.size() && c[LeftChild] < c[RightChild]) {
            biggest_child = RightChild;
        }
        if(c[n] < c[biggest_child]) {
            swap(c[n], c[biggest_child]);
            n = biggest_child;
            LeftChild = 2*n+1;
            RightChild = LeftChild + 1;
        } else {
            break;
        }
    }
}

//pushing it onto the queue and then checking
//to see if it is bigger or smaller.
//O(nlogn)
template <class T>
void Priority_queue<T>::push(const T & x)
{
    c.push_back(x);
    unsigned int n = c.size()-1;
    unsigned int parent = (n-1)/2;
    
    while(n > 0 && c[parent] < c[n]) {
        swap(c[n], c[parent]);
        n = parent;
        parent = (n-1)/2;
    }
}

//same as other push, but moving instead of 
//stealing all of the data. 
//O(nlogn)
template <class T>
void Priority_queue<T>::push(T && x)
{
    c.push_back(move(x));
    unsigned int n = c.size()-1;
    unsigned int parent = (n-1)/2;

    while(n > 0 && c[parent] < c[n]) {
        swap(c[n], c[parent]);
        n = parent;
        parent = (n-1)/2;
    }
}

#endif
