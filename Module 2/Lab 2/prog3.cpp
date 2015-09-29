// Author: Tyler Bieker
// Assignment: Lab 2 Program 3
// Date: 09/29/2015
// Sources: None

#include <iostream>
#include <string>

using namespace std;

int main(){
    double byte;                        //bytes to be entered
    double kbyte, mbyte, gbyte;       
    double storageNumber;               //number to be displayed
    string storagePrefix;               //storage size to be displayed byte/KB/MB/GB
    char reply;
    
    cout << " Enter size specified by the manufacturer: ";
    cin >> byte;                        //Input in bytes
    kbyte = byte / 1024;                //Conversions
    mbyte = kbyte / 1024;
    gbyte = mbyte / 1024;
    
    if(kbyte >= 1){                     //Determine what prefix to be displayed
        if (mbyte >= 1){                //Bytes/KB/MB/GB
            if (gbyte >= 1){
               storageNumber = gbyte;
               storagePrefix = "GB";
               }
            else{
                storageNumber = mbyte;
                storagePrefix = "MB";
                }
            } 
        else{
            storageNumber = kbyte;
            storagePrefix = "KB";
            }
		}
    else{
        storageNumber = byte;
        storagePrefix = "Bytes";
        }
            
    cout << "\nActual storage is: " << storageNumber << storagePrefix << endl;
    
    cin >> reply;
    return 0;
}
