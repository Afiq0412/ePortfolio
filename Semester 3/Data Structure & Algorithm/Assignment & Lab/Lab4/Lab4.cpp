// Lab 4 - SECJ2013 - 24251 (Lab4.cpp)
// Group Members:
// 1. MUHAMMAD AFIQ DANIAL BIN ROZAIDIE A23CS0117
// 2. MOHAMED ALIF FATHI BIN ABDUL LATIF A23CS0112

#include <iostream>
#include <string>

using namespace std;

const int size = 5;

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
    int MAX_QUEUE = size; 
    int count;

public:
    void createQueue();
    void destroyQueue();
    void enQueue(char);
    char deQueue();
    bool isEmpty();
    bool isFull();
    char getFront();
    char getRear();
};

// Queue class implementation (circular linked list)
void Queue::createQueue() {
    front = NULL;
    rear = NULL;
    count = 0;
}

void Queue::enQueue(char c) {
    cout << "Try to enqueue item " << c << " into the queue\n";
    
    if (!isFull()) {
        Node *newNode = new Node(c);
        if (isEmpty()) {
            front = newNode;
            rear = newNode;
            rear->setNext(front);
        } else {
            rear->setNext(newNode);
            rear = newNode;
            rear->setNext(front);
        }
        count++;

    } else {
        cout << "Can't enqueue item " << c << ", queue is full!\n";
    }
}

char Queue::deQueue() {
    if (!isEmpty()) {
        char c = front->getItem();
        if (front == rear) {
            delete front;
            front = NULL;
            rear = NULL;
        } else {
            Node* temp = front;    
            front = front->getNext(); 
            rear->setNext(front); 
            delete temp; 
        }
        count--;
        return c;

    } else {
        cout << "Can't dequeue item, queue is empty!\n";
        return ' ';
    }
}

bool Queue::isFull() { return count == MAX_QUEUE; }

bool Queue::isEmpty() { return count == 0; }

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

// Main function section
int main() {
    Queue myQueue;

    myQueue.createQueue();

    myQueue.enQueue('A');
    myQueue.enQueue('B');
    myQueue.enQueue('C');
    myQueue.enQueue('D');
    myQueue.enQueue('E');
    myQueue.enQueue('F');
    myQueue.enQueue('G');

    cout << "\n";
    cout << "Front item: " << myQueue.getFront() << "\n";
    cout << "Rear item: " << myQueue.getRear() << "\n";
    
    cout << "\n";
    while (!myQueue.isEmpty()) {
        char delItem = myQueue.deQueue();
        cout <<  "dequeue item " << delItem << " from the queue\n";
    }

    myQueue.deQueue();

    cout << "\n";
    myQueue.enQueue('F');
    myQueue.enQueue('G');

    cout << "\n";
    cout << "Front item: " << myQueue.getFront() << "\n";
    cout << "Rear item: " << myQueue.getRear() << "\n";

    cout << "\n";
    while (!myQueue.isEmpty()) {
        char delItem = myQueue.deQueue();
        cout <<  "dequeue item " << delItem << " from the queue\n";
    }

    myQueue.deQueue();

    system("pause");
    return 0;
}
