#include <iostream>
#include <string>
#include <fstream>

using namespace std;

void LogxN(int x, int n) {

}

// Main function section
int main() {
  int counter = 1;
  int n = 8; // the size of problem

  // represent O(Log2n)
  cout << "O(Log2n) where n = 8\n";
  for (int i = 2; i <= n; i=i*2) {
	  cout << "cout num. " << counter << "\n";
    cout << "cout num 'i'. " << i << "\n";
	  counter++;
  }

  counter = 1;
  // represent O(n)
  cout << "\nO(n) where n = 8\n";
  for (int i = 0; i < 1; i++) {
	  cout << "cout num. " << counter << "\n";
	  counter++;
  }

  counter = 1;
  // represent O(nLog2n)
  cout << "\nO(nLog2n) where n = 8\n";
  for (int i = 0; i < 1; i++) {
	  cout << "cout num. " << counter << "\n";
	  counter++;
  }

  counter = 1;
  // represent O(n2)
  cout << "\nO(n2) where n = 8\n";
  for (int i = 0; i < 1; i++) {
	  cout << "cout num. " << counter << "\n";
	  counter++;
  }
  system("pause");
  return 0;
}
