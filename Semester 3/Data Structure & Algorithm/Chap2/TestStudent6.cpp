#include <iostream>
#include <string>

using namespace std;

class Student {
    public:
      string name;
      int cwMark;
      int feMark;
      
      Student() { }
      
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
      
      void updateMark(int cw, int fe) {
        this->cwMark = cw;
        this->feMark = fe;
      }
      
      ~Student() {
          cout << "Destroy student: " << this->name << "\n";
      }
};

Student addStudent() {
  string n;
  int cw, fe;
    
  cout << "Name: ";
  cin >> n;
  cout << "Coursework: ";
  cin >> cw;
  cout << "Final Exam: ";
  cin >> fe;
  
  Student s(n, cw, fe);
  return s;
}

void listStudent(Student sl[], int n) {
  cout << "List student info:\n";
  for (int i = 0; i < n; i++) {
    sl[i].printInfo();
  }
}

int main() {
  // create and store student object (s) as pointer for Student("Brady", 47, 18)

}
