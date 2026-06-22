#include <iostream>
using namespace std;

int main()
{
	double speed, hours, distance;
	cout << "What is the speed of the vehicle in km/h? " ;
	cin >> speed;
	
	while (speed < 1){
		cout << "Please enter a non-negative number for speed: ";
		cin >> speed;
	}
	
	cout << "For how many hours has it travelled? ";
	cin >> hours;
	
	while (hours < 1){
		cout << "Please enter a 1 or greater for hours: " ;
		cin >> hours;}
	
	cout << endl << "Hour\tDistance Travelled in km" << endl;
	cout << "----------------------------------" << endl;
	
	for (int i = 1;i <= hours; i++){
		distance = speed * i;
		cout << i << "\t" << distance << endl;

	}
	return 0;
}
