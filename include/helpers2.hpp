#ifndef HELPERS_HPP
#define HELPERS_HPP

#include <string>
#include <iostream>  // for std::cout
#include <fstream>   // for std::ifstream (loading files from disk)

namespace helpers
{

std::string getFastaDNA( const char *filePath )
{
    std::ifstream input(filePath);
    std::string line, dna;

    if (input)
    {
        while (std::getline(input, line))
        {
            // line may be empty so you *must* ignore blank lines
            // or you have a crash waiting to happen with line[0]
            if (line.empty())
                continue;

            if (line.front() == '>')
            {
                continue;
            }
            else
            {
                dna += line;
            }
        }
    }
    else
    {
        std::cout << "Failed to open file:" << filePath << std::endl;
    }
    return dna;
}

} // namespace helpers

#endif // HELPERS_HPP
