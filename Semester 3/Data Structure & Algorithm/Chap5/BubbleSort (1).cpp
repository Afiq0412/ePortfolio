#include <iostream>
#include <string>
#include <fstream>

using namespace std;

void listItem(int d[], int listSize) {
    for (int x = 0; x < listSize; x++) {
        cout << d[x] << " ";
    }
    cout << "\n";
}

void BubbleSort(int d[], int listSize) {
    bool sorted = false;
    for(int pass = 1; pass < listSize && !sorted; pass++)
    {
        sorted = true;
        
        cout << "Pass " << pass << ": \n";
        for (int x = 0; x < listSize - pass; x++) // compare adjacent
        {
            cout << "compare " << x << " - " << x + 1 << "\n";

            if (d[x] > d[x + 1])
            {
                cout << d[x] << " > " << d[x + 1] << " (swap)\n";
                swap(d[x], d[x+1]);
                sorted = false;

                listItem(d, 5);

                // sorted = false;
            }
        }
        cout << "The list after pass " << pass << ": \n";
        listItem(d, 5);
        cout << endl;
    }
}

void swap(int a, int b)
{
    int temp = a;
    a = b;
    b = temp;
}

// Main function section
int main() {
  //int data[4] = {12, 8, 3, 21}; // average case
  int data[5] = {2, 3, 4, 5, 1}; // worst case
  //int data[4] = {3, 8, 12, 21}; // best case
  
  // manual bubble sort operation
  cout << "The origanal list: ";
  listItem(data, 5);

  BubbleSort(data, 5);

  system ("pause");
  return 0;
}
