import java.util.Scanner;
import java.util.*;

public class Main {
    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);
        int test = sc.nextInt();
        while (test-- > 0) {
            int n = sc.nextInt(); // till date
            int d = sc.nextInt(); // reduce amount
            int h = sc.nextInt(); // red alert
            int arr[] = new int[n];
            for (int i = 0; i < n; i++) {
                arr[i] = sc.nextInt();
            }
            func(arr, n, d, h);
            // System.out.println(Arrays.toString(arr));
        }
    }

    public static void func(int[] arr, int n, int d, int h) {
        int waterLevel = 0;
        for (int i = 0; i < n; i++) {
            if (arr[i] > 0) {
                waterLevel += arr[i];
            } else if (arr[i] == 0) {
                if (waterLevel <= d) {
                    waterLevel = 0;
                } else {
                    waterLevel -= d;
                }

            }
            if (waterLevel > h) {
                System.out.println("YES");
                return;
            }
        }
        System.out.println("NO");
    }
}
