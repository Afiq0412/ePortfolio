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
	Line(int slope = 1, int intercept = 0) : m(slope), c(intercept) {}
	void read()
	{
		cout << "Enter the slope (m) and y-intercept of a line (c) => ";
		cin >> m >> c;
	}

	Line operator-(const Line &line2)
	{
		Line result;
		result.m = m - line2.m;
		result.c = c - line2.c;
		return result;
	}

	bool operator!=(const Line &line2)
	{
		if (m * line2.m != -1)
			return true;
		else 
			return false;
	}

	string toString()
	{
		string answer = "y=";
		string slope = to_string(m);
		string xVar = "x";

		string intercept = to_string(c);
		string operators = "+";

		if (m == 1) {slope = "";}
		else if (m == -1) {slope = "-";}

		answer.append(slope);
		answer.append(xVar);

		if (c == 0)
		{
			intercept = "";
			operators = "";
		}

		else if ( c < 0) {operators = "";}

		answer.append(operators);
		answer.append(intercept);

		return answer;
	}

	friend void printLines(Line lines[]);

};


// This function is partially given.
void printLines(Line lines[])
	{
		cout << endl;
		for (int i = 0; i<3; i++)
		{
			cout << "Line " << i+1 
			<< " slope(m) = " << lines[i].m 
			<< ", y-intercept(c) = " << lines[i].c 
			<< ", equation: " 
			<< lines[i].toString()
			<< endl;
		}
		cout << endl;
	}

int main()
{
	Line liness[3];
	liness[0] = Line(1,5);
	printLines(liness);

	liness[1].read();

	liness[2] = liness[0] - liness[1];

	printLines(liness);

	if (liness[0] != liness[2])
	{
		cout << "The first line is perpendicular to the last line ";
	}
	else 
	{
		cout << "The first line is not perpendicular to the last line";
	}
	
	cout << endl;
	system("pause"); // ! remove this line if you are using Dev C++
	return 0;
}
