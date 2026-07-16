#include<iostream>
using namespace std;

class Complex {
    int real, imag;

public:
    Complex(int r = 0, int i = 0) {
        real = r;
        imag = i;
    }

    Complex operator+(const Complex &other) {
        Complex temp;
        temp.real = real + other.real;
        temp.imag = imag + other.imag;
        return temp;
    }

    bool operator==(const Complex &other) {
        return (real == other.real && imag == other.imag);
    }

    void display() {
        cout << real << " + " << imag << "i" << endl;
    }
};

int main() {
    Complex c1(2, 3);
    Complex c2(4, 5);
    Complex c3 = c1 + c2;
    c3.display();              // 6 + 8i

    Complex c4(2, 3);
    if (c1 == c4)
        cout << "c1 and c4 are equal\n";
    else
        cout << "c1 and c4 are NOT equal\n";

    if (c1 == c2)
        cout << "c1 and c2 are equal\n";
    else
        cout << "c1 and c2 are NOT equal\n";

    return 0;
}
