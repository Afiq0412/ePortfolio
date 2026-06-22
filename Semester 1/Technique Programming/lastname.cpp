#include <iostream>
#include <cctype>
using namespace std;
int main()
{
	const int size= 20;
	char first_name[size], last_name[size]; 
	string full_name;

	cout << "Enter first name: ";
	cin.getline (first_name, size);
	cout << "Enter last name: ";
	cin.getline (last_name, size);
	
	full_name= string(first_name) + " " + string(last_name);
	cout << "Your full name is " << full_name << endl;
	return 0;

}
