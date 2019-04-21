#include "helpers1.hpp" // for helpers::loadDNA
#include "dna3.hpp"     // for dna::analyzeDNA

int main(int argc, char **argv) {
    if (argc != 2) {
        std::cout << "Invalid usage!" << std::endl;
        return 1;
    } else {
        int size = 0;
        char *dnaArray1 = helpers::getFastaDNA(argv[1], size);

        dna::DNA dna{dnaArray1};

        std::cout << "Adenine (A) content:" << dna.countChar('A') << std::endl
                  << "Guanine (G) content:" << dna.countChar('G') << std::endl
                  << "Cytocine(C) content:" << dna.countChar('C') << std::endl
                  << "Thymine (T) content:" << dna.countChar('T') << std::endl
                  << std::endl
                  << "Complementary Sequence:" << std::endl
                  << dna.complementarySequence() << std::endl;
                  
        return 0;
    }

}