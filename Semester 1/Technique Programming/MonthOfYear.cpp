#include <iostream>
using namespace std;
const int MONTHS = 12;

int main(){
	int days[MONTHS] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	
	for (int count = 0; count < MONTHS; count++){
		cout << "Month " << count+1 << " @";
		
		switch(count){
		case 0 : cout <<" January"; break;
		case 1 : cout <<" February";break;
		case 2 : cout <<" March" ;break;
		case 3 : cout <<" April" ;break;
		case 4 : cout <<" May" ;break;
		case 5 : cout <<" June";break;
		case 6 : cout <<" July" ;break;
		case 7 : cout <<" August" ;break;
		case 8 : cout <<" September";break;
		case 9 : cout <<" October" ;break;
		case 10 : cout <<" November";break;
		default : cout <<" December";break;}
		
	if (count == 1)
		cout <<" has " << days[count] << " days or " << days[count] +1 << " days.\n";
	else
		cout <<" has " << days[count] << " days.\n"; 
	}
	return 0;
}
