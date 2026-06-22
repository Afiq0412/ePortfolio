# include <iostream>
using namespace std;

int main(){
	int height;
	cout << "Enter your height in cm: ";
	cin >> height;
	
	if ( height > 180)
		cout << "Very tall";
	else if ( height < 130)
		cout << "Quite small";
	else
		cout << "Average height";
	
	return 0;
}
