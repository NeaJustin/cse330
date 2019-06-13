/****************************************************************************************************
* Justin Pulido
* Unordered_map_test1.cpp
* March 14th, 2018
* checks the implementation of the unordered.h file and if anything is missing the program will not 
  run.
* the ones that it is checking for this is the print, the insert to make sure it is running correct.
* O(n) size of the problem. 
* 100% complete 
****************************************************************************************************/

#include <iostream>

#include "Unordered.h"

using namespace std;

int main()
{
    Unordered_map<string, string> h(7);

    cout << "h # cout = " << h.bucket_count() << endl;
    cout << "h size = " << h.size() << endl;
    
    cout << "Insert a few pairs\n";
    h.insert(pair<string, string>("Red", "123 Main"));
    h.insert(pair<string, string>("Brown", "45 First"));
    h.insert(make_pair("Blue", "20 2nd St")); //make_pair() also works and is simpler
    h["Jack"] = "500 E st";
    h["Jill"] = "400 Lakewood";
    h["Jake"] = "2 Sierra Madre";

    cout << "h # count = " << h.bucket_count() << endl;
    cout << "h size = " << h.size() << endl;
    
    cout << "Lookup a few values\n";
    cout << "Brown: " << h["Brown"] << endl;
    cout << "Green: " << h["Green"] << endl;
    cout << "Jack:" << h["Jack"] << endl;
    cout << "one more:" << h["One more"] << endl;
    
    cout << "h # cout = " << h.bucket_count() << endl;
    cout << "h size = " << h.size() << endl;

    cout << "h Everything\n";
    h.print();

    cout << "Modify Red's value\n";
    h["Red"] = "1234 Main St";

    cout << "h Again\n";
    h.print();

	cout << endl;

    return 0;
}

