#include <iostream>
using namespace std;

int days(int,int,int);

int main(){
	int years, months, weeks;
	cout << "Enter years: ";
	cin >> years;
	cout << "Enter months: ";
	cin >> months;
	cout << "Enter weeks: ";
	cin >> weeks;
	days(years, months, weeks);
	return 0;
}

	int days(int x,int y, int z){
		cout << "Enter years: ";
	cin >> years;
	cout << "Enter months: ";
	cin >> months;
	cout << "Enter weeks: ";
	cin >> weeks;
		cout << endl <<"We are in a year: "<< x << "\tOn month: " << y << "\tIn a weeks: " << z << endl;
}


