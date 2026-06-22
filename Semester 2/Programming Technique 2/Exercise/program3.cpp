#include<iostream>
#include<string>

using namespace std;

int main()
{
    string expression;
	string operand1, operand2, operation;
    double value1, value2, result;
    
    // Task 1: Read the string of arithmetic expression and put it into the variable "expression"
	cout <<"Enter an arithmetic expression, e.g. 20 + 30  => ";
	getline(cin, expression);
	//cout << expression;
    
    // Task 2: Extract the operator and both operands from "expression" and 
	//           put them into the variables "operation", "operand1", and "operand2", accordingly
		
    operand1 = expression.substr(0, expression.find(" "));
    operation = expression.substr(expression.find(" "), 3);
    operand2 = expression.substr(expression.find(" ") + 3, expression.length() - '0');
    
	// Task 3:  Convert the string operands to numbers. 
	//            Put the numbers into variables "value1" and "value2", respectively
	
	value1 = stod(operand1);
    value2 = stod(operand2);
    
    // Task 4: Determine the type of operation (i.e., either +, -, *, or / ) and perform the arithmetic calculation accordingly.
    //          Put the result of the calculation into the variable "result".
   
	// cout << value1 << endl;
    // cout << value2 << endl;
    // cout << operation << endl;

    if (operation == " + ") result = value1 + value2;
    if (operation == " - ") result = value1 - value2; 
    if (operation == " * ") result = value1 * value2; 
    if (operation == " / ") result = value1 / value2; 
	
    cout << "The value of the expression " << expression << " is " << result << endl << endl;
    
    system("pause"); //! remove this line if you are using Dev C++
    return 0;
}
// shettle
