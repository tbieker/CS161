//Author: Tyler Bieker
//Assignment: Assignment 8 Ceasar Cipher
//Date: 11/12/2015
//Sources: www.cplusplus.com

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void openFile(ifstream& inFile);
void decrypt(ifstream& inFile, int decryptKey, ofstream& outFile);
int findKey(ifstream& inFile);

int main(){
	ifstream encryptedFile;
	ofstream decryptedFile;
	
	openFile(encryptedFile);
	
	cout << "Determining key..." << endl;
	
	int key = findKey(encryptedFile);
	
	cout << "The key shift is: "  << key << endl;
	
	cout << "Decrypting file..." << endl;
	
	decrypt(encryptedFile, key, decryptedFile);
	
	cout << "File decrypted" << endl;
	
	encryptedFile.close();	//close input file
	
	char reply;
	cout << "Enter q to quit: ";
	cin >> reply;
	
	return 0;
}

void openFile(ifstream& inFile){  //function for user prompt for file location and opening
	string fileName;
	
	cout << "Please enter file name: ";
	cin >> fileName;
	cout << endl;
	cout << "Opening file...." << endl;
	inFile.open(fileName.c_str());  //Open file
	
	while(!inFile){
		cout << "That was not a valid file! Please enter valid file: ";
		cin >> fileName;
		cout << endl;
		inFile.clear(); //clear error
		inFile.open(fileName.c_str());
		
	}
	cout << "File opened" << endl;
	
}

void decrypt(ifstream& inFile, int decryptKey, ofstream& outFile){ //open output file, decrypt the file and close the file
	outFile.open("decrypted.txt"); //create file to place decrypted characters into
	char inputChar, outputChar;
	
	inFile.clear();
	inFile.seekg(0);	//return to beginning of file
	inFile.get(inputChar);
	while(!inFile.eof()){
		outputChar = inputChar;
		if(inputChar > 96 && inputChar < 127){	//decrypt lowercase letters
			outputChar = inputChar + decryptKey;
			if(outputChar > 126){				//wrap characters if the shift places it out of bounds
				outputChar = outputChar - 26;
			}
			if(outputChar < 97){
				outputChar = outputChar + 26;
			}
		}
		if(inputChar > 64 && inputChar < 91){	//decrypt uppercase letters
			outputChar = inputChar + decryptKey;
			if(outputChar > 90){
				outputChar = outputChar - 26;
			}
			if(outputChar < 65){
				outputChar = outputChar + 26;
			}
		}
		outFile.put(outputChar); //output decrypted character to decrypted file
		inFile.get(inputChar);	//get next character
	}
	outFile.close();  //close file created to put the decrypted characters into
}

int findKey(ifstream& inFile){  //find the cipher shift and return the number
	int chArray[128] = {0};	//create array to hold counter for characters
	char ch;
	char maxCharacter;
	int maxCounter = 0;
	inFile.get(ch);		//get each character from file
	while(!inFile.eof()){
		if((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z')){ //increment counter in array if ch is a letter. Ignores punctuation
			chArray[ch]++;
		}
		inFile.get(ch);
	}
	for(int i = 0; i < 128; i++){	//iterate through array and find highest counter
		int counter;
		counter = chArray[i];
		if(counter > maxCounter){ //set the most common letter to max character
			maxCounter = counter;
			maxCharacter = static_cast<char>(i);
		}
	}
	
	int keyCounter = 0;
	while(maxCharacter < 'e'){ //if character is less than 'e' increment until e is reached
		maxCharacter++;
		keyCounter++;
	}
	while(maxCharacter > 'e'){//if character is more that 'e' decrease until e
		maxCharacter--;
		keyCounter--;
	}
	
	return keyCounter; //forward the key shift

}






