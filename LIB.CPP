#include <iostream>
#include <string>
using namespace std;

class LibraryItem {
public:
    virtual ~LibraryItem() {
        cout << "LibraryItem destructor called!" << endl;
    }

    virtual void display() const = 0;

    virtual string details() const = 0; 

    virtual string details(const string &additionalInfo) const {
        return details() + ", Additional Info: " + additionalInfo;
    }
};

class Book : public LibraryItem {
private:
    string title;
    string author;
    int publicationYear;

public:
    Book() : title("Unknown"), author("Unknown"), publicationYear(0) {
        cout << "Book default constructor called!" << endl;
    }

    Book(const string &t, const string &a, int pYear) 
        : title(t), author(a), publicationYear(pYear) {
        cout << "Book parameterized constructor called!" << endl;
    }

    Book(const Book &b) 
        : title(b.title), author(b.author), publicationYear(b.publicationYear) {
        cout << "Book copy constructor called!" << endl;
    }

    ~Book() {
        cout << "Book destructor called!" << endl;
    }

    void display() const override {
        cout << "Book Title: " << title << ", Author: " << author 
             << ", Publication Year: " << publicationYear << endl;
    }

    string details() const override {
        return "Book - Title: " + title + ", Author: " + author 
               + ", Publication Year: " + to_string(publicationYear);
    }
};


class Magazine : public LibraryItem {
private:
    string title;
    int issueNumber;
    string publicationMonth;

public:
   
    Magazine() : title("Unknown"), issueNumber(0), publicationMonth("Unknown") {
        cout << "Magazine default constructor called!" << endl;
    }

    Magazine(const string &t, int issue, const string &month) 
        : title(t), issueNumber(issue), publicationMonth(month) {
        cout << "Magazine parameterized constructor called!" << endl;
    }

    Magazine(const Magazine &m) 
        : title(m.title), issueNumber(m.issueNumber), publicationMonth(m.publicationMonth) {
        cout << "Magazine copy constructor called!" << endl;
    }

    ~Magazine() {
        cout << "Magazine destructor called!" << endl;
    }

    void display() const override {
        cout << "Magazine Title: " << title << ", Issue Number: " << issueNumber 
             << ", Publication Month: " << publicationMonth << endl;
    }

    string details() const override {
        return "Magazine - Title: " + title + ", Issue Number: " + to_string(issueNumber) 
               + ", Publication Month: " + publicationMonth;
    }
};

int main() {

    LibraryItem *items[4];

    items[0] = new Book(); 
    items[1] = new Book("1984", "George Orwell", 1949); 
    items[2] = new Magazine(); 
    items[3] = new Magazine("National Geographic", 202, "August"); 

    // Display items and their details
    for (int i = 0; i < 4; ++i) {
        items[i]->display();
        cout << "Details: " << items[i]->details() << endl;
        cout << "Details with extra info: " << items[i]->details("This is additional info.") << endl;
        
    }

    return 0;
}