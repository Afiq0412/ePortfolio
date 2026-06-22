// MUHAMMAD AFIQ DANIAL BIN ROZAIDIE
// A23CS0117

#include <iostream>
using namespace std;

void readQty(int&, int&, int&);
void displayHighProd(double, double, double);
double calcAvrg(double, int);
void summaryCom (double, double, double, double);

int main(){
	string agent_name,low3p,high3p,highpA,highpB,highpC;
	int quanA, quanB, quanC, nameCount = 0;
	double comA,comB,comC,total,average,allAve=0,allTtl=0,low=123456,high=0,highA=0,highB=0,highC=0;
	do{
		cout << "----------------------AGENT------------------------" << endl;
		cout << "Agent Name: ";
		getline(cin, agent_name);
		if (agent_name == "") break;
		nameCount++;
		readQty(quanA, quanB, quanC);
		
		
		comA = quanA*150*0.025;
		comB = quanB*300*0.05;
		comC = quanC*450*0.1;
		
		total = comA + comB + comC;
		average = calcAvrg(total,nameCount);
		summaryCom(comA, comB, comC, total);
	
		if (total < low){
			low = total;
			low3p = agent_name;
		}
		if (total > high){
			high = total;
			high3p = agent_name;
		}
		if (comA > highA){
			highA = comA;
			highpA = agent_name;
		}
		if (comB > highB){
			highB = comB;
			highpB = agent_name;
		}
		if (comC > highC){
			highC = comC;
			highpC = agent_name;
		}
		allTtl+=total;
		cin.ignore();
		
	} while (agent_name != "");
	cout << "------------------SALES ANALYSIS-------------------" << endl;
	cout << "Lowest commission for three products: RM " << low << " (" << low3p << ")" << endl;
	cout << "Highest commission for three products: RM " << high << " (" << high3p << ")" << endl;
	cout << "Highest commission for Product A: RM " << highA << " (" << highpA << ")" << endl;
	cout << "Highest commission for Product B: RM " << highB << " (" << highpB << ")" << endl;
	cout << "Highest commission for Product C: RM " << highC << " (" << highpC << ")" << endl;
	cout << "Total of commission for " << nameCount << " agents: RM " << allTtl << endl;
	cout << "Average of commission for " << nameCount << " agents: RM " << calcAvrg(allTtl,nameCount) << endl;
	return 0;
}

void readQty(int &pA, int &pB, int &pC){
	do{
		cout << "PRODUCT A: ";
		cin >> pA;
	} while(pA >100 || pA < 0);

	do{
		cout << "PRODUCT B: ";
		cin >> pB;
	} while(pB >100 || pB < 0);

	do{
		cout << "PRODUCT C: ";
		cin >> pC;
	} while(pC >100 || pC < 0);
}

void displayHighProd(double A, double B, double C){
	if (A > B && A > C)
		cout << "Highest commission - Product A: RM" << A << endl << endl;
	else if (B > A && B > C)
		cout << "Highest commission - Product B: RM" << B << endl << endl;
	else
		cout << "Highest commission - Product C: RM" << C << endl << endl;
}

double calcAvrg(double totalCom, int name){
	double average = totalCom / name;
	return average;
}

void summaryCom(double A, double B, double C, double total){
	cout << "-------------------SALES SUMMARY-------------------" << endl;
	cout << "Total of commission for three products: RM" << total << endl;
	displayHighProd(A,B,C);
}
