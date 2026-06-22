#include <iostream>
#include <string>

using namespace std;

class Node {
    public:
        char data;
        Node *next;

        Node(char c) {
            data = c;
            next = NULL;
        }

        ~Node() {
            cout << "Destroy node " << data << "\n";
        }
};

// Stack class (linked list)
class Stack {
    private:
        Node *top;

    public:
        void createStack() {
            top = NULL;
        }

        void push(char c) {
            Node *nn = new Node(c);
            if (this->isEmpty()) {
                cout << "Push item " << c << " onto the stack.\n";
                top = nn;
            } else {
                cout << "Push item " << c << " onto the stack.\n";
                nn->next = top;
                top = nn;
            }
            
        }

        void pop() {
            if (this->isEmpty()) {
                cout << "Can't pop item. Stack is empty!\n";
            } else {
                Node *temp = top;
                top = top->next;
                delete temp;
            }
        }

        char stackTop() {
            if (this->isEmpty()) {
                cout << "Can't get top item. Stack is empty!\n";
                return ' ';
            } else {
                return top->data;
            }
        }

        bool isEmpty() {  return ( top == NULL); }

        // not implement this method
        //bool isFull() {  }
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

    while (!myStack.isEmpty()) {
        cout << "Popping: " << myStack.stackTop() << "\n";
        myStack.pop();
    }

    // reversing the word spelling
    string word = "HELLO";

    for (int i = 0; i < 5; i++) {
        cout << word[i] << "\n";
        myStack.push(word[i]);
    }

    int idx = 0;
    while (!myStack.isEmpty()) {
        word[idx] = myStack.stackTop();
        myStack.pop();
        idx++;
    }

    cout << word << "\n";

    system("pause");
    return 0;
}
