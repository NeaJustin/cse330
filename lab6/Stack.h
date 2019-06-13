#ifndef STACK_H
#define STACK_H

//Justin Pulido
//Stack.h -- a stack implemented as an adapter (of vector or list or ...)
//February 21, 2018
//100% Completed

#include "../lab5/List.h"

using namespace std;

//use the folloing line for STL containers
//template <class T, template <class S, class = allocator<S> > class Container = list>
template <class T, template <class S> class Container = List>
class Stack
{
private:
	Container<T> container;
public:
	//dont need Big-6, Container already includes them
	bool empty() const { return container.empty(); }
	unsigned int size() const { return container.size(); }
	void push(const T & x) { container.push_back(x); }
	void push(T && x) { container.push_back(move(x)); }
	void pop() { container.pop_back(); }
	T & top() { return container.back(); }
};

#endif

