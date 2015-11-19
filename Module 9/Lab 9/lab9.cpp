//Author: Tyler Bieker
//Lab 9
//Date: 11/18/2015
//Sources:

#include <fstream>
#include <iomanip>
#include <iostream>
#include <string>

using namespace std;

const int STUDENT_NUMBER = 20;

struct Student {
   string name;
   int asgn[10];
   int quiz[10];
   int lab[10];
   int midterm;
   int finalTest;
};

void openFile(ifstream& inFile);
void loadData(Student students[STUDENT_NUMBER], ifstream& inFile);
void printData(Student students[STUDENT_NUMBER]);
int computeFinalGrade(Student stu);
int findQuiz10Average(Student students[STUDENT_NUMBER]);

int main(){
	ifstream inFile;
	
	openFile(inFile);
	
	Student students[20];
	
	loadData(students, inFile);
	printData(students);
	
	cout << "Alice's final grade is: " << computeFinalGrade(students[0]);
	cout << endl;
	
	cout << "The class average for quiz 10 is: " << findQuiz10Average(students);
	cout << endl << endl;
	
	inFile.close();
	
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

void loadData(Student students[STUDENT_NUMBER], ifstream& inFile){	//Load data from file into students struct array
	cout << "Loading data..." << endl;
	for(int i = 0; i < 19; i++){				//iterate through all students in array
		inFile >> students[i].name;
		for(int j = 0; j < 9; j++){				//load all 10 assignments
			inFile >> students[i].asgn[j];
		}	
		for(int k = 0; k < 9; k++){				//load all quizzes
			inFile >> students[i].quiz[k];
		}
		for(int l = 0; l < 9; l++){				//load all labs
			inFile >> students[i].lab[l];
		}
		inFile >> students[i].midterm;		//load midterm
		inFile >> students[i].finalTest;	//load final test
		
	}
	cout << "Data loaded" << endl;
}

void printData(Student students[STUDENT_NUMBER]){	//Print out all data loaded into students
	cout << endl;
	for(int i = 0; i < (STUDENT_NUMBER - 1); i++){				
		cout << left;
		cout << "Name";
		cout << endl;
		cout << students[i].name;
		cout << endl;
		
		cout << "Assignments";
		cout << endl;
		for(int j = 0; j < 9; j++){				
			cout << students[i].asgn[j];
			cout << " ";
		}
		cout << endl;
		
		cout << "Quizzes";
		cout << endl;
		for(int k = 0; k < 9; k++){				
			cout << students[i].quiz[k];
			cout << " ";
		}
		cout << endl;
		
		cout << "Labs";
		cout << endl;
		for(int l = 0; l < 9; l++){				
			cout << students[i].lab[l];
			cout << " ";
		}
		cout << endl;
		
		cout << "Midterm";
		cout << endl;
		cout << students[i].midterm;
		cout << endl;
		
		cout << "Final";
		cout << endl;	
		cout << students[i].finalTest;
		cout << endl;
		
	}
}

int computeFinalGrade(Student stu){
	return 100;
}

int findQuiz10Average(Student students[STUDENT_NUMBER]){
	int sum = 0;
	int avg;
	
	for(int i = 0; i < (STUDENT_NUMBER - 1); i++){	//add all of the quiz 10 results
		sum = sum + students[i].quiz[9];
	}
	avg = sum / STUDENT_NUMBER;		//divide the total of all quiz 10 results and divide by the number of students
	return avg;		//return the class average of quiz 10
}
