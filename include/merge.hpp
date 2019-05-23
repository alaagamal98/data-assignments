#include <vector>
#include <queue>

void merge( std::vector< double > &, int , int , int );

// A function to split array into two parts.
void mergeSort( std::vector< double > &a , int low, int high)
{
	if (low < high)
	{
		int mid=(low+high)/2;
		// Split the data into two half.
		mergeSort(a, low, mid);
		mergeSort(a, mid+1, high);
 
		// Merge them to get sorted output.
		merge(a, low, mid, high);
	}
}

void merge( std::vector< double > &a , int low, int mid , int high )
{
    int n1 = mid - low + 1;
    int n2 =  high - mid;
 
    std::queue<double> left, right;
    
    for (int i = 0; i < n1; i++)
        left.push( a[low + i] );
    for (int i = 0; i < n2; i++)
        right.push( a[mid + 1 + i]);
    
    int offset = low;
    while( !left.empty() && !right.empty())
    {
        if( left.front() < right.front())
        {
            a[ offset ] = left.front();
            left.pop();
        }
        else
        {
            a[ offset ] = right.front();
            right.pop();
        }
        ++offset;
    }

    while( !left.empty())
    {
        a[ offset++ ] = left.front();
        left.pop();
    }
    while( !right.empty())
    {
        a[ offset++ ] = right.front();
        right.pop();
    }
}