/*

Allocate minimum number of pages 


Problem Statement: 

You are given N number of books. Every ith book has Ai number of pages. 
You have to allocate books to M number of students. There can be many ways or permutations to do so. 
In each permutation, one of the M students will be allocated the maximum number of pages. 
Out of all these permutations, the task is to find that particular permutation in which the maximum number of 
pages allocated to a student is minimum of those in all the other permutations and print this minimum value. 
Each book will be allocated to exactly one student. Each student has to be allocated at least one book.

Note: Return -1 if a valid assignment is not possible, and allotment should be in contiguous order (see the explanation for better understanding).


Example 1:

Input:
N = 4
A[] = {12,34,67,90}
M = 2
Output:
113


Example 2:

Input:
N = 3
A[] = {15,17,20}
M = 2
Output:
32


Constraints:
1 <= N <= 105
1 <= A [ i ] <= 106
1 <= M <= 105

*/


// ********************************************************************************************************


// Solution

public class AllocateMinimumNumberOfPages{
    static boolean isValid(int []arr,int n,int m,int max){
        int student = 1;
        int sum = 0;
        for(int i=0;i<n;i++) {
            sum += arr[i];
            
            if(sum > max) {
                student++;
                sum = arr[i];
            }
        
        if(student>m)
            return false;
        }
        return true;
    }

    static int findPages(int[]arr,int n,int m){ 
        if(n < m) 
            return -1;
        
        int start = 0, end = 0;
		int ans = Integer.MAX_VALUE;
		
        for(int i = 0; i < n; i++) {
            start = Math.max(arr[i],start);
            end += arr[i];
        }
    
        int mid;
        // binary search
        while(start <= end) { 
            mid = start + (end - start) / 2;
            if(isValid(arr, n, m, mid)) {
                ans = mid;
                end = mid - 1;
            }
        
            else {
                start = mid + 1;
            }
        }
    return ans;
    }



 public static void main(String[] args)
    {
        //Number of pages in books
        int arr[] = {12, 34, 67, 90};
        
        int m = 2; //No. of students
      
        System.out.println("Minimum number of pages = " +
                          findPages(arr, arr.length, m));
    }
}



//  Time Complexity: O(NlogN)
//  Space Complexity: O(1)
