// Programming Technique II

//? EXERCISE 3: STRING MANIPULATIONS
//? file: custom_string.cpp

//!----------------------------------------------------------------------------------------
//! This is the only file that you will need to modify in this exercise.
//! Also, you will submit only this file.
//! This file is the implementation for the class CustomString.
//!----------------------------------------------------------------------------------------


// Member 1's Name: _____________
// Member 2's Name: _____________

#include <iostream>
#include <string>
using namespace std;

#include "custom_string.hpp"

//?----------------------------------------------------------------------------------------
//? The following methods are fully given: a constructor, getData() and setData()
//?----------------------------------------------------------------------------------------

CustomString::CustomString(const string &_data) : data(_data) {}
string CustomString::getData() const { return data; }
void CustomString::setData(const string &_data) { data = _data; }

//! Task 1: Complete the implementation of the following mutator methods:
//!        (a) pushFront()
//!        (b) pushBack()
//!        (c) pop()
//!        (d) popFront()
//!        (e) popBack()

void CustomString::pushFront(const string &s)
{
    data.insert(0, s);
}

void CustomString::pushBack(const string &s)
{
   data.insert(data.length(), s);
}

string CustomString::pop(int index, int count)
{
    string str = data.substr(index, count);
    data.erase(index, count);
    return str;
}

string CustomString::popFront(int count)
{
    string str = data.substr(0, count);
    data.erase(0, count);
    return str;
}

string CustomString::popBack(int count)
{
    string str = data.substr(data.length()-count, count);
    data.erase(data.length()-count, count);
    return str;
}

//! Task 2: Complete the implementation of the following overloaded operators:
//!        (a) operator !
//!        (b) operator *

CustomString CustomString::operator!() const
{
    return CustomString(string(data.crbegin(), data.crend()));
}

CustomString CustomString::operator*(int count) const
{
    string str;
    for (int i = 0; i < count; ++i) {
            str.append(data);
        }
    return CustomString(str);
}

//! Task 3: Complete the implementation of the following conversion methods:
//!        (a) toDouble()
//!        (b) toUpper()

double CustomString::toDouble() const
{ 
    return stod(data);
}

CustomString CustomString::toUpper() const
{
    string str, a;
    for (int i = 0; i < data.length() ; i++)
    {
        a = toupper(data[i]);
        str.append(a);
    }
    return str;
}+