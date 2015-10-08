// Author: Tyler Bieker
// Assignment: Lab 3.4
// Date: 10/07/2015
// Sources: None

#include <iostream>
#include <cmath>

using namespace std;

int main(){
	
	double a, b, c;
	double rootOne, rootTwo;
	double discriminant;
	char reply;
	
	cout << "Enter three coefficients of the trinomial separated by spaces :";
	cin >> a >> b >> c;				
	cout << endl;
	
	discriminant = pow(b, 2) - (4 * a * c);
	
	if(discriminant > 0){											//Determine number of roots
		rootOne = (-b + sqrt(discriminant)) / (2 * a);				//Discriminant > 2 has two roots, == 0 has one root, < 0 has not roots 
		rootTwo = (-b - sqrt(discriminant)) / (2 * a);
		cout << rootOne << " " << rootTwo << endl;
	}else if(discriminant == 0){
		rootOne = -b / (2 * a);
		cout << rootOne << endl;
	}else{
		cout << "There are no roots" << endl;
	}
	
	cout << "Press enter to quit: ";
	cin >> reply;
	
	return 0;
}
