

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void merge(int arr1[], int arr2[], int n, int m)
    {

        // Starting from last index of first array and first index of second arary
        int i = n - 1;
        int j = 0;

        //iterating till the small array is traversed [Note that AND operator is
        //used]
        while (i >= 0 && j < m)
        {
            if (arr1[i] > arr2[j])
            {
                swap(arr1[i], arr2[j]);
                i--;
                j++;
            }
            else
            {
                break;
            }
        }

        //Sorting both the arrays
        sort(arr1, arr1 + n);
        sort(arr2, arr2 + m);
    }
};

int main()
{
    int t;
    cin >> t;
    while (t--)
    {

        //n -> Size of first Array
        //m -> Size of Second Array
        //i -> Iterator
        //arr1 -> First Array
        //arr2 ->Second Array
        int n, m, i;
        cin >> n >> m;
        int arr1[n], arr2[m];
        for (i = 0; i < n; i++)
        {
            cin >> arr1[i];
        }
        for (i = 0; i < m; i++)
        {
            cin >> arr2[i];
        }

        //Creating an instance of class
        Solution ob;
        ob.merge(arr1, arr2, n, m);
        for (i = 0; i < n; i++)
        {
            cout << arr1[i] << " ";
        }
        for (i = 0; i < m; i++)
        {
            cout << arr2[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}
