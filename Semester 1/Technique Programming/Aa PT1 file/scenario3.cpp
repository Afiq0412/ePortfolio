// Muhammad Afiq Danial Bin Rozaidie
// A23CS0117
// Scenario 3
#include <iostream>
#include <cstring>
#include <cctype>
#include <iomanip>
#include <fstream>
using namespace std;

double calculateKeywordPercentage(const char* userInput,int lengthchar, int totalword, const char keyword[]){
	double dataCount = 0;
	
	for (int i = 0; i < lengthchar; i++){ 
		if (strstr(userInput+i,keyword) == (userInput+i)) // count total words of "data"
			dataCount++;
	}
	return (dataCount/totalword*100);
}


int main(){
	const int MAX_SIZE = 999;
	char userInput[MAX_SIZE];
	int total = 1, totalchar = 0;
	
	ifstream in("input2.txt");
	ofstream out("output2.txt");
	if (in.fail()){
		cout << "Error. Cannot open file" << endl;
		return 0;
	}
	in.getline(userInput, MAX_SIZE);
	out << "Input:\n";
	out << userInput << " " << endl << endl;
		

	for(int i = 0; userInput[i] != '\0'; i++){ 
		userInput[i] = tolower(userInput[i]); // convert the letter of D in "Data" into lower case
		totalchar++;
	}
	
	for(int i = 0; userInput[i] != '\0'; i++){ 
		if (userInput[i] == ' ') // count total words
			total++;
	}
	const char word []= "data";
	double percent = calculateKeywordPercentage(userInput, totalchar, total, word);
	
	out << fixed << setprecision(2);
	out << "Percentage of the word containing 'data' in the text: " << percent << "%" << endl;
	
	in.close();
	out.close();
	cout << "Results written to 'output2.txt'" << endl;
	return 0;
}
