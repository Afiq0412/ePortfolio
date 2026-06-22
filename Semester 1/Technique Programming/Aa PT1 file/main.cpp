// ? EXERCISE 1: INTRODUCTION TO CLASSES AND OBJECTS

// Programming Technique II

// Member 1's Name: MUHAMMAD AFIQ DANIAL BIN ROZAIDIE
// Member 2's Name: MOHAMED ALIF FATHI BIN ABDUL LATIF
//
// Section: 03
// Member 1's Name: MUHAMMAD AFIQ DANIAL BIN ROZAIDIE   Location: Rengit, Batu Pahat, Johor (i.e. where are you currently located)
// Member 2's Name: MOHAMED ALIF FATHI BIN ABDUL LATIF   Location: Parit Buntar, Perak

// Log the time(s) your pair programming sessions
//  Date         Time (From)   To             Duration (in minutes)
// 14/4/2024     2.30   		
//  _________    ___________   ___________    ________

// Video link:
//   _________


#include <iostream>
#include <string>

using namespace std;

class Subject {
	private:
	string name;
	string code;
	int score;
	
	public:
	Subject(){
		name = " ";
		code = " ";
		score = 0.00;
	}
	Subject(string nm, string cd, int sc){
		name = nm;
		code = cd;
		score = sc;
	}
	void setName(string nm){
		name = nm;
	}
	void setCode(string cd){
		code = cd;
	}
	void setScore(int sc){
		score = sc;
	}
	
	string getName() const{
		return name;
	}
	string getCode() const{
		return code;
	}
	int getScore() const{
		return score;
	}

	string getGrade(){

		if (score > 100 || score < 0) {return "Error";}
		else if (score <= 100 && score >= 90) {return "A+";}
		else if (score <= 89 && score >= 80) {return "A";}
		else if (score <= 79 && score >= 75) {return "A-";}
		else if (score <= 74 && score >= 70) {return "B+";}
		else if (score <= 69 && score >= 65) {return "B";}
		else if (score <= 64 && score >= 60) {return "B-";}
		else if (score <= 59 && score >= 55) {return "C+";}
		else if (score <= 54 && score >= 50) {return "C";}
		else if (score <= 49 && score >= 45) {return "C-";}
		else if (score <= 44 && score >= 40) {return "D+";}
		else if (score <= 39 && score >= 35) {return "D";}
		else if (score <= 34 && score >= 30) {return "D-";}
		else  {return "E";}
	}

	double getPointValue(string grade){
		//string grade = getGrade();

		if (grade == "A+" || grade == "A") {return 4.00 ;}
		else if (grade == "A-") {return 3.67;}
		else if (grade == "B+") {return 3.33;}
		else if (grade == "B") {return 3.00;}
		else if (grade == "B-") {return 2.67;}
		else if (grade == "C+") {return 2.33;}
		else if (grade == "C") {return 2.00;}
		else if (grade == "C-") {return 1.67;}
		else if (grade == "D+") {return 1.33;}
		else if (grade == "D") {return 1.00;}
		else if (grade == "D-") {return 0.67;}
		else  {return 0.00;}
	}
	double pointEarned(int credit, double point){
		//double point = getPointValue();
		return point * credit;
	}
	~Subject(){}
};



int main()
{
	Subject s;
	string name;
	string code;
	double score;
	int creditHours;
	
	cout << "Enter the following data: " << endl;
	cout << "  Subject name => ";
	getline(cin,name);
	s.setName(name);
	cout << endl;

	cout << "  Subject code => ";
	getline(cin,code);
	s.setCode(code);
	cout << endl;

	cout << "  Score earned => ";
	cin >> score;
	s.setScore(score);
	cout << endl;

	cout << endl
		 << endl;

	cout << "THE RESULT" << endl
		 << endl;

	creditHours = code.back();
	cout << "Subject Code : " << code << endl;
	cout << "Subject Name : " << name << endl;
	cout << "Credit Hour  : " << creditHours << endl;
	cout << "Score Earned : " << score<< endl;
	
	string grade = s.getGrade(score);
	cout << "Grade Earned : " << grade << endl;
	
	double point = s.getPointValue(grade);
	cout << "Grade Point  : " << endl;
	cout << "Point Earned : " << endl;
	cout << endl;

	system("pause");

	return 0;
}
