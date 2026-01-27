#include <iostream>
using namespace std;

// Creating own namespace
namespace BookInfo {
    string title = "Harry Potter and the Philosopher's Stone";
    string author = "J.K. Rowling";
    int year = 1997;
}

int main() {
    // Access variables inside the namespace
    cout << "Book Title: " << BookInfo::title << endl;
    cout << "Author: " << BookInfo::author << endl;
    cout << "Published Year:" << BookInfo::year << endl;

    return 0;
}