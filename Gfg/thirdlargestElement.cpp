
// Question : Given an array of distinct elements. Find the third largest element in that array...

// Sample Input :
//             N = 5 (Number of the element in array)
//             A[] = {42,74,11,73,50}  (array's elements)
// Sample Output :
//             50 (third largest element)

#include <bits/stdc++.h>
using namespace std;

//create a function to find third largest element...
int third_greatest(int arr[], int n)
{
    //let three variable such as ...
    int first = arr[0]; //first element of the array...
    int second = INT_MIN;
    int third = INT_MIN;
    //traverse the array....
    for (int i = 1; i < n; i++)
    {
        //check condition for first largest element
        if (arr[i] > first)
        {
            third = second;
            second = first;
            first = arr[i];
        }//condition for second largest element
        else if (arr[i] > second)
        {
            third = second;
            second = arr[i];
        }//condition for third largest...
        else if (arr[i] > third)
        {
            third = arr[i];
        }
    }
    return third;
}

int main()
{
    //input number of the elements in array..
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    //calling of the funtion
    int res = third_greatest(arr, n);
    //print our result..
    cout << res << endl;
    return 0;
}
