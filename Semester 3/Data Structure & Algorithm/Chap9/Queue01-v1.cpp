#include <iostream>
#include <string>

using namespace std;

const int size = 5;

// Queue class (array)
class Queue {
private:
    int front, back;
    char data[size];

public:
    void createQueue() {
        front = 0;
        back = -1;
    }

    void enQueue(char c) {
        if (isFull())
            cout << "\nCannot Enqueue Item " << c <<". Queue is full!" << endl;
        else    
        {
            back++;
            data[back] = c;
            cout << "Enqueue item " << c << "\n";
        }

    }

    char deQueue() {
        if(isEmpty())
        {
            cout << "Cannot Dequeue item. Queue is empty!" << endl;
            return ' ';
        }
        else
        {
            char item = data[front];
            front++;
            cout << "Dequeue item " << item << "\n";
            return item;
        }      
    }

    char getFront() {
        if (isEmpty())
            return ' ';
        else
            return data[front];
    }

    char getRear() {
        if (isEmpty())
            return ' ';
        else
            return data[back];
    }

    bool isEmpty() { return (back < front); }
    bool isFull() { return (back == size - 1); }

    void checkArray()
    {
        cout << "Array: ";
        for (int i = 0; i < size; i++)
        {
            cout << data[i] << " ";
        }
        cout << endl;
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

    cout << "Front item: " << myQueue.getFront() << "\n";
    cout << "Rear item: " << myQueue.getRear() << "\n";

    while (!myQueue.isEmpty())
    {
        char item = myQueue.deQueue();
        cout << "Success dequeue item " << item << endl;
        myQueue.checkArray();
    }

    myQueue.deQueue();
    myQueue.checkArray();

    // demonstrate that this current queue implementation is not optimize
    // if we take out all item from the queue, should able put 'F' into the queue
    myQueue.enQueue('F');
    myQueue.enQueue('G');

    system("pause");
    return 0;
}
