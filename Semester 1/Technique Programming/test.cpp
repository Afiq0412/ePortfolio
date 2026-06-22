# include <iostream>
# include <iomanip>
using namespace std;

int main(){
	double x = 156.74, y = 235.765, z = 9525.9874;
	cout << setprecision(5) << x << endl;
	cout << setprecision(3) << x << endl;
	cout << setprecision(2) << x << endl;
	cout << setprecision(1) << x << endl;
	cout << "-----------------------------"<< endl;
	cout << showpoint << fixed << setprecision(9);
	cout << x << endl << y << endl << z << endl;
	cout << "-----------------------------"<< endl;
	cout << fixed << showpoint << setprecision(9);
	cout << x << endl << y << endl << z << endl;
	return 0;

}    

