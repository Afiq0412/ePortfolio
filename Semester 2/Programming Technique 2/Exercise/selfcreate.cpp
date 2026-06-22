#include <iostream>
#include <string>
#include <cstring>
using namespace std;

class Point{
    private:
    float x;
    float y;
    public:
    Point(int a=0,int b=0):x(a),y(b){}
    void setX(){
        cout<<"Enter X-coordinates: ";
        cin>>x;
    }
    void setX(float newX){
        x=newX;
    }
    void setY(){
        cout<<"Enter Y-coordinates: ";
        cin>>y;
    }
    void setY(float newY){
        y=newY;
    }
    float getX(){return x;}
    float getY(){return y;}

    Point operator+(const Point&right)const{
        Point result;
        result.x=this->x+right.x;
        result.y=this->y+right.y;
        return result;
    }
    string toString()const{
        string result;
        result="("+to_string(x)+","+to_string(y)+")";
        return result;
    }

    Point(const Point &other){
        x=other.x;
        y=other.y;
    }

    friend class Calculation;
};

class Calculation{
    private:
    Point *coordinate;
    int num;
    public:
    Calculation(int number=1){
        num=number;
        coordinate = new Point[number];
    }
    ~Calculation(){
        delete[]coordinate;
    }
    Point* getCoordinate(){return coordinate;}
    Point calculateMidpoint(int first,int second)const{
        Point sum,result;
        sum = coordinate[first-1]+coordinate[second-1];
        result.setX(sum.getX()/2.0);
        result.setY(sum.getY()/2.0);
        return result;
    }

    string toString(const Point &midpoint,int first,int second)const{
        string fomratedFormat,point1,point2,mid;
        int c=0;
        for (int i=0;i<num;i++){
            c++;
            fomratedFormat=coordinate[i].toString();
            cout<<"Point "<<c<<" coordinate:"<<fomratedFormat<<endl;
        }
        point1=coordinate[first-1].toString();
        point2=coordinate[second-1].toString();
        mid=midpoint.toString();
        cout<<endl;
        return "Midpoint of the choosen 2 point "+point1+" and "+point2+" :"+mid;
    }

    void input(int number){
        cout<<"Point "<<number+1<<endl;
        coordinate[number].setX();
        coordinate[number].setY();
        cout<<endl;
    }

};

int main(){
    int num=0,i1,i2;
    string midpoint;
    cout<<"How many points to record : ";
    cin>>num;
    Calculation graph(num);
    Point result;
    cout<<endl;
    for (int i=0;i<num;i++){
        graph.input(i);
    }
    cout<<"Which 2 point used to calculate the midpoint? : ";
    cin>>i1>>i2;
    cout<<endl;
    result=graph.calculateMidpoint(i1,i2);
    midpoint=graph.toString(result,i1,i2);
    cout<<midpoint<<endl;

    system("pause");
    return 0;

    
}