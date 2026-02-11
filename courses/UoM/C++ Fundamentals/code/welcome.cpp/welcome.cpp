#include <iostream>
#include <string>

using namespace std;

int main() {
    string name;
    int age;

    std::cout<<"Welcome to Library Tracker!!"<<std::endl;
    std::cout<<"What is your Name? ";
    std::cin>>name;
    std::cout<<"What is your Age? ";
    std::cin>>age;
    std::cout<<name<<" (age: "<<age<<" years) registered!!";

    return 0;
}
