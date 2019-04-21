#ifndef SHAPES_HPP
#define SHAPES_HPP

#include <cmath>

namespace geometry
{

double triangleArea(double a, double b, double c)
{
    double s = (a + b + c) / 2;
    return std::sqrt(s * (s - a) * (s - b) * (s - c));
}

struct Point
{
    double euclideanDistance(Point p)
    {
        double dx = x - p.x;
        double dy = y - p.y;
        return std::sqrt(dx * dx + dy * dy);
    }

    double x;
    double y;
};

struct Circle
{
    double area()
    {
        return radius * radius * M_PI;
    }

    bool contains(Point test)
    {
        double dx = center.x - test.x;
        double dy = center.y - test.y;
        return dx * dx + dy * dy <= radius * radius;
    }

    Point center;
    double radius;
};

struct Square
{

    double area()
    {
        return length * length;
    }

    bool contains(Point test)
    {
        return test.x >= corner.x &&
               test.x <= corner.x + length &&
               test.y >= corner.y &&
               test.y <= corner.y + length;
    }

    Point corner;
    double length;
};

struct Rectangle
{
    double area()
    {
        return width * height;
    }

    bool contains(Point test)
    {
        return test.x >= corner.x &&
               test.x <= corner.x + width &&
               test.y >= corner.y &&
               test.y <= corner.y + height;
    }

    Point corner;
    double width;
    double height;
};

struct Rectangle2Points
{
    double width()
    {
        return std::abs(p1.x - p2.x);
    }

    double height()
    {
        return std::abs(p1.y - p2.y);
    }

    double area()
    {
        return width() * height();
    }

    bool contains(Point test)
    {
        return test.x >= p1.x &&
               test.x <= p2.x &&
               test.y >= p1.y &&
               test.y <= p2.y;
    }

    Point p1;
    Point p2;
};

struct Triangle
{
    double area()
    {
        double s = (a + b + c) / 2;
        return std::sqrt(s * (s - a) * (s - b) * (s - c));
    }

    double a;
    double b;
    double c;
};

} // namespace geometry

#endif