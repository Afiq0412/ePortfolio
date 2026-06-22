#include <iostream>
using namespace std;

void funA(int n); // Forward declaration of funA

void funB(int n) {
    cout << "funB - " << n << "\n";
    n = n + 1;

    if (n < 5) {
        if (n % 2 == 0) {
            funB(n); // Calls funB if n is even
        } else {
            funA(n); // Calls funA if n is odd
        }
    }
}

void funA(int n) {
    cout << "funA - " << n << "\n";
    n = n + 1;

    if (n < 5) {
        if (n % 2 == 0) {
            funB(n); // Calls funB if n is even
        } else {
            funA(n); // Calls funA if n is odd
        }
    }
}

int main() {
    int n = 1; // Initial value
    funA(n);   // Start with funA
    return 0;
}

