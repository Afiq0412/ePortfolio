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

void InsertionSort(int d[], int listSize) {
    // do play with these parameters to apply the insertion sort: 
    // pass, insertIndex, item
    int pass, insertIndex, item;

    for(pass = 1; pass < listSize; pass++)
    {
        item = d[pass];
        insertIndex = pass;

        cout << "Pass " << pass << endl;
        cout << "The insertIndex stars at: " << pass << endl;
        cout << "Try to insert " << item << " at the correct place" << endl;

        while ((insertIndex > 0) && (d[insertIndex-1] > item))
        {
            cout << "Current insertIndex: " << insertIndex << endl;
            cout << "Insert " << d[insertIndex-1] << endl;
            d[insertIndex] = d[insertIndex-1];
            insertIndex--;
        }
        cout << "Current insertIndex: " << insertIndex << endl;
        cout << "Insert item" << item << endl;
        d[insertIndex] = item;
        cout << "List after the insert: ";
        listItem(d, listSize);
        cout << endl << endl;
    }
}

// Main function section
int main() {
  // all below are in the context of sort in ascending order (bubble sort)
  //int data[4] = {12, 3, 8, 21}; // average case
  int data[4] = {21, 12, 8, 3}; // worst case
  //int data[4] = {3, 8, 12, 21}; // best case
  
  cout << "The original array content: ";
  listItem(data, 4);

  InsertionSort(data, 4);

  cout << "The array content after insertion sort: ";
  listItem(data, 4);

  system("pause");
  return 0;
}
