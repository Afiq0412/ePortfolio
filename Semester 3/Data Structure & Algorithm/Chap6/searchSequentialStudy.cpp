#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int SeqSearch(int searchKey, int data[], int size) {
    int index = -1; // if there is none such key, return -1
    int steps = 0; // count the steps
    for (int i = 0; i < size; i++) {
        steps++;
        if (data[i] == searchKey) {
            index = i;
            break;
        }
    }
    cout << "steps = " << steps << endl;
    return index;
}
