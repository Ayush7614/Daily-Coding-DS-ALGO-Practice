//effecient way to solve next permutation
//with O(n) time complexity and O(1) space complexity
import java.io.*;
import java.util.*;
//function in java which accepts array and return the next possible permutation
class next_permutation {
    static void nextPermutation(int[] array) {
        int n=array.length;
        int k=0;
        int j;
        //loop to break at array[j]>array[j-1]
        for( j=n-1;j>0;j--)
        {
            if(array[j]>array[j-1])
            {
                k=1;
                break;
            }
        }
        if(k==0)
        {   
            //to reverse the array if no next permutation is possible
            //this is according to the problem statement
            for(int i=0;i<n/2;i++)
            {
                int temp=array[i];
                array[i]=array[n-1-i];
                array[n-i-1]=temp;
            }
        }
        else
        {
            int x=j-1;
            //to find max in array from x to n-1 range
            for( k=n-1;k>x;k--)
            {
                if(array[k]>array[x])
                {
                    break;
                }                
            }
            //swaping
            int temp =array[x];
            array[x]=array[k];
            array[k]=temp;
            //sort function
            Arrays.sort(array, j, n);
        }
        //to print the final answer
        for(int s=0;s<n;s++)
        {
            System.out.print(array[s]+" ");
        }   
    }
    public static void main(String args[])
    {
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter the size of array");
        int n=sc.nextInt();
        int array[]=new int[n];
        System.out.println("Enter the elements of array");
        for(int i=0;i<n;i++)
        array[i]=sc.nextInt();
        //calls the static function
        nextPermutation(array);
        
    }
}