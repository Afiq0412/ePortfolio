#include<iostream>
#include<vector>
#include<ctime>
using namespace std;

int main(){
    srand(time(0));
    vector<int> list;
    vector<int> count (10,0);

    for(int i = 0; i < 100; i++){
        int n = rand() % 10;
        list.push_back(n);
        cout << list[i] << endl;
    }
    for(int n : list){
        count[n]++;
    }

    for (int i = 0; i < 10; i++){
        cout << "Frequency of " << i << " is " << count[i] << endl;
    }

    system("pause");
    return 0;
}