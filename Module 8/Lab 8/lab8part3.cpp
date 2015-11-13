//Author: Tyler Bieker
//Program: Lab 8.3 Update to prime function
//Date: 11/12/2015
//Sources:none

#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

const int PRIME_COUNT = 100; //number of prime numbers to count
const double NTH_COUNTER = 7; //10^x to count to  ex: 10, 100, 1000...

const int ARRAY_SIZE = 50000000;
int primeArray[ARRAY_SIZE];
int primeArrayCounter = 0;

void initialize(int array[]);
bool isPrime(int number);
void output(int n, int nthPrime);
void partOne();
void partTwo();

int main(){
	initialize(primeArray);
	cout << "Array initialized" << endl;
	partOne();
	cout << endl << endl; //make two empty lines between part one and part two
	partTwo();

	char reply;
	cout << "\n\npress q to quit:";
	cin >> reply;
	return 0;
}

void partOne(){ //part one of the assignment. Outputs prime numbers to 100
	int num = 0;	
	int counter = 0;
	
	while(counter <= PRIME_COUNT){
		if(isPrime(num) == true){	//only display and increase counter if the number is prime
			cout << num << endl;
			counter++;				//increase prime count
			primeArray[primeArrayCounter] = num; //add prime number to array
			primeArrayCounter++;  //increment counter
		}
		num++;
	}
}

void partTwo(){	//part two of the assignment. Outputs prime numbers at 10^1 though 10^6
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
}

void output(int n, int nthPrime){ //output formatted results
	cout << left << setw(12) << n << nthPrime << endl;
}


bool isPrime(int number){
	
	if(number < 2){
		return false;
	}
	
	double num = sqrt(number);		//use all numbers less than the square root to divide the number and check for prime

	for(int i = 0; primeArray[i] <= num; i++){	//divide by the prime numbers under the sqrt of the test number
		if(number % primeArray[i] == 0){
			return false;
		}
	}
	return true;	//return true if for loop does not return a false
}


/*
//Original
//******************************************************************
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
*/

void initialize(int array[]){
	for(int i = 0; i < ARRAY_SIZE; i++){
		array[i] = i + 2; //initialize array to hold prime numbers starting at prime number 2
	}
}
