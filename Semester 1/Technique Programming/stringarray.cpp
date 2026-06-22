#include <iostream>
#include <iomanip>
using namespace std;

int main(){
/*	double scores[3][5] ={{88, 97, 79, 86, 94},
						{86, 91, 78, 79, 84},
						{82, 73, 77, 82, 89}};
	
	for (int i = 0; i < 3; i++){
		if (i == 0)
			for (int k = 0; k<3; k++)
				cout << scores[k][0] << " " ;*/

/*cout << "*" << -17 << "*" << endl;
cout << "*" << setw(6) << -17 << "*" << endl << endl;
cout << "*" << "Hi there!" << "*" << endl;
cout << "*" << setw(9) << "Hi there!" << "*" << endl;
cout << "*" << setw(3) << "Hi there!" << "*" << endl;*/

cout << "*" << -17 << "*" << endl;
cout << "*" << setw(6) << -17 << "*" << endl;
cout << left;
cout << "*" << setw(6) << -17 << "*" << endl << endl;
cout << "*" << "Hi there!" << "*" << endl;
cout << "*" << setw(20) << "Hi there!" << "*" << endl;
cout << right;
cout << "*" << setw(20) << "Hi there!" << "*" << endl;
	return 0;
}

