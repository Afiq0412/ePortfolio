#include <iostream>
using namespace std;

int main(){
	double weight, height, bmi;
	cout << "Enter weight in kg: ";
	cin >> weight;
	
	while (weight <= 0){
		cout << "\nInvalid Value, Please try again." << endl;
		cout << "Enter weight in kg: ";
		cin >> weight;}
		
	cout << "Enter height in m: ";
	cin >> height;
	
	while (height <= 0){
		cout << "\nInvalid Value, Please try again." << endl;
		cout << "Enter height in m: ";
		cin >> height;}
		
	bmi = weight / (height * height);
	
	if (bmi < 18.5)
		cout << "The BMI is Underweight";
	else if (bmi >= 18.5 && bmi <= 24.9)
		cout << "The BMI is Normal";
	else
		cout << "The BMI is Overweight";
	
	return 0;
}
