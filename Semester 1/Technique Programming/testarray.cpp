#include <iostream>
using namespace std;

const int SIZE = 5;

int main(){
	
	int numbers[SIZE] = {1,5,10,100,16};
	int highest, lowest;
	
	highest = numbers[0];
	lowest = numbers[0];
	
	for (int count = 1; count < SIZE; count++)
	{
	if (numbers[count] > highest)
		highest = numbers[count];
	
	if (lowest > numbers[count])
		lowest = numbers[count];

}
	cout << "The highest number is "<< highest << endl;
	cout << "The highest number is " << lowest;
}

