#include <iostream>
#include <string>
#include <fstream>

using namespace std;

void listItem(int d[], int first, int last) {
    for (int x = first; x <= last; x++) {
        cout << d[x] << " ";
    }
    cout << "\n";
}

int partition(int d[], int first, int last) {
    int pivot = d[first];
    int bottom = first;
    int top = last;
    int temp;

    cout << "bottom index = " << bottom << ", top index = " << top << "\n";

    while (true) {
        // move top
        while (d[top] > pivot) {
            top--;
        }

        //move bottom
        while (d[bottom] < pivot) {
            bottom++;
        }

        cout << "bottom index = " << bottom << ", top index = " << top << "\n";

        if (bottom < top) {
            cout << "swap " << d[bottom] << " and " << d[top] << "\n";
            temp = d[bottom];
            d[bottom] = d[top];
            d[top] = temp;
            listItem(d, first, last);

        } else {
            cout << "cut point = " << top << "\n";
            return top;
        }
    }
}

void quickSort(int d[], int first, int last) {
    int cut = partition(d, first, last);
    
    // there are at least 2 items to partition
    if (first < last) {
        // the left array
        //quickSort(d, ???, ???);

        // the right array
        //quickSort(d, ???, ???);
    }
}

// Main function section
int main() {
  int size = 9;

  int data[size] = {5, 15, 7, 2, 4, 1, 8, 10, 3}; 
  
  cout << "The original array content: ";
  listItem(data, 0, 8);
  
  partition(data, 0, size - 1);
  listItem(data, 0, 8);

  cout << "The array content after quick sort: ";
  listItem(data, 0, 8);

  system("pause");  
  return 0;
}