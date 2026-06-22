#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int main()
{
	fstream fin("Marks.txt", ios::in);
	fstream fout("Results.txt", ios::out);
	string name;
	int cw, fe;
	
	if (fin.fail())
		cout << "File error. Cannot open" << endl;
	else
		cout << "Can Open" << endl;

	while (!fin.eof())
	{
		fin >> name;
		fin >> cw >> fe;
		
		cout << name << " " << cw << " " << fe << " " << endl;
		
		fout << name << " " << cw << " " << fe << " " << endl;
	}
	
	fout.close();
	fin.close();
	return 0;
}
