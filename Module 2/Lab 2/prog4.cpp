//Author: Tyler Bieker
//Assignment: Lab 2 Program 4
//Date 09/29/2015
//Sources: None

#include <iostream>
#include <string>

using namespace std;

int main(){
    string a, b, c;
    char reply;
    
    cout << "Enter three strings: " << endl;
    cin >> a >> b >> c;
    
    cout << endl;
    
    //six permutations
    cout << a << " " << b << " " << c << endl;
    cout << a << " " << c << " " << b << endl;
    cout << b << " " << a << " " << c << endl;
    cout << b << " " << c << " " << a << endl;
    cout << c << " " << a << " " << b << endl;
    cout << c << " " << b << " " << a << endl;
    
    cout << "Press enter to quit: " << endl;
    cin >> reply;
    
    return 0;
}
