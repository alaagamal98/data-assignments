#include "mathematics.hpp" // for mathematics::calculation
#include <string>
#include <iostream>  // for std::cout and std::cin
#include <algorithm> // for std::atof

int main(int argc, char *argv[])
{
mathematics::calculator calc{0,0,0};

    if (argc == 1)
    {
        // If argc == 1, then the user hasn't introduce
        // command line arguments.
        // we can give him a chance to input his parameters
        // using std::cin
        std::cin >> calc.a >> calc.operation >> calc.b;
    }
    else if (argc == 4)
    {
        calc.a = std::atof(argv[1]);
        calc.b = std::atof(argv[3]);
        calc.operation = argv[2][0];
    }
    else
    {
        std::cout << "Incorrect usage!" << std::endl;
        return 1; // Failure Code!
    }

    std::cout << mathematics::calculation(calc) << std::endl;
    return 0; // Success Code!
}
