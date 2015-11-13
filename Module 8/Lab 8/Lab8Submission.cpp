//Lab 8 parts 2 and 3
//I have marked the updated array in part 2 and isPrime() function


//***********************************************************************************************************
//Author: Tyler Bieker
//Assignment: Lab 8 part 2
//Date: 11/11/2015
//Sources: None


#include <iostream>
#include <string>

using namespace std;

const string owner = "Tyler";     //owner of checker
const int SIZE = 4; //size of square

int main(){
	
	//Updated array
	//***************************************************************************************************
	int magicArray[SIZE][SIZE];
	//***************************************************************************************************
	
    int sumLineA = 0, sumLineB = 0, sumLineC = 0, sumLineD = 0;
    int sumColA = 0, sumColB = 0, sumColC = 0, sumColD = 0;
    int sumDiagTop = 0, sumDiagBot = 0;  //Diagonals starting from top left(sumDiagTop) and bottom left(sumDiagBot)
    
    bool isMagicSquare = false; //Does square work true/false. Initial is false
   
    cout << "Welcome to " << owner <<"'s Magic Square Checker! Please enter your magic square: " << endl;
    cout << endl;
	
	//Updated calculations
	//***************************************************************************************************
	for(int i = 0; i < SIZE; i++){		//Input square line by line
		cout << "Line " << i + 1 << ": ";
		for(int x = 0; x < SIZE; x++){	//Input a number in each column per line
			cin >> magicArray[i][x];
		}
	}
	for(int i = 0; i < SIZE; i++){  //Determine sum of rows
		sumLineA = sumLineA + magicArray[0][i];
		sumLineB = sumLineB + magicArray[1][i];
		sumLineC = sumLineC + magicArray[2][i];
		sumLineD = sumLineD + magicArray[3][i];
	}
	for(int j = 0; j < SIZE; j++){  //Determine sum of columns
		sumColA = sumColA + magicArray[j][0];
		sumColB = sumColB + magicArray[j][1];
		sumColC = sumColC + magicArray[j][2];
		sumColD = sumColD + magicArray[j][3];
	}
	for(int k = 0; k < SIZE; k++){	
		sumDiagTop = sumDiagTop + magicArray[k][k]; //add diagonal upper left to lower right
		sumDiagBot = sumDiagBot + magicArray[(SIZE - 1) - k][k]; //add diagonal lower left to upper right
	}
	//***************************************************************************************************
	
	if (sumLineA == sumLineB && sumLineB == sumLineC && sumLineC == sumLineD){ //Determine if the square meets requirements
        if (sumColA == sumColB && sumColB == sumColC && sumColC == sumColD){
           if (sumDiagTop == sumDiagBot){
              isMagicSquare = true;  //Square has meet all requirements and therefore is true
		   }
		}
	}
    if(isMagicSquare == true){
		cout << "\nThis was a magic square! Thank you!" << endl;
	}else{
		cout << "\nThis was not a magic square! Thank you!" << endl;
	}
	
	char reply;
    cout << "\n \n \n \n" << "Enter q to quit: "; //Keep program from flashing
    cin >> reply;  
    return 0;
}



//***************************************************************************************************

//Author: Tyler Bieker
//Program: Lab 8 part 3
//Date: 11/12/2015
//Sources:none

#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

const int PRIME_COUNT = 100; //number of prime numbers to count
const double NTH_COUNTER = 7; //10^x to count to  ex: 10, 100, 1000...

//Updated array to store prime numbers
//***************************************************************************************************
const int ARRAY_SIZE = 50000000;
int primeArray[ARRAY_SIZE];
int primeArrayCounter = 0;
//***************************************************************************************************

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

//Updated isPrime function
//***************************************************************************************************
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
//***************************************************************************************************

void initialize(int array[]){
	for(int i = 0; i < ARRAY_SIZE; i++){
		array[i] = i + 2; //initialize array to hold prime numbers starting at prime number 2
	}
}
