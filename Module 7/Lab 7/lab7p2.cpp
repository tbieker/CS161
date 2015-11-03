//Author: Tyler Bieker
//Assignment: Lab 7 part one
//Date: 11/02/2015
//Sources:

#include <iostream>
#include <cmath>

using namespace std;

int sumDigits(int n);
int integerLength(int n);
void continueProg(bool& answer);

int main(){
	bool calculate = true;
	
	while(calculate){
		int number;
		int finalNumber;
	
		cout << "Enter number: ";
		cin >> number;
		
		finalNumber = sumDigits(number);
		
		cout << "\nThe sum of the digits is: " << finalNumber << endl;;
		
		continueProg(calculate); //repeat while loop if true
	}
	
	return 0;
}

void continueProg(bool& answer){
	char input;
	cout << "Would you like to calculate another number(y/n): ";
	cin >> input;
	
	switch(input){	
			case 'y':
			case 'Y':
				answer = true; //Repeat program and enter new number
				break;
			case 'n':
			case 'N':
				answer = false;	//Stop the program
				break;
			default:	//user did not enter y or no. Repeat statement
				cout << "That is not a valid answer" << endl;
				continueProg(answer);
		}
}

int sumDigits(int n){
	int digitSum = 0;
	
	while(n != 0){
		digitSum = digitSum + (n % 10);  //divide by 10 and add the dropped digit(the last digit in the integer) to the sum
		n = n / 10;
	}
	
	return digitSum;
}
