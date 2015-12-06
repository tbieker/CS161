//Author: Tyler Bieker
//Assignment 10
//Date: 12/04/2015
//Sources: www.cplusplus.com

#include <fstream>
#include <iostream>
#include <string>

using namespace std;

const int ARRAY_SIZE = 1000;

//assignment 9 strings
//string bookTitle[ARRAY_SIZE];
//string bookAuthor[ARRAY_SIZE];

//assignment 10 convert to struct
struct Book{
	string title;
	string author;
};

Book books[ARRAY_SIZE];

//assignment 9
int loadData(string pathname);	//open the file located at pathname
void showAll(int count);			//display in format book_name(Author) for the count read into loadData
int showBooksByAuthor(int count, string title); //search function by author
int showBooksByTitle(int count, string title); //search function by author

//assignment 10 additional functions
void sortByTitle(int count);
void sortByAuthor(int count);

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
	
	sortByTitle(count);
	
	for(int i = 0; i < count; i++){
		cout << books[i].title;
		cout << " (" << books[i].author << ")";
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
		getline(inFile, books[count].title);
		getline(inFile, books[count].author);
		count++;
	}
	inFile.close();
	return count;
}

int showBooksByAuthor(int count, string title){
	unsigned int titleIndex;	//index location of where author is found
	int counter = 0;	//counter for number of books found in search
	sortByAuthor(count);
	
	for(int i = 0; i < count; i++){
		titleIndex = books[i].author.find(title);
		if(titleIndex != string::npos){		//if titleIndex does not return npos(value for not found in .find() function) output title and increment counter
			cout << books[i].title << " (" << books[i].author << ")" << endl;
			counter++;
		}
	}
	
	return counter;	//return count of books found with that author
}

int showBooksByTitle(int count, string title){
	unsigned int titleIndex;	//index location of where author is found
	int counter = 0;	//counter for number of books found in search
	sortByTitle(count);
	
	for(int i = 0; i < count; i++){
		titleIndex = books[i].title.find(title);
		if(titleIndex != string::npos){		//if titleIndex does not return npos(value for not found in .find() function) output title and increment counter
			cout << books[i].title << " (" << books[i].author << ")" << endl;
			counter++;
		}
	}
	
	return counter;	//return count of books found with that title
}

void sortByTitle(int count){
	Book temp;
	
	for(int i = 0; i < count; i++){
		for(int j = 0; j < count - i; j++){
			if(books[j].title > books[j + 1].title){
				temp = books[j];
				books[j] = books[j + 1];
				books[j + 1] = temp;
			}
		}
	}
}

void sortByAuthor(int count){
	Book temp;
	
	for(int i = 0; i < count; i++){
		for(int j = 0; j < count - i; j++){
			if(books[j].author > books[j + 1].author){
				temp = books[j];
				books[j] = books[j + 1];
				books[j + 1] = temp;
			}
		}
	}
}

	
	
