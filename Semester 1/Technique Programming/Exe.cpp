#include <iostream>
#include <iomanip>
using namespace std;

int main()
{   
 int x, y;
 int count=1;
 int month = 12, day = 4;
    for(x=0;x<=month;x+=1){
     for(y=x;y<=day;y+=1){
         cout << "\ncount: " << count << setw(10);
		 cout<<"\tx = " << x << setw(10) << "  y = "<<y;
         count++;
  }
 }
    return 0;
}

