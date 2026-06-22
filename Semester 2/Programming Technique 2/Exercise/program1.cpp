// Programming Technique II (SCSJ1023)
// Semester 1, 2019/2020

// Skill-Based Test
// Date: 26 November 2019 (Tuesday)
//
// Template program for Question 1

#include <iostream>
using namespace std;

//-------------------------------------------------------------------------------------------------------------
// Class declaration
//!   The class declarations have TWO (2) errors.
//-------------------------------------------------------------------------------------------------------------

class Schedule
{
private:
    string date;
    string venue;

public:
    Schedule(string d = "", string v = "");
    string getDate() const;
    string getVenue() const;

    void setDate(string d);
    void setVenue(string v);
};

class Workshop
{
private:
    string title;
    Schedule *schedule;

public:
    Workshop(string t, Schedule s);
    string getTitle() const;
    Schedule getSchedule() const;

    void setTitle(string t);
    void setSchedule(Schedule t);
};

class Participant
{
private:
    string name;
    Workshop *workshop;

public:
    Participant(string n);
    string getName() const;
    Workshop *getWorkshop() const;

    void setName(string n);
    void setWorkshop(Workshop w);
    void print() const;
};

//-------------------------------------------------------------------------------------------------------------
// The Main Function
//
//!   There is NO ERRROR in the main function.
//?   Thus, do nothing on it.
//?   If the compiler shows you errors here, it means, the errors might be from the other parts
//?   of the program, not the main function.
//-------------------------------------------------------------------------------------------------------------

int main()
{
    //? The main function only tests out the classes for the following purposes.

    //? To create objects of Workshop
    Workshop workshop1("Python Programming for Beginners", Schedule("20 Dec 2019", "Computer Lab 8, School of Computing"));
    Workshop workshop2("Creative Content Development", Schedule("2 January 2020", "Digital Art Lab, School of Computing"));

    //? To create a list of Participant objects
    Participant participants[4] = {Participant("Azrul Malik"),
                                   Participant("Siti Nurdiana"),
                                   Participant("Kamarul Ariffin"),
                                   Participant("Aminah")};

    //? To assign the first and second participants to attend workshop1 and the last participant to workshop2.
    //?   The third participant is not assigned with any workshop.
    participants[0].setWorkshop(&workshop1);
    participants[1].setWorkshop(&workshop1);
    participants[3].setWorkshop(&workshop2);

    //? To print all the participants along with their workshop information
    for (int i = 0; i < 4; i++)
        participants[i].print();

    system("pause");
    return 0;
}

//-------------------------------------------------------------------------------------------------------------
// Class definition >> Schedule
//-------------------------------------------------------------------------------------------------------------

Schedule::Schedule(string d, string v) : date(d), venue(v) {}
string Schedule::getDate() const { return date; }
string Schedule::getVenue() const { return venue; }

void Schedule::setDate(string d) { date = d; }
void Schedule::setVenue(string v) { venue = v; }

//-------------------------------------------------------------------------------------------------------------
// Class definition >> Workshop
//-------------------------------------------------------------------------------------------------------------

//! This constructor has ONE(1) error.
Workshop::Workshop(string t, Schedule s)
{
    title = t;
    schedule = &s;
}

string Workshop::getTitle() const { return title; }

//! This method has ONE(1) error.
Schedule Workshop::getSchedule() const
{
    return *schedule;
}

void Workshop::setTitle(string t)
{
    title = t;
}

//! This method has ONE(1) error.
void Workshop::setSchedule(Schedule s)
{
    *schedule = s;
}

//-------------------------------------------------------------------------------------------------------------
// Class definition >> Participant
//-------------------------------------------------------------------------------------------------------------
//! This constructor has ONE(1) error.
Participant::Participant(string n)
{
    name = n;
}

string Participant::getName() const
{
    return name;
}

//! This method has ONE(1) error.
Workshop *Participant::getWorkshop() const
{
    return *workshop;
}

void Participant::setName(string n) { name = n; }

//! This method has ONE(1) error.
void Participant::setWorkshop(Workshop w)
{
    workshop = &w;
}

//?  The purpose of the following method is to print the name of a participant and the information about the workshop
//?    that he / she will be attending. However, if a workshop is not assigned  yet, only
//?    the participant's name is printed.

//! This method has TWO(2) errors.
void Participant::print() const
{
    name = "Participant's Name: " + name;
    cout << name << endl;

    if (workshop != NULL)
    {
        Schedule s = workshop.getSchedule();

        cout << "Workshop to be attended: " << endl;
        cout << "     Workshop's title  : " << workshop->getTitle() << endl;
        cout << "                date   : " << s.getDate() << endl;
        cout << "                venue  : " << s.getVenue() << endl;
    }
    cout << endl;
}
