#include "map.hpp"
#include <map>
#include <iostream>
#include "helpers3.hpp"

int main(int argc, char **argv)
{
    if (argc == 2)
    {
        std::string dna = getFileFirstLine(argv[1]);

        // Replace the `std::map` with your own dictionary that maps chars to integers.
        map::Map<char, int> dnaCounter;

        for (char &c : dna)
        {
            // Use `dnaCounter.value( c )++` instead
            dnaCounter.value(c)++;
        }

        // Replace the for with `map::printAll( dnaCounter );`
        dnaCounter.printAll();
    }

    return 0;
}