#include <vector>
#include <algorithm>

namespace heap
{

struct Heap
{
    std::vector<int> buffer;
};

int getLeftIdx(int parent)
{
    return parent * 2 + 1;
}

int getRightIdx(int parent)
{
    return parent * 2 + 2;
}

int getParentIdx(int child)
{
    if (child % 2 == 1)
    {
        return (child - 1) / 2;
    }
    else
    {
        return (child - 2) / 2;
    }
}


int size(Heap &h)
{
    return h.buffer.size();
}

void bubbleUp(Heap &h, int child )
{
    int parent = getParentIdx(child);
    if( child >= 0 && parent >= 0  && h.buffer[child] < h.buffer[parent])
    {
        std::swap(h.buffer[child], h.buffer[parent]);
        bubbleUp( h , parent );
    }
}

void bubbleDown(Heap &h, int parent)
{
    int left = getLeftIdx(parent);
    int right = getRightIdx(parent);
    int length = size(h);
    int minimum = parent;

    if (left < length && h.buffer[left] < h.buffer[minimum])
        minimum = left;

    if (right < length && h.buffer[right] < h.buffer[minimum])
        minimum = right;

    if (minimum != parent)
    {
        std::swap(h.buffer[minimum], h.buffer[parent]);
        bubbleDown(h, minimum);
    }
    else return;
}

void insert(Heap &h, int data)
{
    h.buffer.push_back(data);
    int childIdx = h.buffer.size() - 1;
    bubbleUp( h , childIdx );
}

int extract(Heap &h)
{
    int child = h.buffer.size() - 1;
    std::swap(h.buffer[child], h.buffer[0]);

    int value = h.buffer.back();
    h.buffer.pop_back();

    bubbleDown( h , 0);
    return value;
}


}