// Lab 1 - SECJ2013 - 24251 (Student.h)
// Group Members:
// 1. MUHAMMAD AFIQ DANIAL BIN ROZAIDIE A23CS0117
// 2. MUHAMMAD MUKHRITZ AL IMAN BIN MOHD RAFFI A23CS0250

#ifndef STUDENT_H  
#define STUDENT_H  
  
#include <iostream> 
#include <string>  
#include <fstream>  
  
using namespace std;  
  
class Student {  
private:  
    string name;  
    int cwMark;  
    int feMark;  
  
public:  
    Student(string name, int cwMark, int feMark);  
    int getTotalMark() const;  
    string getGrade() const;  
    void printInfo() const;  
    void printResult() const;  
    void printResultFile(fstream &file) const;  
    ~Student();  
};  
  
  
Student::Student(string name, int cwMark, int feMark) : name(name), cwMark(cwMark), feMark(feMark) {}  
  
int Student::getTotalMark() const {  
    return cwMark + feMark;  
}  
  
string Student::getGrade() const {  
    int totalMark = getTotalMark();  
    if (totalMark >= 75) return "A";  
    else if (totalMark >= 65 && totalMark < 75) return "B";  
    else if (totalMark >= 50 && totalMark < 65) return "C";  
    else if (totalMark >= 35 && totalMark < 50) return "D";  
    else return "E";  
}  
  
void Student::printInfo() const {  
    cout << "Name: " << name << endl;  
    cout << "Coursework: " << cwMark << endl;  
    cout << "Final Exam: " << feMark << endl;  
}  
  
void Student::printResult() const {  
    cout << name << " " << getTotalMark() << " " << getGrade() << endl;  
}  
  
void Student::printResultFile(fstream &file) const {  
    file << name << " " << getTotalMark() << " " << getGrade() << endl;  
}  
  
Student::~Student() {  
    cout << "Destroy student object - " << name << endl;
}

#endif
