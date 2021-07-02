// Given an array arr of n elements which is first increasing and then may be decreasing, find the maximum element in the array.
// Note: If the array is increasing then just print then last element will be the maximum value.

// Example

// Input: 
// n = 9
// arr[] = {1,15,25,45,42,21,17,12,11}
// Output: 45
// Explanation: Maximum element is 45.

// Input: 
// n = 5
// arr[] = {1, 45, 47, 50, 5}
// Output: 50
// Explanation: Maximum element is 50.

//Naive Approach
//Time complexity: O(n). 
// One traversal is needed so the time complexity is O(n)
// Space Complexity: O(1). 
// No extra space is needed, so space complexity is constant

public class Bitonic_point{

// Find the peak element in the array
    static int findPeak(int arr[], int n)
    {
        if(n == 1) return 0;
        int num = arr[0];
        int i = 1;
        while(i < n){
            if(arr[i] > num)
                num = arr[i];
            i++;
        }
        return num;
    }
    public static void main(String[] args)
    {
        int arr[] = { 1, 3, 20, 4, 1, 0 };
        int n = arr.length;
        
        System.out.print("Peak point is " +findPeak(arr, n));
    }
}

// Better approach using binary search
// Time Complexity: O(Logn). 
// Where n is the number of elements in the input array. In each step our search becomes half. So it can be compared to Binary search, So the time complexity is O(log n)
// Space complexity: O(1). 
// No extra space is required, so the space complexity is constant.

class PeakElement {
    // A binary search based function
    // that returns index of a peak element
    static int findPeakUtil(
        int arr[], int low, int high, int n)
    {
        // Find index of middle element
        // (low + high)/2
        int mid = low + (high - low) / 2;

        // Compare middle element with its
        // neighbours (if neighbours exist)
        if ((mid == 0 || arr[mid - 1] <= arr[mid])
            && (mid == n - 1 || arr[mid + 1] <= arr[mid]))
            return mid;

        // If middle element is not peak
        // and its left neighbor is
        // greater than it, then left half
        // must have a peak element
        else if (mid > 0 && arr[mid - 1] > arr[mid])
            return findPeakUtil(arr, low, (mid - 1), n);

        // If middle element is not peak
        // and its right neighbor
        // is greater than it, then right
        // half must have a peak
        // element
        else
            return findPeakUtil(
                arr, (mid + 1), high, n);
    }

    // A wrapper over recursive function
    // findPeakUtil()
    static int findPeak(int arr[], int n)
    {
        return findPeakUtil(arr, 0, n - 1, n);
    }

    // Driver method
    public static void main(String[] args)
    {
        int arr[] = { 1, 3, 20, 4, 1, 0 };
        int n = arr.length;
        System.out.println("Peak point is " + arr[findPeak(arr, n)]);
    }
}