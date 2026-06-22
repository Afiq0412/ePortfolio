#include <iostream>
using namespace std;

double getNumber(){
	return 9.5;
}

int main(){
	auto f = getNumber();
	auto g = getNumber;
	
	cout << f << endl;
	cout << g << endl;
	cout << g() << endl;
	
	return 0;
}
