// Muhammad Afiq Danial Bin Rozaidie
// A23CS0117
// 
#include <iostream>
#include <cstring>
#include <cctype>
#include <iomanip>
using namespace std;

double calculateKeywordPercentage(const char *userInput, int totalword){
	double dataCount = 0;
	const char word []= "data";
	const char *position = userInput;
	
	while ((position = strstr(position, word)) != NULL) { // count total words of "data"
        dataCount++;
        position += strlen(word);
    }
	return (dataCount/totalword*100);
}


int main(){
	const int MAX_SIZE = 999;
	char userInput[MAX_SIZE];
	int total = 0;
	
	cout << "Enter the input (up to 999 characters, end with the empty line):" << endl;
	cout << "A data engineer is someone who builds and maintains the systems that data scientists and data analysts use to collect, store, and analyze data. They use their skills to design and build data pipelines, and to ensure that data is stored in a secure and efficient way. Data engineers are in high demand across a wide range of industries, including finance, healthcare, retail, and technology." << endl;
	
	cout << "\nInput:" << endl;
	cin.getline(userInput, MAX_SIZE);
	cout << endl;
	
	for(int i = 0; userInput[i] != '\0'; i++){ // convert the word "Data" to lower case
		userInput[i] = tolower(userInput[i]);
	}
	
	for(int i = 0; userInput[i] != '\0'; i++){ // count total words
		if (userInput[i] == ' ')
			total++;
	}
	total++;
	double percent = calculateKeywordPercentage(userInput, total);
	
	cout << fixed << setprecision(2);
	cout << "Percentage fo lines containing 'data': " << percent << "%" << endl;
	return 0;
}
