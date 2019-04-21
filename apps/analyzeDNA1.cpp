#include "helpers1.hpp" // for helpers::loadDNA
#include "dna1.hpp"     // for dna::analyzeDNA

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        std::cout << "Invalid usage!" << std::endl;
        return 1;
    }
    else
    {
        int size = 0;
        char *dnaArray1 = helpers::getFastaDNA(argv[1], size);
        dna::DNAArray dna{dnaArray1, size};
        dna::counter count{0, 0, 0, 0};
        char *complementarySeq = dna::analyzeDNA(dna, count);
        std::cout << dnaArray1 << std::endl;
        
        // We may need to make a new character array, but with a null terminated character to be able to print on screen.
        char *complementarySeqTerminated = new char[size + 1];
        std::copy(&complementarySeq[0], &complementarySeq[size], &complementarySeqTerminated[0]);
        complementarySeqTerminated[size] = '\0';

        std::cout << "Adenine (A) content:" << count.counterA << std::endl
                  << "Guanine (G) content:" << count.counterG << std::endl
                  << "Cytocine(C) content:" << count.counterC << std::endl
                  << "Thymine (T) content:" << count.counterT << std::endl
                  << std::endl
                  << "Complementary Sequence:" << std::endl
                  << complementarySeqTerminated << std::endl;

        // Clean up.
        delete[] complementarySeq;
        delete[] complementarySeqTerminated;
        return 0;
    }
}

