#include <iostream>
#include <string>

using namespace std;

// List class definition
class List {
    private:
        Student *head, *last;

    public:
        List() { 
            cout << "Create list...\n";
            head = NULL; 
            last = NULL;
        }

        void insertNode(Student *newStud) {
            cout << "Insert " << newStud->getName() << "\n";
            if (!head || newStud->getName() < head->getName()) {
                newStud->setNext(head);
                head = newStud;
                if (!last) {
                    last = newStud;
                }
            } else {
                Student *current = head;
                while (current->getNext() && current->getNext()->getName() < newStud->getName()) {
                    current = current->getNext();
                }
                newStud->setNext(current->getNext());
                current->setNext(newStud);
                if (!newStud->getNext()) {
                    last = newStud;
                }
            }
        }

        Student *findNode(string name) {
            Student *current = head;
            while (current) {
                if (current->getName() == name) {
                    return current;
                }
                current = current->getNext();
            }
            return NULL;
        }

        void deleteNode(string name) {
            Student *current = head;
            Student *previous = NULL;

            while (current && current->getName() != name) {
                previous = current;
                current = current->getNext();
            }

            if (!current) {
                cout << "Can't found student with name " << name << "\n";
                return; // Node not found
            }

            if (!previous) { // Deleting head node
                head = current->getNext();
                if (!head) {
                    last = NULL; // List is now empty
                }
            } else {
                previous->setNext(current->getNext());
                if (!current->getNext()) {
                    last = previous; // Deleting last node
                }
            }

            delete current;
        }

        void displayList() {
            Student *stud = head;

            while (stud != NULL) {
                stud->printResult();
                stud = stud->getNext();
            }
        }

        Student *getHead() { 
            return head; 
        }

        Student *getLast() { 
            return last; 
        }

        ~List() {
            Student *stud = head;
            cout << "Destroy list...\n";
            while (stud != NULL) {
                Student *prevStud = stud;
                stud = stud->getNext();
                delete prevStud;
            }
            head = NULL;
            last = NULL;
        }
};
