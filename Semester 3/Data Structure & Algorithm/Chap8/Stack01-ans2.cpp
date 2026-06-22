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
            if (this->isFull()) {
                cout << "Can't push item " << c << ". Stack is full!\n";
            } else {
                cout << "Push item " << c << " onto the stack.\n";
                top = top + 1; // top must be incremented before data is stored because top=-1 
                data[top] = c;
            }
        }

        char pop() {
            if (this->isEmpty()) {
                cout << "Can't pop item. Stack is empty!\n";
                return ' ';
            } else {
                char topItem = data[top];
                top = top - 1;
                return topItem;
            }
        }

        char stackTop() {
            if (this->isEmpty()) {
                cout << "Can't get top item. Stack is empty!\n";
                return ' ';
            } else {
                return data[top];
            }
        }

        bool isEmpty() {  return (top == -1); }
        bool isFull() {  return (top == size-1); }
};


bool isOperator(char c) {
    if (c == '+' || c == '-' || c == '*' || c == '/') 
        return true;
    else
        return false;
}

// Main function section
int main() {
    Stack myStack;

    myStack.createStack();

    cout << myStack.stackTop() << "\n";
    myStack.pop();

    myStack.push('A');
    myStack.push('B');
    myStack.push('C');
    myStack.pop();
    myStack.push('D');
    myStack.push('E');
    myStack.push('F');

    while (!myStack.isEmpty()) {
        cout << "Popping: " << myStack.pop() << "\n";
    }

cout << "\nconvert infix (2+2*3/2) to postfix (223*2/+)\n";

    string infix = "2+2*3/2";
    string postfix = "";

    for (int i = 0; i < infix.length(); i++) {
        string type = "operand";
        if (isOperator(infix[i])) type = "operator";
        cout << infix[i] << " - " << type << "\n";
        
        if (type ==  "operand") {
            postfix += infix[i];
        }
    }

    cout << "postfix = " << postfix << "\n";

    cout << "\nevaluating postfix (223*2/+) experssion\n";
    postfix = "223*2/+";


    for (int i = 0; i < postfix.length(); i++) {
        string type = "operand";
        if (isOperator(postfix[i])) type = "operator";
        cout << postfix[i] << " - " << type << "\n";

        if (type ==  "operand") {
            cout << "push " << postfix[i] << " onto stack\n";
        }
    }

    // technique to convert operand char from postfix to numeric value
    // to be used when evaluating postfix expression
    string opn1 = {postfix[0]};
    string opn2 = {postfix[1]};
    cout << stoi(opn1) + stoi(opn2) << "\n";

    system("pause");
    return 0;
}
