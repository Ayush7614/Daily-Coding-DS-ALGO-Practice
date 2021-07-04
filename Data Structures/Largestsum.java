import java.util.*;
import java.io.*;
public class Largestsum{
    static int maxSubArraySum(int nums[]){
    int n=nums.length;
    int i;
    int maximum_so_far = Integer.MIN_VALUE, maximum_ending_here = 0;
    for (i = 0; i < n; i++){
        maximum_ending_here=maximum_ending_here+nums[i];
        if(maximum_ending_here<nums[i])
        maximum_ending_here=nums[i];
        if(maximum_so_far<maximum_ending_here)
        maximum_so_far=maximum_ending_here;
    }
    return maximum_so_far;
    }
    public static void main(String []args){
        int size;
        System.out.println("Enter size of array");
        Scanner sc=new Scanner(System.in);
        size=sc.nextInt();
        int[] arr = new int[size];  
        System.out.println("Enter the elements of the array: ");  
        for(int i=0; i<size; i++)  
         {  
         //reading array elements from the user   
         arr[i]=sc.nextInt();  
         }
         int sum=maxSubArraySum(arr);
         System.out.println("Maximum contiguous sum is "+sum);
 }
 }
/*
Time Complexity: O(n)
Space Complexity:O(1)
*/
