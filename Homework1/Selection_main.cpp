/************************************************************************
 * Justin Pulido
 * Selection_main.cpp
 * January 28th, 2018
 * The program needs to find the highest number within a given file, 
   as well as giving the N size of the file. 
 * 
 * Big O(n^2)
***********************************************************************/

#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>

using namespace std;

//checks the size of the vector and goes through each index value
//checking to see which value is higher than the other. If i is 
//less than j, it will swap i with j. 
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

int main(int argc, char * argv[])
{
	ifstream myfile;
	//string temp = argv[1];

	//cout << temp << endl;

	myfile.open(argv[1]);
	if (!myfile.is_open()) {
			cout << "Sorry could not find this file. " << endl;
			exit(1);
		//	cout << "Please try another file: ";
		//	cin >> temp;
		//	myfile.open(temp.c_str());
	}
	int k;
	cout << "Please enter in a size for a vector: ";
	cin >> k;
	vector <int> v(k);
	int t;

	for(int i = 0; i < v.size(); i++) {
		myfile >> v[i];
	}

	select(v);

    for (int i = 0; i < v.size(); i++)
        cout << v[i] << " ";
    cout << endl;

    myfile >> t;
	while (!myfile.eof()) {
		cout <<"t=" << t << endl;
		int i;
		if(t > v[k-1]) {
			for(i = k - 1; i >= 0; i--) {
				if(v[i] > t) {
					v.insert(v.begin() + i + 1, t);
					v.pop_back();
					break;
				}
			}
            if (i == -1) {
                v.insert(v.begin(), t);
                v.pop_back();
            }
		}

    	for (int i = 0; i < v.size(); i++)
    	    cout << v[i] << " ";
    		cout << endl;
		
		myfile >> t;

	}
	cout << "Kth largest : " << v[k-1] << " " << "k: " << v.size() << endl;
	myfile.close();
    return 0;
}
