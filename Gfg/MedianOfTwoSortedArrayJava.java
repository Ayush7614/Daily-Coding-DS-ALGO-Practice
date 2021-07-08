// Given two sorted arrays of sizes N and M respectively. The task is to find the median of the two arrays when they get merged.


// Input:
// N = 5, M = 6 
// arr[] = {1,2,3,4,5}
// brr[] = {3,4,5,6,7,8}

// Output: 4
// Explanation: After merging two arrays, 
// elements will be as 1 2 3 3 4 4 5 5 6 7 8
// So, median is 4.

// problem link: https://practice.geeksforgeeks.org/problems/median-of-two-sorted-arrays1618/1/?track=P100-Searching#
import java.util.*;
public class MedianOfTwoSortedArrayJava
{

    public static void main(String[] args)
    {
         Scanner scn = new Scanner(System.in);

         int n = scn.nextInt();

         int[] arr = new int[n];
         for(int i=0;i<n;i++)
         {
             arr[i] = scn.nextInt();
         }
         int m = scn.nextInt();
         int[] brr = new int[m];
         for(int i=0;i<m;i++)
         {
             brr[i] = scn.nextInt();
         }

         System.out.println(findMedian(arr,n,brr,m));
    }
    //Function to find the median of the two arrays when they get merged.
    public static int findMedian(int arr[], int n, int brr[], int m)
    {
        //Your code here
        int k = (n + m)%2;
        
        if(k == 0)
        {
            return merge(arr,n,brr,m,true);
        }
        else
        {
            return merge(arr,n,brr,m,false);
        }
        
    }
    
    public static int merge(int arr[],int n,int brr[],int m,boolean flag)
    {
        int i = 0,j = 0;
        int k = 0;
        
        int [] temp = new int[n+m];
        while(i<n && j<m)
        {
            if(arr[i] <= brr[j])
            {
                temp[k] = arr[i];
                i++;
            }
            else
            {
                temp[k] = brr[j];
                j++;
            }
            k++;
        }
        
        if(i<n)
        {
            while(i<n)
            {
                temp[k] = arr[i];
                i++;
                k++;
            }
        }
        
        if(j<m)
        {
            while(j<m)
            {
                temp[k] = brr[j];
                j++;
                k++;
            }
        }
        
        if(flag)
        {
            int p = (n+m)/2;
            return (temp[p] + temp[p-1])/2;
        }
        else
        {
            int p = (n+m)/2;
            return temp[p];
        }
        
    }
    
}
