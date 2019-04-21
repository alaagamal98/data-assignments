#include <iostream>
#include <cmath>
#include "shapes.hpp"

int main()
{
    geometry::Point p1, p2;

    std::cout << "Enter the two points coordinates as following: x1 y1 x2 y2 [ENTER]\n";
    std::cin >> p1.x >> p1.y >> p2.x >> p2.y;
    std::cout << p1.euclideanDistance( p2 );
}
