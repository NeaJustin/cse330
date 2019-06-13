#ifndef LIST_H
#define LIST_H

#include <cassert>
#include <iostream>

/**********************************************************************************
*Justin Pulido
*Union.h
*February 7th, 2018
*holds the operator functions to be used in a test file to make sure each member 
 function runs properly.
*it solves the problem by being able to have all the impletations of the functions
 and it will be called in the main program. 
*100% completed
*Big O(n) is the size of the problem
**********************************************************************************/

using namespace std;

template <typename Object>
class Union
{
private:
	struct Node;
	
	int theSize;
	Node *head;
	Node *tail;

	void init();
public:
	class const_iterator;
	class iterator;
	//typedef * 

	Union(){ /*cout << "Default Constructor\n";*/ init();} //
	Union(const Union & rhs); //
	Union(Union && rhs); //
	Union & operator=(const Union & rhs); //
	Union & operator=(Union && rhs); //
	~Union();

	iterator begin() { return head->next;} //
	const_iterator begin() const { return head->next; } //
	iterator end() { return tail; } //
	const_iterator end() const { return tail; } //
	
	int size() const { return theSize; } //
	bool empty() const { return theSize == 0; } //

	void clear(); //

	Object & front() { return *begin(); } //
	const Object & front() const { return *begin(); } //
	Object & back() { return *--end(); } //
	const Object & back() const { return *--end(); } //

	void push_front(const Object & x) { insert(begin(), x); } //
	void push_front(Object && x) {insert(begin(), move(x)); } //
	void push_back(const Object & x) { insert(end(), x); } //
	void push_back(Object && x) { insert(end(), move(x)); } //

	void pop_front() { erase(begin()); } //
	void pop_back() { erase(--end()); } //
	
	iterator insert(iterator, const Object &); //
	iterator insert(iterator, Object &&); //

	iterator erase(iterator); //
	iterator erase(iterator, iterator); //

    void my_intersect(const Union<Object> & a, const Union<Object> & b);
    void my_union(const Union<Object> & a, const Union<Object> & b);
};

template <typename Object>
void Union<Object>::my_intersect(const Union<Object> & a, const Union<Object> & b)
{
    list<T> list_a = a;
	list<T> list_b = b;
	my_list(list_a);
	my_list(list_b);
	return my_intersect(list_a, list_b);
}

template <typename Object>
void Union<Object>::my_union(const Union<Object> & a, const Union<Object> & b)
{
	list<T> list_a = a;
	list<T> list_b = b;
	my_list(list_a);
	my_list(list_b);
	return my_union(list_a, list_b);
}

//Big O(n) const
template <typename Object>
void Union<Object>::init()
{
	theSize = 0;
	head = new Node();
	tail = new Node();
	head->next = tail;
	tail->prev = head;
}

//Big O(n) size of problem
template <typename Object>
Union<Object>::Union(const Union & rhs) 
{
	init();
	for(auto & x: rhs) {
		push_back(x);
	}
}

//Big O(n) const
template <typename Object>
Union<Object> & Union<Object>::operator=(Union && rhs)
{
	swap(theSize, rhs.theSize);
	swap(head, rhs.head);
	swap(tail, rhs.tail);

	return *this;
}

//Big O(n) const
template <typename Object> 
typename Union<Object>::iterator Union<Object>::insert(iterator itr, const Object & x)
{
	Node *p = itr.current;
	theSize++;
	return p->prev = p->prev->next = new Node{x, p->prev, p};
}

//Big O(n) const
template <typename Object>
Union<Object> & Union<Object>::operator=(const Union & rhs)
{
	Union copy = rhs;
	swap(*this, copy);
	return *this;
}

//Big O(n) const
template <typename Object>
Union<Object>::~Union()
{
	clear();
	delete head;
	delete tail;
	
}

//Big O(n) size of problem
template <typename Object>
void Union<Object>::clear()
{
	while(!empty()) {
		pop_front();
	}
}

//Big O(n) const
template <typename Object>
Union<Object>::Union(Union && rhs)
{
	rhs.theSize = 0;
	rhs.head = nullptr;
	rhs.tail = nullptr;
}

