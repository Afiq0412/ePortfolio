// Muhammad Afiq Danial Bin Rozaidie
// A23CS0117
// Scenario 1
#include <iostream>
#include <cstring>
#include <cctype>
#include <iomanip>
using namespace std;

double calculateKeywordPercentage(const char userInput[],int lengthchar, int totalword, const char keyword[]){
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
	
	cout << "Enter the input (up to 999 characters, end with the empty line):" << endl;
	cin.getline(userInput, MAX_SIZE);
	
	cout << "\nInput:" << endl;
	cout << userInput << endl;
	cout << endl;

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
	
	cout << fixed << setprecision(2);
	cout << "Percentage of the word containing 'data' in the text: : " << percent << "%" << endl;
	return 0;
}
