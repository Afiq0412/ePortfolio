#include <iostream>
using namespace std;

void displayAccountInfo (int);
int deposit (int&);
int withdraw (int&);

int main(){
	int balance = 200;
	char decision;

	do{ system("cls");
		displayAccountInfo(balance);
		deposit (balance);
		withdraw (balance);
		displayAccountInfo(balance);
		
		cout << "Do you want to perform another transaction? (Y/N): ";
		cin >> decision;
		cout << "\n\n";
	} while (decision == 'Y');

	return 0;
}

void displayAccountInfo (int i){ // i is 4 balance
	cout << "<<<<< My Accounts Overview >>>>>" << endl;
	cout << "Account Holder Name: User 1" << endl;
	cout << "Account Number: 1013202341" << endl;
	cout << "Balance: RM " << i << "\n\n";	
}

int deposit(int &k){ // k is 4 balance
	cout << "<<<<< Deposit Transaction >>>>>" << endl;
	cout << "Deposit of RM 500 successful.\n\n";
	k += 500;
	return k;
}

int withdraw (int &q){ // p is 4 withdraw, q is 4 balance
	cout << "<<<<< Withdrawal Transaction >>>>>" << endl;
	if (q >= 200){
		cout << "Withdrawal of RM 200 successful.\n\n";
	}
	else 
		cout << "Insufficient funds for withdrawal\n\n";
	q -= 200;
	return q;
}
