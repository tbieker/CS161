//Author: Tyler Bieker
//Lab 4.1
//Date: 10/10/2015
//Sources: None

#include <iostream>

using namespace std;

int main(){
	
	
    double term = 100;      //number of terms to count
    double i = 0;           //counter
	double x=1, y=0;		//sum
	bool sym = true;		//determine plus(+) or minus(-) symbol
	double PI_calc;			//final number to output
	char reply;
	
	while(i < term){
		if(sym == true){
			y = y + (1 / x);
            sym = false;
		} else{
			y = y - (1 / x);
			sym = true;
		}	
		x = x + 2;
		i++;
	}
	
	PI_calc = 4 * y;
	
	cout << PI_calc << endl;
	
	cout << "\nPress enter to quit: ";
	cin >> reply;
	
	return 0;
}
