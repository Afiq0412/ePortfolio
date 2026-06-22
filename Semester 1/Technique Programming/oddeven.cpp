// task: to enter the number
// to differentiate between odd number and even number
// Muhammad Afiq Danial bin Rozaidie
// A23CS0177
# include <iostream>
using namespace std;

int main ()
{
	int num;
	string decision;
	cout << "Enter your number: " ;
	cin >> num;
	
	while ( num != 0){
		if ( num % 2 == 0)
			{ cout << num << " is an even number\n" << endl;}
		else 
			{ cout << num << " is an odd number\n" << endl;}
	cout << "Enter your number again: " ;
	cin >> num;
}

	return 0;
} 
