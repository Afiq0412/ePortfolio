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

void swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

void SelectionSort(int d[], int listSize)
{
    // play with last, largestIndex, and p
    int pass = 1;
    for(int last = listSize - 1; last >= 1; last--) // to show the last index
    {
        cout << "Pass " << pass << endl;
        cout << "The current last index to place the item: " << last << endl;

        int largestIndex = 0;
        for(int p = 1; p <= last; ++p)
        {
            cout << "Compare item " << largestIndex << " and " << p << endl;
            cout << "Compare item at " << d[largestIndex] << " and " << d[p] << endl;

            if(d[largestIndex] < d[p])
            {
                largestIndex = p;
                cout << "The largestIndex now at " << largestIndex << endl;
            }
        }
        if(largestIndex != last)
        {
            cout << "Swap item " << d[largestIndex] << " and " << d[last] << endl;
            swap(d[largestIndex], d[last]);
        }
        listItem(d, 5);
        pass++;

        cout << endl;
    }
}

// Main function section
int main() {
  //int data[4] = {12, 8, 3, 21}; // average case
  int data[5] = {2, 1, 4, 3, 5}; // worst case
  //int data[5] = {3, 8, 12, 21}; // best case
  
  // manual bubble sort operation
  cout << "The origanal list: ";
  listItem(data, 5);

  SelectionSort(data, 5);

  cout << "The list after selection: ";
  listItem(data, 5);

  system ("pause");
  return 0;
}