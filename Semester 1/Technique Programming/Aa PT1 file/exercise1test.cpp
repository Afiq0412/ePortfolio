#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

const int MAXIMUM_STUDENT = 10;

class Student {
	private:
		string name;
		string code;
		int score;

	public:
		Student() {
			name="";
			code="";
			score = 0;
		}
		void setName(string n) {
			name = n;
		}
		void setCode(string c) {
			code = c;
		}
		void setScore(int s) {
			score = s;
		}
		int getScore() const {
			return score;
		}
		string getName() const {
			return name;
		}
		string getCode() const {
			return code;
		}
		string Grade(int);
		double getPoint(string);
		double calculateTotal(double s, int cHour)
		{
			return s * cHour;
		}
		~Student(){
		}
};

string Student::Grade(int s) {
	if (s < 0 || s > 100) {
		return "Error";
	}
	if (s >= 90) {
		return "A+";
	}
	else if (s >= 80) {
		return "A";
	}
	else if (s >= 75) {
		return "A-";
	}
	else if (s >= 70) {
		return "B+";
	}
	else if (s >= 65) {
		return "B";
	}
	else if (s >= 60) {
		return "B-";
	}
	else if (s >= 55) {
		return "C+";
	}
	else if (s >= 50) {
		return "C";
	}
	else if (s >= 45) {
		return "C-";
	}
	else if (s >= 40) {
		return "D+";
	}
	else if (s >= 35) {
		return "D";
	}
	else if (s >= 30) {
		return "D-";
	}
	else {
		return "E";
	}
}

double Student::getPoint(string g) {
	if (g == "A+") {
		return 4.00;
	}
	else if (g == "A") {
		return 4.00;
	}
	else if (g == "A-") {
		return 3.67;
	}
	else if (g == "B+") {
		return 3.33;
	}
	else if (g == "B") {
		return 3.00;
	}
	else if (g == "B-") {
		return 2.67;
	}
	else if (g == "C+") {
		return 2.33;
	}
	else if (g == "C") {
		return 2.00;
	}
	else if (g == "C-") {
		return 1.67;
	}
	else if (g == "D+") {
		return 1.33;
	}
	else if (g == "D") {
		return 1.00;
	}
	else if (g == "D-") {
		return 0.67;
	}
	else {
		return 0.00;
	}
}

int main()
{
    string name;
    string code;
    int score;
    Student p;
    int cHour;

    int studentCount = 0;
    char continueLoop = 'y';

    while (continueLoop == 'y' && studentCount < MAXIMUM_STUDENT) {
        cout << "Enter the following data:" << endl;

        cout << setw(18) << "Subject name => ";
        getline(cin, name);
        p.setName(name);

        cout << setw(18) << "Subject code => ";
        getline(cin, code);
        p.setCode(code);

        cout << setw(18) << "Score earned => ";
        cin >> score;
        p.setScore(score);

        cout << endl << endl << "THE RESULT" << endl << endl;
        cout << "Subject Code : " << p.getCode() << endl;
        cout << "Subject Name : " << p.getName() << endl;
        cout << "Credit Hour  : ";
        cin >> cHour;
        cout << "Score Earned : " << p.getScore() << endl;

        string grade = p.Grade(score);
        cout << "Grade Earned : " << grade << endl;

        double point = p.getPoint(grade);
        cout << "Grade Point  : " << point << endl;
        cout << "Point Earned : " << p.calculateTotal(point, cHour) << endl;

        studentCount++;
        cin.ignore();
		
        if (studentCount < MAXIMUM_STUDENT) {
            cout << endl << "Do you want to enter another student's data? (y/n) ";
            cin >> continueLoop;
            cout << endl;
        } else {
            cout << endl << "Maximum number of students reached." << endl;
        }
        cin.ignore();
    }

    return 0;
}