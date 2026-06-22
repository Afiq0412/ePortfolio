#include <iostream>
#include <cstring>
using namespace std;

int main()
{
	int x = 25;
	int *intptr = &x;
	cout << *intptr << endl;
	cout << intptr;
	return 0;
}

