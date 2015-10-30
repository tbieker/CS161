//Author: Tyler Bieker
//Program: Assignment 6 Part 1
//Date: 10/25/2015
//Sources:none

#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

const int PRIME_COUNT = 100; //number of prime numbers to count

bool isPrime(int number);

int main(){
	int num = 0;	
	int counter = 0;
	
	while(counter <= PRIME_COUNT){
		num++;
		if(isPrime(num) == true){	//only display and increase counter if the number is prime
			cout << num << endl;
			counter++;				//increase prime count
		}
	}
	
	char reply;
	cout << "press q to quit";
	cin >> reply;
	return 0;
}

bool isPrime(int number){
	int testNumber;
	
	if(number < 2){
		return false;
	}
	
	int num = sqrt(number) + 1;		//use all numbers less than the square root to divide the number and check for prime
	
	for(int i = 2; i < num; i++){
		if(number % i == 0){		// return false if is equal to 0, otherwise continue through numbers
			return false;
		}
	}
	
	return true;	//return true if for loop does not return a false
}
	