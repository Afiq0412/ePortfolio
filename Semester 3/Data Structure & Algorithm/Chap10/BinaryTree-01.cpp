#include <iostream>
#include <string>

using namespace std;

class Node {
    public:
        char opr;
        Node *left, *right; // left and right are the Node class itself

        Node(char c) {
            opr = c;
            left = NULL;
            right = NULL;
        }

        ~Node() {
            cout << "Destroy Node " << opr << "\n";
        }
};

void traverseIn(Node *n) {
    if (n != NULL) {
        traverseIn(n->left); // go to left
        cout << n->opr << " "; // print
        traverseIn(n->right); // go to right
    }

}

void traversePost(Node *n) {
    if (n != NULL) {
        traversePost(n->left); // go to left
        traversePost(n->right); // go to right
        cout << n->opr << " "; // print
    }
}

void traversePre(Node *n) {
    if (n != NULL) {
        cout << n->opr << " "; // print
        traversePre(n->left); // go to left
        traversePre(n->right); // go to right
    }
}


// Main function section
int main() {
    // represent the infix 8 + 5 in binary tree 
    Node *eight = new Node('8');
    Node *plus = new Node('+');
    Node *five = new Node('5');

    plus->left = eight;
    plus->right = five;

    // print as infix manually
    /*
    cout << plus->left->opr << " ";
    cout << plus->opr << " ";
    cout << plus->right->opr << "\n";
    */

    // print as infix using traverseIn function

    traverseIn(plus);
    cout << "\n";

    traversePost(plus);
    cout << "\n";

    traversePre(plus);
    cout << "\n";

    delete eight;
    delete plus;
    delete five;

    system("pause");
    return 0;
}