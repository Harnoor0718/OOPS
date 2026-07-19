#include<iostream>
using namespace std;

class Shape{
public:
    virtual void area(){
        cout<<"Shape Area\n";
    }
};

class Circle : public Shape{
public:
    void area() override{
        cout<<"Circle area\n";
    }
};

class Square : public Shape{
public:
    void area() override{
        cout<<"Square area\n";
    }
};

class Triangle : public Shape{
public:
    void area() override{
        cout<<"Trianglr area\n";
    }
};

int main(){
    Shape* shapes[4];
    shapes[0] = new Shape();
    shapes[1] = new Circle();
    shapes[2] = new Square();
    shapes[3] = new Triangle();

    for(int i=0; i<4; i++){
        shapes[i]->area();
    }
}
