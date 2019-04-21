//
// Created by asem on 19/03/19.
//

#ifndef SBE201_STACKS_QUEUES_RNA_HPP
#define SBE201_STACKS_QUEUES_RNA_HPP

#include <string>
#include "codon_table.hpp"
#include "adt.hpp"

char codon2Aminoacid( char b1, char b2, char b3 )
{
    std::string codon = {b1, b2, b3};
    return codon2AATable.at( codon );
}

std::string transcribeDNA( const std::string &dna )
{
    // REQUIRED: Make an `rna` variable of type `std::string`, and initialize with a copy of `dna` sequence.
    std::string rna = dna;

    // REQUIRED: Loop on `rna`, convert each `T` to `U`.
    for (int i = 0; i < rna.size(); ++i)
    {
        if (rna[i] == 'T')
        {
            rna[i] = 'U';
        }
    }

    // REQUIRED: return `rna`
    return rna;
}


std::string translateRNA( const std::string &rna )
{
    // REQUIRED IMPLEMENTATION.
    ADT::QueueLL<char> rnaQueue;
    std::string protein;
    for (int i = 0; i < rna.size() - 2; i = i + 3)
    {
        char codon = codon2Aminoacid(rna[i], rna[i + 1], rna[i + 2]);
        rnaQueue.enqueue( codon);
    }
    while (!rnaQueue.isEmpty())
    {

        protein.push_back(rnaQueue.frontt());
        rnaQueue.dequeue();
    }
    return protein;
}

std::string translateDNA( const std::string &dna )
{
    std::string rna = transcribeDNA( dna );
    std::string protein = translateRNA( rna );
    return protein;
}


#endif //SBE201_STACKS_QUEUES_RNA_HPP
