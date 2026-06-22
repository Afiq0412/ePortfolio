#include <iostream>
#include <string>

using namespace std;

class Student {
    public:
        string name;
        int cwMark;
        int feMark;
};

int main() {
  Student s;
  s.name = "Adam";
  s.cwMark = 60;
  s.feMark = 20;
  
  cout << "Name: " << s.name << "\n";
  cout << "Coursework: " << s.cwMark << "\n";
  cout << "Final Exam: " << s.feMark << "\n";
}
