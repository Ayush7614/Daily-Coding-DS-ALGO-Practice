/* Given two sorted arrays arr1[] and arr2[] of sizes n and m in non-decreasing order. Merge them in sorted order without using any extra space. Modify arr1 so that it contains the first N elements and modify arr2 so that it contains the last M elements.*/

// This question is based on the Gap Method.

#include <bits/stdc++.h>
using namespace std;

//Function to merge the arrays.
int newGap(int gap)
{
    if (gap <= 1)
        return 0;
    return gap / 2 + gap % 2;
}
void merge(long long arr1[], long long arr2[], int n, int m)
{
    int i, j, gap = m + n;

    //we traverse the array till our gap became 0..
    for (gap = newGap(gap); gap > 0; gap = newGap(gap))
    {

        //now check the condition when both compared elements are in first array...
        for (i = 0; i + gap < n; i++)
        {
            if (arr1[i] > arr1[i + gap])
            {
                swap(arr1[i], arr1[i + gap]);
            }
        }

        //when compared elements are in first and second both array...
        for (j = 0; j < m && i < n; i++, j++)
        {
            if (arr1[i] > arr2[j])
                swap(arr1[i], arr2[j]);
        }

        //when compared element are in second array...
        for (j = 0; j + gap < m; j++)
        {
            if (arr2[j] > arr2[j + gap])
                swap(arr2[j], arr2[j + gap]);
        }
    }
}

int main()
{
    int n, m;
    cin >> n >> m;
    long long arr1[n], arr2[m];

    //input first array...
    for (int i = 0; i < n; i++)
        cin >> arr1[i];
    
    //input second array...
    for (int i = 0; i < m; i++)
        cin >> arr2[i];

    //call the function..
    merge(arr1, arr2, n, m);

    //print first array after performing task...
    for (int i = 0; i < n; i++)
        cout << arr1[i] << " ";

    //print second array after performing task...
    for (int i = 0; i < m; i++)
        cout << arr2[i] << " ";
    cout << endl;


return 0;
}

// Input :
//      n, m :     4 5
//      arr1[] :   1 3 5 7
//      arr2[] :   0 2 6 8 9

// Output :
//      arr1[] :  [0 1 2 3] 
//      arr2[] :  [5 6 7 8 9]