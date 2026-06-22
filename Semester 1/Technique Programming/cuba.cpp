#include <iostream>
using namespace std;

int main(){
	int a = 1, b = 2,*ptr;
//	ptr = &b;
//	cout << a << " " << b << " " << ptr << " " << *ptr << endl;
//
//	*ptr = a;
//	cout << a << " " << b << " " << ptr  << " " << *ptr << endl;
//
//	ptr = &b;
//	cout << a << " " << b << " " << ptr  << " " << *ptr << endl;
//
//	*ptr = a + b;
//	cout << a << " " << b << " " << ptr  << " " << *ptr << endl;
//
//	*ptr = b;
//	cout << a << " " << b << " " << ptr << " "  << *ptr << endl;
	a = *ptr;
	cout << "a = " << a << endl;
//	cout << "b = " << b << endl;
//	cout << "ptr = " << ptr << endl;
//	cout << "*ptr = " << *ptr << endl;
	return 0;
}
