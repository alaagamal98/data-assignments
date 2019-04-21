#include "heap.hpp"
#include <iostream>

int main()
{
    std::vector< int > a = {4, 5, 2, 3, 6, 7 , -12 , 23 , 0 , 13 , -1 , 15 };
    heap::Heap myHeap;
    
    for ( int element : a )
    {
        heap::insert( myHeap , element );
    }

    while ( heap::size(myHeap) > 0 )
        std::cout << "Heap Min:" << heap::extract( myHeap ) << std::endl;
    
    return 0;
}