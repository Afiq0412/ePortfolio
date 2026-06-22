// Lab 2 - SECJ2013 - 23241 (Lab2.cpp)
// Group Members:
// 1. ???
// 2. ???
// 3. ???

#include <iostream>
#include <string>

using namespace std;

void printStar(int n) {
     for (int i = 1; i <= n; i++) {
         cout << "*";
     }
}

void printNum(int n) {
     for (int i = 1; i <= n; i++) {
         cout << i << " - ";
         printStar(i);
         cout << endl;
     }
}

int totalOdd(int list[], int n) {
    int total = 0;

    for (int i = 0; i < n; i++) {
        if (list[i] % 2 != 0) {
             cout << list[i] << " ";
             total += list[i];
        }
    }

    return total;
}

// Main function
int main(int argc, char *argv[])
{
    printNum(6);

    cout << "\n\n";

    int num[6] = {0, 1, 2, 3, 4, 5};
    int result = totalOdd(num, 6);
    cout << "= " << result << endl;
    system("pause");
    return 0;
}

