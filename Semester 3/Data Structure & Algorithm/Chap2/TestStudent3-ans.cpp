#include <iostream>
#include <string>

using namespace std;

class Student {
    public:
      string name;
      int cwMark;
      int feMark;
      
      Student(string n, int cw, int fe) {
        this->name = n;
        this->cwMark = cw;
        this->feMark = fe;
      }
        
      void printInfo() {
        cout << "Name: " << this->name << "\n";
        cout << "Coursework: " << this->cwMark << "\n";
        cout << "Final Exam: " << this->feMark << "\n\n";
      }
      
      ~Student() {
          cout << "Destroy student: " << this->name << "\n";
      }
};

int main() {
  Student s1("Adam", 60, 20);
  s1.printInfo();
  
  Student s2("Brady", 47, 18);
  s2.printInfo();
}
