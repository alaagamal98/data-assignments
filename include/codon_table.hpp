//
// Created by asem on 19/03/19.
//

#ifndef SBE201_STACKS_QUEUES_CODON_TABLE_HPP
#define SBE201_STACKS_QUEUES_CODON_TABLE_HPP

#include <string>
#include <map>


std::map<std::string, char> makeLookupTable()
{
    std::map<std::string, char> lut;
    lut["AAA"] = 'K';
    lut["AAC"] = 'N';
    lut["AAG"] = 'K';
    lut["AAU"] = 'N';
    lut["ACA"] = 'T';
    lut["ACC"] = 'T';
    lut["ACG"] = 'T';
    lut["ACU"] = 'T';
    lut["AGA"] = 'R';
    lut["AGC"] = 'S';
    lut["AGG"] = 'R';
    lut["AGU"] = 'S';
    lut["AUA"] = 'I';
    lut["AUC"] = 'I';
    lut["AUG"] = 'M';
    lut["AUU"] = 'I';
    lut["CAA"] = 'Q';
    lut["CAC"] = 'H';
    lut["CAG"] = 'Q';
    lut["CAU"] = 'H';
    lut["CCA"] = 'P';
    lut["CCC"] = 'P';
    lut["CCG"] = 'P';
    lut["CCU"] = 'P';
    lut["CGA"] = 'R';
    lut["CGC"] = 'R';
    lut["CGG"] = 'R';
    lut["CGU"] = 'R';
    lut["CUA"] = 'L';
    lut["CUC"] = 'L';
    lut["CUG"] = 'L';
    lut["CUU"] = 'L';
    lut["GAA"] = 'E';
    lut["GAC"] = 'D';
    lut["GAG"] = 'E';
    lut["GAU"] = 'D';
    lut["GCA"] = 'A';
    lut["GCC"] = 'A';
    lut["GCG"] = 'A';
    lut["GCU"] = 'A';
    lut["GGA"] = 'G';
    lut["GGC"] = 'G';
    lut["GGG"] = 'G';
    lut["GGU"] = 'G';
    lut["GUA"] = 'V';
    lut["GUC"] = 'V';
    lut["GUG"] = 'V';
    lut["GUU"] = 'V';
    lut["UAA"] = '_';
    lut["UAC"] = 'Y';
    lut["UAG"] = '_';
    lut["UAU"] = 'T';
    lut["UCA"] = 'S';
    lut["UCC"] = 'S';
    lut["UCG"] = 'S';
    lut["UCU"] = 'S';
    lut["UGA"] = '_';
    lut["UGC"] = 'C';
    lut["UGG"] = 'W';
    lut["UGU"] = 'C';
    lut["UUA"] = 'L';
    lut["UUC"] = 'F';
    lut["UUG"] = 'L';
    lut["UUU"] = 'F';
    return lut;
}

const std::map<std::string, char> codon2AATable = makeLookupTable();

#endif //SBE201_STACKS_QUEUES_CODON_TABLE_HPP
