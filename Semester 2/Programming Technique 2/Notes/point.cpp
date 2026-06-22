
#include <iostream>
#include <cmath>

using namespace std;

// 1. Declare a class that represents a 2D point with the following methods.
//
//    (a). A default constructor that sets the coordinates x and y to 0
//    (b). A constructor that accepts only one parameter. This constructor uses
//         the parameter to set both x and y coordinates
//    (c). A constructor that accepts two parameters to initialize the coordinates x and y respectively
//    (d). A destructor that does nothing
//
//    (e). A method that perfoms an addition operation of two points. Point additions is done by
//         adding the coordinates, respectively. This method returns the result as another point
//         e.g. let p1 =(1, 2) and p2 (4, 0).   Adding p1 and p2 results in p3=(5, 2)
//
//    (f-i). A method that perfoms a scaling operation to the point by multiplying the coordinates x and y
//         with a number. This method returns the result as another point.
//         e.g.  Multiplying p1 with 2.5 results in a point of (2.5 , 5.0)
//    (f-ii). A method that perfoms a conversion from the object to an int. The conversion will be done as the square root 
//         of the sum of squared of the coordinates x and y. i.e., value = sqrt( x^2 + y^2)
//         e.g.  int d = p1 => d will result in 2.236

// UP TO (F)
//
//    (g) The same method from (e), but this time using an overloaded operator +
//
//    (h) The same method from (g), but this time using an overloaded operator *
//
//    (i) A method that prints the coordinates x and y
//
// 2. Define a regular function that calculates the distance between two points. Specify this function as a friend to the class
//    Do google on pythagoras theorem, to know the formula about finding the distance
//
// 3. Test the class (from 1) and the function (from 2) in the main function by
//    (a). Creating two points
//    (b). Finding the distance between these points (utilize the function from (2) for this task)
//    (c). Finding the middle point between these points (utilize the operators from (1) for this task)

class Point
{
private:
    double x, y;

public:
    // c)
    Point (int _x, int _y):x(_x), y(_y){}
    // a)
    Point():Point(0,0){}
    // b)
    Point (int value):Point(value,value){}
    
    Point (const Point &p):x(p.getX()), y(p.getY()) {}
    // Point(const Point &p){
    //     this->x = p.getX();
    //     this->y = p.getY();

    // }
    int getX() const { return x;}
    int getY() const { return y;}
    // d)
    ~Point (){}
    // e)
    Point add(const Point &p){ // Object Oriented Programming approach/ style
        Point result(x + p.getX(), y + p.getY());
        return result;
    }
//         (f-i). A method that perfoms a scaling operation to the point by multiplying the coordinates x and y
//         with a number. This method returns the result as another point.
//         e.g.  Multiplying p1 with 2.5 results in a point of (2.5 , 5.0)

    Point multiply(int number){
        return Point(this->x* number, this->y * number); 
    }

    Point operator+(const Point &p){ // overload operator style
        return Point(x + p.getX(), y + p.getY());
    }

    operator int(){
        return sqrt(x*x + y*y)
    }

    Point operator*(int number){
        return Point(this->x* number, this->y * number);
    }
    void print() const // constant method
    {
        cout << x;
        cout << y;
    }

    friend display(const Point &p)
};

void display(const Point &p)
{
    cout << p.x;
    cout << p.y;
}

int main()
{
    Point *p = new Point;

    *p // pointer -> value (object)
    p->getX();

    Point p[20];
    p[0].getX(); //an array -> element (obj)
    
    Point *p[20];
    p[0]->getX(); // array -> element (pointer)
    

    system("pause");
    return 0;
}

/* friends to a class can be established/ declared with:

1. regular function
2. another class
3. methods from another class

friend: to allow outsiders accessing private member of a class
*/