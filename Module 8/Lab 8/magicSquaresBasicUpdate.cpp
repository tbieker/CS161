//Author: Tyler Bieker
//Assignment: Assignment 2 Magic Squares
//Date: 11/11/2015
//Sources: None


#include <iostream>
#include <string>

using namespace std;

const string owner = "Tyler";     //owner of checker
const int SIZE = 4; //size of square

int main(){
	
	int magicArray[SIZE][SIZE];
	
    int sumLineA = 0, sumLineB = 0, sumLineC = 0, sumLineD = 0;
    int sumColA = 0, sumColB = 0, sumColC = 0, sumColD = 0;
    int sumDiagTop = 0, sumDiagBot = 0;  //Diagonals starting from top left(sumDiagTop) and bottom left(sumDiagBot)
    
    bool isMagicSquare = false; //Does square work true/false. Initial is false
   
    cout << "Welcome to " << owner <<"'s Magic Square Checker! Please enter your magic square: " << endl;
    cout << endl;
	
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
