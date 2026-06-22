// Programming Technique II (SECSJ1023)
// Semester 2, 2021/2022

// Skill-Based Test (Practical)

// Student's Name:.....................
// Matric Number:.....................
// Location:..................... (e.g. area and state name if in malaysia, or country name if outside Malaysia)

#include <iostream>
#include <string>
#include <cstring>
using namespace std;

class Line
{
private:
	int m, c;

public:
	Line (int _m = 1, int _c = 0): m(_m), c(_c){}

	void read(){
		cout << "Enter the slope (m) and y-intercept of a line (c) => ";
		cin >> m >> c;	
	}
	Line operator-(const Line &L){
		return Line (m - L.m, c - L.c);
	}
	bool operator!=(const Line &L){
		if (m* L.m != -1)
			return true;
		else
			return false;
	}
	string toString(){
		
		string equation = "y=";
		string slope = to_string(m);
		string varX = "x";
		string operation = "+";
		string intercept = to_string(c);
		
		if (m == 1) slope = "";
		if (m == -1) slope = "-";

		equation.append(slope);
		equation.append(varX);

		if (c == 0){ 
			operation = "";
			intercept = "";
		}
		if (c < 0) operation = "";

		equation.append(operation);
		equation.append(intercept);

		return equation;
	}
	friend void printLines(Line lines[]);
};


// This function is partially given.
void printLines(Line lines[])
{
	cout << endl;
	for (int i = 0; i < 3; i++){
		cout << "Line " << i+1
		<< " slope(m) = "
		<< lines[i].m << ", y-intercept(c) = "
		<< lines[i].c
		<< ", equation: " << lines[i].toString()
		<< endl;
	}
	cout << endl;
}

int main()
{
	Line lines[3];
	cout << endl << "ORIGANAL LINES";
	lines[0] = Line(1,5);
	printLines(lines);

	cout << "Set the second line from user input" << endl;
	lines[1].read();

	lines[2] = lines[0] - lines[1];
	cout << endl << "UPDATED LINES";
	printLines(lines);

	if (lines[0] != lines[2])
		cout << "The first line is not perpendicular to the last line";
	else
		cout << "The first line is perpendicular to the last line";

	cout << endl;
	system("pause"); // ! remove this line if you are using Dev C++
	return 0;
}
