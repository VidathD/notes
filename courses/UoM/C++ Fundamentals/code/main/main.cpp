#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <algorithm>

using namespace std;

struct Book {
    string title;
    string author;
    int year;
    bool isAvailable;
};

void addBook(vector<Book>& lib);
void listBooks(const vector<Book>& lib);
bool containsSubstring(const std::string& str, const std::string& sub);
bool findBook(const vector<Book>& lib, const string& title);
void save(const std::vector<Book>& lib, const std::string& path);
void load(std::vector<Book>& lib, const std::string& path);
void sortBy(std::vector<Book>& lib, int mode);
int binarySearchByTitle(const vector<Book>& lib, const string& title);
void findByTitle(vector<Book>& lib, const string& title);


int main() {

    vector<Book> library;
    const string db = "library.csv";
    load(library, db);

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
        cout<<"\t8. Sort (1=Title, 2=Author, 3=Year)"<<endl;
        cout<<"\t98. Save"<<endl;
        cout<<"\t99. Exit"<<endl;
        cout<<"Choice: ";

        int choice;
        cin >> choice;
        cin.ignore();

        switch (choice)
        {
        case 1:
            addBook(library);
            break;
        case 2:
            listBooks(library); 
            break;
        case 3: {
            cout << "Enter the book title to search: ";
            string title;
            getline(cin, title);
            findBook(library, title);
            break;
        }
        case 4:
            cout << "You chose to burrow a book" <<  endl;
            break;

        case 5:
            cout << "You chose to return a book" <<  endl;
            break;
        case 6:
            cout << "You chose to reserve a book" <<  endl;
            break;
        case 7:
            cout << "You chose to remove a book" <<  endl;
            break;
        case 8: {
            cout << "Enter sort mode (1=Title, 2=Author, 3=Year): ";
            int mode;
            cin >> mode;
            cin.ignore();
            sortBy(library, mode);
            break;
        }
        case 98:
            save(library, db);
            break;
        case 99:
            cout << "Exiting the program..." << endl;
            save(library, db);
            run = false;
            break;
        default:
            cout << "Your input is incorrect" << endl;
            break;
        }
        cout<<endl;
    }

    return 0;
}

void addBook(vector<Book>& lib) {
    Book book{};
    cout << "Title: ";
    getline(cin, book.title);
    cout << "Author: ";
    getline(cin, book.author); 
    cout << "Year: ";
    cin >> book.year;
    book.isAvailable = true;

    lib.push_back(book);

    cout << "Book added successfully!" << endl;
    cout << " - " << book.title << " by " << book.author << " (" << book.year << ")" << (book.isAvailable ? " Available" : " Burrowed") << endl;
}

void listBooks(const vector<Book>& lib) {
    if (lib.empty()) {
        cout << "No books in the library." << endl;
    } else {
        for (size_t i = 0; i < lib.size(); ++i) {
            cout << " - " << lib.at(i).title << " by " << lib.at(i).author << " (" << lib.at(i).year << ")" << (lib.at(i).isAvailable ? " Available" : " Burrowed") << endl;
        }
    }
}

bool containsSubstring(const std::string& str, const std::string& sub) {
    if (sub.empty()) {
        return true;
    }
    if (str.empty()) {
        return false;
    }
    if (str.size() < sub.size()) {
        return false;
    }

    // Outer loop: choose starting index i in str
    for (size_t i = 0; i < str.size(); i++) {
        // Inner loop: match sub starting at i
        size_t j;
        for (j = 0; j < sub.size(); j++) {
            // If str ends or mismatch happens -> stop this attempt
            if (i + j >= str.size() || str[i + j] != sub[j]) {
                break;
            }
        }
        if (sub[j] == '\0') {
            return true;
        }
    }
    return false;
// Something is missing here: What is it?
}

bool findBook(const vector<Book>& lib, const string& title) {
    for (size_t i = 0; i < lib.size(); ++i) {
        if (lib.at(i).title == title) {
            cout << "Found book: " << endl;
            cout << " - " << lib.at(i).title << " by " << lib.at(i).author << " (" << lib.at(i).year << ")" << (lib.at(i).isAvailable ? " Available" : " Burrowed") << endl;
            return true;
        }
    }
    cout << "Book titled \"" << title << "\" not found in the library." << endl;
    return false;
}

void save(const std::vector<Book>& lib, const std::string& path) {
    std::ofstream out(path);
    if (!out) { std::cout << "Cannot open " << path << '\n'; return; }
    for (const auto& b : lib)
        out << b.title << ',' << b.author << ',' << b.year << ','
            << (b.isAvailable ? 1 : 0) << '\n';
    std::cout << "Saved to " << path << '\n';
}
void load(std::vector<Book>& lib, const std::string& path) {
    std::ifstream in(path);
    if (!in) { std::cout << "No file. Starting fresh.\n"; return; }
    lib.clear();
    std::string line;
    while (std::getline(in, line)) {
        // naive CSV split (no commas inside fields)
        Book b{};
        size_t p1 = line.find(','); if (p1 == std::string::npos) continue;
        size_t p2 = line.find(',', p1+1); if (p2 == std::string::npos) continue;
        size_t p3 = line.find(',', p2+1); if (p3 == std::string::npos) continue;
        b.title  = line.substr(0, p1);
        b.author = line.substr(p1+1, p2-p1-1);
        b.year   = std::stoi(line.substr(p2+1, p3-p2-1));
        int avail = std::stoi(line.substr(p3+1));
        b.isAvailable = (avail != 0);
        lib.push_back(b);
    }
    std::cout << "Loaded " << lib.size() << " books from " << path << '\n';
    return;
}

void sortBy(std::vector<Book>& lib, int mode) {
    if (mode == 1)
        std::sort(lib.begin(), lib.end(),
                  [](const Book& a, const Book& b){ return a.title < b.title; });
    else if (mode == 2)
        std::sort(lib.begin(), lib.end(),
                  [](const Book& a, const Book& b){ return a.author < b.author; });
    else if (mode == 3)
        std::sort(lib.begin(), lib.end(),
                  [](const Book& a, const Book& b){ return a.year < b.year; });
}

int binarySearchByTitle(const vector<Book>& lib, const string& title) {
    int left = 0;
    int right = lib.size() - 1;
    
    while (left <= right) {
        int mid = left + (right - left) / 2;
        
        // Compare titles letter by letter (lexicographically)
        int comparison = lib[mid].title.compare(title);
        
        if (comparison == 0) {
            // Exact match found
            return mid;
        }
        else if (comparison < 0) {
            // lib[mid].title comes before target title alphabetically
            left = mid + 1;
        }
        else {
            // lib[mid].title comes after target title alphabetically
            right = mid - 1;
        }
    }
    
    // Book not found
    return -1;
}

void findByTitle(vector<Book>& lib, const string& title) {
    if (lib.empty()) {
        cout << "Library is empty." << endl;
        return;
    }
    
    // Sort the library by title first (required for binary search)
    sort(lib.begin(), lib.end(),
        [](const Book& a, const Book& b){ return a.title < b.title; });
    
    cout << "Library sorted by title. Searching..." << endl;
    
    // Perform binary search
    int index = binarySearchByTitle(lib, title);
    
    if (index != -1) {
        cout << "Book found at position " << (index + 1) << ":" << endl;
        cout << " - " << lib[index].title << " by " << lib[index].author 
             << " (" << lib[index].year << ")" 
             << (lib[index].isAvailable ? " Available" : " Borrowed") << endl;
    } else {
        cout << "Book titled \"" << title << "\" not found in the library." << endl;
    }
}