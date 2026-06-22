#include <iostream>
#include <cmath>
using namespace std;

int distance(int, int, int, int);
void listvalue(char [3], int = 1, int = 3);

int main(){
	
	int x1,y1,x2,y2,x3,y3;
	x1 = 1;y1 = 3;x2 = 2;y2 = 6;x3 = 5; y3 = 4;
	
/*	cout << "A(" << x1 << ", " << y1 << "), " ;
	cout << "B(" << x2 << ", " << y2 << "), and " ;
	cout << "C(" << x3 << ", " << y3 << ")\n" << endl ;*/
	char arr[3];
	arr[3] = {'A','B','C'};
	
	
//	cout << "\tx\ty" << endl;
	listvalue();
//	listvalue(x2, y2);
//	listvalue(x3, y3);
	
/*	cout << "\nAB = " ; distance(x2, x1, y2, y1);
	cout << "AC = " ;distance(x3, x1, y3, y1);
	cout << "BC = " ; distance(x3, x2, y3, y2);*/
	
	system("pause");
	return 0;
}

int distance(int a, int b, int c, int d){
	
	float result;
	result = sqrt(pow((a - b ), 2) + pow((c - d ), 2) );
	cout << result << endl;
}

void listvalue(char arr[q], int i, int j){
	
	for ()
	if (i==1 && j==3)
		cout << "A\t" << i <<"\t" << j << endl ;
	else if (i==2 && j==6)
		cout << "B\t" << i <<"\t" << j << endl ;
	else
		cout << "C\t" << i <<"\t" << j << endl ;
}
