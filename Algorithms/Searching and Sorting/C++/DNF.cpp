// Given an array containing only 0,1 and 2. You have to sort the array in O(N) time,
// single pass, and O(1) space.
// we take 3variables [low,mid,high]
// set low=0,mid=0,high=n-1;
// Traverse array and check arr[mid]
// if 0, swap(arr[low],arr[mid]) low++ mid++
// if 1, mid++;
// if 2, swap(arr[mid],arr[high]) high--

#include <iostream>
using namespace std;
void dnf(int arr[],int size )
{
    int low=0,mid=0,high=size-1;
    for(int i=0;i<size;i++)
    {
        if(arr[mid]==0)
        {
            swap(arr[low],arr[mid]);
            low++;
            mid++;
        }
        else if(arr[mid]==1)
        {
            mid++;
        }
        else if(arr[mid]==2)
        {
            swap(arr[mid],arr[high]);
            high--;
        }
        else if(mid==high)
        break;
    }
    return;
}
int main()
{
    int arr[9]={1,0,2,1,0,1,2,1,2};
    dnf(arr,9);
    for(int i=0;i<9;i++)
    cout<<arr[i]<<" ";
    
}
