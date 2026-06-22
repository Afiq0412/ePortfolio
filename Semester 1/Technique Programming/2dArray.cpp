#include <iostream>
using namespace std;
const int ROWS = 2;
const int COLM = 2;
void display(string [ROWS][COLM]);

int main(){
	string names[ROWS][COLM] = {{"ALI", "ABU"},{"MAN","MIN"}};

	display(names);
	return 0;
}

void display(string name[ROWS][COLM]){
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
