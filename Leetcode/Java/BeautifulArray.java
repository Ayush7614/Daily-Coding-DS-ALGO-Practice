/*
 * Implementation of Beautiful Array problem of LeetCode
 * 
 * Problem statement:
 * An array nums of length n is beautiful if:
 *      1. nums is a permutation of the integers in the range [1, n].
 *      2. For every 0 <= i < j < n, there is no index k with i < k < j 
 *         where 2 * nums[k] == nums[i] + nums[j].
 * 
 * Given the integer n, return any beautiful array nums of length n. There will 
 * be at least one valid answer for the given n.
 * 
 * Problem link: https://leetcode.com/problems/beautiful-array/
 */

import java.util.*;
import java.io.*;

class BeautifulArray 
{
    public int[] beautifulArray(int n) 
    {
        ArrayList<Integer> arr = new ArrayList<>();
        arr.add(1);
        while(arr.size()<n)
        {
            ArrayList<Integer> tmp = new ArrayList<>();
            for(int i : arr)
            {
                if(2*i - 1 <=n)
                    tmp.add(2*i - 1);
            }
            for(int i : arr)
            {
                if(2*i <=n)
                    tmp.add(2*i);
            }
            arr = tmp;
        }
        int ans[]= new int[arr.size()];
        for(int i = 0; i<arr.size(); i++)
            ans[i] = arr.get(i);
        
        return ans;
    }
    
    public static void main(String args[])
    {
        Scanner sc = new Scanner(System.in);
        BeautifulArray obj = new BeautifulArray();
        int n = sc.nextInt();
        int ans[] = obj.beautifulArray(n);
        for(int i = 0; i<ans.length ; i++)
            System.out.print(ans[i]+" ");
            
    }
}

/*
 * Time Complexity: O(N*logN)
 * Space Complexity: O(N*logN)
 * 
 * Example 1:
 * 
 * Input: n = 4
 * Output: [2,1,4,3]
 * 
 * Example 2:
 * 
 * Input: n = 5
 * Output: [3,1,2,5,4]
 */