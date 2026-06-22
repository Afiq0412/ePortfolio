#include <iostream>
using namespace std;

void displayStars(int = 10, int = 1);
	int main (){
		cout << "PROGRAM OUTPUT" << endl;
		displayStars();
		cout << endl;
	
		displayStars(5);  
		cout << endl;
	
		displayStars(7,3); 
		return 0;
	}
	
void displayStars(int cols, int rows){
	for (int down = 0; down < rows; down++){
		for (int across = 0; across < cols; across++)
			cout << "*";
		cout << endl;
	}
	
}
