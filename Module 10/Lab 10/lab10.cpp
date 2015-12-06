//Author: Tyler Bieker
//Assignment: Lab 10
//Date: 12/03/2015
//Sources: StackOverflow

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <sys/time.h>
#include <time.h>

using namespace std;

static int arr[10][100000];

void init(int arr[10][100000]);	//function to initialize array with random numbers
void selectionSort(int arr[], int size);	//function to implement selection sort on array

int main(){
	
	init(arr); //initialize array with random integers
	
	for(int i = 0; i < 10; i++){	//sort list in multiples of ten
		
		timeval start, end;
		
		gettimeofday(&start, NULL);	//get beginning time
		double t1 = start.tv_sec+(start.tv_usec / 1000);
		
		selectionSort(arr[i], 10000*(i + 1));
		
		gettimeofday(&end, NULL);	//get ending time
		double t2 = end.tv_sec+(end.tv_usec / 1000);

		cout << left << setw(10) << 10000*(i + 1) << t2 - t1 << endl; //output selectionSort number and the time taken to perform sort
	}
	
	char reply;	//stop program flash
	cout << "enter q to quit: ";
	cin >> reply;
	
	return 0;
}

void init(int arr[10][100000]){	//initialize array to random numbers
	for(int i = 0; i < 10; i++){
		for(int j = 0; j < 100000; j++){
			srand(time(NULL));
			arr[i][j] = rand();
		}
	}
}

void selectionSort(int arr[], int size){
	int index;
	int smallestIndex;
	int location;
	int temp;
	for(index = 0; index < size - 1; index++){
		smallestIndex = index;
		for(location = index + 1; location < size; location++){
			if(arr[location] < arr[smallestIndex]){
				smallestIndex = location;
			}
		}
		temp = arr[smallestIndex];
		arr[smallestIndex] = arr[index];
		arr[index] = temp;
	}
}
