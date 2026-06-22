#include <iostream>
using namespace std;

int main (){
	
	int i = 12, repeat;
	string months [i] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "Novermber", "December"};
	
	cout << "Please enter number of the months: ";
	cin >> i;
	
	cout << "\nYour month is " << months[--i] << endl << endl;
	
	cout << "Would you like to try agian?\nif yes click 1\nif no click 0\n==";
	cin >> repeat;
	
	while (repeat == 1){
		cout << "Please enter number of the months: ";
		cin >> i;
	
		cout << "\nYour month is " << months[--i] << endl << endl;
	
		cout << "Would you like to try agian?\nif yes click 1\nif no click 0\n==";
		cin >> repeat;
	}
	
	return 0;
}
