#ifndef ARRAYS_HPP
#define ARRAYS_HPP

#include <iostream>
#include "mathematics.hpp"

// Your code starts from here
namespace arrays
{
struct DoubleArray
{
    double *base;
    int size;
};
struct CharacterArray
{
    char *base;
    int size;
};
void printAll(DoubleArray array)
{
    for (int i = 0; i < array.size; ++i)
    {
        std::cout << array.base[i] << ", ";
    }
    std::cout << std::endl;
}
void printAll(double *base, int arraySize)
{
    for (int i = 0; i < arraySize; ++i)
    {
        std::cout << base[i] << ", ";
    }
    std::cout << std::endl;
}
double maxArray(double *base, int arraySize)
{
    double max_num = base[0];
    for (int i = 0; i < arraySize; ++i)
    {
        if (base[i] > max_num)
        {
            max_num = base[i];
        }
    }
    return max_num;
}
double maxArray(DoubleArray array)
{
    double max_num = array.base[0];
    for (int i = 0; i < array.size; ++i)
    {
        if (array.base[i] > max_num)
        {
            max_num = array.base[i];
        }
    }
    return max_num;
}
double minArray(DoubleArray array)
{
    double min_num = array.base[0];
    for (int i = 0; i < array.size; ++i)
    {

        if (array.base[i] < min_num)
        {
            min_num = array.base[i];
        }
    }
    return min_num;
}
double minArray(double *base, int arraySize)
{
    double min_num = base[0];
    for (int i = 0; i < arraySize; ++i)
    {
            
        if (base[i] < min_num)
        {
            min_num = base[i];
        }
    }
    return min_num;
}
double meanArray(double *base, int arraySize)
{
    double sum = 0;
    for (int i = 0; i < arraySize; ++i)
    {
        sum += base[i];
    }
    return sum / arraySize;
}

double meanArray(DoubleArray array)
{
    double sum = 0;
    for (int i = 0; i < array.size; ++i)
    {
        sum += array.base[i];
    }
    return sum / array.size;
}
double varianceArray(DoubleArray array)
{
    double sum_var = 0;
    double mean = meanArray(array);
    for (int i = 0; i < array.size; ++i)
    {
        sum_var += mathematics::square(mean - array.base[i]);
    }
    return sum_var / array.size;
}
double varianceArray(double *base, int arraySize)
{
    // Logic here
    double sum_var = 0;
    double mean = meanArray(&base[0], arraySize);
    for (int i = 0; i < arraySize; ++i)
    {
        sum_var += mathematics::square(mean - base[i]);
    }
    return sum_var / arraySize;
    // Hint: use meanArray ;)
    // Do you need a square function?
    // Maybe you can implement one in mathematics.hpp
    // then include "mathematics.hpp" to use mathematics::square here
}
int countCharacter(char *basePointer, int size, char query)
{
    int counter = 0;
    for (int i = 0; i < size; ++i)
    {
        if (basePointer[i] == query)
        {
            ++counter;
        }
    }
    return counter;
}
int countCharacter(CharacterArray array, char query)
{
    int counter = 0;
    for (int i = 0; i < array.size; ++i)
    {
        if (array.base[i] == query)
        {
            ++counter;
        }
    }
    return counter;
}
} // namespace arrays

// Your code ends here

#endif // ARRAYS_HPP
