// Create count array of size maxElemnt+1;
// Find the count of each element in an array and store it in "Count array"
// Calculate the position of each element using "Count array"and store it in "position array". [intilize position[0-1]=0]
// Traverse the array from end and place the elemnt at value [position-1] extracted from position array
// soterd[postion[arr[i]]-1]=arr[i];


#include<iostream>
using namespace std;
void countSort(int arr[],int size)
{
    int maximum=0;
    for(int i=0;i<size;i++)
    {
        maximum=max(arr[i],maximum);
    }
    int countArray[maximum+1]={0};
   
    for(int i=0;i<size;i++)                 // defining the count of element in customized way; 
    {
        countArray[arr[i]]++;
    }
    int positionArray[maximum+1]={0};
    positionArray[0-1]={0};
    for(int i=0;i<maximum+1;i++)
    {
        positionArray[i]=positionArray[i-1]+countArray[i];
    }
    int sortedArray[size];int k=0;
    for(int i=size-1;i>=0;i--)
    {
        positionArray[arr[i]]=positionArray[arr[i]]-1;
        k=positionArray[arr[i]];

        sortedArray[k]=arr[i];
    }
    for(int i=0;i<size;i++)
    {
        arr[i]=sortedArray[i];
    }
    return;

}


int main()
{
    int arr[9]={1,3,2,3,4,1,6,4,3};
    countSort(arr,9);
    for(int i=0;i<9;i++)
    cout<<arr[i]<<" ";
}
