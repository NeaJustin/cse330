/*********************************************************************
*Justin Pulido
*Select.cpp
*January 17th, 2018
*The program has the problem that we want to generate random numbers
 and put them in the correct order. 
*The solution is done through the function of select, where it will
 take the size of the vector, create random numbers, and compare them
 with the indecies of the vector and see which one is bigger or smaller
 and replace it with the correct one at that instance. 
*The time Complexity is O(n^2)
*********************************************************************/

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

//checks the size of the vector and goes through each index value
//checking to see which value is higher than the other. If i is 
//greater than j, it will swap i with j. 
void select(vector<int> & V) 
{
    int i = 0;
    int j = 0;
    int n = V.size();
	for (i = 0; i < n-1; i++) {
		for (j = i+1; j < n; j++) {
			if (V[i] < V[j]) {
				swap(V[i], V[j]);
			}
		}
	}
}

int main()
{
	int n = 0;
	int i = 0;

    cout << "Please enter a number: ";
	cin >> n;
	vector <int> v(n);
    for (i = 0; i < v.size(); i++) {
		v[i] = rand()%1000000;
	}

	select(v);
	for (i = 0; i <= v.size(); i++) {
		cout << v[i] << endl;
	}

	return 0;
}

