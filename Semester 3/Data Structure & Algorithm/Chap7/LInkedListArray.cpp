#include <iostream>
#include <string>

using namespace std;

class Node
{
public:
    int data;
    int next;

    Node(int d = 0)
    {
        data = d;
        next = -1;
    }
    ~Node() { cout << "Destroy node " << data << "\n"; }
};

const int MAX_SIZE = 100;
Node array[MAX_SIZE];
int head = -1;
int firstAvailable = 0;
int size = 0;

void initializeList()
{
    for (int i = 0; i < MAX_SIZE - 1; ++i)
    {
        array[i].next = i + 1;
    }
    array[MAX_SIZE - 1].next = -1;
}

int findNode(int val)
{
    int current = head;
    while (current != -1)
    {
        if (array[current].data == val)
            return current;
        current = array[current].next;
    }
    return -1;
}

void insertNode(int val)
{
    cout << "Try to insert node " << val << "\n";
    if (size == MAX_SIZE)
    {
        cout << "List is full. Cannot insert.\n";
        return;
    }

    int newIndex = firstAvailable;
    firstAvailable = array[firstAvailable].next;

    array[newIndex].data = val;
    array[newIndex].next = head;
    head = newIndex;

    ++size;
}

void deleteNode(int val)
{
    cout << "Try to delete node " << val << "\n";

    int current = head;
    int prev = -1;

    while (current != -1 && array[current].data != val)
    {
        prev = current;
        current = array[current].next;
    }

    if (current == -1)
    {
        cout << "Can't find node " << val << " to delete\n";
        return;
    }

    if (prev == -1)
    {
        head = array[current].next;
    }
    else
    {
        array[prev].next = array[current].next;
    }

    array[current].next = firstAvailable;
    firstAvailable = current;

    --size;
}

void displayList()
{
    cout << "Print all nodes:\n";
    int current = head;
    while (current != -1)
    {
        cout << array[current].data << " ";
        current = array[current].next;
    }
    cout << "\n";
}

int main()
{
    initializeList();

    insertNode(50);
    insertNode(40);
    insertNode(30);
    insertNode(20);
    insertNode(10);
    displayList();

    int nodeIndex = findNode(30);
    if (nodeIndex != -1)
        cout << "Found node " << array[nodeIndex].data << " in the list\n";
    else
        cout << "Not found node 30 in the list\n";

    deleteNode(30);
    displayList();
    deleteNode(30);

    insertNode(25);
    displayList();

    insertNode(5);
    displayList();

    insertNode(60);
    displayList();

    system("pause");
    return 0;
}
