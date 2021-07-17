
import java.util.Scanner;

public class LeftRotationOfArray {

    static void ArrayRotate(int arr[], int n) {
        int temp = arr[0];
        for (int i = 1; i < n; i++) {
            arr[i - 1] = arr[i];
        }
        arr[n - 1] = temp;
    }

    public static void main(String[] args) {
        Scanner cin = new Scanner(System.in);
        System.out.print("Enter array size: ");
        int n = cin.nextInt();

        int[] arr = new int[n];
        System.out.print("Enter " + n + " element: ");
        for (int i = 0; i < n; i++) {
            arr[i] = cin.nextInt();
        }
        System.out.print("Enter number of rotation: ");
        int shift = cin.nextInt();
        for (int i = 0; i < shift; i++) {
            ArrayRotate(arr, n);
        }
        System.out.print("Array after " + shift + " rotation: ");
        for (int i = 0; i < n; i++) {
            System.out.print(arr[i] + " ");
        }
        System.out.println("\n");
    }
}
