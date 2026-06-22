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
  Student s1;
  s1.name = "Adam";
  s1.cwMark = 60;
  s1.feMark = 20;
  
  cout << "Name: " << s1.name << "\n";
  cout << "Coursework: " << s1.cwMark << "\n";
  cout << "Final Exam: " << s1.feMark << "\n\n";
  //s1.printInfo();
  
  
  Student s2;
  s2.name = "Bardy";
  s2.cwMark = 47;
  s2.feMark = 18;
  
  cout << "Name: " << s2.name << "\n";
  cout << "Coursework: " << s2.cwMark << "\n";
  cout << "Final Exam: " << s2.feMark << "\n\n";
  // s2.printInfo();
}
