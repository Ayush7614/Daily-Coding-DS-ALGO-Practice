// Question
/*
https://www.geeksforgeeks.org/recursive-program-to-find-all-indices-of-a-number/
*/

// Solution

import java.util.Scanner;

class Solution {
    public static int[] AllIndices(int[] arr, int x, int start, int tot) {

        if(start == arr.length)
            return new int[tot];

        int[] res;
        if(arr[start] == x){
            res = AllIndices(arr, x, start + 1, tot + 1);
            res[tot] = start;
        }else {
            res = AllIndices(arr, x, start + 1, tot);
        }
        return res;
    }

    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();

        int[] arr = new int[n];
        for(int i = 0;i < n;i++)
            arr[i] = sc.nextInt();

        int x = sc.nextInt();
        int[] res= (AllIndices(arr, x, 0, 0));

        for(int i = 0;i < res.length;i++)
            System.out.println(res[i]);
    }
}

// Example
/*
Input: arr = {1, 2, 3, 2, 2, 5}, X = 2 
Output: 1 3 4 

Input: arr[] = {7, 7, 7}, X = 7 
Output: 0 1 2 
*/