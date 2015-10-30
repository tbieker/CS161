//Author: Tyler Bieker
//Program: Assignment 6 Part 2
//Date: 10/25/2015
//Sources:none

#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

const double NTH_COUNTER = 4; //10^x to count to  ex: 10, 100, 1000...

bool isPrime(int number);
void output(int n, int nthPrime);

int main(){
	cout << left << setw(12) << "n:" << "nth Prime:" << endl; //heading of output
	int num = 1;
	int primeCounter = 0;
	int n = 10;
	
	
	while(primeCounter < pow(10, NTH_COUNTER)){
		if(isPrime(num) == true){	//only display and increase counter if the number is prime
			primeCounter++;				//increase prime count
		}
		if(primeCounter == n){  	//output each prime at 10^x   ex: 10, 100, 1000...
			output(n, num);
			n = n * 10;
		}
		num++;
	}
	
	char reply;
	cout << "\n\npress q to quit:";
	cin >> reply;
	return 0;
}

void output(int n, int nthPrime){ //output formatted results
	cout << left << setw(12) << n << nthPrime << endl;
}

bool isPrime(int number){
	int testNumber;
	
	if(number < 2){
		return false;
	}
	
	double num = sqrt(number) + 1;		//use all numbers less than the square root to divide the number and check for prime
	
	for(int i = 2; i < num; i++){
		if(number % i == 0){		// return false if is equal to 0, otherwise continue through numbers
			return false;
		}
	}
	
	return true;	//return true if for loop does not return a false
}
