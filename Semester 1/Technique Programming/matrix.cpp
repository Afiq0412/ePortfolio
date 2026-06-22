#include <iostream>
#include <iomanip>
using namespace std;

const int ROWS = 3;
const int COLM = 3;
void displayMatrix(int [ROWS][COLM]);
void subtractMatrix(int [ROWS][COLM],int [ROWS][COLM]);

int main(){
	int matrixA[ROWS][COLM];
	int matrixB[ROWS][COLM];
	
	cout << "MATRIX A\n" << "*********************************" << endl;
	for (int x = 0; x< ROWS ; x++){
		for (int y = 0; y< COLM ; y++){
			cout << "Enter number of Row " << (x+1) << " Column " << (y+1)<< " : " ;
			cin >> matrixA[x][y];
		}
	}
	cout << "\nMATRIX A\n" << "*********************************" << endl;
	displayMatrix(matrixA);
	
	cout << "\nMATRIX B\n" << "*********************************" << endl;
	for (int a = 0; a< ROWS ; a++){
		for (int b = 0; b< COLM ; b++){
			cout << "Enter number of Row " << (a+1) << " Column " << (b+1)<< " : " ;
			cin >> matrixB[a][b];
		}
	}
	cout << "\nMATRIX B\n" << "*********************************" << endl;
	displayMatrix(matrixB);
	cout << "\nA - B\n" << "*********************************" << endl;
	subtractMatrix(matrixA, matrixB);
	return 0;
}
void displayMatrix(int number[ROWS][COLM]){
	for (int i = 0; i< ROWS ; i++){
		cout << endl;
		for (int j = 0; j< COLM ; j++){
			cout << setw(3) << number[i][j] ;
		}
	}
	cout << endl;
}
void subtractMatrix(int A[ROWS][COLM],int B[ROWS][COLM]){
	int matrixC[ROWS][COLM];
	for (int p = 0; p< ROWS ; p++){
		cout << endl;
		for (int q = 0; q< COLM ; q++){
			matrixC[p][q] = A[p][q] - B[p][q];
			cout << setw(3) << matrixC[p][q] ;
		}
	}
}
