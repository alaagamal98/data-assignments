#include "mathematics.hpp" // for mathematics::heron
#include <iostream>        // for std::cout
#include <algorithm>       // for std::atof
#include <string>

// We need main function here!4
int main(int argc, char *argv[])
{
    mathematics::Triangle t{0,0,0};
    if (argc == 1)
    {
        std::cin >> t.a >> t.b >> t.c;
    }
    else if (argc == 4)
    {
        t.a = std::atof(argv[1]);
        t.b = std::atof(argv[2]);
        t.c = std::atof(argv[3]);
    }
    else
    {
        std::cout << "Incorrect usage!" << std::endl;
        return 1; // Failure Code!
    }
    std::cout << mathematics::heron(t) << std::endl;
    return 0;
}