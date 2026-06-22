#include <iostream>
#include <string>

using namespace std;

const int size = 5;

// Queue class (array)
class Queue {
private:
    int front, back;
    char data[size - 1];

public:
    void createQueue() {

    }

    void enQueue(char c) {
        cout << "Enqueue item " << c << "\n";

    }

    char deQueue() {

    }

    char getFront() {

    }

    char getRear() {

    }

    bool isEmpty() {  }
    bool isFull() {  }
};

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

    cout << "Front item: " << myQueue.getFront() << "\n";
    cout << "Rear item: " << myQueue.getRear() << "\n";

    while (!myQueue.isEmpty())
    {
        myQueue.deQueue();
    }

    myQueue.deQueue();

    // demonstrate that this current queue implementation is not optimize
    // if we take out all item from the queue, should able put 'F' into the queue
    myQueue.enQueue('F');
    myQueue.enQueue('G');

    return 0;
}
