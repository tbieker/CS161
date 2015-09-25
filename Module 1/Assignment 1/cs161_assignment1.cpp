//Assignment 1
//Author: Tyler Bieker
//Date: 09/25/2015
//Sources: Stackoverflow.com for clarification of debug errors

#include <iostream>
#include <string>

using namespace std;

int main()
{
	string name1 = "Tyler"; // Name for crystal ball owner
	string name2 = "";      // Name for user to enter
	string subject = "";    // Subject user will enter
	char reply;

	cout << "Welcome to " << name1 << "'s Crystal Ball!" << endl;
	cout << "What is your name, please? ";
	cin >> name2;
	cout << "Hello, " << name2 << ". My name is " << name1 << "." << endl;
	cout << "What subject are you studying? ";
	cin >> subject;
	cout << "Well, " << name2 << ", " << name1 << "'s crystal ball says you will do very well in " << subject << " this term." << endl;
	cout << "Good luck!" << endl;
	cout << "Press <enter> or quit: "; //Keep program from immediately quitting after last answer
	cin >> reply;
	
	return 0;
}

