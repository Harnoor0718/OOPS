#include <iostream>
using namespace std;

class Animal {
protected:
    string name;

public:
    Animal() {
        cout << "Animal Constructor\n";
    }

    void setName(string n) {
        name = n;
    }

    void eats() {
        cout << "Animal eats\n";
    }
};

class Dog : public Animal {
public:
    Dog() {
        cout << "Dog Constructor\n";
    }

    void speak() {
        cout << name << " barks\n";   // 'name' inherited from Animal (protected)
    }
};

int main() {
    Dog d;
    d.setName("Tommy");
    d.eats();     // inherited from Animal
    d.speak();    // Dog's own method

    return 0;
}
