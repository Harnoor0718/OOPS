#include <iostream>
using namespace std;

class BankAccount {
    int id;
    string name;
    int balance;

public:
    BankAccount(int i, string n, int b) {
        id = i;
        name = n;
        if (b < 0)
            balance = 0;
        else
            balance = b;
    }

    ~BankAccount() {
        cout << name << "'s account closed\n";
    }

    void display() {
        cout << "ID: " << id << ", Name: " << name << ", Balance: " << balance << endl;
    }
};

int main() {
    BankAccount b1(101, "Raj", -500);    // test negative balance
    b1.display();

    BankAccount b2(102, "Simran", 2000); // normal balance
    b2.display();

    return 0;
}
