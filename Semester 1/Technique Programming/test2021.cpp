// MUHAMMAD AFIQ DANIAL BIN ROZAIDIE
// A23CS0117

#include <iostream>
#include <iomanip>
using namespace std;

// Task 6
void dispStatus(int);
void getInput(int &,int &,int &,int &);
void dispOutput(int);
int calcAverage(int, int);

int main(){
	string state,highstate,choose;
	int count=0,total=0,high=0,active,totalcase,newcase,totatdeath,recovered;
	//bool choise = true;
	do{
		cout << "<<<<<<<<<<<<<< DATA >>>>>>>>>>>>>" << endl;
		cout << left;
		cout << setw(15) << "State name" << ": ";
		getline(cin, state);
		count++;
		getInput(totalcase,newcase,totatdeath,recovered);
		
		active = totalcase + newcase - totatdeath - recovered;
		dispOutput(active);
		total+=active;
		if (active > high){
			high = active;
			highstate = state;
		}
		cin.ignore();
		cout << "Press <ENTER> to continue...";
		getline(cin, choose);
		cout << endl;
		
	} while (choose == "");
	cout << "<<<<<<<<< ACTIVE CASES >>>>>>>>>>" << endl;
	cout << setw(7) << "Total" << ": " << total << endl;
	cout << "Highest: " << high << " (" << highstate << ")" << endl;
	cout << "Average for " << count << "states: " << calcAverage(count,total) << endl;
	return 0;
}
// Task 1
void dispStatus(int active){
	if (active > 40)
		cout << setw(15) << "Status" << ": Red zone" << endl;
	else if (active <= 40 && active >= 21)
		cout << setw(15) << "Status" << ": Orange zone" << endl;
	else if (active <= 20 && active >= 1)
		cout << setw(15) << "Status" << ": Yellow zone" << endl;
	else
		cout << setw(15) << "Status" << ": Green zone" << endl;
	cout << endl;
}
// Task 2
void getInput(int & total, int &news, int &death, int &recover){
	cout << left;
	cout << setw(15) << "Total cases" << ": ";
	cin >> total;
	cout << setw(15) << "New cases" << ": ";
	cin >> news;
	cout << setw(15) << "Total death" << ": ";
	cin >> death;
	cout << setw(15) << "Total recovered" << ": ";
	cin >> recover;
}
// Task 3
void dispOutput(int active){
	cout << "<<<<<<<<<<<<< SUMMARY >>>>>>>>>>>" << endl;
	cout << setw(15) << "Active cases" << ": " << active << endl;
	dispStatus(active);
}
// Task 4
int calcAverage(int state, int total){
	return total/state;
}
