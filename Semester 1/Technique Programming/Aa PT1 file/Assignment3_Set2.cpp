// Name 1: Muhammad Afiq Danial bin Rozaidie A23CS0117
// Name 2: Mohamed Alif Fathi bin Abdul Latif A23CS0112

#include <iostream>
using namespace std;

#define MAX_OPERATIONS 100

int multiplyUsingAddition(int, int);
void displayMainMenu();
void performMultiplication(int [], int [], int &);
void displayResults(int [], int [], int);

int main()
{
	int operands1[MAX_OPERATIONS];
	int results[MAX_OPERATIONS];
	int operationCount = 0;
	int choice;
	
	do
	{
		displayMainMenu();
		cout << "Enter your choice: ";
		cin >> choice;
		
		switch (choice)
		{
			case 1:
				performMultiplication(operands1, results, operationCount);
				break;
				
			case 2:
				if (operationCount == 0)
				{
					cout << endl << "Please perform multiplication first before display the results." << endl << endl << endl;
					break;
				}
				displayResults(operands1, results, operationCount);
				break;
				
			case 3:
				cout << endl << "Goodbye!";
				break;
			
			default:
				cout << endl << "Invalid choice. Please enter a valid option." << endl << endl;
		}
		
	}
	while (choice != 3);
	
	return 0;
}

int multiplyUsingAddition(int a, int b)
{
	int result;
	
	for (int i = 0 ; i < a ; i++)
	{
		result += b;
	}
	
	return result;
}

void displayMainMenu()
{
	cout << "<<<<<Main Menu>>>>>" << endl << endl;
	cout << "=============================" << endl << endl;
	cout << "1. Perform Multiplication" << endl << endl;
	cout << "2. Display Results" << endl << endl;
	cout << "3. Quit" << endl << endl;
}

void performMultiplication(int operands1[], int results[], int &operationCount)
{
	int numOperand;
	int operand;
	int result = 1;
	
	cout << endl << "Enter the number of operands for multiplication: ";
	cin >> numOperand;
	
	while (numOperand < 2)
	{
		cout << endl << "Invalid number of operands. Please enter number more than 1." << endl;
		cin >> numOperand;
	}
	
	for (int i = 0 ; i < numOperand ; i++)
	{
		cout << endl << "Enter operand " << i+1 << ": ";
		cin >> operand;
		
		result = multiplyUsingAddition(operand, result);
		operands1[operationCount] = numOperand;
	}
	
	results[operationCount] = result;
	operationCount++;
	
	cout << endl << "Multiplication performed successfully!" << endl << endl << endl;
}

void displayResults(int operands1[], int results[], int operationCount)
{
	cout << endl << endl << "Results of Mathematical Operations:" << endl << endl;
	cout << "========================================" << endl << endl;
	
	for (int i = 0 ; i < operationCount ; i++)
	{
		cout << "Operation " << i+1 << ": " << results[i] << " (Operands: " << operands1[i] << ")" << endl << endl << endl;
	}
	
}