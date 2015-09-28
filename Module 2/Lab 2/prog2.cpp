//Author: Tyler Bieker
//Assignment: Lab 2 Program 2
//Date: 09/27/2015
//Sources: None

#include <iostream>

using namespace std;

int main(){
	
	int numSec; //Number of seconds to input_iterator
	int initMinutes;
        int seconds, minutes, hours;
	char reply;
	
	cout << "Enter number of seconds: ";
	cin >> numSec;                                     //Enter seconds
	seconds = numSec % 60;                             //Remainder of seconds
	initMinutes = numSec / 60;                         //Initial amount of minutes
	minutes = initMinutes % 60;                        //Minutes remaining after hour division
        hours = initMinutes / 60;                          //Calculate hours
	cout << hours << ":" << minutes << ":" << seconds;
	
	cin >> reply;
	
	return 0;
}
