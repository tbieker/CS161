//Assignment 1
//Author: Tyler Bieker
//Date: 09/25/2015
//Sources: None

#include <iostream>
#include <string>

using namespace std;

int main()
{
	char name1;
	char name2;
	char subject;
	
	name2 = "Tyler";
	cout << "Welcome to " << name2 << "'s Crystal Ball!" << endl;
	cout << "What is your name, please? ";
	cin >> name2 >> endl;
	cout << "Hello, " << name2 << ". My name is " << name1 << endl;
	cout << "What subject are you studying? ";
	cin >> subject >> endl;
	cout << "Well, " << name2 << " " << name1 << "'s crystal ball says you will do very well in " << subject << " this term" << endl;
	cout << "Good luck!" << endl;
	
	return 0;
}

