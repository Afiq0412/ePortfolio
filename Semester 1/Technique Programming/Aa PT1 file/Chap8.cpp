#include <iostream>
#include <iomanip>
using namespace std;

enum month { JANUARY, FEBRUARY, MARCH, APRIL, MAY, JUNE, JULY, AUGUST, SEPTEMBER, OCTOBER, NOVEMBER, DECEMBER };

int main(){
	char months[20][20] ={"JANUARY", "FEBRUARY", "MARCH", "APRIL", "MAY", "JUNE", "JULY", "AUGUST", "SEPTEMBER", "OCTOBER", "NOVEMBER", "DECEMBER"};
	const int NUM_MONTH = 12;
	double sale[NUM_MONTH];
	double total = 0.0;
	month salary;
	
	for (salary =  JANUARY; salary <= DECEMBER; salary = static_cast<month>(salary+1)){
		cout << "Enter the salary for month " << (salary + 1) << " (" << months[salary] << ") : " ;
		cin >> sale[salary];
	}
	
	for (salary =  JANUARY; salary <= DECEMBER; salary = static_cast<month>(salary+1)){
		total += sale[salary];
	}
	
	cout << "The total salary are $" << setprecision(2) << fixed << total << endl;
	return 0;
}
