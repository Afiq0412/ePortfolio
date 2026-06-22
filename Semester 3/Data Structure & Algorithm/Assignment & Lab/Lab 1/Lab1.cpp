// Lab 1 - SECJ2013 - 24251 (Lab1.cpp)
// Group Members:
// 1. MUHAMMAD AFIQ DANIAL BIN ROZAIDIE A23CS0117
// 2. MUHAMMAD MUKHRITZ AL IMAN BIN MOHD RAFFI A23CS0250

#include <iostream>
#include <string>
#include <fstream>
#include "Student.h"

using namespace std;

// main function
int main() {
    const int LIST_SIZE = 10;
    Student* studList[LIST_SIZE];

    int count = 0;

    fstream inFile("Marks.txt", ios::in);
    fstream outFile("Results.txt", ios::out);
    
    string nm;
    int cw, fe;

    if(inFile) //to know if the file "Marks.txt" can be open or not
        cout << "Can open the file" << endl;
    else
        cout << "Cannot open the file" << endl;

    while(!inFile.eof())
    {
        if(count < LIST_SIZE)
        {
            inFile >> nm >> cw >> fe; //read the input from text file
            studList[count++] = new Student(nm, cw, fe); //create and set the parameters
        }
    }

    cout << "Student mark info:" << endl;
    for(int i = 0; i < count; i++) //display each student information
    {
        studList[i]->printInfo();
        cout << endl;
    }
    
    cout << "\nPrint and save results to file:" << endl;
    for(int j = 0; j < count; j++) //print student final results
    {
        studList[j]->printResult();
        studList[j]->printResultFile(outFile);
        delete studList[j];
    }

    inFile.close();
    outFile.close();

    system("pause");
    return 0;
}
