#include <bits/stdc++.h>
using namespace std;
 
// Function to sort the input array of {0,1,2}

void arrange(int arr[], int size)
{
    int low = 0;
    int high = size - 1;
    int mid = 0;
 
    while (mid <= high) {
        switch (arr[mid]) {
 
        // If the element is 0
        case 0:
            swap(arr[low++], arr[mid++]);
            break;
 
        // If the element is 1 .
        case 1:
            mid++;
            break;
 
        // If the element is 2
        case 2:
            swap(arr[mid], arr[high--]);
            break;
        }
    }
}
 
// Function to print array 
void print(int arr[], int size)
{
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
}
 

int main()
{
   int arr[50],n;
   cout<<"Accept the value of n ";
   cin>>n;
   cout<<"Accept the values ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        cout<<" ";
    }
    arrange(arr, n);
    cout << "Array after Sorting ";
    print(arr, n);
    return 0;
}
 
/* 
Time Complexity: O(n). 

Space Complexity: O(1). 

*/