#include "hash_chaining.hpp"
#include "helpers3.hpp"


int main( int argc, char **argv )
{
    if( argc == 2 )
    {
        std::string dna = getFileFirstLine( argv[1] );

        auto cMap = hash::create();

        // Complete here!
        for( auto b : dna )
            hash::value( cMap , b )++;

        // Done here!

        hash::printAll( cMap );
    }

    return 0;
}