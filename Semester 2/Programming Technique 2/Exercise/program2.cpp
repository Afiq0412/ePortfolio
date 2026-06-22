#include<iostream>
#include<string>

using namespace std;

int main()
{
	string name;
	string id;
	
	// Task 1: Allow user to enter his or her full name and id number
	cout << "Enter your full name => ";
	getline(cin, name);


	cout << "Enter your ID Number => ";
	cin >> id;


	// Task 2: To determine the gender from the last digit
	// Task 2a: Extract the last digit from the id
	string lastdigit = id.substr(11, 1);


	// Task 2b: Convert the last digit to a number
	int lastDigit = stoi(lastdigit);

	
	// Task 2c: Determine the gender such that, an odd value is male and even is female
	string gender;
	gender = (lastDigit % 2 == 0)? "Female" : "Male";
	
	// Task 3: To extract the dob
	// Task 3a: Extract the year, month and day from the id

	string sYear  = id.substr(0,2);
	string sMonth = id.substr(2,2);
	string sDay = id.substr(4,2);

	// Task 3b: Convert the year, month and day to integers
	int year = stoi(sYear);
	int month = stoi(sMonth);
	int day = stoi(sDay);

	// Task 3c: Convert the year to be in full value form, e.g. 99 becomes 1999 and 02 becomes 2002
	if (year >= 0 && year <= 24 ) year += 2000;
	if (year >= 25 && year <= 99 ) year += 1900;

	
	// Task 4: Calculate the age
	int age = 2024 - year;

	
	// Task 5: Determine the string name for the month
	string MONTH[] = {"Jan", "Feb", "March", "Apr", "May", "June", "July", "Aug", "Sep", "Oct", "Nov", "Dec"};

	// Task 6: Using a loop, convert the name to capital letters
	for (int i = 0; i < name.length(); i++){
		name[i] = toupper(name[i]);
	}


	// Task 7: print all the required output
	cout << "Output: " << endl << endl;
	cout << "Name    : " << name << endl;
	cout << "ID      : " << id << endl;
	cout << "Gender  : " << gender << endl;
	cout << "Age     : " << age << " years old" << endl;
	cout << "DOB     : " << day << " " << MONTH[month - 1] << " " << year << endl << endl;

	system("pause"); //! remove this line if you are using Dev C++

    return 0;
}

