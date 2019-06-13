/****************************************************************************
 *String_test2.cpp
 *Percent completed 100%
 *Big O(n) is size of the problem. 
****************************************************************************/

#include <iostream>
#include "String.h"

using namespace std;

int main()
{
    String s1{"abcd"}, s2{"abe"};
    
    if (s1 == s2) {
        cout << s1 << " == " << s2;
    } else {
        if (s1 <= s2) {
            cout << s1 << " < " << s2 << endl;
        }
        else {
            cout << s1 << " > " << s2 << endl;
        }
    }

    s1 = move(s2);
    cout << "s1=" << s1 << "s2=" << s2 << endl;

    String s3 = move(s1);
    cout << "s1=" << " s3=" << s3 << endl;

    return 0;
}

