//Author: Tyler Bieker
//Lab 5
//Date: 10/20/2015
//Sources: http://www.cplusplus.com/reference/istream/istream/seekg/ 

#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>

using namespace std;

int main(){
	//const string FILEPATH = "/home/tbieker/Documents/Programming/CS161/Module 5/Lab/EnglishWords.txt"; //Enter filepath of text file
	
	ifstream wordsText;
	string longestWord = ""; //store the longest word while looking through file 
	string currentWord;
	int wordLength;
	int counter = 0;
	
		
	//wordsText.open(FILEPATH.c_str);
	wordsText.open("/home/tbieker/Documents/Programming/CS161/Module 5/Lab 5/EnglishWords.txt");
	
	
	if(!wordsText){
		cout << "File not found";
		return 1;
	}
	
	wordsText >> currentWord;
	
	cout << "One letter words" << endl; //Print one letter words from file


	while(wordsText){
		wordLength = currentWord.length();
		
		if(wordLength > longestWord.length()){ //evaluate for longest word in file
			longestWord = currentWord;
		}
		
		if(wordLength == 1){
			cout << currentWord << endl; //Print all words with one letter
		}
		
		wordsText >> currentWord;
		
	}

	cout << "Longest word: " << longestWord << "  Length: " << longestWord.length() << endl;
	
	cout << left;
	cout << setw(8) << "Length" << "Number of words" << endl;
	
	for(int i = 1; i <= longestWord.length(); i++){				//repeat throught the word list (i) times until longest length is reached
	
		wordsText.clear();							//clear wordsText eof
		wordsText.seekg(0, wordsText.beg);			//set pointer to beginning of file
	
		while(wordsText){							//count through list for all word lengths that equal (i)
			if(currentWord.length() == i){
				counter++;
			}
			wordsText >> currentWord;
		}
		
		cout << setw(8) << i << counter << endl;
		counter = 0;		//reset counter to zero for next loop

	}
	
	wordsText.close();
	return 0;
}		//Most common length is 8 letters

