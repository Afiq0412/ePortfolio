////////////////////// Test 2, 2023/2024 (Sem 1) //////////////////////
//// QUESTION 2
//// Name: MUHAMMAD AFIQ DANIAL BIN ROZAIDIE
//// Matric No: A23CS0117
//// Date / Day: 4/1/2024
///////////////////////////////////////////////////////////////////////

// Task 7. Directives, library, header, etc.
#include <iostream>
#include <iomanip>
using namespace std;

// Task 6. Function prototypes
double calculateLateFees(int);
void displayMenu();
void displayLibraryInfo();
int getUserInput(int&);

// Task 5. Main function
int main(){
	int option, days;
	do{
		displayMenu();
		cout << "Enter your choice (1-3): " ;
		cin >> option;
		
		switch (option){
			case 1 : getUserInput(days);
					 cout << "Late fees: RM"  << setprecision(2) << fixed << calculateLateFees(days) << endl;
					 break;
			case 2 : displayLibraryInfo(); break;
			case 3 : cout << "Exiting the program. Thank you!" << endl; break;
		}
		if (option > 3 || option < 1)
			cout << "Invalid choice. Please enter a number between 1 and 3" << endl;
	} while (option != 3);
	return 0;
}

// Task 1. Function calculateLateFees  
double calculateLateFees(int day){
	double fee;
	if (day <= 7)
		fee = day * 0.5;
	else if (day < 7 && day <= 14)
		fee = 3.5 + (day -7) * 1;
	else
		fee = 10.5 + (day - 14) * 2;
	return fee;
}

// Task 2. Function displayMenu 
void displayMenu(){
	cout << "************ Library Book Checkout System ************" << endl;
	cout << "1. Calculate Late Fees\n2. Display Library Information\n3. Quit" << endl;
	
}

// Task 3. Function displayLibraryInfo 
void displayLibraryInfo(){
	cout << "************ Library Information ************" << endl;
	cout << "Library Name: UTM Library" << endl;
	cout << "Address: Skudai, Johor" << endl;
	cout << "Contact: (123) 456 7890" << endl;
}

// Task 4. Function getUserInput with reference parameter
int getUserInput(int& day){
	cout << "Enter the number of days the book is overdue: ";
	cin >> day;	
	return day;
}
