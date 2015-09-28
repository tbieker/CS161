//Author: Tyler Bieker
//Lab 2: Program 1
//Date: 09/27/2015
//Sources: None

#include <iostream>

using namespace std;

int main(){
	int test1, test2, test3, test4, test5;
	float testAvg;
	char reply;
	
	cout << "Enter five test scores:" << endl;
	cin >> test1 >> test2 >> test3 >> test4 >> test5;
	testAvg = (test1 + test2 + test3 + test4 + test5) / 5.0;
	cout << "The average test score is: " << testAvg;
	
	cin >> reply;
	
	return 0;
}
