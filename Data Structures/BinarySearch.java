/*Sample Input
Enter number of elements
5
Enter 5 integers
78
67
89
56
45
Enter a number to search for: 67
Sample Output
Found at index: 1  */

import java.util.*;

public class BinarySearch {

    public static void main(String[] args) {

        int n, a[];
        int searchV = 0, index;

        Scanner input = new Scanner(System.in);
        System.out.println("Enter number of elements");
        n = input.nextInt();
        a = new int[n];
        System.out.println("Enter " + n + " integers");
        // now we put all the value in a previous define array with help of scanner
        // class
        for (int i = 0; i < n; i++) {
            a[i] = input.nextInt();
        }
        System.out.print("Enter a number to search for: ");
        // take the user input which he wants to search
        searchV = input.nextInt();
        index = binarySearch(a, searchV);
        if (index != -1) {
            System.out.println("Found at index: " + index);
        } else {
            System.out.println("Not Found");
        }
    }

    // here we define binary search method
    static int binarySearch(int[] search, int find) {
        int start, end, midPt;
        start = 0;
        end = search.length - 1;
        while (start <= end) {
            midPt = (start + end) / 2;
            if (search[midPt] == find) {
                return midPt;
            } else if (search[midPt] < find) {
                start = midPt + 1;
            } else {
                end = midPt - 1;
            }
        }
        return -1;
    }
}