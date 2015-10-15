//Author: Tyler Bieker
//Assignment 4
//Date: 10/10/2015
//Sources: None

#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

int main(){
	
	const string OWNER = "Tyler";										//Fare calculator owner
	char reply;	
	
	int numAdults, numChildren, vehicleLength;	
    double priceAdults, priceChildren;
	double passengerSurcharge;
    double totalPassengerPrice, totalSurcharge, totalPrice;
	
	double vehicleSurcharge = 0;										//Initialiaze vehicleSurcharge, vehiclePrice,  
	double vehiclePrice = 0;											//lenghtPrice and extraLength as 0.
	double lengthPrice = 0;												//Unable to calculate total price 
	int extraLength = 0;												//if isDriving == 'n'
	
	char isDriving, height;												// y/n answers
    bool isOverHeight = false, isOverLength = false;					
	
	
	cout << fixed << showpoint << setprecision(2);						// Display two decimals in the totals
	
	cout << "Welcome to " << OWNER << "'s Fare Calculator" << endl;
	
	cout << "How many adults (age 12 or over) are in your party? ";
	cin >> numAdults;
	
	cout << "How many children (age 5 to 11) are in your party? ";
	cin >> numChildren;
	
	cout << "Are you driving a vehicle onto the ferry? (y/n): ";
	cin >> isDriving;
	
	if(isDriving == 'y'){												// Determine if vehicle must be calculated
        cout << "What is the length of the vehicle in feet? ";
		cin >> vehicleLength;
		if(vehicleLength > 20){											// Determine if vehicle is 20ft or under
            isOverLength = true;										
			extraLength = vehicleLength - 20;
		}
	
		cout << "Is the vehicle over 7 feet high? (y/n): ";
		cin >> height;
		if(height == 'y'){												// Determine if vehicle is under 7ft in height or under
			isOverHeight = true;
		}
		
		if(isOverHeight == true){										//Set prices based on vehicle height
			vehiclePrice = 69.00;
			vehicleSurcharge = 10.40;
			lengthPrice = extraLength * 3.45;
		}else{
			vehiclePrice = 43.00;
			vehicleSurcharge = 4.15;
			lengthPrice = extraLength * 2.15;
		}
	}
	
	priceAdults = numAdults * 13.00;
	priceChildren = numChildren * 6.50;
	totalPassengerPrice = priceAdults + priceChildren;
	passengerSurcharge = (numAdults + numChildren) * 1.25;
	totalSurcharge = passengerSurcharge + vehicleSurcharge;
	
	totalPrice = totalPassengerPrice + vehiclePrice + totalSurcharge + lengthPrice;

//Original format begin
//************************************************************************************************************************
/*
	cout << "Your fare is " << totalPassengerPrice + vehiclePrice + lengthPrice << " plus a fuel surcharge of " << totalSurcharge << endl;
	cout << "The total amount payable is " << totalPrice;
*/
//************************************************************************************************************************
//Original format end






//Output as table format for extra points
//Table format begin
//************************************************************************************************************************    
    cout << setfill('.') << left;
	cout << setw(31) << "\nCategory" << right << setw(10) << "Price" << endl;
	cout << setfill('-') << setw(40) << "-" << endl;
	cout << setfill('.') << left;
    cout << setw(30) << "Adults" << right << setw(10) << priceAdults << endl;
    cout << left;
	cout << setw(30) << "Children" << right << setw(10) << priceChildren << endl;

	if(isDriving == 'y'){												//Display vehicle categories if driving or hide if not
		if(isOverHeight == true){										//Display oversized vehicle
			cout << left;
			cout << setw(30) << "Oversized vehicle" << right << setw(10) << vehiclePrice << endl;
			if(isOverLength == true){
				cout << left;
				cout << setw(30) << "   Extra length(per foot)" << right << setw(10) << lengthPrice << endl;
			}
		}else {															//Display passenger vehicle
			cout << left;
			cout << setw(30) << "Passenger vehicle" << right << setw(10) << vehiclePrice << endl; 
			if(isOverLength == true){
				cout << left;
				cout << setw(30) << "   Extra length(per foot)" << right << setw(10) << lengthPrice << endl;
			}
		}
	}
	
	cout << left;
	cout << setw(30) << "Fuel Surcharge" << right << setw(10) << totalSurcharge << endl;
    cout << left;
	cout << setfill('-') << setw(40) << "-" << endl;
    cout << setfill('.');
    cout << setw(30) << "Total price" << right << setw(10) << totalPrice << endl;

//************************************************************************************************************************
//Table format end	

	
	cout << "\nThank you for using " << OWNER << "'s Fare Calculator" << endl;
	
	cout << "\nPress enter to quit: ";
	cin >> reply;
	
	return 0;
}
