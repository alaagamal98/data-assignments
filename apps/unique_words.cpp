#include "set.hpp"
#include "helpers3.hpp"

using SetString = set::Set<std::string>;

int main( int argc, char **argv )
{
    if( argc == 2 )
    {
        std::vector< std::string > words = getFileWords( argv[1] );
        std::cout << words.size() << std::endl;

        SetString wordSet;

        for( std::string &word : words )
            wordSet.add(word);

        std::cout << wordSet.size() << std::endl;
        wordSet.printAll();
    }

    return 0;
}