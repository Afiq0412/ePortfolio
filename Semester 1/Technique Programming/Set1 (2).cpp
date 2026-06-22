# include <iostream>
using namespace std;

int main(){
	
	string name1, name2, matric1, matric2;

	cout << "Enter member 1 name: ";
	cin >> name1;
	cout << "Enter member 1 matric number: ";
	cin >> matric1;
	cout << "Enter member 2 name: ";
	cin >> name2;
	cout << "Enter member 2 matric number: ";
	cin >> matric2;

	cout << "\nAssignment 1\n-----------------\nCourse: SECJ 1013 Programming Technique 1" << endl;
	cout << "Section: 03\nProgram: Bachelor of Computer Science(Data Engineering)" << endl;
	cout << "Member:\n" << name1 << " (" << matric1 << ")" << endl;
	cout << name2 << " (" << matric2 << ")" << endl;
	
	return 0;
}
