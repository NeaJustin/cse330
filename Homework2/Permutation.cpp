/******************************************************************************
 * Justin Pulido
 * Permutation.cpp
 * February 10, 2018
 * The program needs an array of numbers to generate random numbers from the
   user input.
 * It solves this by using a fnctino to be able to create a pointer to arr
   and generate random nmbers based on the user input. It will then detect
   if the random numbers are duplicated and if they are, they are not 
   inclded into the arr and are not outputed making sure the duplicates are 
   not there. 
 * Big O(n) is O(n^2)
 * 100% Complete
*****************************************************************************/

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

//creates an arr to hold the n spaces
//then randomly generates numbers without
//duplicating them and returns the arr
int *perm(int n) 
{
    int i = 0;
    int count = 0;
    int *arr = new int[n]; //creatiing a new array
    
    while(count < n) {
        //creating random numbers
        int random = rand()% n + 1;
        //checking to see if numbers are identical 
        bool Number = false;
        for (i = 0; i < n; i++) {
            if(arr[i] == random) {
                Number = true;
                break;
            } 
        }    
        if(!Number) {
            arr[count] = random;
            count++;
        } else {
            Number = false;
        }
    }
    return arr;

}

int main()
{
    int i = 0;
    int n = 0;
    cout << "Please enter a Number: ";
    cin >> n;

    int *arr = perm(n);

    for(i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    delete [] arr;

    return 0;
}
 
