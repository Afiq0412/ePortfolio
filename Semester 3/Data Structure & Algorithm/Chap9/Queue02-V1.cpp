#include <iostream>
#include <string>

using namespace std;

class Data {
    private:
        char val;
        Data *next;

    public:
        Data(char c) {
            val = c;
            next = NULL;
        }

        char getVal()
        {
            return val;
        }

        void setNext(Data *n) {
            next = n;
        }

        Data *getNext() {
            return next;
        }

        ~Data() {
            cout << "Delete Data " << val << "\n";
        }
};


// Queue class (array)
class Queue {
private:
    Data *front, *back;

public:
    void createQueue() {
        front = NULL;
        back = NULL;
    }

    void enQueue(char c) {
        cout << "Enqueue item " << c << "\n";

        Data *item = new Data(c);

        if(isEmpty())
        {
            front = item;
            back = item;
        }
        else{
            back->setNext(item);
            back = item;
        }

    }

    char deQueue() {
        if (isEmpty()) {
            cout << "Can't dequeue item, queue is empty!\n";
            return ' ';
        } 
        else
        {
            char item = front->getVal();
            Data *temp = front;
            front = front->getNext();

            cout << "Dequeue item " << item << "\n";

            delete temp;
            return item;
        }
    }

    char getFront() {
        if (isEmpty()) {
            cout << "Can't dequeue item, queue is empty!\n";
            return ' ';
        } 
        else
        {
            return front->getVal();
        }
    }

    char getRear() {
        if (isEmpty()) {
            cout << "Can't dequeue item, queue is empty!\n";
            return ' ';
        } 
        else
        {
            return back->getVal();
        }
    }

    bool isEmpty() {return front == NULL; }
    //bool isFull() {  }

    ~Queue()
    {
        while(!isEmpty())
        {
            deQueue();
        }
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
        myQueue.deQueue();
    }

    myQueue.deQueue();

    // demonstrate that this current queue implementation is not optimize
    // if we take out all item from the queue, should able put 'F' into the queue
    myQueue.enQueue('F');
    myQueue.enQueue('G');

    system("pause");
    return 0;
}
