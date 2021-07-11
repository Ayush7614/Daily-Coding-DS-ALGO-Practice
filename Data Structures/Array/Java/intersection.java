/**
 * Java code to find intersection when
 * elements may not be distinct
*/

import java.io.*;
import java.util.Arrays;

class intersection {

	// Method to find intersection
	static void intersectionOfSortedArray(int firstArray[], int secondArray[], int n, int m)
	{
		int i = 0, j = 0;

		while (i < n && j < m) {

			// move iterator when same element not found
			if (firstArray[i] > secondArray[j]) { 
				j++;
			}
			// move iterator when same element not found
			else if (secondArray[j] > firstArray[i]) {
				i++;
			}
			// print when same element not found
			else {
			    
				System.out.print(firstArray[i] + ", ");
				i++;
				j++;
			}
		}
	}

	public static void main(String[] args)
	{
	    // Input Array
		int firstArray[] = {1, 1, 1, 2, 4, 5};
		int secondArray[] = { 2, 3, 5 };

		int length1 = firstArray.length;
		int length2 = secondArray.length;
	
		// Sorting if Un-Sorted
		Arrays.sort(firstArray);
		Arrays.sort(secondArray);
	
		// Method Call
		System.out.print("{ ");
		
		intersectionOfSortedArray(firstArray, secondArray, length1, length2);
		
		System.out.print("}");
	}
}
