#include <iostream>
#include <string>

using namespace std;

class Student {
    public:
      string name;
      int cwMark;
      int feMark;

      Student(){}
      
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

      void updateMark(int c, int f)
      {
        this->cwMark = c;
        this->feMark = f;
      }

      ~Student() {
          cout << "Destroy student: " << this->name << "\n";
      }
};

Student addStudent()
{
  string name;
  int cMark, fMark;

  cout << "Enter Name: ";
  cin >> name;
  cout << "Enter Coursework: ";
  cin >> cMark;
  cout << "Enter Final Exam: ";
  cin >> fMark;

  return Student(name, cMark, fMark);
}

int main() {
  Student s1("Adam", 60, 20), s2("Brady", 47, 18), s3;
  s1.printInfo();
  s2.printInfo();

  s2.updateMark(47, 23);
  s2.printInfo();

  // interactively create/add student via cin
  s3 = addStudent();
  s3.printInfo();
}

