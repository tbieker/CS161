//Author: Tyler Bieker
//Assignment 3
//Date: 10/06/2015
//Sources: Textbook for use of setprecision function

#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

int main(){
	
	const string owner = "Tyler";
	int a1, b1, c1;
	int a2, b2, c2;
	double divisor;
	double x, y;
	string reply;
	
	cout << fixed << showpoint << setprecision(2);                                      //Set to display two decimal places
	
	cout << "Welcome to " << owner << "'s Simultaneous Equation Solver." << endl;
	cout << "Please enter a1, b1, c1 (separated by spaces): ";                          //Equation one
	cin >> a1 >> b1 >> c1;
	cout << "Please enter a2, b2, c2 (separated by spaces): ";
	cin >> a2 >> b2 >> c2;                                                              //Equation two
	
	divisor = (a1 * b2) - (a2 * b1);
	
    if (divisor != 0){                                                                  //Confirm not dividing by zero(undefined). Equations will never intersect
		x = ((c1 * b2) - (c2 * b1)) / divisor;
		y = ((a1 * c2) - (a2 * c1)) / divisor;
		
		cout << "The solution of the equations:" << endl << a1 << "x + " << b1 << " = " << c1 << endl;
		cout << a2 << "x + " << b2 << "y = " << c2 << endl << "is x = " << x << " and y = " << y << endl;
		cout << "Thank you for using " << owner << "'s Simultaneous Equation Solver." << endl;
	}
	
	else {
		cout << "Those equations do not intersect: ";
	}
		
	cout << "Press enter to quit: " << endl;
	cin >> reply;
	
	return 0;
	
}
