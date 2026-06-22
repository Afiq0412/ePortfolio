// FILEPATH: c:/Users/hp/Documents/Aa UTM/SEM 3/DSA/Assignment & Lab/Assg2/List.h

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
            head = NULL; last = NULL;
        }
        
        void insertNode(Student *newStud) {
            cout << "Insert " << newStud->getName() << "\n";
            if (head == NULL) {
                head = last = newStud;
            } else {
                last->setNext(newStud);
                last = newStud;
            }
        }
        
        Student *findNode(string name) {
            Student *current = head;
            while (current != NULL) {
                if (current->getName() == name) {
                    return current;
                }
                current = current->getNext();
            }
            return NULL;
        }
        
        void deleteNode(string name) {
            Student *current = head;
            Student *prev = NULL;

            while (current != NULL && current->getName() != name) {
                prev = current;
                current = current->getNext();
            }

            if (current == NULL) {
                cout << "Student " << name << " not found.\n";
                return;
            }

            if (prev == NULL) {
                head = current->getNext();
            } else {
                prev->setNext(current->getNext());
            }

            if (current == last) {
                last = prev;
            }

            delete current;
            cout << "Deleted " << name << "\n";
        }
        
        void displayList() {
            Student *stud = head;
            if (stud == NULL) {
                cout << "The list is empty.\n";
                return;
            }
            cout << "Student List:\n";
            while (stud != NULL) {
                stud->printResult();
                stud = stud->getNext();
            }
        }
        
        Student *getHead() { return head; }
        Student *getLast() { return last; }
        
        ~List() {
            Student *stud = head;
            cout << "Destroy list...\n";
            while (stud != NULL) {
                Student *prevStud = stud;
                stud = stud->getNext();
                delete prevStud;
            }
        }
};
