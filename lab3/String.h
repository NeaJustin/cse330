#ifndef STRING_H
#define STRING_H

/**********************************************************************
*Justin Pulido
*String.h
*January 29th, 2018
*String.h class holds all the operations to be called during the main
 program.
**********************************************************************/

#include <iostream>

using namespace std;

class String
{
private:
	int size;
	char * buffer;
public:
	String(); //Default Constructor
	String(const String &); //Copy constructor
	String(String &&); //move constructor
	String(const char *);
	String(char);
	~String(); //destructor

	int length(); 
	char & operator[](const int);
	String & operator=(const String &); //copy assignment 
	String &operator=(String &&); //Move assignment
	String &operator+=(const String &);

	friend bool operator==(const String &, const String &);
	friend bool operator<=(const String &, const String &);
	friend bool operator<(const String &, const String &);

	friend ostream & operator<<(ostream &, const String &);
};

#endif
