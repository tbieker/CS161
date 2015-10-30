//Author: Tyler Bieker
//Program: Lab 6 - Vowel and consonant counter
//Date: 10/26/2015
//Sources: None

#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>

using namespace std;

const string FILEPATH = "EnglishWords.txt"; //path of file containing words

int getVowelCount(string word);
int getConsonantCount(string word);

int main(){	
	int vowels = 0;
	int totalVowels = 0;
	double vowelPercentage;
	
	int consonants = 0;
	int totalConsonants = 0;
	double consonantPercentage;
	
	double totalLetters = 0; //number of letters in text
	
	string inputWord;
	ifstream inputFile;
	
	cout << fixed << showpoint << setprecision(1);
	
	inputFile.open(FILEPATH.c_str());	//Open file with words
	
	if(!inputFile){						//Error if no file
		cout << "File not found" << endl;
		return 1;
	}
	
	inputFile >> inputWord;
	
	while(inputFile){	//iterate through all words in file
		vowels = getVowelCount(inputWord);
		totalVowels = totalVowels + vowels;  //add vowel count to running total
		consonants = getConsonantCount(inputWord);
		totalConsonants = totalConsonants + consonants; //add consonant count to running total
		inputFile >> inputWord;		//get next word
	}
	
	totalLetters = totalVowels + totalConsonants;  //add vowels and consonants together to get total letter count
	vowelPercentage = (totalVowels / totalLetters) * 100.0;    		//divide and multiply by 100 to get percentage
	consonantPercentage = (totalConsonants / totalLetters) * 100.0;
	
	//cout << "Number of vowels: " << totalVowels << endl;
	//cout << "Number of consonants: " << totalConsonants << endl;
	cout << "Percentage of vowels: " << vowelPercentage << endl;
	cout << "Percentage of consonants: " << consonantPercentage << endl;
	
	inputFile.close();	//close file

	char reply;
	cout << "Press q to quit" << endl;
	cin >> reply;
	
	return 0;
}


/*
Functions to determine vowels and consonants. This does not determine if y is a vowel or consonant and
is treated as a consonant.
*/

int getVowelCount(string word){			//function to determine number of vowels in word
	char letter;
	int count = 0;
	int wordLength = word.length();
	
	for(int i = 0; i < wordLength; i++){	//iterate through all letters of word
		letter = word.at(i);			//read letter at position i
		letter = tolower(letter);		//make letter lowercase
		
		switch(letter){					//determine if vowel
			case 'a':
			case 'e':
			case 'i':
			case 'o':
			case 'u':
				count++;				//increase counter of vowels in word
			default:
				break;
		}
	}
	
	return count;
	
}

int getConsonantCount(string word){		//function to determine number of consonants in word
	char letter;
	int count = 0;
	int wordLength = word.length();
	
	for(int i = 0; i < wordLength; i++){	//iterate through all letters of word
		letter = word.at(i);	//read letter at position i
		letter = tolower(letter);
		
		switch(letter){				
			case 'a':
			case 'e':
			case 'i':
			case 'o':
			case 'u':
				break;		//break statement if letter is vowel
			default:
				count++; //if letter is consonant, increase count
		}
	}
	
	return count;
	
}
