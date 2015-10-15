//Author: Tyler Bieker
//Lab 4 Program 2
//Date: 10/12/2015
//Sources: None

#include <iostream>

using namespace std;

int main(){
	
	int a;								//First number
    int b;								//Second number
    int c;								//Display number
	char charOne;						//input to continue with program
	bool endProg = false;				//
	
	cout << "Fibonacci number generator" << endl;
	cout << "To stop the program enter 'q'" << endl;
	cout << "Enter the first two numbers: ";
	cin >> a >> b;
	cout << "The numbers entered are: " << a << " " << b;
	
	while(!endProg){
		charOne = getchar();
		c = a + b;
		cout << endl << c;
		a = b;							//Shift numbers
		b = c;							//
		
		if(charOne == 'q'){
			endProg = true;				//Break loop if user enters 'q'
		}
		
	} //End of while loop
	
	return 0;
}
