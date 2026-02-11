#include <iostream>

int main() {
    int count=0;
    int stop=5;

    while (count<=stop){
        count++;
        std::cout<<"Hello World! (while)"<<std::endl;
    }

    for (count=0; count<=stop; count++){
        std::cout<<"Hello World! (for)"<<std::endl;
    }

    count=0;
    do {
        count++;
        std::cout<<"Hello World! (do-while)"<<std::endl;
    } while (count<=stop);

    return 0;
}