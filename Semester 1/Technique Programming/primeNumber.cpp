#include <iostream>
using namespace std;
const int size = 15;

int main(){
	int numbers[size] = {1,2,3,6,7,10,13,15,18,23,31,32,36,49,53};
	
	for(int count = 0; count < size; count++){
		bool prime = true;
		if (numbers[count] <= 1)
				prime = false;
		
		for (int i = 2;i < numbers[count]; i++){
			if (numbers[count] % i == 0 )
				prime = false;}
		
		if (prime)
			cout << numbers[count] << " is a prime number" << endl;
		else
			cout << numbers[count] << " is not a prime number" << endl;
	}
	return 0;
}

