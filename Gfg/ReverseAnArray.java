
import java.util.Scanner;

public class ReverseAnArray {

    static void reverse(int a[], int n) {
        int i, k, t;
        for (i = 0; i < n / 2; i++) {
            t = a[i];
            a[i] = a[n - i - 1];
            a[n - i - 1] = t;
        }

        System.out.print("Reversed array is: ");
        for (k = 0; k < n; k++) {
            System.out.print(a[k]+" ");
        }
        System.out.print("\n");
    }

    public static void main(String[] args) {
        Scanner cin = new Scanner(System.in);
        System.out.print("Enter array size: ");
        int n = cin.nextInt();

        int[] arr = new int[n];
        for (int i = 0; i < n; i++) {
            System.out.print("  Enter element " + (i + 1) + " : ");
            arr[i] = cin.nextInt();
        }
        reverse(arr, n);
    }
}
