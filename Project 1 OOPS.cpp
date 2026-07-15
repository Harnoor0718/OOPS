#include<iostream>
#include<vector>
using namespace std;

class Book{
private:
    string isbn;
    string title;
    bool isAvailable;

public:
    Book(string i, string t){
        isbn = i;
        title = t;
        isAvailable = true;
    }

    string getIsbn() {
        return isbn;
    }

    string getTitle(){
        return title;
    }

    bool isBookAvailable(){
        return isAvailable;
    }

    void setAvailability(bool status) {
        isAvailable = status;
    }

};

class Person{
protected:
    string name;
    int id;

public:
    Person(string n, int i){
        name = n;
        id = i;
    }

    void displayInfo() {
        cout << "Name: " << name << ", ID: " << id << endl;
    }
};

class Member : public Person{
    int borrowedBooksCount;

public:
    Member(string n, int i) : Person(n, i) {
        borrowedBooksCount = 0;
    }

    int getBorrowedCount(){
        return borrowedBooksCount;
    }

    void incrementBorrowedCount() {
        borrowedBooksCount++;
    }

    void decrementBorrowedCount() {
        if (borrowedBooksCount > 0)
            borrowedBooksCount--;
        }
};

class Librarian : public Person {
public:
    Librarian(string n, int i) : Person(n, i) {

    }

    void addNewBook() {
        cout << "New book added to library\n";
    }
};

class Library{
    vector<Book> books;

public:
    void addBook(Book b){
        books.push_back(b);
    }

    void searchByTitle(string title){
        for(int i=0; i<books.size(); i++){
            if(books[i].getTitle() == title){
                cout<<"Found :"<<books[i].getTitle()
                <<"| ISBN :"<<books[i].getIsbn()
                <<"| Available :"<<(books[i].isBookAvailable() ? "Yes" : "No")<<endl;
                return;
            }
        }
        cout<<"Book not found\n";
    }

    void issueBook(string title, Member &m) {
    for (int i = 0; i < books.size(); i++) {
        if (books[i].getTitle() == title) {
            if (books[i].isBookAvailable()) {
                books[i].setAvailability(false);
                m.incrementBorrowedCount();
                cout << "Book issued successfully\n";
            } else {
                cout << "Book is already issued\n";
            }
            return;
        }
    }
    cout << "Book not found\n";
}

    void returnBook(string title, Member &m){
        for(int i=0; i<books.size(); i++){
            if(books[i].getTitle() == title){
                books[i].setAvailability(true);
                m.decrementBorrowedCount();
                cout << "Book returned successfully\n";
                return;
            }
        }
        cout << "Book not found\n";
    }
};

int main() {
    Library lib;

    Book b1("978-1234", "The Alchemist");
    Book b2("978-5678", "Atomic Habits");
    lib.addBook(b1);
    lib.addBook(b2);

    Member m1("Harnoor", 1);

    lib.searchByTitle("The Alchemist");

    lib.issueBook("The Alchemist", m1);
    cout << "Harnoor's borrowed count: " << m1.getBorrowedCount() << endl;

    lib.issueBook("The Alchemist", m1);   // try issuing again - should say already issued

    lib.returnBook("The Alchemist", m1);
    cout << "Harnoor's borrowed count: " << m1.getBorrowedCount() << endl;

    lib.searchByTitle("Unknown Book");    // test not-found case

    return 0;
}
