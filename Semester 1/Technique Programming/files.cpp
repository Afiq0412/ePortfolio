#include <iostream>
#include <fstream>
using namespace std;

int main(){
//	ifstream inpt;
//	inpt.open("tests.txt");
	ofstream outp;
	outp.open("try.txt");
	
	cout << "Writing the data\n";

	outp << "My name is Afiq" << endl;
	outp << "------------------" << endl;
	outp << "\nCongratulation...you did well" << endl;
	
//	inpt.close();
	outp.close();
	
	cout << "Already done!" << endl;
	return 0;
}
