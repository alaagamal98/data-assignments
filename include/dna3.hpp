#ifndef DNA_HPP
#define DNA_HPP

#include <string>

namespace dna
{

char complementaryBase(char base)
{
    switch (base)
    {
    case 'A':
        return 'T';
    case 'T':
        return 'A';
    case 'C':
        return 'G';
    default:
        return 'C';
    }
}

struct DNA
{
    struct Distribution
    {
        int countA;
        int countG;
        int countT;
        int countC;
    };

    std::string complementarySequence()
    {
        std::string compSeq = sequence;
        for (int i = 0; i < sequence.size(); ++i)
        {
            compSeq[sequence.size() - 1 - i] = complementaryBase(sequence[i]);
        }
        return compSeq;
    }

    int countChar(char target)
    {
        int counter = 0;
        for (int i = 0; i < sequence.length(); ++i)
        {
            if (sequence[i] == target)
            {
                ++counter;
            }
        }
        return counter;
    }

    Distribution computeDistribution()
    {
        Distribution d;
        d.countA = countChar('A');
        d.countG = countChar('G');
        d.countC = countChar('C');
        d.countT = countChar('T');
        return d;
    }

    std::string sequence;
};

} // namespace dna

#endif