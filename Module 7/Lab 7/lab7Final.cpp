//Author: Tyler Bieker
//Assignment: Lab 7
//Date: 11/02/2015
//Sources: None

#include <iostream>
#include <string>
#include <cmath>

using namespace std;

bool isBalanced(string paren); //function to determine if string of parenthesis are balanced
int sumDigits(int n);	//function to determine sum of integers in number
void partOne();
void partTwo();

int main(){
	partOne();
	cout << endl;
	partTwo();
	
	char reply;
	cout << endl << "Press enter to quit: ";
	cin >> reply;
	
	return 0;
}

int sumDigits(int n){
	int digitSum = 0;
	
	while(n != 0){
		digitSum = digitSum + (n % 10);  //divide by 10 and add the dropped digit(the last digit in the integer) to the sum
		n = n / 10;
	}
	
	return digitSum;
}

bool isBalanced(string paren){
	bool isEmpty = false;
	int positionTwo;	//position of second parenthesis character
	char charOne, charTwo;
	int length = paren.length();

	if(length % 2 != 0){ //If the number of parenthesis is odd, the string cannot be balanced
		return false;
	}
	while(isEmpty == 0){
		charOne = paren.at(0);
			if(charOne == ')'){ //string cannot be balanced if it starts with right parenthesis
				return false;
			}
		positionTwo = paren.find(')');
		charTwo = paren.at(positionTwo);
			
		if(positionTwo == string::npos){ //return false if char is not found
			return false;
		}
		
		paren.erase(positionTwo, 1); //remove set of parenthesis from string
		paren.erase(0, 1);			 //remove second position prior to first. If first position is removed prior,
									 //it shifts the positions.
									 
		isEmpty = paren.empty(); //continue loop until the string is empty
	}
	
	return true;
}

void partOne(){
	string inputString; //user input string

	cout << "Input string of parenthesis to test for balance: ";
	cin >> inputString;
	bool balanced = isBalanced(inputString);
	
	if(balanced == true){
		cout << "\nThe string is balanced." << endl;
	}else{
		cout << "\nThe string is not balanced." << endl;
	}
}

void partTwo(){
	int number;
	int finalNumber;
	
	cout << "Enter number: ";
	cin >> number;
		
	finalNumber = sumDigits(number);
		
	cout << "\nThe sum of the digits is: " << finalNumber << endl;;
}