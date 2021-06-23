/*Problem : Find all triplets with zero sum*/

/*Explanation of problem : Given an array of distinct elements. The task is to find triplets in the array whose sum is zero.*/
/*Approach : 
    a> Sort the array in ascending order and traverse the array from start to end.
    b> For every index i, create two variables l = i + 1 and r = n – 1
    c> Run a loop until l is less than r if the sum of array[l], array[r] is equal to zero then print the triplet and break the loop
    d> If the sum is less than zero then increment the value of l, by increasing the value of l the sum will increase as the array is sorted, so array[l+1] > array [l]
    e> If the sum is greater than zero then decrement the value of r, by increasing the value of l the sum will decrease as the array is sorted, so array[r-1] < array [r].
*/
/* C++ program to find all triplets in an array with zero sum using Hashing*/
#include <bits/stdc++.h>
using namespace std;

void Triplets(int arr[], int n) /* function to print triplets with 0 sum */
{
    bool found = false;
    sort(arr, arr + n); /* sorting array elements */
    for (int i = 0; i < n - 1; i++)
    {
        int l = i + 1; /* initialize left and right */
        int r = n - 1;
        int x = arr[i];
        while (l < r)
        {
            if (x + arr[l] + arr[r] == 0)
            {
                printf("%d %d %d\n", x, arr[l], arr[r]); /* print elements if it's sum is zero*/
                l++;
                r--;
                found = true;
                break;
            }
            else if (x + arr[l] + arr[r] < 0) /* If sum of three elements is less than zero then increment in left */
                l++;

            else /* if sum is greater than zero than decrement in right side */
                r--;
        }
    }
    if (found == false)
        cout << "No Triplets Found in the array that would sum up to zero" << endl;
}

/* Main Program */
int main()
{
    int arr[] = {0, 1, 2, -3, -1};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "Triplets Found : \n";
    Triplets(arr, n);
    return 0;
}
/*
   Time Complexity : O(n2) //n2 = square of n
   Space Complexity : O(1)

   OUTPUT :
    Triplets found : 
    -3 1 2
    -1 0 1
*/