#include "merge.hpp"
#include <iostream>

int main() {
    std::vector<double> array = {1000.5,1.2,3.4,2,9,4,3,2.3,0,-5};

    std::cout << "Input:" << std::endl;
    
    for (int i=0 ; i < array.size(); i++)
        std::cout << array[i] << ",";
    
    mergeSort( array , 0 , array.size()-1 );

    std::cout << std::endl << "Result:" << std::endl;
    
    for (int i=0 ; i < array.size(); i++)
        std::cout << array[i] << "," ;
    
    return 0;
}