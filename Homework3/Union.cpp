/******************************************************************************
 *Justin Pulido
 *Union.cpp
 *March 5th, 2018
 *The problem is getting two lists and finding the intersection and the union
  of them both.
 *The program solves this by using the two functions my_intersect and my_union.
  My_intersect compares the values and if they are the same it is returned to a 
  temp and outputed to the user. For the union it will merge the two lists and 
  check to see if there are any duplicates within the program itself. 
 *O(n^2) and O(n)
 *100% Complete
******************************************************************************/

#include <iostream>
#include <list>

using namespace std;

//O(n^2)
template <class T>
list<T> my_intersect(const list<T> & a, const list<T> & b) 
{
	list<T> list_a = a;
	list<T> list_b = b;
	list<T> temp;

	//created two const iterator for a and b and checked to see 
	//if i and j are equal then push it onto the temp created. 
	//else do nothing. 
	for(list<int>::const_iterator i = a.begin(); i != a.end(); i++) {
		for(list<int>::const_iterator j = b.begin(); j != b.end(); j++) {
			if(*i == *j) {
				temp.push_back(*i);
			}
		}
	}
	return temp;
}

//O(n)-linear time
template <class T>
list<T> my_union(const list<T> & a, const list<T> & b)
{
    list<T> list_a = a;
	list<T> list_b = b;
	//having the list_a have the second list pushed onto it. 
	for(list<int>::const_iterator j = b.begin(); j != b.end(); j++) {
		list_a.push_back(*j);
	}
	//then using the stl library sort to sort it.
	list_a.sort();
	//did the same as the for loop above, was not sure which one you prefer.  
	//list_a.merge(list_b); //using basic function of stl library for merge
	list_a.unique(); //getting rid of duplicates using the stl library
	return list_a;
}

int main()
{
    list<int> first_list;
    list<int> second_list;
    list<int> final_list;
	int i = 0;
    
	for(i = 0; i < 30; i++) {
		first_list.push_back(i);
	}

	for(i = 0; i < 45; i += 2) {
		second_list.push_back(i);
	}
	
	//showing first list without any functions to show it is working
	cout << "First_list: ";
	for(list<int>::iterator i = first_list.begin(); i != first_list.end(); i++) {
		cout << endl;	
		cout << *i << " ";
	}
	
	cout << endl << endl; // using it to create a space between the output statements 

	//same as the first list
	cout << "Second List: ";
	for(list<int>::iterator i = second_list.begin(); i != second_list.end(); i++) {
		cout << endl;
		cout << *i << " ";	
	}
	
	cout << endl<< endl;

	final_list = my_intersect(first_list, second_list);
	cout << "Intersection List: ";
	for(list<int>::iterator i = final_list.begin(); i != final_list.end(); i++) {
		cout << endl;	
		cout << *i << " ";
	}
	
	cout << endl << endl;

	final_list = my_union(first_list, second_list);
	cout << "The union list is: ";
	for(list<int>::iterator i = final_list.begin(); i != final_list.end(); i++) {
		cout << endl;	
		cout << *i << " ";
	}

	cout << endl << endl;
	
    return 0;
}


