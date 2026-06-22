#include <iostream>
#include <string>

using namespace std;

class Student
{
	public:
		string name;
		int cwMark, feMark;
		
		Student(string n, int c, int f): 	name(n), cwMark(c), feMark(f){}

    void displayInfo()
    {
      cout << "Name: " << name << "\n";
      cout << "Coursework: " << cwMark << "\n";
      cout << "Final Exam: " << feMark << "\n";
    }
};

int main() {
  Student s("Amin", 20, 60);

  s.displayInfo();

  system("pause");
  return 0;
}
