#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int main() { 
  cout << "Test file operation (binary and text)\n";
  
  // open input files "Bignum.txt" and "Bignum.dat" 
  // respectively in text and binary mode 
	fstream outF("Bignum.txt", ios::in);
	fstream outB("Bignum.dat",ios::in|ios::binary);

  // read and print the input from "Bignum.txt"
	while(!outF.eof())
	{
		char c = outF.get();
		cout << c;
	}

  cout << "\n";
  int num;
  cout << sizeof(num) << "\n";
	
	// read and print the input from "Bignum.dat"
	while(!outB.eof())
	{
		outB.read((char *)&num, sizeof(num));
		cout << num << endl;
	}
	
	outF.close();
  	outB.close();
	return 0;
}
