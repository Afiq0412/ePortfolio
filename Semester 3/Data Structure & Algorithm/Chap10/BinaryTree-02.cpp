#include <iostream>
#include <string>

using namespace std;
class Student {


};

class Node {
    public:
        int num;
        // Student s;
        Node *left, *right; // left and right are the Node class itself

        Node(int val) {
            num = val;
            left = NULL;
            right = NULL;
        }

        ~Node() {
            cout << "Destroy Node " << num << "\n";
        }
};

class Tree {
    public:
        Node *root;

        void createTree() {
            root = NULL;
        }

        void insertNode(Node *n) {
            if (root == NULL) {
                root = n;
            } else {
                Node *parent = root;
                bool stop = false;
                while (!stop) {
                    if (n->num < parent->num) {
                        if (parent->left == NULL) {
                            parent->left = n;
                            stop = 1;
                        } else {
                            parent = parent->left;
                        }
                        
                    } else {
                        if (parent->right == NULL) {
                            parent->right = n;
                            stop = 1;
                        } else {
                            parent = parent->right;
                        }
                    }
                }
            }

        }

};

void traverseIn(Node *n) {
    if (n != NULL) {
        traverseIn(n->left); // go to left
        cout << n->num << " "; // print
        traverseIn(n->right); // go to right
    }

}

void traversePost(Node *n) {
    if (n != NULL) {
        traversePost(n->left); // go to left
        traversePost(n->right); // go to right
        cout << n->num << " "; // print
    }
}

void traversePre(Node *n) {
    if (n != NULL) {
        cout << n->num << " "; // print
        traversePre(n->left); // go to left
        traversePre(n->right); // go to right
    }
}



// Main function section
int main() {
    int numbers[5] = {15, 6, 18, 3, 7};

    Tree myTree;

    myTree.createTree();

    for (int i = 0; i < 5; i++) {
        myTree.insertNode(new Node(numbers[i]));
    }

    traverseIn(myTree.root);
    cout << "\n";
    traversePost(myTree.root);
    cout << "\n";
    traversePre(myTree.root);
    cout << "\n";

    system("pause");
    return 0;
}
