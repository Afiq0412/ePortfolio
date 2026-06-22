// class of point
#include <iostream>
using namespace std;

class Point{
   
    private:
        int x, y;
        // int c(0);
        // int *c; // dynamic allocated array
    public:
        // parameterlized constructor
        Point(int _x, int _y): x(_x), y(_y){}
        // Point(int _x, int _y){
        //     c = new int[2];
        //     c[0] = _x;
        //     c[1] = _y;
        // }
        
        // default constructor
        //Point()x(0),y(0){}
        Point(): Point(0,0){}

        // copy construtor
        // Point (const Point &point){
           // x = point.x;
           // y = point.y;

        // }
        Point (const Point &point): Point(point.x, point.y){}
        // ~Point(){ delete[] c;}
        ~Point(){}

        int () {return x+y;}
        string () 
        {
            return "(" + to_string(x) + " , " + to_string(y)+ ")";
        }

        friend void printPoint(string label, const Point &p);
        friend Point middle(const Point &a, const Point &b);

};

// void printPoint(string label, const Point &p);

int main(){
    Point a; // default constructor 
    Point b(2,3); // parameterlized constructor
    Point c(b); // copy constructor

    Point points[4] = {Point(), Point(b), Point(1,2) };

    printPoint(b);
}

void printPoint(string label, const Point &p){
    cout << label << ":(" << p.x << "," << p.y << ")" << endl;
}

//
Point middle(const Point &a, const Point &b){
    Point c((a.x+b.x)/2, (a.y+b.y)/2);
    return c;
}
// adding points
Point operator+(const Point &p){
    return Point (x +p.x, y+ p.y);
}
// multiplying points
Point operator*(int number){
    return Point (x * number, y * number);
}
// object conversion
// 1. convert the object to int such that the value is e

manipulation of string 
substr , str.length 