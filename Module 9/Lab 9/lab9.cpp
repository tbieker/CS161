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
   int finalGrade;
};

void openFile(ifstream& inFile);
void loadData(Student students[STUDENT_NUMBER], ifstream& inFile);
void printData(Student students[STUDENT_NUMBER]);
void computeFinalGrade(Student students[STUDENT_NUMBER]);
int findQuiz10Average(Student students[STUDENT_NUMBER]);

int main(){
	ifstream inFile;
	
	openFile(inFile);
	
	Student students[STUDENT_NUMBER];	//array to store student data
	
	loadData(students, inFile);
	printData(students);
	computeFinalGrade(students);
	
	cout << "Alice's final grade is: " << students[0].finalGrade;		 //Question 1
	cout << endl;
	
	cout << "The class average for quiz 10 is: " << findQuiz10Average(students); //Question 2
	cout << endl << endl;
	
	int current;
	int lowestScore = 100;
	int lowestNumber;
	for(int j = 0; j < STUDENT_NUMBER; j++){	//calculate lowest final grade in the class. Question 3
		current = students[j].finalGrade;
		if(current < lowestScore){
			lowestScore = current;
			lowestNumber = j;
		}
	}
	
	cout << "The lowest grade in the class is: " << students[lowestNumber].name;						 //Question 3
	cout << endl;
	
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
		inFile.clear(); //clear error
		cin >> fileName;
		cout << endl;
		inFile.open(fileName.c_str());
		
	}
	cout << "File opened" << endl;
	
}

void loadData(Student students[STUDENT_NUMBER], ifstream& inFile){	//Load data from file into students struct array
	cout << "Loading data..." << endl;
	inFile.ignore(1000, '\n');	//ignore first line of the file
	for(int i = 0; i < 20; i++){				//iterate through all students in array
		inFile >> students[i].name;
		for(int j = 0; j < 10; j++){				//load all 10 assignments
			inFile >> students[i].asgn[j];
		}	
		for(int k = 0; k < 10; k++){				//load all quizzes
			inFile >> students[i].quiz[k];
		}
		for(int l = 0; l < 10; l++){				//load all labs
			inFile >> students[i].lab[l];
		}
		inFile >> students[i].midterm;		//load midterm
		inFile >> students[i].finalTest;	//load final test
		
	}
	cout << "Data loaded" << endl;
}

void printData(Student students[STUDENT_NUMBER]){	//Print out all data loaded into students
	cout << endl;
	for(int i = 0; i < (STUDENT_NUMBER); i++){				
		cout << left;
		cout << "Name";
		cout << endl;
		cout << students[i].name;
		cout << endl;
		
		cout << "Assignments";
		cout << endl;
		for(int j = 0; j < 10; j++){				
			cout << setw(4) << students[i].asgn[j];
		}
		cout << endl;
		
		cout << "Quizzes";
		cout << endl;
		for(int k = 0; k < 10; k++){				
			cout << setw(4) << students[i].quiz[k];
		}
		cout << endl;
		
		cout << "Labs";
		cout << endl;
		for(int l = 0; l < 10; l++){				
			cout << setw(4) << students[i].lab[l];
		}
		cout << endl;
		
		cout << "Midterm exam";
		cout << endl;
		cout << students[i].midterm;
		cout << endl;
		
		cout << "Final exam";
		cout << endl;	
		cout << students[i].finalTest;
		cout << endl << endl;
	}
}

void computeFinalGrade(Student students[STUDENT_NUMBER]){		//Not completed yet
	for(int x = 0; x < STUDENT_NUMBER; x++){
		int assignSum = 0, quizSum = 0, labSum = 0;
		
		for(int i = 0; i < 10; i++){			//total of assignments
			assignSum = assignSum + students[x].asgn[i];
		}
		for(int j = 0; j < 10; j++){			//total of quizzes
			quizSum = quizSum + students[x].quiz[j];
		}
		for(int k = 0; k < 10; k++){			//total of labs
			labSum = labSum + students[x].lab[k];
		}
		double assignPercentage = ((assignSum / 10) / 100.0) * 30;	
		double quizPercentage = ((quizSum / 10) / 100.0) * 20;
		double labPercentage = ((labSum / 10) / 100.0) * 15;
		double finalPercentage = (students[x].finalTest / 100.0) * 15;
		double midtermPercentage = (students[x].midterm / 100.0) * 15;
		students[x].finalGrade = assignPercentage + quizPercentage + labPercentage + finalPercentage + midtermPercentage + 5;  //assign to final grade in student struct
	}
}

int findQuiz10Average(Student students[STUDENT_NUMBER]){
	int sum = 0;
	int avg;
	
	for(int i = 0; i < (STUDENT_NUMBER); i++){	//add all of the quiz 10 results
		sum = sum + students[i].quiz[9];
	}
	avg = sum / STUDENT_NUMBER;		//divide the total of all quiz 10 results and divide by the number of students
	return avg;		//return the class average of quiz 10
}
