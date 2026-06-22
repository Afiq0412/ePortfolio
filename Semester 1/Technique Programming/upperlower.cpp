#include <iostream>
#include <cctype>
using namespace std;
int main()
{
	char input[20];
	cout<<"Enter a name: ";
	cin>>input;
	
	for(int i=0;input[i] != '\0';i++){
		
		if (islower(input[i])){
			input[i] = toupper(input[i]);}
		else{
			input[i] = tolower(input[i]);}
	}
	cout<<"The name after the convertion is: " << input;
	return 0;
}
