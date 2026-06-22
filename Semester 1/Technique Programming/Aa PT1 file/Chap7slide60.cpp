#include <iostream>
#include <iomanip>
using namespace std;

double *sale(int number){
	double *arraysales;
	
	if (number <= 0)
		return NULL;
	
	arraysales = new double[number];
	
	cout << "Enter the sales figures below" << endl;
	for (int count = 0; count < number ; count++){
		cout << "Day " << (count+1) << ": ";
		cin >> arraysales[count];
	}
	return arraysales;
}

int main (){
	double *sales, total = 0.0, average;
	int numDays, count;
	
	cout << "How many days of sales figures do you wish ";
	cout << "to process? ";
	cin >> numDays;
	
	sales = new double[numDays];
	sales = sale(numDays);
	
	for (count = 0; count < numDays; count++){
		total += sales[count];
	}
	average = total / numDays;
	
	cout << fixed << showpoint << setprecision(2);
	cout << "\n\nTotal Sales: $" << total << endl;
	cout << "Average Sales: $" << average << endl;
	
	delete [] sales;
	sales = 0;

	return 0;
}
