#ifndef DNA_HPP
#define DNA_HPP

#include "arrays.hpp"

// Your code starts from here
namespace dna
{
using DNAArray = arrays::CharacterArray;
struct counter
{
    int counterA;
    int counterC;
    int counterG;
    int counterT;
};
char complementaryBase(char base)
{
    switch (base)
    {
    case 'A':
    {
        return 'T';
    }
    break;
    case 'T':
    {
        return 'A';
    }
    break;
    case 'G':
    {
        return 'C';
    }
    break;
    default:
    {
        return 'G';
    }
    break;
    }
    // First I used a default case, but as the dna has other bases different from the 4 bases (A,T,C,G) so the complementarySequance wasn't written completely and stopped when the first different base appeared, so to solve this I removed the deafult case.
}
char *complementarySequence(DNAArray array)
{
    char *dna_seq = new char[array.size];
    for (int i = 0; i < array.size; ++i)
    {
        dna_seq[i] = complementaryBase(array.base[(array.size - 1) - i]);
    }
    return dna_seq;
}
char *complementarySequence(char *base, int size)
{
    char *dna_seq = new char[size];
    for (int i = 0; i < size; ++i)
    {
        dna_seq[i] = complementaryBase(base[(size - 1) - i]);
    }
    return dna_seq;
}

char *analyzeDNA(char *base, int size, int &countA, int &countC, int &countG, int &countT)
{
    countA = arrays::countCharacter(&base[0], size, 'A');
    countC = arrays::countCharacter(&base[0], size, 'C');
    countG = arrays::countCharacter(&base[0], size, 'G');
    countT = arrays::countCharacter(&base[0], size, 'T');
    return complementarySequence(&base[0], size);
}
char *analyzeDNA(DNAArray array, counter &count)
{
    count.counterA = arrays::countCharacter(array, 'A');
    count.counterC = arrays::countCharacter(array, 'C');
    count.counterG = arrays::countCharacter(array, 'G');
    count.counterT = arrays::countCharacter(array, 'T');
    return complementarySequence(array);
}
} // namespace dna
// Your code ends here

#endif // DNA_HPP
