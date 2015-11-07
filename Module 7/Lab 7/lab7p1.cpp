//Author: Tyler Bieker
//Assignment: Lab 7 part one
//Date: 11/02/2015
//Sources: None

#include <iostream>
#include <string>

using namespace std;

bool isBalanced(string paren);

int main(){
	string inputString; //user input string

	cout << "Input string of parenthesis to test for balance: ";
	cin >> inputString;
	bool balanced = isBalanced(inputString);
	
	if(balanced == true){
		cout << "\nThe string is balanced." << endl;
	}else{
		cout << "\nThe string is not balanced." << endl;
	}
	
	char reply;
	cout << "Press enter to quit: ";
	cin >> reply;
	
	return 0;
}

bool isBalanced(string paren){
	bool isEmpty = false;
	int positionTwo;
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
		paren.erase(0, 1);			 //remove second position prior to first. If first position is removed before, it shifts the positions.
	
		isEmpty = paren.empty(); //continue loop until the string is empty
	}
	
	return true;
}
