//Author: Tyler Bieker
//Assignment 9
//Date: 11/20/2015
//Sources: www.cplusplus.com

#include <fstream>
#include <iostream>
#include <string>

using namespace std;

const int ARRAY_SIZE = 1000;

string bookTitle[ARRAY_SIZE];
string bookAuthor[ARRAY_SIZE];

int loadData(string pathname);	//open the file located at pathname
void showAll(int count);			//display in format book_name(Author) for the count read into loadData
int showBooksByAuthor(int count, string title); //search function by author
int showBooksByTitle(int count, string title); //search function by author


int main(){
	string path; 		//path of file
	char selection;	//selection choice Q, A, T, S
	bool runProg = true;
	
	cout << "Welcome to Tyler's library database." << endl;
	
	cout << "Enter the name of the backup file: ";
	cin >> path;
	cout << endl;
	
	int bookCount = loadData(path);
	if(bookCount >= 0){
		cout << bookCount << " records loaded successfully." << endl;
	}else{
		cout << "File not found" << endl;
		return 1;
	}
	
	while(runProg){	//run the main program with 4 options: show all, quit and search by title or author
		string title, author;
		cout << endl;
		cout << "Enter Q to (Q)quit, Search (A)uthor, Search (T)itle, (S)how All: ";
		cin >> selection;
		switch(selection){
			case 'a':
			case 'A':
				cout << "Author: ";
				cin >> author;
				cout << showBooksByAuthor(bookCount, author) << " records found." << endl;
				break;
			case 's':
			case 'S':
				showAll(bookCount);
				break;
			case 't':
			case 'T':
				cout << "Title: ";
				cin >> title;
				cout << showBooksByTitle(bookCount, title) << " records found." << endl;
				break;
			case 'q':
			case 'Q':
				runProg = false;
				break;
		}
	}
	
	return 0;
}

void showAll(int count){		//print all books in book_title(author) format
	for(int i = 0; i < count; i++){
		cout << bookTitle[i];
		cout << " (" << bookAuthor[i] << ")";
		cout << endl;
	}
}

int loadData(string pathname){	//load all books into arrays bookTitle[] and bookAuthor[]
	int count = 0; 
	ifstream inFile;
	inFile.open(pathname.c_str());
	if(!inFile){		//return error if file not loaded
		return -1;
	}
	while(!inFile.eof()){
		getline(inFile, bookTitle[count]);
		getline(inFile, bookAuthor[count]);
		count++;
	}
	inFile.close();
	return count;
}

int showBooksByAuthor(int count, string title){
	int titleIndex;	//index location of where author is found
	int counter = 0;	//counter for number of books found in search
	
	for(int i = 0; i < count; i++){
		titleIndex = bookAuthor[i].find(title);
		if(titleIndex != string::npos){		//if titleIndex does not return npos(value for not found in .find() function) output title and increment counter
			cout << bookTitle[i] << " (" << bookAuthor[i] << ")" << endl;
			counter++;
		}
	}
	
	return counter;	//return count of books found with that author
}

int showBooksByTitle(int count, string title){
	int titleIndex;	//index location of where author is found
	int counter = 0;	//counter for number of books found in search
	
	for(int i = 0; i < count; i++){
		titleIndex = bookTitle[i].find(title);
		if(titleIndex != string::npos){		//if titleIndex does not return npos(value for not found in .find() function) output title and increment counter
			cout << bookTitle[i] << " (" << bookAuthor[i] << ")" << endl;
			counter++;
		}
	}
	
	return counter;	//return count of books found with that title
}



	
	