//Big O(n) const
template <typename Object>
typename Union<Object>::iterator Union<Object>::erase(iterator itr) 
{
	Node *p = itr.current;
	iterator retVal{p->next};
	p->prev->next = p->next;
	p->next->prev = p->prev;
	delete p;
	theSize--;
	
	return retVal;
}

//Big O(n) size of problem
template <typename Object>
typename Union<Object>::iterator Union<Object>::erase(iterator from, iterator to)
{
	for(iterator itr = from; itr !=0; ) {
		itr = erase(itr);
	}
	return to;
}

//Big O(n) const
template <typename Object>
typename Union<Object>::iterator Union<Object>::insert(iterator itr, Object && x)
{
	Node *p = itr.current;
	theSize++;
	return {p->prev = p->prev->next = new Node{move(x), p->prev, p}};
}

//******************************************** Node
template <typename Object>
struct Union<Object>::Node
{
	Object data;
	Node *prev;
	Node *next;

	Node(const Object & d = Object{}, Node * p = nullptr, Node * n = nullptr): 
		data{d}, prev{p}, next{n} { }
	Node(Object && d, Node * p = nullptr, Node * n = nullptr): 
		data{move(d)}, prev{p}, next{n} { }
};

//***************************************** const_iterator
template <typename Object>
class Union<Object>::const_iterator
{
public:
	const_iterator(): current{nullptr} { } //
	const Object & operator*() const { return retrieve(); } //
	
	const_iterator & operator++(); // 
	const_iterator operator++(int); //
	
	const_iterator & operator--(); // not in textbook
	const_iterator operator--(int); //not in textbook

	bool operator==(const const_iterator & rhs) const {return current == rhs.current;}
	bool operator!=(const const_iterator & rhs) const {return current != rhs.current;}

protected:
	Node *current;
	
	Object & retrieve() const { return current->data; }
	const_iterator(Node *p): current{p} { }
	
	friend class Union<Object>;
};

//Big O(n) const
template <typename Object>
typename Union<Object>::const_iterator & Union<Object>::const_iterator::operator++()
{
	current = current->next;
	return *this;
}

//Big O(n) const
template <typename Object>
typename Union<Object>::const_iterator Union<Object>::const_iterator::operator++(int)
{
	const_iterator old = *this;
	++(*this);
	return old;
}

//Big O(n) const
template <typename Object>
typename Union<Object>::const_iterator & Union<Object>::const_iterator::operator--()
{
	current = current->prev;
	return *this;
}

//Big O(n) const
template <typename Object>
typename Union<Object>::const_iterator Union<Object>::const_iterator::operator--(int)
{
	const_iterator N = *this;
	--(*this);
	return N;
}
//ITERATOR
template <typename Object>
class Union<Object>::iterator: public Union<Object>::const_iterator
{
public:
	iterator() { }
	Object & operator*() { return Union<Object>::const_iterator::retrieve(); } //mutator
	const Object & operator*() const { return Union<Object>::const_iterator::operator*(); } //accessor
	
	iterator & operator++(); //
	iterator operator++(int); // 

	iterator & operator--(); //
	iterator operator --(int); //
	
protected:
	iterator(Node *p): Union<Object>::const_iterator{p} { }
	friend class Union<Object>;
};

//Big O(n) const
template<typename Object>
typename Union<Object>::iterator & Union<Object>::iterator::operator++()
{
	this->current = this->current->next; //must use "this" pointer for protected members
	return *this;
}

//Big O(n) const
template <typename Object>
typename Union<Object>::iterator Union<Object>::iterator::operator++(int)
{
	iterator old = *this;
	++(*this);
	return old;
}

//Big O(n) const
template <typename Object>
typename Union<Object>::iterator & Union<Object>::iterator::operator--()
{
	this->current = this->current->prev;
	return *this;
}

//Big O(n) const
template <typename Object>
typename Union<Object>::iterator Union<Object>::iterator::operator--(int)
{
	iterator N = *this;
	--(*this);
	return N;
}

#endif

