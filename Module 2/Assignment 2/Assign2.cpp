//Author: Tyler Bieker
//Assignment: Assignment 2 Magic Squares
//Date: 09/27/2015
//Sources: Textbook for if statements and &&


#include <iostream>
#include <string>

using namespace std;

int main(){
	
    const string owner = "Tyler";     //owner of checker
	
    int a1, a2, a3, a4;  //Line 1
    int b1, b2, b3, b4;  //Line 2
    int c1, c2, c3, c4;  //Line 3
    int d1, d2, d3, d4;  //Line 4
	
    int sumLineA, sumLineB, sumLineC, sumLineD;
    int sumCol1, sumCol2, sumCol3, sumCol4;
    int sumDiagTop, sumDiagBot;  //Diagonals starting from top left(sumDiagTop) and bottom left(sumDiagBot)
    
    bool isMagicSquare = false; //Does square work true/false. Initial is false
    char reply;
    
    cout << "Welcome to " << owner <<"'s Magic Square Checker! Please enter your magic square: " << endl;
    cout << endl;
    cin >> a1 >> a2 >> a3 >> a4;  //Input lines
    cin >> b1 >> b2 >> b3 >> b4;
    cin >> c1 >> c2 >> c3 >> c4;
    cin >> d1 >> d2 >> d3 >> d4;
    
    sumLineA = a1 + a2 + a3 + a4;  //Determine sum of the lines
    sumLineB = b1 + b2 + b3 + b4;
    sumLineC = c1 + c2 + c3 + c4;
    sumLineD = d1 + d2 + d3 + d4;
    
    sumCol1 = a1 + b1 + c1 + d1;  //Determine sum of the columns
    sumCol2 = a2 + b2 + c2 + d2;
    sumCol3 = a3 + b3 + c3 + d3;
    sumCol4 = a4 + b4 + c4 + d4;
    
    sumDiagTop = a1 + b2 + c3 + d4;  //Determine sum of diagonals
    sumDiagBot = d1 + c2 + b3 + a4;
    
	if (sumLineA == sumLineB && sumLineB == sumLineC && sumLineC == sumLineD) //Determine if the square meets requirements
        if (sumCol1 == sumCol2 && sumCol2 == sumCol3 && sumCol3 == sumCol4)
           if (sumDiagTop == sumDiagBot)
              isMagicSquare = true;  //Square has meet all requirements and therefore is true
              
    if(isMagicSquare == true)
		cout << "\nThis was a magic square! Thank you!" << endl;
    else
		cout << "\nThis was not a magic square! Thank you!" << endl;
	
    cout << "\n \n \n \n" << "Press enter to quit: "; //Keep program from flashing
    cin >> reply;
    
    return 0;
	
}
