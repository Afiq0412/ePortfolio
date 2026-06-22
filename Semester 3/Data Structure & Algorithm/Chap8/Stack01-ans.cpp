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
            top = -1;
        }

        void push(char c) {
            if (isFull()) {
                cout << "Can't push item " << c << ". Stack is full!\n";
            } else {
                cout << "Push item " << c << " onto the stack.\n";
                top = top + 1;
                data[top] = c;
            }
        }

        void pop() { // pop the value
            if (isEmpty()) {
                cout << "Can't pop item. Stack is empty!\n";
            } else {
                top = top - 1;
            }
        }

        char stackTop() { // return value what is about to pop
            if (isEmpty()) {
                cout << "Can't get top item. Stack is empty!\n";
                return ' ';
            } else {
                return data[top];
            }
            
        }

        bool isEmpty() {  return (top == -1); }
        bool isFull() {  return (top == size-1); }
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
       for(int i = 0; i < 3; i++)
    {
        cout << "Popping: " << myStack.stackTop() << "\n";
        myStack.pop();
    }
    myStack.push('E');
    myStack.push('F');
    myStack.push('G');
    myStack.push('H');

    while (!myStack.isEmpty())
    {
        cout << "Popping: " << myStack.stackTop() << "\n";
        myStack.pop();
    }
    system("pause");
    return 0;
}
