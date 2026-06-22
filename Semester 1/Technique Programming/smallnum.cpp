#include <iostream>
using namespace std;
const int SIZE = 8;
void test(int[], int);

int main (){
	int index;
	int num [SIZE] = {1,2,4,5,10,100,2,-22};
	test(num ,SIZE);
	
	return 0;
}

void test (int num [] , int SIZE){	
	int index;
	int smallest = num [0];
	for (int i = 0 ;i < SIZE;i++){
		if (smallest > num [i] )
			smallest = num [i];
			index = i;}

	cout << "The smallest number is " << smallest << endl;
	cout << "The index of the smallest number is " << index;
}

