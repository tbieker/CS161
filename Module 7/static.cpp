// This program demonstrates static variables
// Author: Colin Goble
// Date: 26-July-2006
// Sources: None

#include <iostream>
#include <string>

using namespace std;

int totalIt(int x);

int main()
{
    int total;
    total = totalIt(1);
    cout << total << endl;
    total = totalIt(2);
    cout << total << endl;
    total = totalIt(3);
    cout << total << endl;
    char reply;
    cout << "Enter q to quit: ";
    cin >> reply;
    return 0;
}

int totalIt(int x)
{
    int total = 0;
    //int total = 0;
    total = total + x;
    return total;
}
