//Author: Tyler Bieker
//Assignment: Lab 3.1
//Date: 10/07/2015
//Sources: None

#include <iostream>
#include <string>

using namespace std;

int main(){
	string dayString, futureDayString;
	int currentDay;
	int dayCounter;
	int output;
	char reply;
	
	cout << "Enter current day in all lowercase: ";
	cin >> dayString;
	cout << "Enter days to count: ";
	cin >> dayCounter;
	
	if(dayString == "sunday"){							//Convert string to integer
		currentDay = 1;
	}else if(dayString == "monday"){
		currentDay = 2;
	}else if (dayString == "tuesday"){
		currentDay = 3;
	}else if (dayString == "wednesday"){
		currentDay = 4;
	}else if (dayString == "thursday"){
		currentDay = 5;
	}else if (dayString == "friday"){
		currentDay = 6;
	}else if (dayString == "saturday"){
		currentDay = 7;
	}else{
		cout << "Not a valid entry.";
	}
	
	output = currentDay + (dayCounter % 7);
	if(output >7){										//If output is greater than 7, reset and start from the beginning
		output = output - 7;
	}
	
	if(output == 1){									//Convert integer back to string
		futureDayString = "sunday";
	}else if(output == 2){
		futureDayString = "monday";
	}else if (output == 3){
		futureDayString = "tuesday";
	}else if (output == 4){
		futureDayString = "wednesday";
	}else if (output == 5){
		futureDayString = "thursday";
	}else if (output == 6){
		futureDayString = "friday";
	}else if (output == 7){
		futureDayString = "saturday";
	}
	
	cout << "\nThat day in the future is: " << futureDayString << endl;
	
	cout << "\nPress enter to quit:";
	cin >> reply;
	return 0;
	
}
