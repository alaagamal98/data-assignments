//
// Created by asem on 19/03/19.
//

#ifndef SBE201_STACKS_QUEUES_DNA_HPP
#define SBE201_STACKS_QUEUES_DNA_HPP

#include <string>
#include <stack>
#include "adt.hpp"

char complementaryBase( char base )
{
    switch ( base )
    {
        case 'A':
            return 'T';
        case 'C':
            return 'G';
        case 'G':
            return 'C';
        default:
            return 'A';
    }
}

std::string complementarySequence1( const std::string &dna )
{
    // Allocate string with the same size of `dna`, and init with zeros.
    std::string complementary = std::string( dna.size(), 0 );
    for ( int i = 0; i < dna.size(); ++i )
    {
        complementary[i] = complementaryBase( dna[dna.size() - 1 - i] );
    }
    return complementary;
}

std::string complementarySequence2( const std::string &dna )
{
    // Empty string.
    std::string complementary;
    std::stack<char> dnaStack;

    for ( int i = 0; i < dna.size(); ++i )
    {
        char c = complementaryBase( dna[i] );
        dnaStack.push( c );
    }

    // Now populate the `complementary` from the stack.
    while ( !dnaStack.empty())
    {
        char c = dnaStack.top();
        complementary.push_back( c );
        dnaStack.pop();
    }

    return complementary;
}

std::string complementarySequence3( const std::string &dna )
{
    std::string complementary; // Empty string.

    // REQUIRED: Declare your implemented stack of characters here.

    ADT::StackLL<char> dnaStack;

    // This loop converts the bases to their complementary then push them into the stack.
    for ( int i = 0; i < dna.size(); ++i )
    {
        char c = complementaryBase( dna[i] );

        // REQUIRED: Push `c` to your stack here
        dnaStack.push(c);
    }

    // REQUIRED: populate the `complementary` sequence using the stack.
    while (!dnaStack.isEmpty())
    {
        char c = dnaStack.frontt();
        complementary.push_back(c);
        dnaStack.pop();
    }

        return complementary;
}


#endif //SBE201_STACKS_QUEUES_DNA_HPP
