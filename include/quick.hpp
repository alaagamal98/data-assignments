#include <algorithm>
#include <vector>
#include <iostream>

int partition(std::vector<double> &a, int low, int high);

void quickSort(std::vector<double> &a, int low, int high)
{
    if (low < high)
    {
        int pIdx = partition(a, low, high);

        if (low < pIdx)
            quickSort(a, low, pIdx - 1); // Before pi
        if (high > pIdx)
            quickSort(a, pIdx + 1, high); // After pi
    }
}

int partition(std::vector<double> &a, int low, int high)
{
    int pivot = a[low];

    int i = low + 1, j = high;

    while (i <= j)
    {
        while (i <= j && a[i] < pivot)
            ++i;
        while (i <= j && a[j] > pivot)
            --j;
        if (i <= j)
            std::swap(a[i++], a[j--]);
    }
    std::swap( a[--i] , a[low] );
    return i;
}