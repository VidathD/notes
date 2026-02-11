#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Book {
    string title;
    string author;
    int year;
    bool isAvailable;
};

int main() {

    vector<Book> library;

    // vector<string> titles;

    // Adding titles
    // titles.push_back("The Great Gatsby");
    // titles.push_back("1984");
    // titles.push_back("To Kill a Mockingbird");


    bool run = true;
    while (run) {
        cout<<"========= Library System Menu ========="<<endl;
        cout<<"\t1. Add a Book"<<endl;
        cout<<"\t2. List All Books"<<endl;
        cout<<"\t3. Search Books"<<endl;
        cout<<"\t4. Burrow a Book"<<endl;
        cout<<"\t5. Recieve a Book"<<endl;
        cout<<"\t6. Reserve a Book"<<endl;
        cout<<"\t7. Remove a Book"<<endl;
        cout<<"\t99. Exit"<<endl;
        cout<<"Choice: ";

        int choice;
        cin >> choice;
        cin.ignore();
    /*
        if (choice <1 || choice > 3) {
            cout << "Your input is incorrect" << endl;
        }
        else if (choice == 1) {
            cout << "You chose to add a book" << endl;
        } 
        else if (choice == 2) {
            cout << "You chose to list all books" <<  endl;
        } 
        else {
            cout << "Exiting the program..." << endl;
            break;
        }
    */
        switch (choice)
        {
        case 1:
        {
            // string title;
            // cout << "Enter the book title> ";

            // getline(cin,title);
            // titles.push_back(title);

            Book book{};
            cout << "Title: ";
            getline(cin, book.title);
            cout << "Author: ";
            getline(cin, book.author); 
            cout << "Year: ";
            cin >> book.year;
            book.isAvailable = true;

            library.push_back(book);

            cout << "Book added successfully!" << endl;
            break;
        }
        case 2:
            // for (const auto& element : titles) {
            //     std::cout << element << " ";
            // }
            if (library.empty()) {
                cout << "No books in the library." << endl;
            } else {
                for (const auto& book : library) {
                    cout << " - " << book.title << " by " << book.author << " (" << book.year << ")" << (book.isAvailable ? " Available" : " Burrowed") << endl;
                }
            }
            break;
        case 3:
            cout << "You chose to search books" <<  endl;
            break;
        case 4:
            cout << "You chose to burrow a book" <<  endl;
            break;
        case 5:
            cout << "You chose to recieve a book" <<  endl;
            break;
        case 6:
            cout << "You chose to reserve a book" <<  endl;
            break;
        case 7:
            cout << "You chose to remove a book" <<  endl;
            break;
        case 99:
            cout << "Exiting the program..." << endl;
            run = false;
            break;
        default:
            cout << "Your input is incorrect" << endl;
            break;
        }

        cin.ignore();
        cout<<endl;
    }

    return 0;

}