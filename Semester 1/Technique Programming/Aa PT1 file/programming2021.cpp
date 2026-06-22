// MUHAMMAD AFIQ DANIAL BIN ROZAIDIE
// A23CS0117
// PROGRAMMING 20/21

#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

struct Employee{
	string name;
	string department[50];
	double basic_salary;
	int otHours;
	int otPay;
	double totalSalary;
};
// Task 2
int readInput(Employee emp[50]){
	int num;
	ifstream inp;
	inp.open("input3.txt");
	if(inp.fail()){
		cout << "File \"input3.txt\" cannot be opened. Terminating!!" << endl;
	}
	while(!inp.eof()){
		inp >> emp[num].department;
		inp >> emp[num].basic_salary;
		inp >> emp[num].otHours;
		getline(inp, emp[num].name);
		num++;
	}
	inp.close();
	displayOutput(num);
	return num;
}

// Task 3
double determineRate(Employee E){
	double rate;
	if (E.department == "Quatlity")
		rate = 11.5;
	else if (E.department == "Production")
		rate = 10.0;
	else if (E.department == "Accounting")
		rate = 12.5;
	else
		rate = 15.0;
	return rate;
}

// Task 4
void displayOutput(const Employee input[50], int num){
	double salary;
	cout << "------------------------------------------------------------------------------" << endl;
	cout << "NAME" <<  setw(30) << "DEPARTMENT" << setw(20) << "BASIC(RM)" << setw(20) << "OT(HOUR)" << setw(20) << "OT PAY(RM" <<
		setw(20) << "SALARY(RM)" << endl;
	cout << "------------------------------------------------------------------------------" << endl;
	for (int i = 0;i < 50; i++){
		input[i].otPay = determineRate(input[i].deparment) * input[i].otHours;
		input[i].totalSalary =  input[i].otPay + input[i].basic_salary;
		cout << input[i].name <<  setw(30) << input[i].department << setw(20) << input[i].basic_salary << setw(20) << input[i].E.otHours << setw(20) << input[i].otPay <<
		setw(20) << input[i].totalSalary << endl;
	}
}
// Task 6
int main(){
	Employee employ[50];
	readInput(employ);
}

