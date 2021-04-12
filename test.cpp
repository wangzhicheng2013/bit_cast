#include <stdio.h>
#include <iostream>
#include "bit_array.hpp"
void fun() {
    std::cout << "I am fun." << std::endl;
}
int main() {
    long x = bit_cast<long, decltype(&fun)>(fun);
    printf("fun address:0x%0x\n", fun);
    printf("fun address with bit cast:0x%0x\n", x);

    decltype(&fun) kk;
    kk = fun;
    kk();   // call fun

    return 0;
}