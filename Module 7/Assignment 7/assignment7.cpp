//Author: Tyler Bieker
//Assignment: Lab 7
//Date: 11/06/2015
//Sources: www.cplusplus.com for function reference

#include <iostream>
#include <string>
#include <cctype>

using namespace std;

bool isPalindrome(string str);
string removePunc(string str);
string lowerString(string str);

int main(){
	string userInput;
	
	cout << "Please enter a possible palindrome: ";
	getline(cin, userInput);
	
	if(isPalindrome(userInput) == true){
		cout << "\nThat was a palindrome!" << endl;
	}else{
		cout << "\nThat was not a palindrome!" << endl;
	}
	
	char reply;
	cout << "Press enter to quit: ";
	cin >> reply;
	return 0;
}

bool isPalindrome(string str){
	str = lowerString(str);		//convert string to all lowercase
	str = removePunc(str);		//remove all punctuation from string
	int length = str.length();
	
	for(int i = 0; str[i]; i++){   	//compare i character and last character - i 
 		if(str[i] != str[length - 1 - i]){
			return false;
		}
		return true;   //return true if all characters compare
	}
}

string lowerString(string str){  //Convert all letters to lowercase
	for(int i = 0; str[i]; i++){
		str[i] = tolower(str[i]);
	}
	return str;
}

string removePunc(string str){ //Remove punctuation from the string
	for(int i = 0; str[i]; i++){
		if(ispunct(str[i])){
			str.erase(i, 1);
			i--;	//reset i counter back one after remove punctuation
		}
	}
	return str;
}

