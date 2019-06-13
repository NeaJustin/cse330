/**************************************************************************
*Justin Pulido
*Bubble.cpp
*The program is reading the size of the vector and generating random 
 numbers and being able to swap specific numbers if one is greater than
 the other. 
*The program solves this problem by using the bubble sort function, 
 checking to see if the size of the vector is greater than 0 and it will
 run until it is less than 0. After it will check to see if j is greater 
 than i and if it is, it will swap them but add 1 to i. and it will 
 place it into the vector to hold until it is needed to be outputed. 
*The big 0 notation is 0(n^2)
**************************************************************************/

#include <iostream>
#include <algorithm>
#include <vector>
#include <random>

using namespace std;

//it will check the size of the vector and subtract it by 1
//and it will then check to see if j is less than i and if it is
//it will then check to see if j is greater than j+1 and if it is
//then it will swap j for j+1 and return it to the vector.
void bubble_sort(vector <int> &v)
{
	int i = 0;
	int j = 0;
	int n = v.size();
	
	for (i = n-1; i > 0; i--) {
		for (j = 0; j < i; j++) {
			if (v[j] > v[j+1]) {
				swap(v[j], v[j+1]);
			}
		}
	}
}

int main()
{
	int c = 0;
	int i = 0;

	cout << "Please enter a number: ";
	cin >> c;
	
	vector <int> v(c);
	for (i = 0; i < v.size(); i++) {
		v[i] = rand()%1000000;
	}

	bubble_sort(v);
	for (i = 0; i <= v.size(); i++) {
		cout << v[i] << endl;
	}
	cout << endl;

	return 0;
}
