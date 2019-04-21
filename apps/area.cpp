#include <iostream>
#include <string> // for std::string
#include "shapes.hpp"

int main(int argc, char **argv)
{
    std::string shape = argv[1]; // this will copy the contents pointed by `argv[1]`
    double area = 0;

    if (shape == "circle")
    {
        geometry::Circle circle;
        circle.center = {0, 0};
        circle.radius = std::atof(argv[2]);
        area = circle.area();
    }
    else if (shape == "square")
    {
        geometry::Square square;
        square.corner = {0, 0};
        square.length = std::atof(argv[2]);
        area = square.area();
    }
    else if (shape == "rectangle")
    {
        geometry::Rectangle rectangle;
        rectangle.corner = {0, 0};
        rectangle.width = std::atof(argv[2]);
        rectangle.height = std::atof(argv[3]);
        area = rectangle.area();
    }
    else if (shape == "triangle")
    {
        double a = std::atof(argv[2]);
        double b = std::atof(argv[3]);
        double c = std::atof(argv[4]);
        geometry::Triangle triangle{a, b, c};
        area = triangle.area();
    }
    else
    {
        std::cout << "Undefined shape! " << shape << "\n";
        exit(EXIT_FAILURE);
    }

    std::cout << "area: " << area << std::endl;

    return 0;
}