#include "quick.hpp"
#include <iostream>
#include <algorithm>

int main() {
    std::vector<double> array = {1000.5,1.2,3.4,2,9,4,3,2.3,0,-5,23,34,1,35,4,23,56,68,2,7,-12,-9};

    std::cout << "Input:" << std::endl;
    
    for (int i=0 ; i < array.size(); i++)
        std::cout << array[i] << ",";
    
    std::cout << std::endl << "size:" << array.size() << std::endl;
    quickSort( array , 0 , array.size()-1 );

    std::cout << std::endl << "Result:" << std::endl;
    
    for (int i=0 ; i < array.size(); i++)
        std::cout << array[i] << "," ;

    return 0;
}