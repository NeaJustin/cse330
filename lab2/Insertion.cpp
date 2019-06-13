/**************************************************************************
*Justin Pulido
*Insertion.cpp
*The program wants to generate numbers based on the input from the user. 
 it will store the correct amount of spaces for the random numbers to be 
 entered into the vector and be produced outwards. 
*The program solves this problem by using an insertion function that 
 will run through the size of the vector and be able to set the specific 
 index to the random value of the generated number. It will then transfer 
 it back to the vector and be able to print out the correct values. 
*The Big O notation is 0(n^2)
**************************************************************************/

#include <iostream>
#include <algorithm>
#include <vector>
#include <random>

using namespace std;

//The void insertion will grab the size of the vector
//from the main program and assign it to n. After it will
//assing each index to a temporary value of elem, and 
//each index will be put checked to see which index value 
//is larger or smaller depending on the random number 
//generated. 
void insertion_sort(vector <int> &v)
{
	int i = 0;
	int j = 0;
	int n = v.size();
	int elem;

    for (i=1; i<=n;i++)
    {
        elem=v[i];
        j=i-1;
        
        while((elem<v[j])&&(j>=0))
        {
            v[j+1]=v[j];
            j=j-1;
        }

        v[j+1]=elem;
    }
    /*
	for (i = 1; i < n; i++) {
		for (elem = v[i], j = i-1; j >=0 && elem < v[j]; j--) {
			v[j+i] = v[j];
		}
		v[j+1] = elem;
	}
    */
}

int main()
{
	int i = 0;
	int c = 0;
	cout << "Please enter a number: ";
	cin >> c;

	vector <int> v(c);
	for (i = 0; i < v.size(); i++) {
		v[i] = rand()%1000000;
	}
	
	insertion_sort(v);
	for (i = 0; i <= v.size(); i++) {
		cout << v[i] << endl;
	}
	cout << endl;

	return 0;
}
