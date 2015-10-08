// Author: Tyler Bieker
// Assignment: Lab 3.3
// Date: 10/07/2015
// Sources: None

#include <iostream>
#include <cmath>

using namespace std;

int main(){
	
	double a1, a2, b1, b2;
	double a, b, c;
	char symbol;
	char reply;
	
	cout << "Enter binomial one in the form ax+b without spaces: ";
	cin >> a1;
	cin.ignore(2);													//ignore x+
	cin >> b1;
	cout << "Enter binomial two in the form ax+b without spaces: ";
	cin >> a2;
	cin.ignore(2);													//ignore x+
	cin >> b2;
	
	a = a1 * a2;
	b = (a1 * b2) + (b1 * a2);
	c = b1 * b2;
	
	cout << "\n" << a << "x^2 ";
    if(b >=0){														//determine + or - symbol
         symbol = '+';
         }else{
               symbol = '-';
               }
    cout << symbol << " " << abs(b) << "x ";						//absoulte value so there are not two minus symbols
    if(c >= 0){														//determine + or - symbol
         symbol = '+';
         }else{
               symbol = '-';
               }
    cout << symbol << " " << abs(c) << endl;						//absolute value so there are not two minus symbols
	
	cout << "\nPress enter to quit: ";
	cin >> reply;
	
	return 0;
}
