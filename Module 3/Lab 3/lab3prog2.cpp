// Author: Tyler Bieker
// Assignment: Lab 3.2
// Date: 10/07/2015
// Sources: None

#include <iostream>

using namespace std;

int main(){
	
	int sharesOwned;
	double purchasePrice, sellPrice, serviceCharge;
	double serviceChargeDecimal;
	double sellProfit, totalProfit;
	char reply;
	
	cout << "Enter shares owned: ";
	cin >> sharesOwned;
	cout << "Enter purchase price: $";
	cin >> purchasePrice;
	cout << "Enter sell price: $";
	cin >> sellPrice;
	cout << "Enter service charge percentage: ";
	cin >> serviceCharge;
	
	sellProfit = sharesOwned * sellPrice;
	serviceChargeDecimal = serviceCharge / 100;	
    totalProfit = (sellProfit - (sellProfit * serviceChargeDecimal)) - (sharesOwned * purchasePrice);
	
	if(totalProfit >= 0){
        cout << "Total profit: $" << totalProfit << endl;
    } else{
        cout << "Total loss: $" << totalProfit << endl;
    }
    
	cout << "Press enter to quit: " << endl;
	cin >> reply;
	return 0;
}
