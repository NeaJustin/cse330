/*****************************************************************************
 * Justin Pulido
 * Infix.cpp
 * January 9th, 2018
 * The program will take a set of numbers or letters and 
   produce an output based on the symbols given. 
 * Algorithm: The program checks to see if the inputs are symbols or letters. 
   If they are letters or numbers they are not pushed onto the stack and 
   printed out. Symbols are pushed onto the stack and checked to see which 
   one has higher precedence over the other. The Symbols will 
   then be popped off until there is nothing left in the 
   stack.
 * O(n) where n is the size of the input.
 * 90% COMPLETE causing segmentation fault 
******************************************************************************/

#include <iostream>
#include <stack>
#include <string>

using namespace std;

//uses a switch so that it can see which operand has more 
//precedence over the other. Each one returning different 
//numbers and how knows the order of precedence. 
int precedence(char c)
{
    switch(c) {
        case '+':
        case '-': return 1;
        case '*': 
        case '/': return 2;
        case '(': return 3;
        
    }
}


int main()
{
    char n;
	cout << "Enter an Arithmetic Expression: ";
    cin >> n;

	stack <char> s;

    while (!cin.eof()) {
       	if(n != '*' && n != '/' && n != '-' && n != '+') {  
            cout << n;
       	}
		else { 
			if (n == '(') {
				s.push(n);
			}
			else if (n == ')') {
       	    	while (!s.empty() && s.top() != '(') {
       	        	cout << s.top();
       	        	s.pop();
       	    	}
       	    	if (!s.empty()) {
       	        	s.pop();
       	    	}
       	    	else {
       	        	cout << "error, no matching '('" << endl;
       	    	}
       		}
            //checking to see if n is equal to specific operands. 
       		else if (n == '*' || n == '/' || n == '-' || n == '+') {
                //checks to see if stack is empty, or stack of top is less 
                //precedence over the one coming in. 
          		if (s.empty() || precedence(s.top()) < precedence(n)) {
					s.push(n);  //if it is, push it onto the stack.
				}
				else {
                    //checking for stack empty. 
					while (!s.empty() || precedence(s.top()) >= precedence(n)) {
						cout << s.top();    //displaying the top of the stack. 
						s.pop();            //then popping off the top of the stack. 
					}
					s.push(n);              //then push n.
				}
			}		
			else { 
			    cout << "Error, invalid input."; //else this is not a correct input. 
			}
		}
        cin >> n;                                //giving the option to enter new characters  

	}
	while (!s.empty()) {        //if the stack is not empty
		cout << s.top();        //display the top of the stack
		s.pop();                //pop it from the stack
        cout << endl;           //new line.
	}

    return 0;
}

