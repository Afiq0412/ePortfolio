#include <iostream>
#include <string>
#include <fstream>

using namespace std;

void listNum(int n) {
  if(n > 3)
  {
    cout << n << endl;
    listNum(n-1);
    cout << n;
  }
}

int main() { 
  listNum(5);
  system("pause");
  return 0;
}
