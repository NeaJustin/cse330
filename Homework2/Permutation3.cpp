/*********************************************************************
 * Justin Pulido
 * Permutation3.cpp
 * February 11, 2018
 * same problem as the previous two where we are required to create 
   a legal permutation through a function.
 * However, this one is required to use a swap functino that will 
   be able to fill the array if i < n.
 * Big O(n^3) is the size of the problem. 
 * 100% Complete
********************************************************************/

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

//the swap function will have a temporary 
//variable to hold an number, and it will be
//set equal to the specific variables.
void swap(int & i, int & j)
{
    int temp;
    temp = i;
    i = j;
    j = temp;
}

//uses the same algorithm as the previous program,
//however, it filles the vector such that the index
//of i is equal to i + 1. 
//it then calls swap function to help sort the function
//and make it smaller without sacrificing too much time.
int *perm3(int n)
{
    int count = 0;
    int i = 0;
    int j = 0;
    int *arr = new int[n];
    
    //filling the array
    for(i = 0; i < n; i++) {
        arr[i] = i + 1;
    }
    
    //using different vaiables 
    //otherwise it would run improperly
    for(j = 0; j < n; j++) {
        //generating random numbers
        int random = rand()% n + 1;
        for(j = 0; j < n; j++) {
            swap(arr[j], arr[random]);
        }
    }
    return arr;
}

int main()
{
    int n = 0;
    int i = 0;
    cout << "Please enter a number: ";
    cin >> n;

    int *arr = perm3(n);

    for(i = 0;  i < n; i++) {
        cout << arr[i] << " ";
    }

    cout << endl;
    delete [] arr;

    return 0;
}

