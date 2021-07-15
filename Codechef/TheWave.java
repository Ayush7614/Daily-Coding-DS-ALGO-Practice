
/*
 * Implementation of problem "The Wave" from June Cook off challenge
 * Problem link: https://www.codechef.com/COOK130B/problems/WAV2
 * 
 */

import java.util.*;
import java.lang.*;
import java.io.*;

class thewave
{
    //In this function, binary search using divide and conquer is used
    //to find out how many elements in the array are greater than the root
    //If number of elements greater than root are odd then output will be NEGATIVE
    //If number of elements greater than root are even then output will be POSITIVE
    //If anyone element is equal to root output will be zero
    public static long lower_bound(long arr[], long N, long X)
    {
        long mid;
        long low = 0;
        long high = N;
        while (low < high) 
        {
            mid = low + (high - low) / 2;
            if (X <= arr[(int)mid]) 
                high = mid;
            else 
                low = mid + 1;
        }
        if(low < N && arr[(int)low] < X) {
        low++;
    }
    return low;
}
   //Main function
    public static void main (String[] args) throws java.lang.Exception
    {
        Scanner sc=new Scanner(System.in);
        long n=sc.nextLong();
        long q=sc.nextLong();
        long [] arr=new long[(int)n];
        for(long a=0;a<n;a++)
        arr[(int)a]=sc.nextLong();
        Arrays.sort(arr);                   //Sorting of array
        for(long b=0;b<q;b++)
        {
            long x=sc.nextLong();
            long y=lower_bound(arr,n,x);      //Function call to find out how many 
            if(y<n && arr[(int)y]==x)
            System.out.println("0");            //printing zero if X == anyone root
            else if(y%2==0)                     //checking whether number of elements greater than root are even or odd
            System.out.println("POSITIVE");     //if number of elements greater than root are even 
            else
            System.out.println("NEGATIVE");     //if number of elements greater than root are odd
        }  
    }
}

/*
Example Input

4 6
1 3 5 100
-2
2
4
80
107
5

Example Output

POSITIVE
NEGATIVE
POSITIVE
NEGATIVE
POSITIVE
0
 */
