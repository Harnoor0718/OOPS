#include<iostream>
using namespace std;

class Animal {
public:
    Animal() {
        cout << "Animal Constructor\n";
    }

    ~Animal() {
        cout << "Animal Destructor\n";
    }

    void eat() {
        cout << "Eats food\n";
    }
};

class Dog : public Animal {
public:
    Dog() {
        cout << "Dog Constructor\n";
    }

    ~Dog() {
        cout << "Dog Destructor\n";
    }

    void bark() {
        cout << "Barks\n";
    }
};

class Puppy : public Dog {
public:
    Puppy() {
        cout << "Puppy Constructor\n";
    }

    ~Puppy() {
        cout << "Puppy Destructor\n";
    }

    void weep() {
        cout << "Weeps\n";
    }
};

int main() {
    {
        Puppy p;
        p.eat();
        p.bark();
        p.weep();
    }
    return 0;
}

