//Author: Tyler Bieker
//Assignment 5
//Date: 10/19/2015
//Sources: StackOverflow for c_str() use 

#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>

using namespace std;

int main(){	
	ifstream resultsFile;   
	string filePath;        //User input of path for results file
	string name;			//Subjects name
	char hasSeen;			//Has seen advertisements y/n
	int age;				//Age of subject
	int score;				//Subject rating
	char ch;
	int totalCounter = 0, underNotSeenCounter = 0, underSeenCounter = 0, overNotSeenCounter = 0, overSeenCounter = 0; //counters for all groups
	double sumUnderNotSeenScore = 0, sumUnderSeenScore = 0, sumOverNotSeenScore = 0, sumOverSeenScore = 0;
	double sumTotalScore = 0;
	double avgOverSeenScore, avgOverNotSeenScore, avgUnderSeenScore, avgUnderNotSeenScore;
	double totalAvgScore;
	
	cout << "Input location path of results.txt file: ";
	cin >> filePath;										//User input of results.txt file path
	
	resultsFile.open(filePath.c_str());						//Open results.txt file
	
	if(!resultsFile){
		cout << "That is not a valid file";
		return 1;
	}
	
	cout << setprecision(2) << fixed << showpoint;
	cout << endl;
	
	resultsFile >> name;
	
	while(resultsFile){
		resultsFile >> hasSeen >> age >> score;													
		resultsFile.get(ch);	//Get \n character at end of line
		cout << left;
		cout << setw(10) << name << " " << hasSeen << " " << age << " " << score << ch;	//echo the input data
		
		if(hasSeen == 'Y' || hasSeen == 'y'){
			switch(age >= 18){
				case true: 
					sumOverSeenScore = sumOverSeenScore + score;
					overSeenCounter++;
					break;
				case false:
					sumUnderSeenScore = sumUnderSeenScore + score;
					underSeenCounter++;
					break;
			}
		}else{
			switch(age >=18){
				case true:
					sumOverNotSeenScore = sumOverNotSeenScore + score;
					overNotSeenCounter++;
					break;
				case false:
					sumUnderNotSeenScore = sumUnderNotSeenScore + score;
					underNotSeenCounter++;
					break;
			}
		}
		
		sumTotalScore = sumTotalScore + score;
		totalCounter++;
		resultsFile >> name;
	}
	
	avgOverSeenScore = sumOverSeenScore / overSeenCounter;					//Find averages for groups
	avgUnderSeenScore = sumUnderSeenScore / underSeenCounter;
	avgOverNotSeenScore = sumOverNotSeenScore / overNotSeenCounter;
	avgUnderNotSeenScore = sumUnderNotSeenScore / underNotSeenCounter;
	
	totalAvgScore = sumTotalScore / totalCounter; //calculate average score for all subjects
	cout << setw(65) << "Average score for subjects under 18 who have not seen the ad:" << avgUnderNotSeenScore << endl;
	cout << setw(65) << "Average score for subjects under 18 who have seen the ad:" << avgUnderSeenScore << endl;
	cout << setw(65) <<"Average score for subjects 18 and over who have not seen the ad:" << avgOverNotSeenScore << endl;
	cout << setw(65) <<"Average score for subjects 18 and over who have seen the ad:" << avgOverSeenScore << endl;
	
	cout << setw(65) << "Average score for all groups: " << totalAvgScore;
	
	resultsFile.close();
	
	cout << "\nEnter 'q' to quit: ";
	cin >> ch; //Stop program flash
	cout << "Goodbye";
	return 0;
}
