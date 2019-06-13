/*******************************************************************************
*Justin Pulido
*January 24th, 2018
*String.cpp
*Implementation of constructors and member functions defined in class of 
 String.h
*******************************************************************************/

#include <cassert>
#include "String.h"
#include <cstring>

//default constructor
String::String()
{
	size = 0;
	buffer = nullptr;
}

//copy constructor
String::String(const String & source)
{
	//cout << "String constructor.";
	size = source.size;
	buffer = new char[size];
	assert(buffer != nullptr);

	for (int i = 0; i < size; i++) {
		buffer[i] = source.buffer[i];
	}
}

//move constructor
String::String(String && source): size{source.size}, buffer{source.buffer}
{
	//cout << "String move constructor.";
	source.size = 0;
	source.buffer = nullptr;
}

//constructor from "char string" to String
//find size of p, allocate space, assign p to buffer
String::String(const char * p)
{
	size = 0;
	for (const char *q = p; *q; q++) {
		size++;
	}
	buffer = new char[size];
	assert(buffer != nullptr);

	for (int i = 0; i < size; i++) {
		buffer[i] = p[i];
	}
}

//delete
String::~String()
{
	//cout << "String destructor.";
	delete [] buffer;
}

//copy assignment 
//similar to char string constructor, but here
//create a temp buffer based on source,
//delete existing buffer, then assign temp buffer to buffer
String & String::operator=(String && source)
{
	swap(size, source.size);
	swap(buffer, source.buffer);
	return *this;
}

bool operator==(const String & left, const String & right)
{
	if (left.size != right.size) {
		return false;
	}

	for (int i = 0; i < left.size; i++) {
		if (left.buffer[i] != right.buffer[i]) {
			return false;
		}
	}
	return true;
}

ostream & operator<<(ostream & out, const String & s)
{
	for (int i = 0; i < s.size; i++) {
		cout << s.buffer[i];
	}
	return out;
}

bool operator<=(const String & left, const String & right)
{
	if (left.size >= right.size) {
		return false;
	}
	
	for (int i = 0; i <= left.size; i++) {
		if (left.buffer[i] >= right.buffer[i]) {
			return false;
		}
	}
	return true;
}

bool operator<(const String & left, const String & right)
{
	if (left.size > right.size) {
		return false;
	}
	
	for (int i = 0; i < left.size; i++) {
		if (left.buffer[i] > right.buffer[i]) {
			return false;
		}
	}
	return true;
}

//grabs the string of the first and adds onto 
//whatever is being passed to it. 
String & String::operator+=(const String & k) 
{
	int j = 0;
    int i = 0;
    char * temp;
	int temp_1 = size + k.size;
    temp = new char[temp_1];
    for(i = 0; i < size; i++) {
        temp[i] = buffer[i];
    }
    for(j = 0; j < k.size; j++, i++) {
        temp[i] = k.buffer[j];
    }
    delete [] buffer;
    size = temp_1;
    buffer = temp;
    return *this;
}

int String::length()
{
	return size;
}

char & String::operator[](const int i)
{
	return buffer[i];
}

//setting one string equal to another string
String & String::operator=(const String & c)
{
    delete [] buffer;
    size = c.size;
    buffer = new char[size];
    int i = 0;
    for(i = 0; i < size; i++) {
        buffer[i] = c.buffer[i];
    }
    return *this;
}
