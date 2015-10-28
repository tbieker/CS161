//Author: Tyler Bieker
//Program: Assignment 6
//Date: 10/25/2015
//Sources:

#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

const int PRIME_COUNT = 10; //number of prime numbers to count

bool isPrime(int number);

int main(){
	int num = 2;	
	int counter = 0;
	bool checkPrime;
	
	while(counter <= PRIME_COUNT){
		checkPrime = isPrime(num);	
		if(checkPrime == true){
			cout << num << endl;
			counter++;
		}
		num++;
	}
	
}

bool isPrime(int number){
	int num;
	if(number % 2 == 0){
		return false;
	}
	
	num = sqrt(number) + 1;
	cout << num;
	for(int i = 2; i < num; i++){
		if(number % i == 0){
			return false;
		}else{
			return true;
		}
	}
	
	
}
