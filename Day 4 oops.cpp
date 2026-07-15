#include<iostream>
using namespace std;
class Rectangle{
    double length;
    double breadth;

public:
    void setLength(double l){
        if(l > 0) length = l;
        else cout<<"Invalid Length\n";
    }

    double getLength(){
        return length;
    }

    void setBreadth(double b){
        if(b > 0) breadth = b;
        else cout<<"Invalid Breadth\n";
    }

    double getBreadth(){
        return breadth;
    }

    double getArea() {
        return length * breadth;
}
};

int main(){
    Rectangle r;
    r.setLength(5.6);
    r.setBreadth(9.6);
    cout<<r.getArea();
}


