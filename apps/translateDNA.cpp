//
// Created by asem on 19/03/19.
//

#include "rna.hpp"
#include "helpers2.hpp"

int main( int argc , char **argv )
{
    if( argc != 2 )
    {
        std::cout << "Invalid usage!" << std::endl;
        return 1;
    }
    else
    {
        std::string dna = helpers::getFastaDNA( argv[1] );

        std::cout << translateDNA( dna ) << std::endl;

        return 0;
    }
}
