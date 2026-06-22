#include <iostream>
#include <string>
#include <fstream>

using namespace std;

void LogxN(int x, int n) {

}

// Main function section
int main() {
	
	int count = 1, n = 6;
  for(int i = 1; i<= n; i++)
  {
  	for(int j  = 1; j<=i; j++)
  	{
  		cout << "number " << count << endl;
  		count++;
	}
  }

  return 0;
}
