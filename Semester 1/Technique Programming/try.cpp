// name 1:Muhammad Afiq Danial bin Rozaidie A23CS0117
// name 2: Mohamed Alif Fathi bin Abdul Latif A23CS0112

#include <iostream>
using namespace std;

const int MAX_BOOKS = 1;
int displayMainMenu();
void addBook (string[MAX_BOOKS], string[MAX_BOOKS], int[MAX_BOOKS]);
void displayLibrary (string[MAX_BOOKS], string[MAX_BOOKS], int[MAX_BOOKS]);
void searchByTitle ();

int main(){
	string title[MAX_BOOKS];
	string author[MAX_BOOKS];
	int i, years[MAX_BOOKS];
	
	do{
		i = displayMainMenu();
		cout << endl;
		switch(i){
			case 1: addBook(title, author, years); break;
			case 2: displayLibrary(title, author, years); break;
			case 3: searchByTitle(); break;
		}
	}while (i != 4 );
	return 0;
	
}
int displayMainMenu(){
	int choice;
	cout << "<<<<<Library Management System>>>>>\n" << "========================================" << endl;
	cout << "1. Add a Book\n2. Display Library\n3. Search Library\n4. Quit\n" << "Enter your choice: ";
	cin >> choice;
	return choice;
}
void addBook (string title[MAX_BOOKS],string author[MAX_BOOKS], int year[MAX_BOOKS] ){
	for (int i = 0; i < MAX_BOOKS; i++){
		cout << "Enter book title: ";
		cin >> title[i];
		cout << "Enter author name: ";
		cin >> author[i];
		cout << "Enter publication year: ";
		cin >> year[i];
		cout << "\nBook added successfully!" << endl << endl;
	}

}
void displayLibrary(string title[MAX_BOOKS],string author[MAX_BOOKS], int year[MAX_BOOKS]){
	cout << "Library Contents:\n====================" << endl;
	for (int x = 0; x < MAX_BOOKS; x++){
		cout << "Title: " << title[x] << endl;
		cout << "Author: " << author[x] << endl;
		cout << "Year: " << year[x] << endl << endl;
	}
}
void searchByTitle (){
	string title[MAX_BOOKS];
	string author[MAX_BOOKS];
	int i, year[MAX_BOOKS];
	string search;
	cout << "Enter the title to search: " ;
	cin >> search;
	cout << "\nBook found:\n====================" << endl;
	for (int y = 0; y < MAX_BOOKS; y++){
		if  (search == title[y]){
			cout << "Title: " << title[y] << endl;
			cout << "Author: " << author[y] << endl;
			cout << "Year: " << year[y] << endl << endl;
		}
	}
}
