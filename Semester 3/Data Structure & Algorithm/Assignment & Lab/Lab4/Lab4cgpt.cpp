// Lab 4 - SECJ2013 - 24251 (Lab4.cpp)
// Group Members:
// 1. ???
// 2. ???

#include <iostream>
#include <string>

using namespace std;

// Node class to implement circular linked-list type queue
class Node {
private:
    char item;
    Node *next;

public:
    Node(char c) {
        item = c;
        next = NULL;
    }

    void setNext(Node *n) { next = n; }
    Node *getNext() { return next; }
    char getItem() { return item; }

    ~Node() { cout << "Delete node-item " << item << "\n"; }
};

// Queue class header (circular linked list)
class Queue {
private:
    Node *front;
    Node *rear;
    int count;
    int MAX_QUEUE;

public:
    Queue(int size);
    ~Queue();
    void enQueue(char);
    char deQueue();
    bool isEmpty();
    bool isFull();
    char getFront();
    char getRear();
    void displayQueue();
};

// Queue class implementation (circular linked list)
Queue::Queue(int size) {
    front = NULL;
    rear = NULL;
    count = 0;
    MAX_QUEUE = size;
}

Queue::~Queue() {
    while (!isEmpty()) {
        deQueue();
    }
}

void Queue::enQueue(char c) {
    cout << "Try to enqueue item " << c << " into the queue\n";

    if (!isFull()) {
        Node *newNode = new Node(c);
        if (isEmpty()) {
            front = newNode;
            rear = newNode;
            rear->setNext(front); // Circular link
        } else {
            rear->setNext(newNode);
            rear = newNode;
            rear->setNext(front); // Maintain circular link
        }
        count++;
    } else {
        cout << "Can't enqueue item " << c << ", queue is full!\n";
    }
}

char Queue::deQueue() {
    if (!isEmpty()) {
        char c = front->getItem();
        if (front == rear) { // Only one node in the queue
            delete front;
            front = NULL;
            rear = NULL;
        } else {
            Node *temp = front;
            front = front->getNext();
            rear->setNext(front); // Maintain circular link
            delete temp;
        }
        count--;
        return c;
    } else {
        cout << "Can't dequeue item, queue is empty!\n";
        return ' ';
    }
}

bool Queue::isFull() {
    return count == MAX_QUEUE;
}

bool Queue::isEmpty() {
    return count == 0;
}

char Queue::getFront() {
    if (!isEmpty()) {
        return front->getItem();
    } else {
        cout << "Can't get front item, queue is empty!\n";
        return ' ';
    }
}

char Queue::getRear() {
    if (!isEmpty()) {
        return rear->getItem();
    } else {
        cout << "Can't get rear item, queue is empty!\n";
        return ' ';
    }
}

void Queue::displayQueue() {
    if (!isEmpty()) {
        Node *current = front;
        cout << "Queue items: ";
        do {
            cout << current->getItem() << " ";
            current = current->getNext();
        } while (current != front);
        cout << "\n";
    } else {
        cout << "Queue is empty!\n";
    }
}

// Main function section
int main() {
    int size = 5; // Define the maximum size of the queue
    Queue myQueue(size);

    myQueue.enQueue('A');
    myQueue.enQueue('B');
    myQueue.enQueue('C');
    myQueue.enQueue('D');
    myQueue.enQueue('E');

    cout << "\n";
    myQueue.displayQueue();

    cout << "\n";
    cout << "Front item: " << myQueue.getFront() << "\n";
    cout << "Rear item: " << myQueue.getRear() << "\n";

    cout << "\n";
    myQueue.deQueue();
    myQueue.deQueue();
    myQueue.displayQueue();

    cout << "\n";
    myQueue.enQueue('F');
    myQueue.enQueue('G');
    myQueue.displayQueue();

    cout << "\n";
    while (!myQueue.isEmpty()) {
        char delItem = myQueue.deQueue();
        cout << "Dequeue item " << delItem << " from the queue\n";
    }

    myQueue.displayQueue();

    system("pause");
    return 0;
}
