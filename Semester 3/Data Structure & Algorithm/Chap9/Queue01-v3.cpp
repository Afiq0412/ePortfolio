#include <iostream>
#include <string>

using namespace std;

const int size = 5;

// Queue class (circular array) 
class Queue {
private:
    int front, back, count;
    char data[size];

public:
    void createQueue() {
        front = 0;
        back = size -1;
        count = 0;
    }

    void enQueue(char c) {
        if (isFull()) {
            cout << "Can't enqueue item " << c << ". Queue is full!\n";
        } else {
            back = (back + 1) % size;
            data[back] = c;
            cout << "Enqueue item " << c << "\n";
            count++;
        }
    }

    char deQueue() {
        if (isEmpty()) {
            cout << "Can't dequeue item, queue is empty!\n";
            return ' ';
        } else {
            char item = data[front];
            count--;
            front = (front + 1) % size;
            cout << "Dequeue item " << item << "\n";
            return item;
        }
        
    }

    char getFront() {
        if (isEmpty()) {
            return ' ';
        } else {
            return data[front];
        }
    }

    char getRear() {
        if (isEmpty()) {
            return ' ';
        } else {
            return data[back];
        }
    }

    bool isEmpty() { return (count == 0); }
    bool isFull() {  return (count == size); }

    void checkArray() {
        cout << "Array: ";
        for (int i = 0; i < size; i++) {
            cout << data[i] << " ";
        }
        cout << "\n";
    }
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

    myQueue.checkArray();

    cout << "Front item: " << myQueue.getFront() << "\n";
    cout << "Rear item: " << myQueue.getRear() << "\n";

    while (!myQueue.isEmpty()) {
        char item = myQueue.deQueue();
        cout << "Success dequeue item " << item << "\n";
        myQueue.checkArray();
    }

    myQueue.deQueue();
    myQueue.checkArray();

    // demonstrate that this current queue implementation is not optimize
    // if we take out all item from the queue, should able put 'F' into the queue
    myQueue.enQueue('F');
    myQueue.enQueue('G');

    myQueue.checkArray();

    system("pause");
    return 0;
}
