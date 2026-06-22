#include <iostream>
#include <string>
#include <fstream>

using namespace std;

// Main function section
int main()
{
    int pass, listSize = 4;

    for (pass = 1; pass < listSize; pass++)
    {
        for (int x = 0; x < listSize - pass; x++)
        {
            cout << "Hello\n";
        }
    }
}