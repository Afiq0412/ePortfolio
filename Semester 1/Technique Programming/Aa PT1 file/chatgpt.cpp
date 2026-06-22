#include <iostream>
#include <string>
using namespace std;

int main() {
    string str = "Hello, world!";
    string substr = "world";

    // Find the position of the substring in the string
    size_t found = str.find(substr);

    if (found != string::npos) {
        cout << "Substring found at position: " << found << endl;
    } else {
        cout << "Substring not found." << endl;
    }

    return 0;
}

