#include <iostream>
#include <string>

using namespace std;

class Student {
    public:
      string name;
      int cwMark;
      int feMark;
        
      void printInfo() {
        cout << "Name: " << this->name << "\n";
        cout << "Coursework: " << this->cwMark << "\n";
        cout << "Final Exam: " << this->feMark << "\n\n";
      }
};

int main() {
  Student s1;
  s1.name = "Adam";
  s1.cwMark = 60;
  s1.feMark = 20;
  s1.printInfo();
  
  Student s2;
  s2.name = "Bardy";
  s2.cwMark = 47;
  s2.feMark = 18;
  s2.printInfo();
}
