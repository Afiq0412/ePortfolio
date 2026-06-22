#include <iostream>
using namespace std;

int main(){
	
	int num, fac = 1;
	cout << "enter num: ";
	cin >> num ;
	cout << num << "*";
	for(int i = 1; i<=num ;i++){
		if ( i < num)
			cout << num - i << "*";
		else
			cout <<  i ;
	
			 
		fac = fac * i;
	
	}
	cout << fac << endl;
	cout << num ;
	
	return 0;
}
