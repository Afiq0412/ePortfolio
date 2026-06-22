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

void merge(int d[], int first, int mid, int last) {
    cout << "merge: " << first << "-" << mid << " and " << mid + 1 << "-" << last << "\n";

    int tempArray[10] = {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1};
    
    // 1st half of array index
    // it may refer to the index in the middle of the array
    int first1 = first;
    int last1 = mid;

    // 2nd half of array index
    int first2 = mid + 1;
    int last2 = last;

    
    // set the index as the first1 here because we will keep increasing the first1 value in the next loop
    // index refers to the location of tempArray to copy item to from the 1st/2nd half of the array
    int index = first1;

    // compare each item in both array and copy the correct item into temp array
    for ( ;(first1 <= last1 && first2 <= last2); ) { // the slide put ++index here
        cout << d[first1] << " < " << d[first2] << "\n";
        if (d[first1] < first2) {
            cout << "copy " << d[first1] << " to tempArray\n";
            tempArray[index] = d[first1];
            first1++;

        } else {
            cout << "copy " << d[first2] << " to tempArray\n";
            tempArray[index] = d[first2];
            first2++;
        }

        cout << "tempArray: ";
        listItem(tempArray, 10);

        index++;
    }

    

    // iterate and copy the rest of items in the 1st half of array (if any) to temp array
    for (; first1 <= last1; ++index) {
        cout << "copy " << d[first1] << " to tempArray\n";
        tempArray[index] = d[first1];
        first1++;
    }

    // iterate and copy the rest of items in the 2nd half of array (if any) to temp array
    for (; first2 <= last2; ++index) {
        cout << "copy " << d[first2] << " to tempArray\n";
        tempArray[index] = d[first2];
        first2++;
    }

    cout << "tempArray: ";
    listItem(tempArray, 10);

    // copy all items from temp array to the original array
    cout << "copt item from tempArray to original array:\n";
    for (index = first; index <= last; ++index) {
        cout << "copy " << tempArray[index] << " to original array\n";
        d[index] = tempArray[index];
    }


}

void MergeSort(int d[], int first, int last) {
    // do play with these parameters to apply the insertion sort: 
    // first, last, mid
    // ???
    int mid = (first + last)/2;

    cout << "first: " << first << "\n";
    cout << "mid: " << mid << "\n";
    cout << "last: " << last << "\n";

    // only make recursive call if can split the array into two halves
    // cout << "MergeSort (left): " << first << ", " << mid << "\n";
    // cout << "MergeSort (right): " << mid + 1 << ", " << last << "\n";
    // ???

    if (first < last) {
        cout << "MergeSort (left): " << first << ", " << mid << "\n";
        MergeSort(d, first, mid);

        cout << "MergeSort (right): " << mid + 1 << ", " << last << "\n";
        MergeSort(d, mid+1, last);
    }
    
}

void MergeSortV2(int d[], int first, int last) {
    // do play with these parameters to apply the insertion sort: 
    // first, last, mid 
    // also try call merge function here
    int mid = (first + last)/2;

    cout << "first: " << first << "\n";
    cout << "mid: " << mid << "\n";
    cout << "last: " << last << "\n";

    // only make recursive call if can split the array into two halves
    // cout << "MergeSort (left): " << first << ", " << mid << "\n";
    // cout << "MergeSort (right): " << mid + 1 << ", " << last << "\n";
    // ???

    if (first < last) {
        cout << "MergeSort (left): " << first << ", " << mid << "\n";
        MergeSortV2(d, first, mid);
        cout << "MergeSort (right): " << mid + 1 << ", " << last << "\n";
        MergeSortV2(d, mid+1, last);
        
        merge(d, first, mid, last);
    }
    
}



// Main function section
int main() {
  int data[5] = {8, 1, 4, 3, 2};
  int last2half[5] = {1, 4, 8, 2, 3}; // example of the final two halves array
  
  // test merge function
  /*
  cout << "last2half: ";
  listItem(last2half, 5);
  merge(last2half, 0, 2, 4);
  cout << "last2half: ";
  listItem(last2half, 5);
  */
  
  cout << "The original array content: ";
  listItem(data, 5);

  //MergeSort(data, 0, 4);
  MergeSortV2(data, 0, 4);

  cout << "The array content after merge sort: ";
  listItem(data, 5);

  system("pause");
  return 0;
}

