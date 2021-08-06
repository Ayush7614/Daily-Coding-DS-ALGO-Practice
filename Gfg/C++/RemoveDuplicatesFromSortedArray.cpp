/*Problem : REMOVE DUPLICATES FROM A SORTED ARRAY*/

/*Explanation of problem : Given a sorted array, the task is to remove the duplicate elements from the array*/

/* For example:
    if Input array = {2, 2, 2, 4, 4}
    --> Output array = {2, 4}
        new size = 2

    if Input array = {14, 22, 22, 31, 40, 40, 40, 52, 56}
    --> Output array = {14, 22, 31, 40, 52, 56}
         new size = 6
*/

// Simple C++ program to remove duplicates
#include <iostream>
using namespace std;

// Function remDUP removes duplicate elements and return new size of modified array.
int remDUP(int a[], int n)
{
    if (n == 0 || n == 1)
        return n; // Returns, if array is empty or contains a single element

    int b[n]; //b[] is an auxillary array to store unique elements
    int j = 0;
    for (int i = 0; i < n - 1; i++)
    { // If current element is not equal to next element then store that current element in b[] array
        if (a[i] != a[i + 1])
            b[j++] = a[i];
    }
    b[j++] = a[n - 1]; // Store the last element as whether it is unique or repeated, it hasn't stored previously

    for (int i = 0; i < j; i++) // Modifying the original array
        a[i] = b[i];

    return j;
}

// Main Function
int main()
{
    int a[] = {20, 21, 22, 22, 24, 24, 24, 25, 25, 26};
    int n = sizeof(a) / sizeof(a[0]);

    n = remDUP(a, n); // remDUP() returns new size of array.

    cout << "Array after removing all duplicates : \n";
    for (int i = 0; i < n; i++) // Prints updated array
        cout << a[i] << " ";

    return 0;
}
/*
   Time Complexity : O(n) 
   Space Complexity : O(n)

   OUTPUT :
   Array after removing all duplicates : 
   20 21 22 24 25 26
*/