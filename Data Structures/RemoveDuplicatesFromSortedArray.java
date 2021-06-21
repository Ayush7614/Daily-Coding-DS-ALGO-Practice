/* Java program to remove duplicate elements in an array */

import java.util.Scanner;
import java.util.Arrays;

public class RemoveDuplicatesFromSortedArray {
    public static int removeDuplicateElements(int arr[], int n) {
        if (n == 0 || n == 1) {
            return n;
        }
        int[] temp = new int[n];
        int j = 0;
        for (int i = 0; i < n - 1; i++) {
            if (arr[i] != arr[i + 1]) {
                temp[j++] = arr[i];
            }
        }
        temp[j++] = arr[n - 1];
        // Changing original array
        for (int i = 0; i < j; i++) {
            arr[i] = temp[i];
        }
        return j;
    }

    public static void main(String[] args) {
        int n;
        Scanner s = new Scanner(System.in);
        System.out.print("Enter no. of elements you want in array:");
        n = s.nextInt();
        int arr[] = new int[n + 1];
        System.out.println("Enter all the elements:");
        for (int i = 0; i < n; i++) {
            arr[i] = s.nextInt();
        }

        Arrays.sort(arr); // sorting array
        int length = arr.length;
        length = removeDuplicateElements(arr, length);

        // printing array elements
        System.out.print("Array after sorting and removing duplicates : ");
        for (int i = 0; i < length; i++)
            System.out.print(arr[i] + " ");
    }
}