#include<iostream>
#include "array/array.hpp"

int main(){
    Array<int,10> a(2);
    a.show();

    Array<int, 10> b(1, 2);
    std::cout << std::endl << b[3] << std::endl;
    b.show(); 

    Array<int, 10> de = a;
    de.show();

    std::cout<< std::endl << de.at(3) << std::endl;

}