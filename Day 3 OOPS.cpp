#include<iostream>
using namespace std;
class Counter{
    string name;
public:
    static int count;

    Counter(string n){
        name = n;
        count++;
    }

    static int getCount(){
        return count;
    }
};

int Counter :: count = 0;
int main(){
    Counter c1("Harnoor");
    Counter c2("Tanveer");
    Counter c3("Sonia");

    cout<<Counter::getCount();
}
