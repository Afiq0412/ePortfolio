#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int main() { 
  cout << "Test file operation (binary and text)\n";
  
  // open output files "Bignum.txt" and "Bignum.dat" 
  // respectively in text and binary mode   
	fstream outF("Bignum.txt", ios::out);
	fstream outF2("Bignum.dat",ios::out|ios::binary);
	
  // write the numbers 10, 11, ..., 90 million into 
  // "Bignum.txt" and "Bignum.dat" 
  for (int i = 1; i < 10; i++) {
    int num = i * 10000000;
    cout << num << "\n";
    
    outF << num << endl;
    outF2.write((char *)&num, sizeof(num));
  }
  	outF.close();
  	outF2.close();
  	
  	return 0;
}
