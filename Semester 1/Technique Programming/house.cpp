/* Afiq Danial
how to make a house using an asterick*/

#include <iostream>
using namespace std;

void roof(int = 5);
void wall(int = 5, int= 5);
	
	int main (){
		roof();
		wall();
		cout << endl;
	
		system("pause");
		return 0;
	}

// make a roof	
void roof(int height){
	for (int x = 1; x <= height ; x++){
		for (int y = 1 ; y <= 2*height; y++)
			 if(y>= height - (x-1) && y<= height + (x-1))
          		cout << " * ";
        	else
          		cout << "   "; 
      
      cout << endl;}

	}

// make a wall	
void wall(int length, int width){
	for (int down = 0; down < width; down++){ 
		cout << "   ";
		for (int across = 0; across < length+2; across++)
			if (down > 1 && across > 1 && across < 5)
				cout << "   ";
			else
				cout << " * ";
		cout << endl;
	}
}
