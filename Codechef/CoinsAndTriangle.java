
import java.util.Scanner;
import java.lang.Math;

public class CoinsAndTriangle {

    public static void main(String[] args) {
        Scanner cin = new Scanner(System.in);
        
        int t = cin.nextInt();
        
        for (int i = 0; i < t; i++) {
            int n = cin.nextInt();
            
            int ans = (int) ((Math.sqrt(1 + 8.0 * n)) - 1);
            ans = ans / 2;
            
            System.out.println(ans);
        }
    }
}

/*
Example: 
Input
3
3
5
7

Output
2
2
3
*/