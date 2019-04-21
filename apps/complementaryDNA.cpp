//
// Created by asem on 19/03/19.
//

#include "helpers2.hpp"
#include "dna2.hpp"

int main( int argc, char **argv )
{
    if ( argc != 2 )
    {
        std::cout << "Invalid usage!" << std::endl;
        return 1;
    } else
    {
        std::string dna = helpers::getFastaDNA( argv[1] );

        std::cout << complementarySequence3( dna ) << std::endl;


        // Verify the output of the 3rd version function with the former versions.
        std::string complementaryDNA1 = complementarySequence1( dna );
        std::string complementaryDNA2 = complementarySequence2( dna );
        std::string complementaryDNA3 = complementarySequence3( dna );

        if ( complementaryDNA1 == complementaryDNA2 &&
             complementaryDNA2 == complementaryDNA3 )
        {
            std::cout << "VERIFIED!" << std::endl;
        } else
        {
            std::cout << "INCORRECT!" << std::endl;
        }

        return 0;
    }
}