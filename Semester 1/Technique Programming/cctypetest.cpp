#include <iostream>
#include <cctype>
using namespace std;
int main()
{
	char ch;
	cout<<"Enter any character: ";
		cin.get(ch);
	if (isalpha(ch))	
		cout<<"letter";
	else if (isdigit(ch))
		cout<<"digit";
	else 
		cout << "special character";
	return 0;
}
