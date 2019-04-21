#ifndef MATHEMATICS_HPP
#define MATHEMATICS_HPP
#include <cmath> // for std::sqrt
namespace mathematics
{
struct Triangle
{
    double a;
    double b;
    double c;
};
struct calculator
{
    double a;
    double b;
    char operation;
};
double calculation(calculator calc)
{
    if (calc.operation == '+')
    {
        return calc.a + calc.b;
    }
    else if (calc.operation == '-')
    {
        return calc.a - calc.b;
    }
    else if (calc.operation == '$')
    // I used this sympol as the multiplication sympol instead of /* because it is more than one character and I had a problem with using a string.
    {
        return calc.a * calc.b;
    }
    else if (calc.operation == '/')
    {
        return calc.a / calc.b;
    }
    else
    {
        return 0;
    }
}
double calculation(double a, double b, char operation)
{
    if (operation == '+')
    {
        return a + b;
    }
    else if (operation == '-')
    {
        return a - b;
    }
    else if (operation == '$')
    // I used this sympol as the multiplication sympol instead of /* because it is more than one character and I had a problem with using a string.
    {
        return a * b;
    }
    else if (operation == '/')
    {
        return a / b;
    }
    else
    {
        return 0;
    }
}

double heron(double a, double b, double c)
{
    double s = (a + b + c) / 2;
    double area = std::sqrt(s * (s - a) * (s - b) * (s - c));
    return area;
}

double heron(Triangle t)
{
    double s = (t.a + t.b + t.c) / 2;
    double area = std::sqrt(s * (s - t.a) * (s - t.b) * (s - t.c));
    return area;
}
double square(double a)
{
    return a * a;
}
} // namespace mathematics

#endif // MATHEMATICS_HPP
