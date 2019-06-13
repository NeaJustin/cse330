/*********************************************************************
 * Justin Pulido
 * Permtation2.cpp
 * February 11th, 2018
 * same problem as the first
 * however, to help solve this problem, we are using a used arr to 
   help check if random numbers are duplicated, making the process 
   slower.
 * Big O(n^2) since there is two loops that it must be passed through
 * 100% Complete
********************************************************************/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//creates a new array that is using a bool status
//to see if the number is random and if it is, 
//then it will be put into the array.
int *perm2(int n)
{
    int i = 0;
    int count = 0;
    int *arr = new int[n];//creating a new array
    //creating an array with a bool status
    bool *create = new bool[n];
    
    //ran into trouble with for loop causing random
    //0's when intregrated with the while loop.
    for(i = 0; i < arr[n]; i++) {
        create[i] = false;
    }

    while(count < n) {
        //generating random numbers
        int random = rand()% n + 1;
        //checking to see if nmbers are random
        //by grabbing random array and comparing
        //it to each value
        if(!create[random-1]) {
            arr[count] = random;
            count++;
            create[random-1] = true; //must be set to true here
        }
    }

    delete [] create;
    return arr;
}

int main()
{
    int n = 0;
    int i = 0;
    cout << "Please enter a number: ";
    cin >> n;
    
    int *arr = perm2(n);
    
    for(i = 0; i < n; i++) {
        cout << arr[i] << " ";
        //cout << endl; //using for debugging
        //had incorrect for loop causing unkown numbers
        //to appear
    }

    cout << endl;
    delete [] arr;
    
    return 0;
}
