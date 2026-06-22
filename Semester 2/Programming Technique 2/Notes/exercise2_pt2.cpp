// ? EXERCISE 2: CLASS AND OBJECT MANIPULATIONS

/// Programming Technique II

// Member 1's Name: MUHAMMAD AFIQ DANIAL BIN ROZAIDIE
// Member 2's Name: MOHAMED ALIF FATHI BIN ABDUL LATIF
//
// Section: 03
// Member 1's Name: MUHAMMAD AFIQ DANIAL BIN ROZAIDIE    Location: UTM, Skudai, Johor Bahru, Johor(i.e. where are you currently located)
// Member 2's Name: MOHAMED ALIF FATHI BIN ABDUL LATIF    Location: UTM, Skudai, Johor Bahru, Johor

// Log the time(s) your pair programming sessions
//  Date         Time (From)   To             Duration (in minutes)
//  22/4/2024    5.30 PM      6.00 PM			30
//  23/4/2024	 4.50 PM	  6.10 PM	        80
//  24/4/2024    9.30 PM      

// Video link:
//   _________

#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

#define MAX_SUBJECT_COUNT 10

class Subject
{
private:
	string name;
	string code;
	int score;

public:
	Subject();
	int credit() const;
	string grade() const;
	double point(string grade) const // Task 1
	{
		if (grade == "A+" || grade == "A") {return 4.00;}
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
		else {return 0.00;}
	}
	void print() const // Task 2
	{
		cout << left << setw(15) << code;
		cout << left << setw(30) << name;
		cout << left << setw(10) << credit();
		cout << left << setw(10) << score;
		cout << left << setw(10) << grade();
		cout << left << setw(10) << point(grade());
		cout << left << setw(10) << point(grade());
	}
	// Task 3
	bool operator<(const Subject& other) const
	{
		return score < other.score;
	}

	friend int readUserInput(Subject subjects[]); // Task 5
};

Subject lower(const Subject &a, const Subject &b); // Task 4

int main()
{
	double totalPoint = 0.0;
	int totalCredit = 0;
	Subject listSubject[MAX_SUBJECT_COUNT]; // Task 6a

	int count = readUserInput(listSubject); // Task 6b

	cout << endl
		 << endl
		 << "THE RESULT"
		 << endl
		 << endl;

	// Print the output table header
	cout << left << setw(15) << "Subject Code";
	cout << left << setw(30) << "Subject Name";
	cout << left << setw(10) << "Credit";
	cout << left << setw(10) << "Score";
	cout << left << setw(10) << "Grade";
	cout << left << setw(10) << "Point";
	cout << left << setw(10) << "Sub Total";
	cout << endl
		 << endl;

	for (int i = 0; i < count ; i++){
		listSubject[i].print(); // Task 6c
		cout << endl;
		totalPoint = listSubject[i].point(listSubject[i].grade()) * listSubject[i].credit();
		totalCredit = listSubject[i].credit();
	}

	cout << endl;
	cout << "TOTAL POINT  : " << totalPoint  << endl;
	cout << "TOTAL CREDIT : " << totalCredit << endl;
	cout << "GPA          : " << setprecision(3) << totalPoint/totalCredit << endl;

	Subject lowest = listSubject[0];
	for (int i = 1; i < count; i++)
	{
		lowest = lower(lowest, listSubject[i]); // Task 6d
	}

	cout << endl;
	cout << "LOWEST SUBJECT : " << endl;
	lowest.print();
	cout << endl;

	system("pause");

	return 0;
}

// The definition of the default constructor is fully given
Subject::Subject() : name(""), code(""), score(0) {}

// The definition of the getter for the 'credit()' is fully given
int Subject::credit() const { return code[7] - '0'; }

// The definition of the getter for the 'grade()' is fully given
string Subject::grade() const
{
	if (score >= 90)
		return "A+";
	if (score >= 80)
		return "A";
	if (score >= 75)
		return "A-";
	if (score >= 70)
		return "B+";
	if (score >= 65)
		return "B";
	if (score >= 60)
		return "B-";
	if (score >= 55)
		return "C+";
	if (score >= 50)
		return "C";
	if (score >= 45)
		return "C-";
	if (score >= 40)
		return "D+";
	if (score >= 35)
		return "D";
	if (score >= 30)
		return "D-";
	return "E";
}
// Define a regular function that read a list of subjects from user input
int readUserInput(Subject subjects[])
{
	int count;

	cout << "How many subjects do you want to enter? => ";
	cin >> count;

	for (int i = 0 ; i < count ; i++){
		cout << endl << "Enter info for subject #" << i+1 << ":" << endl;
		cout << "Subject Code => ";
		cin >> subjects[i].code;
		cin.ignore();
		
		cout << "Subject name => ";
		getline(cin,subjects[i].name);
		
		cout << "Score earned => ";
		cin >> subjects[i].score;

	}
	
	return count;

}

// Define a regular function that determines the lower subject.
Subject lower(const Subject &a, const Subject &b)
{
	if (a < b)
		return a;
}

