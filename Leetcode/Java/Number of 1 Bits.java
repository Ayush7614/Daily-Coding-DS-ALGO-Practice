// Question  https://leetcode.com/problems/number-of-1-bits/

// Solution
import java.util.Scanner;

class main {
    public static int bits(int n) {
        int count = 0;
        while (n != 0) {
            count += (n & 1);
            n >>>= 1;
        }
        return count;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter number : ");
        int n = sc.nextInt();
        System.out.println(bits(n));
    }
}
