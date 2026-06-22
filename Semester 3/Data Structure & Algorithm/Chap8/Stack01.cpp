#include <iostream>
#include <string>

using namespace std;

const int size = 5;

// Stack class (array)
class Stack {
    private:
        int top;
        char data[size];

    public:
        void createStack() {
        }

        void push(char c) {

        }

        void pop() {

        }

        char stackTop() {
            return NULL;
        }

        bool isEmpty() {  }
        bool isFull() {  }
};

// Main function section
int main() {
    Stack myStack;

    myStack.createStack();

    cout << myStack.stackTop() << "\n";
    myStack.pop();

    myStack.push('A');
    myStack.push('B');
    myStack.push('C');
    myStack.push('D');
    myStack.push('E');
    myStack.push('F');

    while (!myStack.isEmpty())
    {
        cout << "Popping: " << myStack.stackTop() << "\n";
        myStack.pop();
    }

    return 0;
}
