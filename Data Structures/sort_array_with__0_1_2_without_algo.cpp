/*
Method: Dutch national flag algorithm
This algorithm is used to sort an array of 0s 1s and 2s without the use of extra space or sorting algorithms
Most optimal solution
Other approaches-ARRAY SORTING or COUNTING SORT
O(n) time comlexity
O(1) space complexity

*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
void sort012(int a[], int n)
{
    //Dutch National Flag algorithm
    int low = 0;
    int mid = 0;
    int high = n - 1;
    while (mid <= high)
    {
        switch (a[mid])
        {
        case 0:
            swap(a[low++], a[mid++]);
            continue;
        case 1:
            mid++;
            continue;
        case 2:
            swap(a[mid], a[high--]);
            continue;
        }
    }
}

int main()
{
    int t = 1;
    //cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];    //input of array elements
        }
        sort012(a, n);
        for (int i = 0; i < n; i++)   //printing the array elements
        {
            cout << a[i] << " ";
        }
    }
}
