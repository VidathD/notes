#include <iostream>

int main() {
    int x=10;
    int* p = &x;
    
    std::cout<<x<<" "<<p<<" "<<*p<<" "<<&x<<" "<<&p<<std::endl;
    
    int& ref=x;
    std::cout<<"ref:"<<ref<<std::endl;

    ref=20;
    std::cout<<ref<<" "<<x<<std::endl;
    
    return 0;
}