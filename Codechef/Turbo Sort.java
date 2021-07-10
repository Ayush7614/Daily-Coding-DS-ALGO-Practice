
import java.util.*;
import java.lang.*;
import java.io.*;

class Codechef
{
	public static void main (String[] args) throws java.lang.Exception
	{
		Scanner sc = new Scanner(System.in);

		int testCases = sc.nextInt();
		// we have taken the array of size testCases
		   int[] arr = new int[testCases];
			//this loop will iterate from 0 to length of the array
			//to take the user input as array index value
			for(int i = 0;i<arr.length;i++){ 

		    		arr[i] = sc.nextInt();
			}
			//this will sort the array in ascending order
			Arrays.sort(arr);
			//this loop will print the array in the ascending order
			for(int i = 0;i<arr.length;i++){
			    
				System.out.println(arr[i]);
			}
	}
}
