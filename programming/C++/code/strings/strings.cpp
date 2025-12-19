#include<iostream>
#include<string> // Include the string header for std::string
using namespace std;

int main()
{
    string s;

    cout << "Enter a string: ";
    getline(cin, s);

    cout << "You entered: ";
    cout << s << endl;

    s.push_back('!');
    cout << "After using push_back: " << s << endl;

    s.pop_back();
    cout << "After using pop_back: " << s << endl;

    return 0;
}