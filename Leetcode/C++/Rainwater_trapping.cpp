//problem
//Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it is able to trap after raining.

//Examples
//Input: arr[]   = {3, 0, 2, 0, 4}
//Output: 7

//Input: arr[] = [0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1]
//Output: 6

//The element of an array can store water only if there are higher bars on the left and right sides. 
//The amount of water to be stored in every element can be found out by finding the heights of bars on the left and right sides. 
//Now we will compute the amount of water that can be stored in every element of the array. 

//____________________________________________________________________________________________________________________________//
//Constraints:

//n == height.length
//0 <= n <= 3 * 104
//0 <= height[i] <= 105
//____________________________________________________________________________________________________________________________//
//Solution
#include <iostream>
using namespace std;
 
int calcWater(int arr[], int n)
{
    // initialize output
    int tot_water = 0;
 
    // maximum element on left and right
    int left_max = 0, right_max = 0;
 
    // indices to traverse the array
    int lo = 0, hi = n - 1;

    //start from first
    while (lo <= hi) {
        if (arr[lo] < arr[hi]) {
            if (arr[lo] > left_max)
                // update max in left
                left_max = arr[lo];
            else
                // water on curr element = max - curr
                tot_water+= left_max - arr[lo];
            lo++;
        }
        else {
            if (arr[hi] > right_max)
                // update right maximum
                right_max = arr[hi];
            else
                tot_water+= right_max - arr[hi];
            hi--;
        }
    }
 
    return  tot_water;
}
 
int main()
{
    int arr[] = { 0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1 };
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "Maximum water that can be accumulated is "
         << calcWater(arr, n);
}
// Time complexity o(n)
// Space complexity o(1)
