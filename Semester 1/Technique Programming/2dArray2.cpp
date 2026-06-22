#include <iostream>
using namespace std;
const int ROWS = 3;
const int COLM = 3;


int main(){
	int a[ROWS][COLM] = {{1,0,0 },{0,1,0},{0,0,1}};
	int b[ROWS - 1][COLM] = {{2,0,0 },{0,0,2}};

	display(names);
	return 0;
}

int add(int arr1 name[ROWS][COLM],int arr2[ROWS][COLM]){
	for(int x = 0; x < ROWS; x++){
		if( x == 0)
			cout << "From Malaysia:" << endl;
		else 
			cout << "Outside Malaysia:" << endl;
		
		for(int y = 0; y < COLM ;y++){
			cout << name[x][y] << endl;
		}
	}
	
}
