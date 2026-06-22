#include <iostream>
#include <string>
#include <fstream>

using namespace std;

void listItem(int d[], int size) {
    for (int x = 0; x < size; x++) {
        cout << d[x] << " ";
    }
    cout << "\n";
}

int SeqSearch(int search_key, int array[], int size) {
    int index = -1;
    int steps = 0;

    for (int p = 0; p < size; p++) {
        steps++;
        cout << search_key << " : " 
             << array[p] << "\n";

        // assign index = p and quit the loop if
        // search_key equal to  array[p]
        if (search_key == array[p]) {
            index = p;
            break;
        }
    }

    cout << "steps = " << steps << "\n";

    return index;
}

int SeqSearchSorted(int search_key, int array[], int size) {
    int index = -1;
    int steps = 0;

    for (int p = 0; p < size; p++) {
        steps++;
        cout << search_key << " : " 
             << array[p] << "\n";

        if (search_key == array[p]) {
            index = p;
            break;
        }
        if (search_key < array[p]){break;}

    }
    cout << "steps = " << steps << "\n";
    return index;
}

int BinSearchSorted(int search_key, int array[], int size) {
    int index = -1;
    int steps = 0;

    int LEFT = 0;
    int RIGHT = size - 1;

    bool found = false;
    while((LEFT <= RIGHT) && !found)
    {
        steps++;
        int MIDDLE = (LEFT + RIGHT) / 2;

        cout << LEFT << " - " << MIDDLE << " - " << RIGHT << endl;
        listItem(array, size);

        cout << search_key << " : " << array[MIDDLE] << endl;

        if(search_key == array[MIDDLE])
        {
            index = MIDDLE;
            found = true;
        }
        else
        {
            if(search_key < array[MIDDLE])
            {
                RIGHT = MIDDLE - 1;
            }
            else
            {
                LEFT = MIDDLE + 1;
            }
        }
    }

    cout << "steps = " << steps << "\n";
    return index;
}

// Main function section
int main() {
    int data[5] = {11, 33, 22, 55, 44}; // unsorted
    int data_sorted[5] = {11, 22, 33, 44, 55}; // sorted ascending
    int search_keys[10] = {11, 16, 22, 25, 33, 37, 44, 15, 55, 60}; // search key test data

    //int item2Search = 11; // O(1)
    //int item2Search = 22; // O(3)

    //for unsorted array
    //int item2Search = 44; // O(n) - found at the end
    //int item2Search = 25; // O(n) - unsorted array

    // O(n) - sorted array (equal or larger than the last item)
    //int item2Search = 55;
    //int item2Search = 56;

    //int foundIdx = SeqSearch(item2Search, data, 5);
    //int foundIdx = SeqSearchSorted(item2Search, data_sorted, 5);


    // Binary search requires sorted array
    int item2Search = 11;
    //int item2Search = 22;

    //int item2Search = 21;
    int foundIdx = BinSearchSorted(item2Search, data_sorted, 5);

    //display search result
    if (foundIdx == -1) {
        cout << "Can't found the item " << item2Search << "\n";
    } else {
        cout << "Found the item " << item2Search << " at index " << foundIdx << "\n";
    };

    // Test sequence search algorithm with 5 exist values and 5 non-exist values
    // for (int i = 0; i < 10; i++) {
    //     // int foundIdx = SeqSearch(search_keys[i], data, 5);
    //     int foundIdx = SeqSearchSorted(search_keys[i], data_sorted, 5);
    //     //int foundIdx = BinSearchSorted(search_keys[i], data_sorted, 5);
    
    //     if (foundIdx == -1) {
    //         cout << "Can't found the item " << search_keys[i] << "\n";
    //     } else {
    //         cout << "Found the item " << search_keys[i] << " at index " << foundIdx << "\n";
    //     };
    // }
    system("pause");
    return 0;
}